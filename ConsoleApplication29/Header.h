#pragma once
#ifndef Header
#define Header

struct Node {
	int data;
	Node* next;
};

struct DoubleNode {
	int data;
	DoubleNode* next;
	DoubleNode* prev;
};

typedef Node* Tlist;
typedef DoubleNode* Dlist;

void init(Tlist& head);
bool isEmpty(Tlist head);
bool ListIsEmpty(Tlist head);
//void print(Tlist& head);

void addToHead(Tlist& head, int elem);
void addToTail(Tlist& head, int elem);

void AddAfterNode(Tlist pNode, int elem);
void AddAfterNumber(Tlist& head, int num, int elem);

void deletefromHead(Tlist& head);
void deletefromTail(Tlist& head);
void deleteAfterNode(Tlist pNode);
void deleteAfterNumber(Tlist pNode, int fnum);

void clear(Tlist& head);
void printList(Tlist head);
int sumList(Tlist head);

void createFromHead(Tlist& head, int lenght = 5); // Change
void createFromTail(Tlist& head, int lenght);

Tlist findPlace(Tlist pNode, int elem);
void createByOrder(Tlist& head, int lenght = 5);

void deleteTwoZeroes(Tlist& head);
void TwoPositiveNumbers(Tlist& head, int elem);

void DeleteFirstNegativeNumber(Tlist& head);
void DoubleE(Tlist& head, int e);
void EqualNeighber(Tlist& head);


//bool CheckLoopIn(Tlist pNode);
//bool isNotLoop(Tlist& head);
#endif