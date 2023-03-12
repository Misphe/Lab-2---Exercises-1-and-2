#include "Book.h"

Book::Book() : author(""), title("") {}

Book::Book(string& set_author, string& set_title) : author(set_author), title(set_title) {}

Book::Book(string&& set_author, string&& set_title) : author(set_author), title(set_title) {}

Book::Book(const Book& other) {
	this->author = other.author;
	this->title = other.title;
}

Book::Book(Book&& other) noexcept{
	this->author = other.author;
	this->title = other.title;
	other.author = "";
	other.title = "";
}

Book& Book::operator=(const Book& right) noexcept {
	this->author = right.author;
	this->title = right.title;
	return *this;
}

Book& Book::operator=(Book&& right) noexcept {
	this->author = right.author;
	this->title = right.title;
	right.author = "";
	right.title = "";
	return *this;
}

string Book::GetAuthor() const{
	return this->author;
}

string Book::GetTitle() const{
	return this->title;
}

void Book::SetAuthor(string& new_author) {
	this->author = new_author;
}

void Book::SetTitle(string& new_title) {
	this->title = new_title;
}

void Book::SetAuthor(string&& new_author) {
	this->author = new_author;
}

void Book::SetTitle(string&& new_title) {
	this->title = new_title;
}

std::ostream& operator<<(std::ostream& output, const Book& book) {
	output << "Book(" << book.GetAuthor() << ", \"" << book.GetTitle() << "\")\n";
	return output;
}

bool operator==(Book left, Book right) noexcept{
	if (left.author == right.author && left.title == right.title) {
		return true;
	}
	return false;
}

bool operator!=(Book left, Book right) noexcept{
	if (left.author != right.author || left.title != right.title) {
		return true;
	}
	return false;
}

Book::~Book() {
	author = "";
	title = "";
}

