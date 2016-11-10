#pragma once
#include "book.h"
using namespace std;

void printBookDetails(book* first) {};
void printSTE(book* first) {};
void printETS(book* last) {};
void removeBook(book* toRemove) {};
void addBookInFront(book* toAdd, book* pos) {};
void addBookAtEnd(book* toAdd, book* pos) {};
book* searchBookByISBN(string ISBN, book* first) {};
