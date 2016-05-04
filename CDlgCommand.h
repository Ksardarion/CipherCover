#pragma once
#include <string>
#include "CWorkspace.h"
//Декларація типу функції, що буде використовуватися для виконання користувацьких команд
//
// typedef void (*myfunc)()
// myfunc f те саме що (*f)()
// typedef спрощує використання вказівників на ф-ції
typedef void (*ptDlgCommandFunc)(CWorkspace& ws);

class CDlgCommand
{
public:
 CDlgCommand(const char* sName, ptDlgCommandFunc pFunc = NULL);
 ~CDlgCommand(void);
 //Отримання назви команди
 const char* GetName() { return m_sName.c_str(); }
 //Виклик зв"язаної функції
 void Run(CWorkspace& ws);
private:
 //Назва команди
 std::string m_sName;
 //Вказівник на функцію, що буде використовуватися для виконання користувацьких команд
 ptDlgCommandFunc m_pFunc;
};