#include "user.h"
#include <string>
#include <iostream>
using namespace std;
user::user(int i, string n) {
	id = i;
	name = n;

	setAsGuest();
}

void user::setAsGuest() {
	canCheckoutBook = false;
	canManipulateUsers = false;
	canManipulateBooks = false;
	canReturnBook = false;
	canMarkAvailability = false;
	canCheckoutBook = false;
	canSearch = true;
	canCheckAvailability = true;
}

void user::setAsAdmin() {
	canCheckoutBook = true;
	canManipulateUsers = true;
	canManipulateBooks = true;
	canReturnBook = false;
	canMarkAvailability = true;
	canCheckoutBook = false;
	canSearch = true;
	canCheckAvailability = true;
}

void user::setAsRegisteredUser() {
	canCheckoutBook = true;
	canManipulateUsers = false;
	canManipulateBooks = false;
	canReturnBook = true;
	canMarkAvailability = false;
	canCheckoutBook = true;
	canSearch = true;
	canCheckAvailability = true;
}

int user::getID() {
	return id;
}

string user::getName() {
	return name;
}