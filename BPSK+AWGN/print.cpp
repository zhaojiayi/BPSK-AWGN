#include"print.h"
#include<iostream>
#include<fstream>

using namespace std;
//将Eb/N0和BER输入到文本文件中，方便到时利用MATLAB进行画图
void print(int ebn0, double ber) {
	cout << ebn0 << " " << ber << endl;
	fstream fout("Result.txt", ios::out | ios::app);
	if (!fout.is_open()) {
		cout << "error" << endl;
		exit(1);
	}
	fout<< ebn0 << " " << ber << endl;
	fout.close();
}
