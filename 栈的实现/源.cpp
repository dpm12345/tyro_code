#define  _CRT_SECURE_NO_WARNINGS
#include"stack.h"
#include<iostream>
using namespace std;

int main()
{
	stack<int> a;
	a.push(5);
	a.push(4);
	cout<<a.get_top_element()<<endl;
	a.pop();
	cout << a.get_top_element() << endl;
	a.pop();
	return 0;
}