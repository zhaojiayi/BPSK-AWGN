#include <ctime>
#include <cstdlib>
#include "createRandomCode.h"
//使用srand()产生随机数
int GetRandCode() {
	srand(time(NULL));
	int randNum = rand() % 2;
	return randNum;
}
