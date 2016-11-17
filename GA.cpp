// GA.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include "Gene.h"
#include <iostream>

using namespace std;

const int iterNum = 1000;	// ���������趨Ϊ1000

int _tmain(int argc, _TCHAR* argv[])
{
	Gene::num = 8;          // ������������Ϊ8
	Gene::bitNum = 8;       // �������г�������Ϊ8
	Gene::upBond = 2;       // �����Ա����Ͻ�
	Gene::lowBond = -1;		// �����Ա����½�
	srand(static_cast<unsigned int>(time(0)));		// ��ʱ����Ϊ�������������
	Gene *gene = new Gene[Gene::num];
	for (int i = 0; i < Gene::num; i++)
	{
		gene[i].init();
	}


	// ѭ������
	for (int i = 0 ; i < iterNum; i++)
	{
		Gene::randSwap(gene);
		
		gene[rand()%Gene::num].variation();

		cout << "�� " << i << " �����Ľ��Ϊ: " << Gene::maxFitness << endl; 
	
	}

	// Gene::randSwap(gene);
	// �����Ž�����������̨
	cout << "��������ֵΪ��" << endl; 
	cout << " ������ " << iterNum << " �Σ����� y = x*sin(10pi*x) + 2.0 ������[-1, 2]�ϣ����Ž��Ϊ: " << Gene::maxFitness << endl;

	return 0;
}

