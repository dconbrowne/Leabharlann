#include <string>
#include "book.h"
using namespace std;

book::book(string i, string n, string a) {
	isbn = i;
	name = n;
	author = a;
	next = NULL;
	prev = NULL;
}

book* book::getNext() const {
	return next;
}

book* book::getPrev() const {
	return prev;
}

void book::setNext(book* c) {
	next = c;
}

void book::setPrev(book* c) {
	prev = c;
}

string book::getName() {
	return name;
}

string book::getISBN() {
	return isbn;
}

string book::getAuthor() {
	return author;
};