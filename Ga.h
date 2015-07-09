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
	void printList();
	void Finallize();
	void printFitness();
	static double decode(const vector<char>&);
	double convert(double);
	void evaluate(Individual *);
	~Ga();
private:
	void selectSurvive(vector<Individual*>&);
	void selectReproduction(vector<Individual*>&);
	void crossOver(vector<Individual*>&);
	void mutation(Individual*);
	vector<Individual*> m_Population;
	int m_PopulationSize;
	int m_Dimension;
	int m_BitSize;
	int m_Generation;
	int m_ChildNum;
	double m_Lower;
	double m_Upper;
	int m_mRate;
};

#endif