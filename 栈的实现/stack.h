#ifndef STACK_H
#define STACK_H
#include<cassert>


template<class T,int SIZE=50>
class stack
{
private:
	T list[SIZE];
	int top;
public:
	stack();
	void push(const T &item);
	void pop();
	bool isfull();
	bool isempty();
	int  get_top();
	T get_top_element();

};

template<class T,int SIZE>
stack<T, SIZE>::stack() :top(-1){}

template<class T,int SIZE>
bool stack<T,SIZE>::isfull()
{
	return top == SIZE - 1;
}

template<class T, int  SIZE>
bool stack<T, SIZE>::isempty()
{
	return top == -1;
}

template<class T, int  SIZE>
void stack<T, SIZE>::push(const T &item)
{
	assert(!isfull());
	list[++top] = item;
}

template<class T, int  SIZE>
void stack<T, SIZE>::pop()
{
	assert(!isempty());
	top--;
}

template<class T, int  SIZE>
int  stack<T, SIZE>::get_top(){ return top; }

template<class T, int SIZE>
T stack<T, SIZE>::get_top_element()
{
	return list[top];
}
#endif
