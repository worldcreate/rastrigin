#ifndef _GA_H_
#define _GA_H_

#include "Individual.h"
#include <vector>

using namespace std;

class Ga{
public:
	Ga(int,char**);
	void Initialize();
	void execute();
	void selectReproduction(vector<Individual*>&);
	void selectSurvive(vector<Individual*>&);
	void crossOver(vector<Individual*>&);
	void evaluate(Individual *);
	void printList();
	void Finallize();
	~Ga();
private:
	vector<Individual*> m_Population;
	int m_PopulationSize;
	int m_Dimension;
	int m_BitSize;
	int m_Generation;
	int m_ChildNum;

};

#endif