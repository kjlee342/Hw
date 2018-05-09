#ifndef _MY_STACK_TEMPLATE_H_
#define _MY_STACK_TEMPLATE_H_
#include <iostream>
using namespace std;
template <class T>
class MyStack
{
public:
	// friend 함수
	friend ostream& operator<< (ostream&, const MyStack<T> &);
	MyStack();
	MyStack(long value);
	~MyStack();
	bool push(const T& pushValue);
	bool pop(T& popValue);
	bool peek(T& peekValue) const;
	bool isEmpty() const; // test
	bool isFull() const;
private:
	T *elements;
	long size;
	long top;
	void setSize(long);
	long getSize();
	void allocateMemory();
	const static long default_stack_size = 64;
};
template <class T>
MyStack<T>::MyStack()
{
	size = default_stack_size;
	allocateMemory();
	top = -1;
}
template <class T>
MyStack<T>::MyStack(long val)
{
	if (val < 0)
		val *= -1;
	else if (val == 0)
		val = default_stack_size;
	size = val;
	allocateMemory();
	top = -1;
}
template <class T>
MyStack<T>::~MyStack()
{
	//delete array dynamically allocated
	delete[] elements;
}
template <class T>
bool MyStack<T>::push(const T& pushValue)
{
	if (!isFull())
	{
		elements[++top] = pushValue;
		return true;
	}
	else
		return false;
}
template <class T>
bool MyStack<T>::pop(T& popValue)
{
	if (!isEmpty())
	{
		popValue = elements[top--];
		return true;
	}
	else
		return false;
}
template <class T>
bool MyStack<T>::peek(T& peekValue) const
{
	{
		if (!isFull())
		{
			peekValue = elements[top];
			return true;
		}
		else
			return false;
	}

}
template <class T>
bool MyStack<T>::isFull() const
{
	return top + 1 >= size;
}
template <class T>
bool MyStack<T>::isEmpty() const
{
	if (top == -1) {
		return true;
	}
	return false;
}
template <class T>
long MyStack<T>::getSize()
{
	return size;
}
template <class T>
void MyStack<T>::setSize(long val)
{
	size = val;
}
template <class T>
void MyStack<T>::allocateMemory()
{
	elements = new T[size];
	if (elements == NULL)
	{
		cout << "stack memory allocation error" << endl;
	}
}
template <class T>
ostream& operator<< (ostream& os, const MyStack<T> &s)
{
	cout << "Contents of Stack:";
	int t = s.top;
	while (t > -1)
		cout << s.elements[t--] << " ";
	cout << endl;
	return os;
}
#endif // _MY_STACK_TEMPLATE_H_