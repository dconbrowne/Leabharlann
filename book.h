#pragma once
#include <string>
using namespace std;
class book {
private:
	book* next;
	book* prev;
	string isbn, name, author;
public:
	book(string i, string n, string a);

	book* getNext() const;

	book* getPrev() const;

	void setNext(book* c);

	void setPrev(book* c);

	string getName();

	string getISBN();

	string getAuthor();
};