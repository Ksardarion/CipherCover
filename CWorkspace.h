#ifndef _CWorkspace_
#define _CWorkspace_

#include "CDataChain.h"
#include "CLink.h"
#include <string>

class CWorkspace
{
public:
	CWorkspace(CDataChain& data);
	~CWorkspace(void);
	//Ініціалізує повну послідовність цифр
	void Init(int nDepth, int nLength);
	//Повертає стрічку із повною послідовністю цифр.
	const char* GetChainString();
	//Зберігає стан Workspace у файл sFilepath
	bool Save(std::string& sFilepath);
	//Відновлює стан Workspace із файлу sFilepath
	bool Load(std::string& sFilepath);

	// МЕТОДИ ДЛЯ РОБОТИ З ЛІНКАМИ
	 
	//Добавляє лінк pLink у список у вибрану позицію nStartPos із довжиною nLength
	bool AddLink(int nStartPos, int nLength, CLink* pLink);
	//Видаляє лінк із списку у вибраній позиції(в списку) nPosInList
	bool RemoveLink(int nPosInList);
	//Повертає всі лінки, що присутні в списку
	bool GetAllLinks(LinksArray& aLinks);
	// ?
	//void showAllLinks();
private:
	//Зсилка на контейнер (породжений від CDataChain) із послідовністю
	CDataChain& m_refChain;
	//Список лінків на частини послідовностей
	LinksArray m_aLinks;
};

#endif