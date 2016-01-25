#include "Array.h"
#include "FArray.h"
#include <iostream>

using namespace std;



int main(){

	//Array1D<int> A(1000000000000);
	//Array1D<int> A(100);
	FArray1D<int> B(100);
	

	//A(100)=10;
	
	for (int i=1;i<=100;i++)	B(i)=10;

	int* p=B.ptr();

	

	for (int i=0;i<100;i++)	cout<< i << " , "<< p[i] << endl;


	return 0;
}