#pragma once
#include <iostream>
using std::string;

class Book
{
private:
	string author;
	string title;

public:
	Book();
	Book(string& set_author, string& set_title);
	Book(string&& set_author, string&& set_title);
	Book(const Book& other);
	Book(Book&& other) noexcept;

	Book& operator=(const Book& right) noexcept;
	Book& operator=(Book&& right) noexcept;

	friend bool operator==(Book left, Book right) noexcept;
	friend bool operator!=(Book left, Book right) noexcept;

	string GetAuthor() const;
	string GetTitle() const;

	void SetAuthor(string& new_author);
	void SetTitle(string& new_title);
	void SetAuthor(string&& new_author);
	void SetTitle(string&& new_title);
	~Book();

	friend std::ostream& operator<<(std::ostream& output, const Book& book);

};

