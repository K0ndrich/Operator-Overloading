#include<iostream>

class Test
{

private:
	int* data;
	int SIZE;

public:
	Test(int size)
	{
		std::cout << "�������� ����������� ��� " << this << std::endl;
		this->SIZE = size;
		this->data = new int[size];
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = rand() % 10;
		}
	}

	//����������� ����������� ������������� ������� (������ ���������� � ����� �������)
	Test(const Test& other)
	{
		std::cout << "�������� ����������� ��� " << this << std::endl;
		this->SIZE = other.SIZE;
		this->data = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = other.data[i];
		}
	}

	//���������� ��������� ������������ =
	void operator = (const Test& other)
	{
		std::cout << "�������� �������� = ��� " << this << std::endl;
		if (this->data != nullptr)
		{
			delete[] this->data;
		}

		this->SIZE = other.SIZE;
		data = new int[this->SIZE];
		for (int i = 0; i < this->SIZE; i++)
		{
			this->data[i] = other.data[i];
		}
	}

	~Test()
	{
		std::cout << "�������� ���������� ��� " << this << std::endl;
		delete[]data;
	}

};

void main()
{
	setlocale(0, "RU");
	srand(time(NULL));


	Test a(5);
	Test b(7);

	b = a;





}