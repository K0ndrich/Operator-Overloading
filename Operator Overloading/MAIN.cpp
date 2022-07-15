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
	Test& operator = (const Test& other)
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
		return *this;
	}

	~Test()
	{
		std::cout << "�������� ���������� ��� " << this << std::endl;
		delete[]data;
	}

};


class Point
{
private:
	int x;
	int y;
public:
	Point()
	{
		x = 0;
		y = 0;
		std::cout << " ����������� " << this << std::endl;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
		std::cout << " ����������� " << this << std::endl;
	}
	//���������� ��������� ��������� ==
	bool operator ==(const Point& other)
	{
		return this->x == other.x && this->y == other.y;
	}
	~Point()
	{
		std::cout << " ���������� " << this << std::endl;
	}

};
void main()
{
	setlocale(0, "RU");
	srand(time(NULL));

	Point a(3, 5);
	Point b(3, 5);

	bool result = a == b;

	std::cout << result << std::endl;






}