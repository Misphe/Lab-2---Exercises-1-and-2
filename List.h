#pragma once
#include "Book.h"

class Node {
public:
	Book book;
	Node* next;
	Node(Book set_book) : book(set_book), next(nullptr) {};
};

class List{
protected:
	Node* head;

public:
	List() : head(nullptr) {};

	friend std::ostream& operator<<(std::ostream& output, const List& list);
	void push_back(const Book& book);
	void push_back(Book&&);
	void remove(Book book);
	Book& GetBook(Book book);
	Book pop_back();
	void PrintList();
};

