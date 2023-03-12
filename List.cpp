#include "List.h"

std::ostream& operator<<(std::ostream& output, const List& list) {
	Node* head = list.head;
	if (head == nullptr) {
		return output;
	}
	Node* current = head;
	do {
		output << current->book;
		current = current->next;
	} while (current != nullptr);
	return output;
}

void List::push_back(const Book& book) {
	Node* new_node = new Node(book);
	if (head == nullptr) {
		head = new_node;
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new_node;
	}
}

void List::push_back(Book&& book) {
	Node* new_node = new Node(book);
	if (head == nullptr) {
		head = new_node;
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new_node;
	}
}

void List::remove(Book book) {
	if (head == nullptr) {
		return;
	}
	if (head->book == book) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
		return;
	}
	Node* current = head;
	while (current->next != nullptr && current->next->book != book) {
		current = current->next;	
	}
	if (current->next != nullptr) {
		Node* tmp = current->next;
		current->next = current->next->next;
		delete tmp;
		return;
	}
}

Book List::pop_back() {
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	Book book = current->book;
	delete current;
	current = nullptr;
	return book;

}

Book& List::GetBook(Book book) {
	if (head == nullptr) {
		return book;
	}
	Node* current = head;
	while (current != nullptr) {
		if (current->book == book) {
			return current->book;
		}
	}
}

void List::PrintList() {
	if (this->head == nullptr) {
		return;
	}
	Node* current = this->head;
	do {
		std::cout << current->book;
		current = current->next;
	} while (current != nullptr);
}