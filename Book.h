#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;


class Book
{
	private:
		String title;
		String type;
		bool checkedIn;
		bool child;
		Date checkedOut;
		int days;
		String user;
		

	public:
		Book(String ti, String ty, bool c, bool ch)
		{
			title = ti;
			type = ty;
			checkedIn = c;
			child = ch;
			checkedOut = NULL;
			days = 0;
			user = library;

			switch (type)
			{
				case "adult":
					days = 14;
					break;
				case "children":
					days = 7;
					break;
				case "dvd":
					days = 2;
					break;
				case "videotape":
					days = 3;
					break;
			}

		}

		//returns true if the book (or media) is avialable to check out
		bool IsAvailable()
		{
			return checkedIn;
		}

		//To calculate the due date, we need to create a copy of the time the book was checked out, then advance the date for how many days the book is allowed to be gone (The days variable)
		Date CalcDueDate()
		{
			Date dueDate;
			dueDate.day = checkedOut.day;
			dueDate.month = checkedOut.month;
			dueDate.year = checkedOut.year;

			for (int i = 0; i < days; i++)
			{
				dueDate.AdvanceDate();
			}

		}

		String getPerson()
		{
			return person;
		}
		
};
