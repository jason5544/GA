// GA.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include "Gene.h"
#include <iostream>

using namespace std;

const int iterNum = 1000;	// 迭代次数设定为1000

int _tmain(int argc, _TCHAR* argv[])
{
	Gene::num = 8;          // 基因数量设置为8
	Gene::bitNum = 8;       // 基因序列长度设置为8
	Gene::upBond = 2;       // 函数自变量上界
	Gene::lowBond = -1;		// 函数自变量下界
	srand(static_cast<unsigned int>(time(0)));		// 用时间作为随机函数的种子
	Gene *gene = new Gene[Gene::num];
	for (int i = 0; i < Gene::num; i++)
	{
		gene[i].init();
	}


	// 循环迭代
	for (int i = 0 ; i < iterNum; i++)
	{
		Gene::randSwap(gene);
		
		gene[rand()%Gene::num].variation();

		cout << "第 " << i << " 迭代的结果为: " << Gene::maxFitness << endl; 
	
	}

	// Gene::randSwap(gene);
	// 将最优结果输出到控制台
	cout << "函数最优值为：" << endl; 
	cout << " 共迭代 " << iterNum << " 次，函数 y = x*sin(10pi*x) + 2.0 在区间[-1, 2]上，最优结果为: " << Gene::maxFitness << endl;

	return 0;
}

