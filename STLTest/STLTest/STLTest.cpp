#include <iostream>
#include<deque>
#include<algorithm>//for erase begin end
#include<set>
#include<map>
using namespace std;

int main()
{
	deque<int> iDeque{ 2,3,4,5,6 };
	iDeque.erase(remove(begin(iDeque), end(iDeque), 3), end(iDeque));
	deque<int>::iterator v = begin(iDeque);
	while (v!=end(iDeque))
	{
		cout << "v = " << *v << endl;
		v++;
	}
	set<int> iSet{ 2,3,4,5,6 };
	iSet.erase(6);
	set<int>::iterator vSet = begin(iSet);
	while (vSet!=end(iSet))
	{
		cout << "vSet = " << *vSet << endl;
		vSet++;
	}
	map<string, int> iMap{ {"aaa",1},{"bbb",2},{"ccc",3} };
	iMap.erase("aaa");
	map<string, int>::iterator vMap = begin(iMap);
	while (vMap!=end(iMap))
	{

	}
}

