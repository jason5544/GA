#include "StdAfx.h"
#include "Gene.h"
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <cmath>
# include <iostream>
const double PI = 3.1415926;
using namespace std;

int Gene::num; 
int Gene::bitNum;
double Gene::upBond;
double Gene::lowBond;
double Gene::maxFitness = -9999;

Gene::Gene(void)
{
	geneSequence = new bool[Gene::bitNum];
}


Gene::~Gene(void)
{
	delete[] geneSequence;
}

void Gene::init()
{
	for(int i = 0; i < Gene::bitNum; i++)
	{	
		geneSequence[i] = rand()%2;
	}

}

void Gene::swapGene(const Gene &gene0, const Gene &gene1, Gene &gene2, Gene &gene3)
{
	int pos = rand()%Gene::num;
	for (int i = 0; i < pos; i++ )
	{
		gene2.geneSequence[i] = gene0.geneSequence[i];
		gene3.geneSequence[i] = gene1.geneSequence[i];
	}

	for (int i = pos; i < Gene::bitNum; i++ )
	{
		gene2.geneSequence[i] = gene1.geneSequence[i];
		gene3.geneSequence[i] = gene0.geneSequence[i];
	}
}

void Gene::variation()
{
	int pos = rand()%Gene::bitNum;
	if (geneSequence[pos])
	{
		geneSequence[pos] = 0;
	}
	else
	{
		geneSequence[pos] = 1;
	}
}

void Gene::fitnessFunction(int low ,int up)
{
	double x = 0;
	for (int i = 0; i < Gene::bitNum; i++)
	{
		x = x + pow(2.0, i)*(geneSequence[i]);
	}
	//cout << "x0 = " << x << endl;
	double part = pow(2.0, Gene::bitNum) - 1;
	//cout << "part = " << part << endl;
	x = low + ((up - low)/(part))*x;
	//cout << "x1 = " << x << endl;
	fitness = x*sin(10 * PI * x) + 2.0; 
}

void Gene::randSwap(Gene *&gene)
{
	double sumFitness = 0;
	for (int i = 0 ; i < Gene::num; i++)
	{
		gene[i].fitnessFunction(Gene::lowBond, Gene::upBond);
		if (gene[i].fitness > Gene::maxFitness)
		{
			Gene::maxFitness = gene[i].fitness;
		}
		sumFitness += gene[i].fitness;
	//	cout << gene[i].fitness << endl;
	}
		
	for (int i = 0; i < Gene::num; i++)
	{
		gene[i].posibility = gene[i].fitness/sumFitness;
	}

	Gene *newGene = new Gene[Gene::num];


	for (int i = 0; i < Gene::num; i = i + 2)
	{
		int order0, order1;
		
		Gene::randSelect(gene , order0, order1);		
		Gene::swapGene(gene[order0], gene[order1], newGene[i], newGene[i + 1]);
	}


	delete[] gene;
	gene = newGene;
}

void Gene::randSelect(Gene *gene, int &order0 ,int &order1)
{
	double randNum0, randNum1;
	get_rand(randNum0, randNum1);
	for (int i = 0; i <Gene::num; i++)
	{
		if (randNum0 < gene[i].posibility)
		{
			order0 = i;
			break;
		}
		else
		{
			randNum0 = randNum0 - gene[i].posibility;
		}
	}

	for (int i = 0; i <Gene::num; i++)
	{
		if (randNum1 < gene[i].posibility)
		{
			order1 = i;
			break;
		}
		else
		{
			randNum1 = randNum1 - gene[i].posibility;
		}
	}
}

void Gene::get_rand(double &x, double &y)
{
	int N = 999;
	x = rand()%(N+1)/(float)(N+1);//Éú³É0-1¼äµÄËæ»úÊý
	y = rand()%(N+1)/(float)(N+1);
}
