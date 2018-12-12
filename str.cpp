#include <iostream>
#include <string>
#include <fftw3.h>
#include <complex>
#include <vector>
using cmpx = std::complex<double>;

template<class T>
struct inp {
	int 	_n;
	void 	(*_doIt)(std::vector<T>&);
	std::vector<T> _buff;
	inp(void(*doit)(std::vector<T>&) ,int n=8) : _n(n), _doIt(doit) {_buff.reserve(n);}
	friend std::istream& operator>>(std::istream&is,inp& i) {
		T tmp;
		is >> tmp; 
		i<<tmp;
		return is;
	}
	void operator<<(T t) {
		_buff.push_back( t );
		if( _buff.size() == _n ) {
			_doIt( _buff );
			_buff.clear();
		}
	}
};

void fft( std::vector<cmpx>& vec ) {
	int sz[1] = {(int)vec.size()};
	fftw_plan p = fftw_plan_many_dft( 1 , sz , 1 , 
			(fftw_complex*)vec.data() , NULL , 1 , vec.size() , 
			(fftw_complex*)vec.data() , NULL , 1 , vec.size() , 
			FFTW_FORWARD , FFTW_ESTIMATE );

	fftw_execute( p );
	fftw_destroy_plan( p );
	std::cout << "\n FFT: ";
	for( auto&x : vec )
		std::cout << " " << x;
	std::cout << "\n----\n";
}

int main() {
	inp<cmpx> obj( fft , 8 );
	do {
		std::cin >> obj;	
	} while( std::cin );
	std::cout <<"\n done \n";
	return 0;
}
