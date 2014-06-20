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

			if (d == "NA")
			{
				checkedIn = true;
			}
			else
			{
				checkedIn = false;
				vector s = split(d, "/");
				s[0] = day;
				s[1] = month;
				s[3] = year;
			}


			child = false;
			switch (type)
			{
				case "AB":
					days = 14;
					break;
				case "CB":
					child = true;
					days = 7;
					break;
				case "DVD":
					days = 2;
					break;
				case "VHS":
					days = 3;
					break;
			}

		}


		vector<string> &split(const string &s, char delimiter, vector<string> &elements) 
		{
			stringstream ss(s);
			string item;
			while (getline(ss, item, delimiter)) 
			{
				elements.push_back(item);
			}
			return elements;
		}
		vector<string> split(const string &s, char delimiter) 
		{
			vector<string> elements;
			split(s, delimimter, elements);
			return elements;
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
