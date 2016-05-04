#include "CLink.h"
#include "CDataChain.h"
#include <cstring>
#include <iostream>
#include <string>

CLink::CLink(CDataChain& refChain):m_refChain(refChain) {};
CLink::~CLink(){};

bool CLink::Attach(const char* sSubStr) {
	if (std::string::npos != m_refChain.Find(sSubStr, 0)) {
		m_nPos = m_refChain.Find(sSubStr, 0);
		m_nSize = strlen(sSubStr);
		return true;
	} else {
		return false;
	}
};

bool CLink::setPos(int nPos) {
	if (nPos >= 0 && nPos < m_refChain.GetLength()) {
		m_nPos = nPos;
		return true;
	} else {
		return false;
	}
};

bool CLink::setSize(int nSize) {
	if (nSize >= 0 && nSize <= m_refChain.GetLength() - nSize) {
		m_nSize = nSize;
		return true;
	} else {
		return false;
	}
};

int CLink::size() {
	return m_nSize;
};

int CLink::startPos() {
	return m_nPos;
};

void CLink::Output(std::ostream& os) {
	std::cout << m_refChain.GetSubStr(m_nPos, m_nSize) << std::endl;
};

bool CLink::Save(std::ostream& so) {
	so.write((char*)&m_nPos, 4);
	so.write((char*)&m_nSize, 4);

	return true;
};

bool CLink::Load(std::istream& is) {
	is.read((char*)&m_nPos, 4);
	is.read((char*)&m_nSize, 4);

	return true;
};
