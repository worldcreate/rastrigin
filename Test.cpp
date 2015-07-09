#include "Test.h"
#include "Individual.h"
#include "Ga.h"
#include <iostream>
#include <cmath>

using namespace std;

Test::Test(){

}

void Test::test(int argc,char** argv){
	Individual ind;
	ind.init();
	char c[10]={
		1,1,1,1,1,1,1,1,1,0
	};
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			ind[i*10+j]=c[j];
		}
	}
	ind.print();
	Ga ga(argc,argv);
	ga.evaluate(&ind);
	cout<<ind.getFitness()<<endl;

}

Test::~Test(){

}