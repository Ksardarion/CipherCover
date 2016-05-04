#pragma once
#include <vector>
#include "CDlgCommand.h"

class CDialogManager
{
public:
 CDialogManager(CWorkspace& ws);
 ~CDialogManager(void);
 //Реєструє нову команду з ім"ям sName і функцією pFunc
 void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc);
 //Виконує цикл обробки команд користувача
 void Run();
private:
 //Вектор вказівників на зареєстровані команди
 std::vector<CDlgCommand*> m_aCommands;
 //Зсилка на робочий простір
 CWorkspace& m_refWorkspace;
};