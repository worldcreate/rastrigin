#include "Test.h"
#include "Individual.h"
#include "Ga.h"
#include "Util.h"
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

Test::Test(){

}

void Test::test(int argc,char** argv){
	Util::setSeed(200);
	Ga ga(argc,argv);
	vector<Individual*> vec;
	for(int i=0;i<10;i++){
		vec.push_back(new Individual());
		vec[i]->init();
		ga.evaluate(vec[i]);
	}
	for(int i=0;i<10;i++){
		vec[i]->print();
	}

	ga.roulette(vec);
}

Test::~Test(){

}