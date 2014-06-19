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
		//We need a variable for when book was checked out
		Date checkedOut;
		int days;
		String user;
		

	public:
		//constructor
		Book(String ti, String ty, bool c, bool ch)
		{
			title = ti;
			type = ty;
			checkedIn = c;
			child = ch;

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

		//can't we calculate if the date is overdue outside of this class by using this function?
		Date CalcDueDate()
		{
			//for loop to advance the date

		}

		String getPerson()
		{
			return person;
		}
		
};
