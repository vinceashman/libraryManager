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
		//Since it doesn't specify, I think we can just start the date whenever we'd like. Easiest was just 1/1/14. Also, do you think we need to handle changing the year? 
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

};
