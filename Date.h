#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;


class Date
{
	private:
		int day;
		int month;
		int year;


	public:
		Date()
		{
			day = 1;
			month = 1;
			year = 2014;
		}

		void AdvanceDate()
		{
			if (month+1 == 2)
			{
				if (day == 28)
				{
					day = 1;
					month++;
				}
			}
			if (month+1 == 4 || month+1 == 6 || month+1 == 9 || month+1 == 11)
			{
				if (day == 30)
				{
					day = 1;
					month++;
				}
			}
			else if (day == 31)
			{
				if (month == 12)
				{
					year++;
					month = 1;
					day = 1;
				}
				else 
				{
					day = 1;
					month++;
				}
			}
			else 
			{
				day++;
			}
		}

		void setDay(int d)
		{
			day = d;
		}
		void setMonth(int m)
		{
			month = m;
		}
		void setYear(int y)
		{
			year = y;
		}

};
