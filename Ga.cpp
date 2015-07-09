#include "Ga.h"
#include "Util.h"
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>

Ga::Ga(int argc,char **argv)
	:m_PopulationSize(500),m_Dimension(10),m_BitSize(10),m_ChildNum(2),m_Generation(100),m_Lower(-5.12),m_Upper(5.12),m_mRate(1){
	int i=1;
	while(argc>i){
		if(argv[i][0]=='-'){
			const char *arg=&argv[i][2];
			switch(argv[i][1]){
				case 'g':
					m_Generation=atoi(arg);
				break;
				case 'p':
					m_PopulationSize=atoi(arg);
				break;
				case 'c':
					m_ChildNum=atoi(arg);
				break;
				case 'd':
					m_Dimension=atoi(arg);
				break;
				case 'b':
					m_BitSize=atoi(arg);
				break;
			}
		}
		i++;
	}
}

void Ga::Initialize(){
	for(int i=0;i<m_PopulationSize;i++){
		m_Population.push_back(new Individual(m_Dimension,m_BitSize));
		m_Population[i]->init();
		evaluate(m_Population[i]);
	}
}

void Ga::printList(){
	for(int i=0;i<m_PopulationSize;i++){
		m_Population[i]->print();
	}
}

void Ga::execute(){
	for(int g=0;g<m_Generation;g++){
		cout<<"gen="<<g<<endl;
		vector<Individual*> family;
		selectReproduction(family);
		crossOver(family);
		selectSurvive(family);
		printFitness();
	}
}

void Ga::printFitness(){
	double min=INT_MAX;
	double ave=0;
	double variance=0;
	for(int i=0;i<m_PopulationSize;i++){
		if(min>m_Population[i]->getFitness()){
			min=m_Population[i]->getFitness();
		}
		ave+=m_Population[i]->getFitness();
	}
	ave/=m_PopulationSize;
	for(int i=0;i<m_PopulationSize;i++){
		variance+=pow((m_Population[i]->getFitness()-ave),2);
	}
	variance/=m_PopulationSize;
	cout<<"min="<<min<<",variance="<<variance<<endl;
}

void Ga::selectReproduction(vector<Individual*> &family){
	random_shuffle(m_Population.begin(),m_Population.end());
	int r=Util::getRand(0,m_Population.size()-1);
	family.push_back(m_Population[r]);
	Util::removeVector(m_Population,r);
	r=Util::getRand(0,m_Population.size()-1);
	family.push_back(m_Population[r]);
	Util::removeVector(m_Population,r);
}

void Ga::crossOver(vector<Individual*> &family){
	Individual *p1=family[0];
	Individual *p2=family[1];
	for(int i=0;i<m_ChildNum;i+=2){
		Individual *c1=new Individual(m_Dimension,m_BitSize);
		Individual *c2=new Individual(m_Dimension,m_BitSize);
		c1->init();
		c2->init();

		for(int i=0;i<m_BitSize;i++){
			if(Util::getRand(0,1)){
				(*c1)[i]=(*p1)[i];
				(*c2)[i]=(*p2)[i];
			}else{
				(*c1)[i]=(*p2)[i];
				(*c2)[i]=(*p1)[i];
			}
		}
		mutation(c1);
		mutation(c2);
		evaluate(c1);
		evaluate(c2);
		family.push_back(c1);
		family.push_back(c2);
	}
}

void Ga::selectSurvive(vector<Individual*> &family){
	sort(family.begin(),family.end(),Individual::Comparator);
	m_Population.push_back(family[0]);
	m_Population.push_back(family[1]);

	for(int i=2;i<family.size();i++){
		delete(family[i]);
	}
}

void Ga::evaluate(Individual *individual){
	vector<double> x(m_Dimension);
	for(int i=0;i<m_Dimension;i++){
		vector<char> bit(m_BitSize);
		for(int j=0;j<m_BitSize;j++){
			bit[j]=(*individual)[j+i*m_BitSize];
		}
		x[i]=decode(bit);
		x[i]=convert(x[i]);
		#ifdef DEBUG
			cout<<x[i]<<endl;
		#endif
	}
	double fit=10*m_Dimension;
	for(int i=0;i<m_Dimension;i++){
		fit+=(x[i]*x[i])-(10*cos(2*M_PI*x[i]));
	}
	individual->setFitness(fit);
}

void Ga::mutation(Individual *individual){
	for(int i=0;i<m_BitSize;i++){
		int r = Util::getRand(1, 100);
		if (r>m_mRate)
			continue;
		(*individual)[i] = !(*individual)[i];
	}
}

double Ga::convert(double src){
	double weight=(m_Upper-m_Lower)/(pow(2,m_BitSize)-1);
	double dst=src*weight+(m_Lower);
	return dst;
}

double Ga::decode(const vector<char>& bit){
	double f=0;
	for(int i=0;i<bit.size();i++){
		f+=bit[i]*pow(2,i);
	}
	return f;
}

void Ga::Finallize(){
	for(int i=0;i<m_Population.size();i++){
		delete(m_Population[i]);
	}
}

Ga::~Ga(){
	Finallize();
}