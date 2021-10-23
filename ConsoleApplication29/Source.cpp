#include "Header.h"
#include <iostream>

void init(Tlist& head)
{
	
	head = nullptr;
}
bool ListIsEmpty(Tlist head)
{
	return head == nullptr;
}
bool isEmpty(Tlist head)
{
	return head->next == nullptr;
}

Tlist findNumber(Tlist pNode, int num)
{
	Tlist p = pNode;
	while ((p->next != nullptr) && (p->data != num))
	{
		p = p->next;
	}
	return p;
}



void addToHead(Tlist& head, int elem)
{
	Tlist p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}
void addToTail(Tlist& head, int elem)
{
	Tlist p = head;
	if (ListIsEmpty(head))
	{
		addToHead(head, elem);
	}
	else
	{
		while (p->next != nullptr)
		{
			p = p->next;
		}
		AddAfterNode(p, elem);
	}
}

void AddAfterNode(Tlist pNode, int elem)
{
	if (pNode != nullptr)
	{
		Tlist p = new Node;
		p->data = elem;
		p->next = pNode->next;
		pNode->next = p;
	}
	else
	{

	}
}

void AddAfterNumber(Tlist& head, int num, int elem)
{
	Tlist p = findNumber(head, num);
	if (p->data == num)
		AddAfterNode(p, elem);
	else
		std::cout << "Не нашли заданное число в списке!" << '\n';
}

void deletefromHead(Tlist& head)
{
	if (ListIsEmpty(head))
	{
		std::cout << "Список пуст, милорд!" << '\n';
	}
	else
	{
		Tlist p = head;
		head = head->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
	}
}
void deletefromTail(Tlist& head)
{
	if (ListIsEmpty(head))
	{
		std::cout << "Список пуст, милорд!" << '\n';
	}
	else
	{
		Tlist  p = head;
		while (p->next->next != nullptr)
			p = p->next;
		deleteAfterNode(p);
	}
}
void deleteAfterNode(Tlist pNode)
{
	if (ListIsEmpty(pNode))
	{
		std::cout << "Список пуст, милорд!" << '\n';
	}
	else
	{
		Tlist p = pNode->next;
		if (p != nullptr)
		{
			pNode->next = p->next;
			p->next = nullptr;
			delete p;
			p = nullptr;
		}
	}
}
void deleteAfterNumber(Tlist pNode, int fnum)
{
	if (ListIsEmpty(pNode))
	{
		std::cout << "Список пуст, милорд!" << '\n';
	}
	else
	{
		Tlist p = findNumber(pNode, fnum);
		if (p->data != fnum)
			std::cout << "Не нашли заданное число в списке!" << '\n';
		else
			deleteAfterNode(p);
	}
}


void clear(Tlist& head)
{
	if (ListIsEmpty(head))
	{
		std::cout << "Список пуст, милорд!" << '\n';
	}
	else
	{
		while (!isEmpty(head))
			deleteAfterNode(head);
		delete head;
		head = nullptr;
	}
}

void printList(Tlist head)
{
	if (ListIsEmpty(head))
	{
		std::cout << "Список пуст, милорд!" << '\n';
	}
	else
	{
		Tlist p = head;
		while (p != nullptr)
		{
			std::cout << p->data << ' ';
			p = p->next;
		}
		std::cout << '\n';
	}
}
int sumList(Tlist head)
{
	Tlist p = head;
	int s = 0;
	while (p != nullptr)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}
void createFromHead(Tlist& head, int lenght) // Change
{
	init(head);
	std::cout << "Введите " << lenght << " чисел:";
	for (int i = 0; i < lenght; i++)
	{
		int ic;
		std::cin >> ic;
		addToHead(head, ic);
	}
}
void createFromTail(Tlist& head, int lenght)
{
	init(head);
	Tlist tail = head;
	std::cout << "Введите " << lenght << " чисел:";
	for (int i = 0; i < lenght; i++)
	{
		int ic;
		std::cin >> ic;
		if (isEmpty(head))
		{
			addToHead(head, ic);
			tail = head;
		}
		else
		{
			AddAfterNode(tail, ic);
			tail = tail->next;
		}
	}
}

