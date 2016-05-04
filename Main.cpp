#include <iostream>
#include <string>
#include "CDataSimple.h"
#include "CWorkspace.h"
#include "CDialogManager.h"
#include "CLink.h"

using namespace std;

void initSequence(CWorkspace& ws) {
	int nDepth = 0;
	int nMaxLength = 0;
	
	cout << "Please enter a number limit" << endl;
	cin >> nDepth;
	cout << "Please enter a length" << endl;
	cin >> nMaxLength;

	ws.Init(nDepth, nMaxLength);
}

void showFullSequence(CWorkspace& ws) {
	cout << ws.GetChainString() << endl;
}

void saveSequence(CWorkspace& ws) {
	string path;
	cout << "Write where will save, or Enter * to use default path (save.bin)" << endl;
	cin >> path;
	if (path.length() == 1 && path[0] == '*') {
		path = "save.bin";
	}
	ws.Save(path);
}

void loadSequence(CWorkspace& ws) {
	string path;
	cout << "Write path to file, or Enter * to use default path (save.bin)" << endl;
	cin >> path;
	if (path.length() == 1 && path[0] == '*') {
		path = "save.bin";
	}
	ws.Load(path);
}

void findSubstring(CWorkspace& ws) {
	// PROBLEMS  m_refChain is private
	CLink* link = new CLink(ws.m_refChain);
	
	string str;
	cout << "Write string to find " << endl; 
	cin >> str;

	if (link->Attach(str.c_str())) {
		string out_str(ws.GetChainString());
		out_str.insert(link->startPos(), 1, '(');
		out_str.insert(link->startPos() + link->size(), 1, ')');
		cout << out_str << endl;
	}
}

int main (int argc, char* argv[]) {
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);
	mgr.RegisterCommand("Init sequence", initSequence);
	mgr.RegisterCommand("Show sequence", showFullSequence);
	mgr.RegisterCommand("Save", saveSequence);
	mgr.RegisterCommand("Load", loadSequence);
	mgr.RegisterCommand("Find substring", findSubstring);
	mgr.Run();

	return 0;
}