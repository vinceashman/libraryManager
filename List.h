#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#pragma once

using namespace std;

class List
{

public:
<<<<<<< HEAD
	List(void){}


//List::List()
//{

//}
void ListAvailable(vector<Book*> books, int currentBook)
=======
	List(void);
	void ListAvailable(vector<Book*> books, int currentBook);
	void AllBooks(vector<Book*> books, int currentBook);
	void ListOverdue(vector<Book*> books, int currentBook, Date currentDate);
	void BooksCheckedOut(vector<Book*> books, string user);
};

List::List()
{}
void List::ListAvailable(vector<Book*> books, int currentBook)
>>>>>>> 556865955223271303bcd203c15f59785cb0ba6b
{
	int startingBook = currentBook;
	string user, title;

	//Prints the next 10 books or the previous 10 books
	//depending on the currentBook parameter passed.
	for(currentBook; currentBook < (startingBook + 10); currentBook++)
	{
<<<<<<< HEAD
	    if(currentBook < books.size())
        {


		user = books[currentBook]->getUser();
=======
		user = books[currentBook][0]->getUser();
>>>>>>> 556865955223271303bcd203c15f59785cb0ba6b
		if(currentBook < books.size() && user == "library") //currentBook can never be bigger than the index of the last element in the vector
		{
			title = books[currentBook][0]->getTitle();
			cout << currentBook << ". " << title << endl;
		}
        }
	}

}

void AllBooks(vector<Book*> books, int currentBook)
{
	int startingBook = currentBook;
	string title, user;

	for(currentBook; currentBook < (startingBook + 10); currentBook++)
	{
		if(currentBook < books.size())
		{
			user = books[currentBook][0]->getUser();
			title = books[currentBook][0]->getTitle();
			cout << currentBook << ". " << title << " ";

			if(user == "library")
				cout << "checked in." << endl;
			else
				cout << "check out." << endl;
		}

	}
}

void BooksCheckedOut(vector<Book*> books, string user)
{
	string currentName, title;

	for(int currentBook = 0; currentBook < books.size(); currentBook++)
	{
		currentName = books[currentBook][0]->getUser();
		if(currentName == user)
		{
			title = books[currentBook][0]->getTitle();
			cout << currentBook << ". " << title << endl;
		}
	}
}

void ListOverdue(vector<Book*> books, int currentBook, Date currentDate)
{
	int startingBook = currentBook;
	string user, title;
	Date dueDate;
	int dueDay, dueMonth, dueYear, todayDay, todayMonth, todayYear;

	todayDay = currentDate.getDay();
	todayMonth = currentDate.getMonth();
	todayYear = currentDate.getYear();
	
	for(currentBook; currentBook < (startingBook + 10); currentBook++)
	{
<<<<<<< HEAD
	    if(currentBook < books.size())
        {


		user = books[currentBook]->getUser();

		if(user == "library"){}

		else
		{
			dueDate = books[currentBook]->CalcDueDate();
			dueDay = dueDate.getDay();
			dueMonth = dueDate.getMonth();
			dueYear = dueDate.getYear();

			if(todayYear > dueYear )
			{
				title = books[currentBook]->getTitle();
				cout << user << " currently has " << title << "." << "It was due on: "<<dueDay<<"/"<<dueMonth<<"/"<<dueYear<<"."<<endl;
			}

			else if(todayMonth > dueMonth)
=======
		if(currentBook < books.size())
		{
			user = books[currentBook][0]->getUser();

			if(user == "library"){}

			else
>>>>>>> master
			{
				dueDate = books[currentBook][0]->CalcDueDate();
				dueDay = dueDate.getDay();
				dueMonth = dueDate.getMonth();
				dueYear = dueDate.getYear();

				if(todayYear > dueYear)
				{
					title = books[currentBook][0]->getTitle();
					cout << user << " currently has " << title << "." << "It was due on: "<<dueDay<<"/"<<dueMonth<<"/"<<dueYear<<"."<<endl;
				}

				else if(todayYear == dueYear && todayMonth > dueMonth)
				{
					title = books[currentBook][0]->getTitle();
					cout << user << " currently has " << title << "." << "It was due on: "<<dueDay<<"/"<<dueMonth<<"/"<<dueYear<<"."<<endl;
				}

				else if(todayYear == dueYear && todayMonth == dueMonth && todayDay > dueDay)
				{
					title = books[currentBook][0]->getTitle();
					cout << user << " currently has " << title << "." << "It was due on: "<<dueDay<<"/"<<dueMonth<<"/"<<dueYear<<"."<<endl;
				}
			}
<<<<<<< HEAD

<<<<<<< HEAD
			else if(todayDay > dueDay)
			{
				title = books[currentBook]->getTitle();
				cout << user << " currently has " << title << "." << "It was due on: "<<dueDay<<"/"<<dueMonth<<"/"<<dueYear<<"."<<endl;
			}

		}

        }
=======
=======
>>>>>>> 556865955223271303bcd203c15f59785cb0ba6b
		}
>>>>>>> master
	}
}

};
