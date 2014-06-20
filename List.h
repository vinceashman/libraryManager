#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#pragma once

using namespace std;

class List
{

public:
	List(void);
	void ListAvailable(vector<Book*> books, int currentBook);
	void AllBooks(vector<Book*> books, int currentBook);
	void ListOverdue(vector<Book*> books, int currentBook, Date currentDate);
	void BooksCheckedOut(vector<Book*> books, string user);
};
List::List()
{}

void List::ListAvailable(vector<Book*> books, int currentBook)
{
	int startingBook = currentBook;
	string user, title;

	//Prints the next 10 books or the previous 10 books 
	//depending on the currentBook parameter passed.
	for(currentBook; currentBook < (startingBook + 10); currentBook++)
	{
		user = books[currentBook]->getUser();
		if(currentBook < books.size() && user == "library") //currentBook can never be bigger than the index of the last element in the vector
		{
			title = books[currentBook]->getTitle();
			cout << currentBook << ". " << title << endl;
		}
	}
}

void List::AllBooks(vector<Book*> books, int currentBook)
{
	int startingBook = currentBook;
	string title, user;

	for(currentBook; currentBook < (startingBook + 10); currentBook++)
	{
		if(currentBook < books.size())
		{
			user = books[currentBook]->getUser();
			title = books[currentBook]->getTitle();
			cout << currentBook << ". " << title << " ";

			if(user == "library")
				cout << "checked in." << endl;
			else
				cout << "check out." << endl;
		}
		
	}
}

void List::BooksCheckedOut(vector<Book*> books, string user)
{
	string currentName, title;

	for(int currentBook = 0; currentBook < books.size(); currentBook++)
	{
		currentName = books[currentBook]->getUser();
		if(currentName == user)
		{
			title = books[currentBook]->getTitle();
			cout << currentBook << ". " << title << endl;
		}
	}
}

void List::ListOverdue(vector<Book*> books, int currentBook, Date currentDate)
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
		user = books[currentBook]->getUser();

		if(user == "library"){}

		else
		{
			dueDate = books[currentBook]->CalcDueDate();
			dueDay = dueDate.getDay();
			dueMonth = dueDate.getMonth();
			dueYear = dueDate.getYear();

			if(todayYear > dueYear)
			{
				title = books[currentBook]->getTitle();
				cout << user << "currently has " << title << "." << "It was due on: "<<dueDay<<"/"<<dueMonth<<"/"<<dueYear<<"."<<endl;
			}

			else if(todayMonth > dueMonth)
			{
				title = books[currentBook]->getTitle();
				cout << user << "currently has " << title << "." << "It was due on: "<<dueDay<<"/"<<dueMonth<<"/"<<dueYear<<"."<<endl;
			}

			else if(todayDay > dueDay)
			{
				title = books[currentBook]->getTitle();
				cout << user << "currently has " << title << "." << "It was due on: "<<dueDay<<"/"<<dueMonth<<"/"<<dueYear<<"."<<endl;
			}
		}

	}
}
