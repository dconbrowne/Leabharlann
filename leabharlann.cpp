#include <string>
#include <iostream>
#include <assert.h>
#include "book.cpp"
#include <iostream>
#include <vector>
using namespace std;

//we need to be able to search for the book.

void printbookDetails(book* first) {
	//while (first->next != NULL)
	{
		printf("ISBN : %s \nName : %s \nAuthor : %s\n\n", first->getISBN().c_str(), first->getName().c_str(), first->getAuthor().c_str());
		//cout << "DEBUG : " << first << "\n\n\n";
	}
}

void printSTE(book* first) {
	while (first != NULL)
	{
		printbookDetails(first);
		first = first->next;
	}
}

void printETS(book* last) {
	while (last != NULL)
	{
		printbookDetails(last);
		last = last->prev;
	}
}

void removeBook(book* toRemove) {
	assert(toRemove != NULL);
	if (toRemove->getPrev() != NULL)
	{
		toRemove->getPrev()->setNext(toRemove->getNext());
	}
	/*else
	{
	toRemove->getNext()->setPrev(NULL);
	}*/
	if (toRemove->getNext() != NULL)
	{
		toRemove->getNext()->setPrev(toRemove->getPrev());
	}
	/*else
	{
	toRemove->getPrev()->setNext(NULL);
	}*/
	//delete(toRemove);
}

void addBookInFront(book* toAdd, book* pos) {
	assert(pos != NULL);
	toAdd->setNext(pos);
	toAdd->setPrev(pos->getPrev());
	pos->setPrev(toAdd);
	if (toAdd->getPrev() != NULL)
	{
		toAdd->getPrev()->setNext(toAdd);
	}
}

book* searchBookByISBN(string ISBN, book* first) {
	while (first != NULL)
	{
		string compared = first->getISBN();
		if (ISBN.compare(compared))
		{
			return first->prev;
		}
		else
		{
			first = first->next;
		}
	}
	return NULL;
}

void main() {
	//Set up our library.
	
	//5 will be grand for now
	book* hamlet = new book("9781932606409", "Hamlet", "William Shakespear");
	book* one984 = new book("9781933306409", "1984", "George R Orwell");
	hamlet->setNext(one984);
	one984->setPrev(hamlet);
	printSTE(hamlet);
	book* toPrint = searchBookByISBN("9781933306409", hamlet);
	printbookDetails(toPrint);
	/*
	while (true)
	{
		cout << "What Would you like to do? \n1 - Add\n2 - Remove\n3 - Print List of books\n4 - Search for book\n\n";
		int c1;
		cin >> c1;
		//Add
		if (c1 == 1) {

		}
		//Remove
		if (c1 == 2) {

		}
		//Print list of books
		if (c1 == 3) {

		}
		//Search for books
		if (c1 == 4) {

		}
		//break;
	}*/

	//printbookDetails(searchBookByISBN("9780141182957", one984));
};