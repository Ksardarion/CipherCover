#include "CDataSimple.h"
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

CDataSimple::CDataSimple(){};
CDataSimple::~CDataSimple(){};

int CDataSimple::_numberLength(int number) {
	if (number == 0) {
		return 1;
	}
	return floor(log10(number)) + 1;
};

char* CDataSimple::_intToChars(int number) {
	char nums[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	int len = _numberLength(number);
	char *result = new char[len];

	for (int i = len - 1; i >= 0; i--) {
		int last = number % 10;
		result[i] = nums[last];
		number /= 10;
	}
	result[len] = '\0';

	return result;
}

void CDataSimple::Generate(int nDepth, int nMaxLength) {
	string s;
	int i = 0, j = 0;
	while (i < nDepth && j < nMaxLength) {
		char* add = _intToChars(i);
		int k = 0;

		while(add[k] != '\0' && j < nMaxLength) {
			s += add[k];
			k++;
			j++;
		}
		i++;
	}

	m_sChain = s;
}
