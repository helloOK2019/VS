#include<iostream>
#include"mySTL.h"
#include<string>

using namespace std;

int main()
{

	cout << "type int test" << endl << endl;
	CIntList<int>* pIntList = new	CIntList<int>();
	cout << "Add 1-->Show:";
	pIntList->Add(1);
	pIntList->Show();

	cout << "Add 23 and Getsecond Value:";
	pIntList->Add(23);
	cout << pIntList->GetValueAt(2) << endl;
	cout << "Get third Value:";
	cout << pIntList->GetValueAt(3) << endl;

	cout << "Delete Last-->Show:";
	pIntList->Delete();
	pIntList->Show();
	cout << "****************************************" << endl;


	cout << "type char test" << endl << endl;
	CIntList<char>* pCharList = new	CIntList<char>();
	cout << "Add a-->Show:";
	pCharList->Add('a');
	pCharList->Show();

	cout << "Add b and Getsecond Value:";
	pCharList->Add('b');
	cout << pCharList->GetValueAt(2) << endl;
	cout << "Get third Value:";
	cout << pCharList->GetValueAt(3) << endl;

	cout << "Delete Last-->Show:";
	pCharList->Delete();
	pCharList->Show();
	cout << "****************************************" << endl;


	cout << "type string test" << endl << endl;
	CIntList<string>* pStringList = new	CIntList<string>();
	cout << "Add hello-->Show:";
	pStringList->Add("hello");
	pStringList->Show();

	cout << "Add OK and Getsecond Value:";
	pStringList->Add("OK");
	cout << pStringList->GetValueAt(2) << endl;
	cout << "Get third Value:";
	cout << pStringList->GetValueAt(3) << endl;

	cout << "Delete Last-->Show:";
	pStringList->Delete();
	pStringList->Show();
	cout << "****************************************" << endl;

	return 0;
}