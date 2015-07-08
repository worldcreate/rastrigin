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
	~Ga();
private:
	void evaluate(Individual *);
	void selectSurvive(vector<Individual*>&);
	void selectReproduction(vector<Individual*>&);
	void crossOver(vector<Individual*>&);
	void mutation(Individual*);
	double convert(double);
	static double decode(const vector<char>&);
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