#include "Library.h"

std::ostream& operator<<(std::ostream& output, const Library& library) {
	Node* head = library.head;
	if (head == nullptr) {
		return output;
	}
	Node* current = head;
	while (current != nullptr) {
		output << current->book;
		current = current->next;
	}
	return output;
}


Library::Library(std::initializer_list<Book> initList) {
	Node* current = head;
	for (Book book : initList) {
		if (head == nullptr) {
			head = new Node(book);
			current = head;
		}
		else {
			current->next = new Node(book);
			current = current->next;
		}
	}
}

Library::Library(const Library& other_library) {
	Node* other = other_library.head;
	Node* current = head;
	while (other != nullptr) {
		if (head == nullptr) {
			head = new Node(other->book);
			current = head;
			other = other->next;
		}
		else {
			current->next = new Node(other->book);
			current = current->next;
			other = other->next;
		}
	}
}

Library::Library(Library&& other_library) noexcept{
	Node* other = other_library.head;
	Node* current = head;
	while (other != nullptr) {
		if (head == nullptr) {
			head = new Node(other->book);
			current = head;
			Node* tmp = other;
			other = other->next;
			delete tmp;
		}
		else {
			current->next = new Node(other->book);
			current = current->next;
			Node* tmp = other;
			other = other->next;
			delete tmp;
		}
	}
	other_library.head = nullptr;
}

Library& Library::operator=(const Library& right) {
	Node* other = right.head;
	Node* current = head;
	while (head != nullptr) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
	head = nullptr;
	current = head;
	while (other != nullptr) {
		Node* tmp = new Node(other->book);
		if (current == nullptr) {
			head = tmp;
		}
		else {
			current->next = tmp;
		}
		current = tmp;
		other = other->next;

	}
	return *this;
}

Library& Library::operator=(Library&& right) noexcept {
	Node* other = right.head;
	Node* current = head;
	while (head != nullptr) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
	head = nullptr;
	current = head;
	while (other != nullptr) {
		Node* tmp = new Node(other->book);
		if (current == nullptr) {
			head = tmp;
		}
		else {
			current->next = tmp;
		}
		current = tmp;
		tmp = other;
		other = other->next;
		delete tmp;

	}
	right.head = nullptr;
	return *this;
}

Book& Library::operator[](std::size_t index) {
	int i = 0;
	Node* current = head;
	while (i != index) {
		if (current != nullptr && current->next != nullptr) {
			current = current->next;
		}
		else {
			Book book("", "");
			return book;
		}
		i++;
	}
	return current->book;
}

const Book& Library::operator[](std::size_t index) const {
	int i = 0;
	Node* current = head;
	while (i != index) {
		if (current != nullptr && current->next != nullptr) {
			current = current->next;
		}
		else {
			Book book("", "");
			return book;
		}
		i++;
	}
	return current->book;
}

std::size_t Library::GetSize() const {
	int i = 0;
	Node* current = head;
	while (current != nullptr) {
		current = current->next;
		i++;
	}
	return i;
}

Library::~Library() {
	Node* current = head;
	while (current != nullptr) {
		current = head->next;
		delete head;
		head = current;
	}
}