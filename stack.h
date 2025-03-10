#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
	int* m_data;
	int m_size;
	int m_capacity;

public:

	Stack();
	Stack(const Stack& right);
	~Stack();

	Stack& operator=(const Stack& right);
	
	void push(int elem);
	int pop();
	bool isEmpty();
	void multiPop(int  N);
	void show();

};
#endif 
