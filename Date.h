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
			//Since most months have 31 days, you can make that the default to carry over to the first of the next month, but then put conditions when it's Febuary and the 29th, etc for other months that don't have 31 days.
			day++;
		}

};
