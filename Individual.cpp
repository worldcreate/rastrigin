#include "Individual.h"
#include "Util.h"
#include <iostream>
#include <cstdio>

Individual::Individual():m_Dimension(10),m_BitSize(10){

}

Individual::Individual(int dim,int bitSize):m_Dimension(dim),m_BitSize(bitSize){

}

char& Individual::operator[](int idx){
	return bit[idx];
}

Individual& Individual::operator=(Individual& dst){
	
}

bool Individual::Comparator(const Individual *l, const Individual *r){
	return l->m_Fitness<r->m_Fitness;
}

void Individual::init(){
	bit.resize(m_Dimension*m_BitSize);
	for(int i=0;i<m_Dimension*m_BitSize;i++){
		bit[i]=Util::getRand(0,1);
	}
}

void Individual::print(){
	for(int i=0;i<m_BitSize*m_Dimension;i++){
		printf("%d",bit[i]);
	}
	printf(":%lf",m_Fitness);
	printf("\n");
}

void Individual::setFitness(double a_Fitness){
	m_Fitness=a_Fitness;
}

double Individual::getFitness(){
	return m_Fitness;
}

Individual::~Individual(){

}