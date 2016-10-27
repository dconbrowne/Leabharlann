#include <string>
using namespace std;
class book {
public:
	book* next;
	book* prev;
	string isbn, name, author;
	book(string i, string n, string a) {
		isbn = i;
		name = n;
		author = a;
		next = NULL;
		prev = NULL;
	}

	book* getNext() const {
		return next;
	}

	book* getPrev() const {
		return prev;
	}

	void setNext(book* c) {
		next = c;
	}

	void setPrev(book* c) {
		prev = c;
	}

	string getName() {
		return name;
	}

	string getISBN() {
		return isbn;
	}

	string getAuthor() {
		return author;
	}
};