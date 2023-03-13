#pragma 
#include "Book.h"
#include "List.h"
#include <initializer_list>

class Library : public List {
public:
	
	friend std::ostream& operator<<(std::ostream& output, const Library& library);

	Library() : List() {};
	Library(std::initializer_list<Book> initList);
	Library(const Library& other_library);
	Library(Library&& other_library) noexcept;

	Library& operator=(const Library& right);
	Library& operator=(Library&& right) noexcept;

	Book& operator[](std::size_t index);
	const Book& operator[](std::size_t index) const;

	std::size_t GetSize() const;
	~Library();
};

