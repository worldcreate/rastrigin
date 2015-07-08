#ifndef _UTIL_H_
#define _UTIL_H_

#include <vector>
#include <iostream>

using namespace std;

class Util{
public:
	static int getRand(int,int);
	static void setSeed(int );
	template <typename T>
	static void removeVector(vector<T> &vec,int idx){
		typename vector<T>::iterator it=vec.begin();
		for(int i=0;i<vec.size();i++,it++){
			if(i==idx){
				vec.erase(it);
				break;
			}
		}
	}
};

#endif