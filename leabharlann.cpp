#include <string>
#include <iostream>
#include <assert.h>
#include "book.h"
#include <iostream>
#include <algorithm>
using namespace std;

book* getLastBook(book* first) {
	while (first != NULL)
	{
		first = first->getNext();
	}
	return first;
}

void printbookDetails(book* first) {
	printf("ISBN : %s \nName : %s \nAuthor : %s\n\n", first->getISBN().c_str(), 
		first->getName().c_str(), first->getAuthor().c_str());
}

void printSTE(book* first) {
	while (first != NULL)
	{
		printbookDetails(first);
		first = first->getNext();
	}
}

void printETS(book* last) {
	while (last != NULL)
	{
		printbookDetails(last);
		last = last->getPrev();
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

void addBookAtEnd(book* toAdd) {
	//we set our new books previous and next books
	//toAdd->setPrev(lastBook);
	//toAdd->setNext(NULL);
	//now we need to set the book that was originally last new previous and next books
	//previous doesn't change
	//lastBook->setNext(toAdd);
}

//Need to make partial search.
void printPartialSearch(string searched, book* first) {
	bool bookFound = false;
	book* theFirstOne = first;
	//ISBN search
	while (first != NULL)
	{
		string compared = first->getISBN();
		if (searched.compare(0, searched.length(), compared, 0, searched.length()) == 0)
		{
			bookFound = true;
			printbookDetails(first);
			first = first->getNext();
		}
		else
		{
			first = first->getNext();
		}
	}
	if (bookFound == false) {
		cout << "No results from ISBN search..." << endl << endl;
	}

	//Name Search
	first = theFirstOne;
	//bookFound = false;
	while (first != NULL)
	{
		string compared = first->getName();
		std::transform(compared.begin(), compared.end(), compared.begin(), ::tolower);
		if (searched.compare(0, searched.length(), compared, 0, searched.length()) == 0)
		{
			bookFound = true;
			printbookDetails(first);
			first = first->getNext();
		}
		else
		{
			first = first->getNext();
		}
	}
	if (bookFound == false) {
		cout << "No results from book name search..." << endl << endl;
	}

	//Name Search
	first = theFirstOne;
	//bookFound = false;
	while (first != NULL)
	{
		string compared = first->getAuthor();
		std::transform(compared.begin(), compared.end(), compared.begin(), ::tolower);
		if (searched.compare(0, searched.length(), compared, 0, searched.length()) == 0)
		{
			bookFound = true;
			printbookDetails(first);
			first = first->getNext();
		}
		else
		{
			first = first->getNext();
		}
	}
	if (bookFound == false) {
		cout << "No results from author search..." << endl << endl;
	}
}

book* searchBookByISBN(string ISBN, book* first) {
	while (first != NULL)
	{
		string compared = first->getISBN();
		if (ISBN.compare(compared) == 0)
		{
			return first;
		}
		else
		{
			first = first->getNext();
		}
	}
	return NULL;
}

void main() {
	//Set up our library.

	//So, my questions are
	//1 - How do we add the books and in what position?
	//2 - Are we to have a first book that never changes?
	//3 - What's the structure behind this list, to make it as functional as possible?

	//5 will be grand for now
	book* firstBook;//////////////////////// check functionality
	book * lastBook;////////////////////////
	book* hamlet = new book("9781932606409", "Hamlet", "William Shakespeare");
	book* one984 = new book("9780141182957", "1984", "George R Orwell");
	hamlet->setNext(one984);
	one984->setPrev(hamlet);
	firstBook = hamlet;
	lastBook = one984;
	printPartialSearch("978", hamlet);
	while (true)
	{
		//Please select a user account.


		cout << "What Would you like to do? \n1 - Add\n2 - Remove\n3 - Print List of books\n4 - Search for book\n5 - Exit\n\n";
		int c1;
		cin >> c1;
		//Add
		if (c1 == 1) {
			string bookISBN = "";
			string bookName = "";
			string bookAuthor = "";
			cout << "Please enter the ISBN of the book." << endl;
			cin >> bookISBN;
			cout << "Please enter the name of the book." << endl;
			cin.ignore();
			getline(cin, bookName);
			cout << "Please enter the author of the book." << endl;
			getline(cin, bookAuthor);

			book* newBook = new book(bookISBN, bookName, bookAuthor);
			addBookInFront(newBook, lastBook);
			cout << "Would you like to view the new booklist?\n N=0, Y=1" << endl;
			while (true) {
				cin >> c1;
				if (c1 == 1) {
					printSTE(firstBook);
					break;
				}
				if (c1 == 0) {
					break;
				}
			}

		}
		//Remove
		if (c1 == 2) {
			cout << "Please enter the ISBN of the book you wish to delete." << endl;
			string removeByISBN = "";
			cin >> removeByISBN;
			book* toRemove = searchBookByISBN(removeByISBN, firstBook);
			if (toRemove != NULL) {
				cout << "The book " << toRemove->getName() << " removed." << endl;
				removeBook(toRemove);
			}
			else {
				cout << "No such book found." << endl;
			}
			
		}
		//Print list of books
		if (c1 == 3) {
			cout << "1 - Start to End\n2 - End to Start\n" << endl;
			cin >> c1;
			if (c1 == 1) {
				printSTE(hamlet);
			}
			if (c1 == 2) {
				printETS(one984);
			}
		}
		//Search for books
		if (c1 == 4) {
			string searchTerms = "";
			cout << "Enter search terms: " << endl;
			cin.ignore();
			getline(cin,searchTerms);
			printPartialSearch(searchTerms, hamlet);
		}
		//Exit
		if (c1 == 5) {
			break;
		}
		//break;
	}
};