#include "CDlgCommand.h"
#include "CWorkspace.h"

#include "CDlgCommand.h"

CDlgCommand::CDlgCommand(const char* sName, ptDlgCommandFunc pFunc):m_sName(sName), m_pFunc(pFunc){};
// Може треба буде видалити вказівник на ф-цію
CDlgCommand::~CDlgCommand(){
	// delete m_pFunc;
};

// Потрібно реалізувати збереження стану
void CDlgCommand::Run(CWorkspace& ws){
	// викликаємо зарезервовану ф-цію
	(*m_pFunc)(ws);
}