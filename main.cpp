#include "Book.h"
#include "Library.h"
using namespace std;

#define ZAD1 false
#define ListTest false
#define ZAD2test false

int main() {

	if (ZAD1) {
		string a = "Boleslaw Prus", t = "Lalka";
		Book e;
		cout << "e: " << e << endl;
		Book b1 = { a, t };
		cout << "b1: " << b1 << endl;
		Book b2 = { "Ernest Hemingway","Stary czlowiek i morze" };
		cout << "b2: " << b2 << endl;
		Book b3 = b1;
		cout << "b3: " << b3 << "b1: " << b1 << endl;
		e = std::move(b2);
		cout << "e: " << e << "b2:" << b2 << endl;
		e.SetAuthor("Henryk Sienkiewicz");
		cout << "e: " << e << endl;
		e.SetTitle("Latarnik");
		cout << "e: " << e << endl << endl << endl;
	}

	if (ListTest) {
		List list;
		list.push_back(Book("hihi", "haha"));
		list.push_back(Book("hihi2", "haha2"));
		list.PrintList();
		list.remove(Book("hihi", "haha"));
		list.PrintList();
		Book book1("hihi3", "haha3");
		list.GetBook(Book("hihi2", "haha2")) = book1;
		list.PrintList();
	}

	if (ZAD2test) {
		Library books = { {"1","1"}, {"2","2"} };
		books.push_back(Book("test", "test"));
		books.PrintList();
		Library books2(books);
		books2.push_back(Book("Ja", "udalo sie"));
		books2.PrintList();
		books = books2;
		books.PrintList();
		Library books3;
		books3 = std::move(books2);
		cout << "\n\n";
		cout << books3;
		cout << books2;
		cout << endl;
		cout << books[2];
		cout << books.GetSize() << endl;
		cout << books2.GetSize() << endl;
	}
	Library e;
	cout << "e: " << e << endl;
	//3-5 ksi¹¿ek
	Library l1 = { {"Boleslaw Prus", "Lalka"},
	{"Boleslaw Prus", "Dama"},
	{"Boleslaw Prus", "Katarynka"} };
	cout << "l1: " << l1 << endl;
	Library l2;
	cout << "l2: " << l2 << endl;
	l2.push_back({ "Henryk Sienkiewicz", "Ogniem i mieczem" });
	l2.push_back({ "Henryk Sienkiewicz", "Latarnik" });
	cout << "l2: " << l2 << endl;
	e = std::move(l2);
	cout << "e: " << e << " l2: " << l2 << endl;
	l1[0] = std::move(e[1]);
	cout << "l1: " << l1 << endl;
	cout << " e: " << e << endl;

}