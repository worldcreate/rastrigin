#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include <vector>

using namespace std;

class Individual{
public:
	Individual();
	Individual(Individual&);
	Individual(int,int);
	char& operator[](int);
	Individual& operator=(Individual&);
	void init();
	void print();
	static bool Comparator(const Individual*,const Individual*);
	~Individual();
private:
	vector<char> bit;
	int m_Dimension;
	int m_BitSize;
	double m_Fitness;
};

#endif