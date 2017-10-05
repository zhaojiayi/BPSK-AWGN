#include"channelAWGN.h"
#include<ctime>
#include<cstdlib>
#include<cmath>



/**************************************************************************
函数：Uniform()
功能：产生0-1间均匀分布的随机数
***************************************************************************/

double Uniform()
{	
	srand(time(NULL));
	static int state = rand();
	double u;
	int tmpState = A * (state % Q) - R * (state / Q);
	if (tmpState >= 0)
		state = tmpState;
	else
		state = tmpState + M;

	u = state / (double)M;

	return u;
}

/***************************************************************************
函数：Normal(double *nn, int len_nn)
功能：产生长为len_nn的服从均值为0，方差为1的正态分布的随机数
输入参数：
len_nn  ----- 随机数长度
输出参数
*nn     ----- 保存产生的随机数
****************************************************************************/

void Normal(double *nn, int len_nn)
{
	double x1, x2, w;
	int t;

	for (t = 0; 2 * t + 1 < len_nn; t++) {
		w = 2.0;
		while (w > 1.0) {
			x1 = 2.0 * Uniform() - 1.0;
			x2 = 2.0 * Uniform() - 1.0;

			w = x1 * x1 + x2 * x2;
		}

		w = sqrt(-2.0 * log(w) / w);

		nn[2 * t] = x1 * w;
		nn[2 * t + 1] = x2 * w;
	}

	if (len_nn % 2 == 1) {
		w = 2.0;
		while (w > 1.0) {
			x1 = 2.0 * Uniform() - 1.0;
			x2 = 2.0 * Uniform() - 1.0;

			w = x1 * x1 + x2 * x2;
		}

		w = sqrt(-2.0 * log(w) / w);

		nn[len_nn - 1] = x1 * w;
	}

	return;
}


double GetAwgnCode(int *_code,int ebn0,double *nn) {
	double 	snr = pow(10, 0.1*ebn0);  // snr = e_d/N_0
	double sigma = sqrt((Eb / snr) / 2);  //经验证，高斯白噪声的功率谱密度为方差，等于N0/2
	double result = *_code + sigma*(*nn);
	return result;
}
