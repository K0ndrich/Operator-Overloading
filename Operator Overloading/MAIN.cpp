#include<iostream>

class Test
{

public:
	Test(int size)
	{
		std::cout << "Вызвался Конструктор для " << this << std::endl;
		this->SIZE = size;
		this->data = new int[size];
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = rand() % 10;
		}
	}

	//Конструктор копирования динамического массива (данные копируются в новый массивв)
	Test(const Test& other)
	{
		std::cout << "Вызвался Конструктор для " << this << std::endl;
		this->SIZE = other.SIZE;
		this->data = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = other.data[i];
		}
	}

	//Перегрузка оператора присваивания =
	Test& operator = (const Test& other)
	{
		std::cout << "Вызвался Оператор = для " << this << std::endl;
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
		std::cout << "Вызвался Деструктор для " << this << std::endl;
		delete[]data;
	}
private:
	int* data;
	int SIZE;


};


class Point
{

public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	//Перегрузка оператора равенства ==
	bool operator ==(const Point& other)
	{
		return this->x == other.x && this->y == other.y;
	}
	//Перегрузка оператора сложение +
	Point operator +(const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}
	//Перегрузка оператора префиксного инкремента ++a
	Point& operator ++() 
	{
		this->x++;
		this->y++;
		return *this;
	}
	//Перегрузка оператора постфиксного инкремента a++ (значение не вписываем) 
	Point& operator ++(int value)
	{
		Point temp(*this);
		this->x++;
		this->y++;
		return temp;
	}
	void Print()
	{
		std::cout << "x  --  " << x << " y  --  " << y << std::endl;
	}
	~Point()
	{

	}
private:
	int x;
	int y;
};

void main()

{
	setlocale(0, "RU");
	srand(time(NULL));

	Point a(4, 3);
	Point b=a++;

	b.Print();





}