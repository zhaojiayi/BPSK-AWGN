#ifndef C_A_H
#define C_A_H

/*******************************************************************
定义一些常数
*******************************************************************/
const int A = 48271;
const long M = 2147483647;
const int Q = M / A;
const int R = M % A;
const int Eb = 1; //单位比特的能量

double Uniform();
void Normal(double *nn, int len_nn);
double GetAwgnCode(int *_code, int ebn0, double *nn);

#endif // !C_A_H

