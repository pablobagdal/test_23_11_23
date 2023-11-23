// #include <conio.h>
#include <math.h>
#include <stdio.h>
// #include <crtdbg.h>
#include <iostream>

class CVector {
public:
	virtual double lenght() = 0;
};

class CVector1 : public CVector {
	double x1;
public:
	CVector1(double);
	double lenght() override;
};

CVector1::CVector1(double coor) : x1{coor}  {
}

double CVector1::lenght() {
	return fabs(this->x1);
}

class CVector2 : public CVector {
	double x1;
	double x2;
public:
	CVector2(double, double);
	double lenght() override;
};

CVector2::CVector2(double coor1, double coor2) : x1{ coor1 }, x2 { coor2 } {

}

double CVector2::lenght() {
	return sqrt(this->x1 * this->x1 + this->x2 * this->x2);
}

class CVectList {
	struct Node {
		CVector* data;
		Node* next;
	};
	Node* head;
public:
	CVectList();
	void Add(CVector*);
	void PrintLengths();
	~CVectList();
};
CVectList::CVectList() : head{ nullptr } {
}
void CVectList::Add(CVector* ptrVector) {
	if (this->head == nullptr) {
		this->head = new Node;
		this->head->data = ptrVector;
		this->head->next = nullptr;
        return;
	}

	Node* ptr = this->head;

	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}

	ptr->next = new Node;
	ptr->next->data = ptrVector;
	ptr->next->next = nullptr;
}
void CVectList::PrintLengths() {
	Node* ptr{ this->head };

	while (ptr != nullptr) {
		std::cout << ptr->data->lenght() << std::endl;

		ptr = ptr->next;
	}
}
CVectList::~CVectList() {
	while (this->head != nullptr) {
		Node* ptr{ this->head };
		Node* prevPtr{ nullptr };

		while (ptr->next != nullptr) {
			prevPtr = ptr;
			ptr = ptr->next;
		}
		delete ptr;
        
        if(ptr == this->head) { // проблема была здесь, голова не становилась nullptr
            this->head = nullptr;
        } else {
            prevPtr->next = nullptr;
        }
        
	}
}

/*===========================================================================================

ЗАДАНИЕ:
========

0.	Внимательно прочитайте задание, перед тем как приступить к его выполнению. Необходимо
	написать программу на C++. 
	Все классы можно описывать прямо в этом файле EMETest.cpp.

1.	Создать класс для одномерного геометрического вектора (с одной пространственной 
	координатой x1).
2.	Создать класс для двумерного геометрического вектора (с двумя пространственными
	координатами x1, x2).

	В этих классах должен быть метод вычисления длины вектора.
	Для одномерного вектора длина вычисляется как fabs(x1),
	 для двумерного - как sqrt(x1*x1 + x2*x2).
	Другие методы описывать не требуется.

3.	Создать класс для связного списка, элементами которого являются векторы из п.1 и п.2
	(т.е. в одном списке хранятся векторы разных размерностей - одномерные и двумерные).

	Достаточно, если список будет однонаправленным (т.е. необязательно делать его
	двунаправленным). В самом списке можно хранить указатели, а не сами векторы.

	В этом классе должен быть метод добавления в список векторов различной размерности.
	Использование стандартных шаблонов (std::list, CList и т.п.) не разрешается.

4.	Написать функцию (можно прямо в классе списка), которая пробегает по списку и распечатывает
	длину каждого вектора с помощью printf (или cout).

5.	Примерный вариант тестирования классов уже реализован в функции main().
	(Не обязательно вводить координаты векторов с клавиатуры, просто
	проинициализируйте их в программе произвольными значениями).

ВНИМАНИЕ!
 При выполнении задания важно продемонстрировать аккуратность, архитектурное
 мышление, умение применять принципы объектно-ориентированного программирования.
 При проектировании классов использовать шаблоны C++ не обязательно.

 Под  а р х и т е к т у р н ы м   м ы ш л е н и е м  понимается способность спроектировать
 систему классов таким образом, чтобы необходимость хранения в списке, например,
 3-мерных векторов не потребовала бы внесения изменений в имеющиеся классы.

 Вся выделенная память должна освобождаться

	Желательно выполнить задание в течение двух часов.


Инструкции по компиляции и отладке:
===========================================================================================

	Для компиляции нажмите F7
	Для того, чтобы перейти к месту программы, при компиляции которого была обнаружена ошибка, нажмите F4
	Для запуска программы под отладчиком нажмите F5 или F10
	
===========================================================================================*/

int main(void)
{
	CVector1 a1(3.0);
	CVector2 a2(3.0, 4.0);
	CVector2 a3(-5.0, -12.0);
	CVector1 a4(-15.0);
	CVector2 a5(80.0, -60.0);
	CVectList list;
	list.Add(&a1);
	list.Add(&a2);
	list.Add(&a3);
	list.Add(&a4);
	list.Add(&a5);

	list.PrintLengths();

	// _getch();  
    system("pause");
	return 0;
};
