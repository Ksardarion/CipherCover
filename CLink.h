#pragma once

#include "CDataChain.h"
#include <iostream>
#include <vector>

class CLink
{
public:
	CLink(CDataChain& refChain);
	virtual ~CLink(void);
	//Пробує прив"язати об"єкт до підстрічки у послідовності
	bool Attach(const char* sSubStr);
	//Вручну встановити позицію підстрічки
	bool setPos(int nPos);
	//Вручну всановити дожину підпослідовності
	bool setSize(int nSize);
	//повертає довжину підстрічки, до якої прив"язується об"єкт
	int size();
	//повертає позицію початку у повній послідовності
	int startPos();
	//Форматований вивід на консоль
	virtual void Output(std::ostream& os);
	//Зберігає об"єкт у вихідному потоці
	virtual bool Save(std::ostream& so);
 	//Зчитує об"єкт із вхідного потоку
	virtual bool Load(std::istream& is);
protected:
	//Посилання на контейнер з повною послідовністю
	CDataChain& m_refChain;
	//Позиція початку у повній послідовності
	int m_nPos;
	//Довжина підстрічки, до якої прив"язується об"єкт
	int m_nSize;
};

typedef std::vector<CLink*> LinksArray;