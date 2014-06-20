#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<sstring>

using namespace std;


class Book
{
	private:
		string title;
		string type;
		Date checkedOut;
		string user;

		bool checkedIn;
		bool child;
		int days;
		

	public:
		Book(string ti, string ty, string d, string u)
		{
			title = ti;
			type = ty;
			user = u;

			if (user == "library")
			{
				checkedIn = true;
			}
			else
			{
				checkedIn = false;
				day = atio(d.substr(0,2));
				month = atio(d.subtr(2,2));
				year = atio(d.subtr(4, 4));
			}


			child = false;

			if (type == "AB")
			{
				days = 14;
			}
			else if (type == "CB")
			{
					child = true;
					days = 7;
			}
			else if (type == "DVD")
			{
				days = 2;
			}
			else if (type == "VHS")
			{
				days = 3;
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
			
			return dueDate;
		}

		string getPerson()
		{
			return person;
		}
		
};
