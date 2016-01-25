#include <exception>

template <class T>
class FArray3D{
private:
	T* p;
	int _sizei,_sizej,_sizek;

public:

	T* ptr() {return p;}
	
	FArray3D (int sizei,int sizej, int sizek){

		try{
		p=new T [sizei*sizej*sizek];
		
		_sizei=sizei;
		_sizej=sizej;
		_sizek=sizek;
		}

		catch (...) {
		std::cerr<<"exception: memory allocation failed";
		exit(0);
		}
		
	}

	FArray3D (const FArray3D& copy){

		_sizei=copy.get_sizei();
		_sizej=copy.get_sizej();
		_sizek=copy.get_sizek();

		p=new T [sizei*sizej*sizek];

		for (int k=0;k<_sizek;k++){
			for (int j=0;j<_sizej;j++){
				for (int i=0;i<_sizei;i++){
					p[i+j*_sizei+k*size_i*_sizej]=copy.p[i+j*_sizei+k*size_i*_sizej];
				}
			}
		}


		
	}


	FArray3D operator= (const FArray3D<T>& copy){

		this.sizei=copy.get_sizei ();
		this.sizej=copy.get_sizej ();
		this.sizek=copy.get_sizek ();
	
		this.p=new T [sizei*sizej*sizek];

		for (int k=0;k<_sizek;k++){
			for (int j=0;j<_sizej;j++){
				for (int i=0;i<_sizei;i++){
					this.p[i+j*_sizei+k*size_i*_sizej]=copy.p[i+j*_sizei+k*size_i*_sizej];
				}
			}
		}

		return this;

	}

	void initialize(T var){

		for (int k=0;k<_sizek;k++){
			for (int j=0;j<_sizej;j++){
				for (int i=0;i<_sizei;i++){
					p[i+j*_sizei+k*_sizei*_sizej]=var;
				}
			}
		}


	}

	int leni() {return _sizei;}
	int lenj() {return _sizej;}
	int lenk() {return _sizek;}


	~FArray3D () {

		delete [] p;
	}

	T& operator() (int i,int j,int k){


			i=i-1;
			j=j-1;

			if (i>= _sizei) {std::cerr<<"exception: index i is out of range"; exit(0);}
			if (j>= _sizej) {std::cerr<<"exception: index j is out of range"; exit(0);}
			if (k>= _sizek) {std::cerr<<"exception: index k is out of range"; exit(0);}

			return p[i+j*_sizei+k*_sizei*_sizej];

	}



};


template <class T>
class FArray2D{
private:
	T* p;
	
	int _sizei,_sizej;

public:

	T* ptr() {return p;}



	FArray2D (int sizei,int sizej){
		
		try{
		p=new T [sizei*sizej];
		pp=&p;
		
		_sizei=sizei;
		_sizej=sizej;
		}

		catch (...) {
		std::cerr<<"exception: memory allocation failed";
		exit(0);
		}
		
		
	}

	FArray2D (const FArray2D& copy){

		_sizei=copy.get_sizei();
		_sizej=copy.get_sizej();
		
		p=new T [sizei*sizej];

		
			for (int j=0;j<_sizej;j++){
				for (int i=0;i<_sizei;i++){
					p[i+j*_sizei]=copy.p[i+j*_sizei];
				}
			}
		


		
	}


	FArray2D operator= (const FArray2D<T>& copy){

		this.sizei=copy.get_sizei ();
		this.sizej=copy.get_sizej ();
		
	
		this.p=new T [sizei*sizej];

		
			for (int j=0;j<_sizej;j++){
				for (int i=0;i<_sizei;i++){
					this.p[i+j*_sizei]=copy.p[i+j*_sizei];
				}
			}
		

		return this;

	}

	void initialize(T var){

		
			for (int j=0;j<_sizej;j++){
				for (int i=0;i<_sizei;i++){
					p[i+j*_sizei]=var;
				}
			}
		


	}

	int leni() {return _sizei;}
	int lenj() {return _sizej;}
	


	~FArray2D () {

		delete [] p;
	}

	T& operator() (int i,int j){

			i=i-1;
			j=j-1;


			if (i>= _sizei) {std::cerr<<"exception: index i is out of range"; exit(0);}
			if (j>= _sizej) {std::cerr<<"exception: index j is out of range"; exit(0);}
			

			return p[i+j*_sizei];

	}

};



template <class T>
class FArray1D{
private:
	T* p;
	int _sizei;

public:

	T* ptr() {return p;}

	FArray1D (int sizei){
		
		
		try{
		
		// this block is only required if the program is compiled under Debug mode in Visual Studio
		//if (sizei<0) {
		//exception e;
		//throw e;
		//}

		p=new T [sizei] ;
		_sizei=sizei;

		}
		
		catch (...) {
		std::cerr<<"exception: memory allocation failed";
		exit(0);
		}


		
		
				
		
	}

	FArray1D (const FArray1D& copy){

		_sizei=copy.get_sizei();
				
		p=new T [sizei];

		
			
				for (int i=0;i<_sizei;i++){
					p[i]=copy.p[i];
				}
			
		


		
	}


	FArray1D operator= (const FArray1D<T>& copy){

		this.sizei=copy.get_sizei ();
				
	
		this.p=new T [sizei];

		
			
				for (int i=0;i<_sizei;i++){
					this.p[i]=copy.p[i];
				}
			
		

		return this;

	}

	void initialize(T var){

		
			
				for (int i=0;i<_sizei;i++){
					p[i]=var;
				}
	

	}

	int leni() {return _sizei;}
		


	~FArray1D () {

		delete [] p;
	}

	T& operator() (int i){

			i=i-1;
			

			if (i>= _sizei) {std::cerr<<"exception: index i is out of range"; exit(0);}
					
			return p[i];

	}

};