Tlist findPlace(Tlist pNode, int elem)
{
	Tlist p = pNode;
	while ((p->next != nullptr) && (p->next->data << elem))
	{
		p = p->next;
	}
	return p;
}
void createByOrder(Tlist& head, int lenght)
{
	init(head);
	for (int i = 0; i < lenght; i++)
	{
		int elem = rand() % 10;
		if (isEmpty(head) || elem <= head->data)
		{
			addToHead(head, elem);
		}
		else
		{
			Tlist p = findPlace(head, elem);
			AddAfterNode(head, elem);
		}

	}
}

Tlist findBeforeFirstZero(Tlist head)
{
	Tlist p = head;
	while (p->next != nullptr && p->next->data != 0)
		p = p->next;
	return p;
}

void deleteTwoZeroes(Tlist& head)
{
	if (ListIsEmpty(head))
	{
		std::cout << "Пустой лист!" << '\n';
	}
	else
	{
		Tlist fBeforeZero = head;
		if (head->data == 0)
		{
			deletefromHead(head);
		}
		else
		{
			fBeforeZero = findBeforeFirstZero(head);
			deleteAfterNode(fBeforeZero);
		}
		if (fBeforeZero->next != nullptr)
		{
			if (head->data == 0)
			{
				deletefromHead(head);
			}
			else
			{
				Tlist sBeforeZero = findBeforeFirstZero(head);
				//Tlist fZero = fBeforeZero->next;
				if (isEmpty(sBeforeZero))
				{
					std::cout << "Второго нуля нет!" << '\n';
				}
				deleteAfterNode(sBeforeZero);
			}
		}
		else
		{
			std::cout << "Нулей нет!" << '\n';
		}
	}
}


void TwoPositiveNumbers(Tlist& head, int elem)
{
	if (ListIsEmpty(head))
	{
		std::cout << "Пустой лист!" << '\n';
	}
	else
	{
		bool condit = true;
		Tlist p = head;
		if (head->data > 0)
		{
			addToHead(head, elem);
		}
		else
		{
			while (p->next != nullptr && p->next->data <= 0)
			{
				p = p->next;
			}
			if (p->next == nullptr)
			{
				std::cout << "Нет положительных чисел!" << '\n';
				condit = false;
			}
			else
			{
				AddAfterNode(p, elem);
				p = p->next->next;
			}
		}
		if (p->next == nullptr)
		{
			if (condit)
			{
				std::cout << "Второго положительного числа нет!" << '\n';
			}
		}
		else
		{
			Tlist h = nullptr;
			while (p->next != nullptr)
			{
				if (p->next->data <= 0)
				{
					h = p->next;
				}
				p = p->next;
			}
			if (h == nullptr)
			{
				std::cout << "Второго положительного числа нет!" << '\n';
			}
			else
			{
				AddAfterNode(h->next, elem);
			}
		}
	}
}


//dz 


void DeleteFirstNegativeNumber(Tlist& head) // #1
{
	if (!isEmpty(head))
	{
		Tlist p = head;
		bool flag = false;
		if (p->data < 0)
		{
			flag = true;
			deletefromHead(head);
		}
		while (p->next != nullptr && !flag)
		{
			if (p->next->data < 0)
			{
				deleteAfterNode(p);
				flag = true;
			}
			else
				p = p->next;
		}
	}
}



void DoubleE(Tlist& head, int e) // #2
{
	if (!ListIsEmpty(head))
	{
		Tlist p = head;
		while (p != nullptr)
		{
			if (p->data == e)
			{
				AddAfterNode(p, e); // 1  2  3  4  5 -> 1  2  2  3  4  5
				p = p->next->next;  //    |             |->
			}
			else
			{
				p = p->next;
			}
		}
	}
}



