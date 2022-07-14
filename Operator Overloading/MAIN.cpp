#include<iostream>

class Test
{

private:
	int* data;
	int SIZE;

public:
	Test(int size)
	{
		this->SIZE = size;
		this->data = new int[size];
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = rand() % 10;
		}
	}
	// онструктор копировани€ динамического массива (данные перенос€тс€ в новый массивв)
	Test(const Test& other)
	{
		this->SIZE = other.SIZE;
		this->data = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = other.data[i];
		}
	}
	~Test()
	{
		delete[]data;
	}

};

void main()
{
	setlocale(0, "RU");
	srand(time(NULL));


	MyClass a(10);
	Myclass b(a);
}