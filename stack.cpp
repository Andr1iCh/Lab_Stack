#include "stack.h"

Stack::Stack() :m_size(0), m_capacity(10)
{
	m_data = new int[m_capacity];
}
//copy constrctr
Stack::Stack(const Stack& right) :m_size(right.m_size), m_capacity(right.m_capacity)
{
	m_data = new int[m_capacity];
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = right.m_data[i];
	}
}
Stack::~Stack()
{
	delete[]m_data;
}
//assignment op
Stack& Stack::operator=(const Stack& right)
{
	if (this == &right)
		return *this;
	delete[]m_data;

	m_size = right.m_size;
	m_capacity = right.m_capacity;
	m_data = new int[m_capacity];

	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = right.m_data[i];
	}
	return *this;
}
void Stack::push(int elem) {
	if (m_size >= m_capacity) {

		int newCapacity = m_capacity * 2;
		int* newData = new int[newCapacity];
		for (int i = 0; i < m_size; i++) {
			newData[i] = m_data[i];
		}
		delete[] m_data;
		m_data = newData;
		m_capacity = newCapacity;
	}
	m_data[m_size++] = elem;
}
int Stack::pop()
{
	if (isEmpty()) {
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}
	return m_data[--m_size];
}
bool Stack::isEmpty()
{
	return(m_size == 0);
}
void Stack::multiPop(int  N)
{
	std::cout << "Deleted: ";
	for (int i = 0; i < N; i++)
	{
		if (isEmpty()) {
			std::cerr << "Stack is empty" << std::endl;
			break;
		}
		std::cout << pop() << " ";
	}
	std::cout << std::endl;
}
void Stack::show()
{
	if (isEmpty()) {
		std::cerr << "Stack is empty" << std::endl;;
	}
	else {
		for (int i = 0; i < m_size; i++) {
			std::cout << m_data[i];
			if (i != m_size - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}