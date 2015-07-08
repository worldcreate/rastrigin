#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Test.h"
#include "Ga.h"

using namespace std;

int main(int argc,char **argv){
	int i=1;
	int trial=1;
	while(argc>i){
		if(argv[i][0]=='-'){
			const char *arg=&argv[i][2];
			switch(argv[i][1]){
				case 't':
					trial=atoi(arg);
				break;
				case 'T':
					Test t;
					t.test();
					exit(0);
				break;
			}
		}
		i++;
	}

	for(int i=0;i<trial;i++){
		Ga ga(argc,argv);
		ga.Initialize();
		ga.execute();
	}
}