void EqualNeighber(Tlist& head) // #3
{
	if (!isEmpty(head))
	{
		Tlist p = head;
		while (p->next !=nullptr && p->next->next != nullptr)
		{
			if (p->data == p->next->next->data)
			{
				deleteAfterNode(p);
				p = p->next; //1 2 1 1...
			}
			p = p->next;
		}
	}

}

Tlist mergeSortedListts(Tlist head1, Tlist head2)
{
	Tlist res = nullptr;
	if (head1 == nullptr) {
		res = head2;
	}
	else if (head2 == nullptr)
	{
		res = head1;
	}
	else {
		if (head1->data <= head2->data)
		{
			res = head1;
			head1 = head1->next;
		}
		else
		{
			res = head2;
			head2 = head2->next;
		}

		Tlist tail = res;
		while (head1 != nullptr && head2 != nullptr) {
			Tlist temp = nullptr;
			if (head1->data <= head2->data)
			{
				tail->next = head1;
				head1 = head1->next;
			}
			else {
				tail->next = head2;
				head2 = head2->next;
			}
			tail = tail->next;
		}

		tail->next = head1 ? head1 : head2;
	}
	return res;
}
// lox jopa
bool isNotLoop(Tlist head)
{
	Tlist slow = head, fast = head;
	while (fast && fast->next && slow != fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow == fast;
}
//bool isNotLoop(Tlist& head) // #4
//{
//	bool answer;
//	if (!isEmpty(head))
//	{
//		Tlist p = head;
//		bool flag = true;
//		while (p != nullptr && flag)
//		{
//			flag=CheckLoopIn(p);
//			p = p->next;
//		}
//		if (flag)
//			answer = true;
//		else
//			answer = false;
//		return answer;
//	}
//}
//
//bool CheckLoopIn(Tlist pNode)
//{
//	bool answer;
//	Tlist p = pNode->next;
//	while (p != pNode && p != nullptr)
//		p = p->next;
//	if (p == pNode)
//		answer = false;
//	else
//		answer = true;
//	return answer;
//}

//Определить количество различных элементов списка действительных чисел, если известно, что его элементы образуют возрастающую последовательность

struct NodeD {
	double data;
	NodeD* next;
};

typedef NodeD* Dlist;

int CountDifferentNumbers(Dlist head)
{
	Dlist p = head;
	int counter = 0;
	if (p != nullptr)
	{
		counter++;
		while (p != nullptr && p->next != nullptr) // 1 2 3 3 4 5 6 7 7 7
		{
			if (p->data != p->next->data)
				counter++;
			p = p->next;
		}
	}
	return counter;
}

Tlist ReverseList(Tlist head)
{
	Tlist p = head;
	Tlist newList = nullptr;
	if (!isEmpty(head))
	{
		while (p != nullptr)
		{
			addToHead(newList, p->data);
			p = p->next;
		}
	}
	return newList;
}
void revers(Tlist& head)
{
	Tlist previous = nullptr, current = head, next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;

	}
	head = previous;
}

bool isPalindrom(Tlist head)
{
	Tlist p = head;
	bool flag = true;
	if (!isEmpty(head))
	{
		Tlist p2 = head;
		int coun = 0;
		while (p2 != nullptr)
		{
			p2 = p2->next;
			coun++;
		}
		Tlist middle = head;
		for (int i = 0; i < coun/2; i++)
		{
			middle = middle->next;
		}
		while (p!=nullptr && p->next != nullptr && flag)
		{
			Tlist p1 = middle;
			while (p1->next->next != nullptr)
				p1 = p1->next;
			if (p1->next->data != p->data)
			{
				flag = false;
			}
			else
			{
				deletefromHead(p);
				deleteAfterNode(p1);
			}
		}
	}
}//лучше перевернуть, реве

