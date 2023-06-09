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
		if (head->next != nullptr) {
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
		else {
			delete head;
			head = nullptr;
		}
		return;
	}
	Node* current = head;
	while (current->next != nullptr && current->next->book != book) {
		current = current->next;	
	}
	if (current->next != nullptr) {
		if (current->next->next != nullptr) {
			Node* tmp = current->next;
			current->next = current->next->next;
			delete tmp;
		}
		else {
			delete current->next;
			current->next = nullptr;
		}
		return;
	}
}

Book List::pop_back() {
	Node* current = head;
	if (head == nullptr) {
		Book book("error", "error");
		return book;
	}
	if (head->next == nullptr) {
		Book book = head->book;
		delete head;
		head = nullptr;
		return book;
	}
	while (current->next->next != nullptr) {
		current = current->next;
	}
	Book book = current->next->book;
	delete current->next;
	current->next = nullptr;
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