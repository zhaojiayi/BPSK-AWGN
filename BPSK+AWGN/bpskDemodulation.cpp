#include"bpskDemodulation.h"

int AfterDemodulation(double *_code) {
	 int n = (*_code > 0) ? 1 : 0;
	 return n;
}
