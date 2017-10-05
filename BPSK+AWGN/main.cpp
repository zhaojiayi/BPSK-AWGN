#include "createRandomCode.h"
#include "bpskModulation.h"
#include "channelAWGN.h"
#include "bpskDemodulation.h"
#include "print.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

const int N = 1000000; //比特长度
const int Ebn0_Num = 11; //ebn0数量
int main() {
	fstream fclear("Result.txt", ios::out); // 每次打开先清空文本原数据
	for (int i = 0; i < Ebn0_Num; i++) { 
		int miss = 0;
		for (int j = 0; j < N; j++) { 
			int input = GetRandCode(); ////获取随机数 
			int n1 = AfterModulation(input);//完成0到-1,1到1的映射
			double uniform = Uniform();
			double *Gaussian_random = new double;
			Normal(Gaussian_random, 1); //产生服从均值为0，方差为1的正态分布的随机数
			double n2 = GetAwgnCode(&n1, i, Gaussian_random);// 获取在信道中加入高斯白噪声后的数据 
			int output = AfterDemodulation(&n2);//完成解调器功能，完成到0和1的还原
			if (output != input) // 与原信号进行比较，进行误码统计
				miss++;
		}
		double ber = miss / (double)N;// 对于每一个ebn0，求得ber
		print(i, ber); // 输出
	}
	system("pause");
	return 0;
}
