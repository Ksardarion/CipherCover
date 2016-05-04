#include "CDataChain.h"

#include <iostream>
#include <string>

using namespace std;

CDataChain::CDataChain(){};
CDataChain::~CDataChain(){};

int CDataChain::Find(const char *sSubStr, int nPos) {
    int pos = m_sChain.find(sSubStr, nPos);
    return ( pos == string::npos) ? -1 : pos;
}
size_t CDataChain::GetLength() {
    return m_sChain.length();
}
string CDataChain::GetSubStr(int nPos, int nLength) {
    return m_sChain.substr(nPos, nLength);
}
const char *CDataChain::GetFullString() {
    return m_sChain.c_str();
}
string CDataChain::setString(string& str) {
	m_sChain = str;
	return str;
}