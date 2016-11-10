#include <string>
#pragma once
using namespace std;
class user {
public:
	user(int id, string name) {};
	user() {};

	void setAsGuest() {};
	void setAsAdmin() {};
	void setAsRegisteredUser() {};

	int getID() {};
	void setID(int id) {};
	string getName() {};
	void setName(string name) {};

private:
	bool canManipulateBooks, canMarkAvailability, canManipulateUsers, canSearch, canCheckAvailability, canCheckoutBook, canReturnBook;
	int id;
	string name;
};