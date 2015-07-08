#include "Test.h"
#include "Individual.h"
#include <iostream>

using namespace std;

Test::Test(){

}

void Test::test(){
	Individual ind;
	ind.init();
	ind.print();
}

Test::~Test(){

}