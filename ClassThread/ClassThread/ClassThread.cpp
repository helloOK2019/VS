//Class for Thread
#include <iostream>
#include<Windows.h>
using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();
	static void	Work(void* p);//线程回调函数
	void StartWork();//启动线程函数

private:
	int* piNum;
};

MyClass::MyClass()
{
	piNum = new int;
}

MyClass::~MyClass()
{
	cout << "class end" << endl;
} MyClass;

void MyClass::Work(void* p)
{
	MyClass* pHandle = (MyClass*)p;
	cout << "work place" << endl;
	*(pHandle->piNum) = 0;
	while (1)
	{
		cout << ++*(pHandle->piNum) << endl;
		Sleep(100);
	}
}

void MyClass::StartWork()
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Work, this, 0, NULL);//参数:this指针
}

int main()
{
	MyClass Ctest;
	Ctest.StartWork();
	Sleep(10000);//
	//cout << "Hello World!" << endl;
}