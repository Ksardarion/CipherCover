#include "CWorkspace.h"
#include "CDataSimple.h"
#include "CLink.h"
#include <string>
#include <fstream>


CWorkspace::CWorkspace(CDataChain& data):m_refChain(data){}

CWorkspace::~CWorkspace(){}

void CWorkspace::Init(int nDepth, int nLength) {
	m_refChain.Generate(nDepth, nLength);
}

const char* CWorkspace::GetChainString() {
	return m_refChain.GetFullString();
}

bool CWorkspace::Save(std::string& sFilepath) {
	std::fstream fo(sFilepath.c_str(), std::ios_base::out | std::ios_base::binary);
	if (!fo.bad()) {
		int size = m_refChain.GetLength();
		fo.write((char*)&size, 4);
		fo.write((char*)this->GetChainString(), size);
		fo.close();
		return true;
	}
	else {
		return false;
	}
}

bool CWorkspace::Load(std::string& sFilepath) {
	std::fstream fi(sFilepath.c_str(), std::ios_base::in | std::ios_base::binary);
	if (!fi.bad()) {
		int size = 0;
		char* ps;
		fi.read((char*)&size, 4);
		ps = new char[size + 1];
		fi.read((char*)ps, size);
		ps[size] = '\0';

		std::string fin(ps);
		delete[] ps;
		m_refChain.setString(fin);
		fi.close();
		
		return true;
	}
	else {
		return false;
	}
}

bool CWorkspace::AddLink(int nStartPos, int nLength, CLink* pLink) {
	if (pLink->setPos(nStartPos) && pLink->setSize(nLength)) {
		m_aLinks.push_back(pLink);
		return true;
	} else {
		return false;
	}
}

bool CWorkspace::RemoveLink(int nPosInList) {
	if (nPosInList < m_aLinks.size()) {
		delete m_aLinks[nPosInList];
		m_aLinks.erase(m_aLinks.begin() + nPosInList);
		return true;
	} else {
		return false;
	}
}

bool CWorkspace::GetAllLinks(LinksArray& aLinks) {
	if (m_aLinks.empty()) {
		aLinks = m_aLinks;
		return false;
	} else {
		aLinks = m_aLinks;
		return true;
	}
}