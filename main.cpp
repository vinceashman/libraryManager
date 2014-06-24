/*main cpp version .01*/


//going to include the class files but as of right now i dont know the names
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Book.h"
#include "Date.h"
#include "UserInterface.h"

//dont know if this is looked down on but this is how i like to do things.
using namespace std;





//not going to handle arguments at the cli at this time.
int main(){
	//declaration of variables
	//the vectors for the lists of books and users respectively
	vector<Book*> books;

	//vector<User*> users;

	//our file handler objects. the text files are going to be hard coded.
	ifstream bookFile;
	//youll want to inplement some error checking here.
	// userFile.open("userlist.txt");
	//bookFile.open("booklist.txt");
	try
	{
		bookFile.open("booklist.txt");
	}
	catch (int e)
	{
		cout << "Could not open book file.\n";
		return 0;
	}

	Date theDate;

	//instantiate ui object. most likely it would take 3 parameters. a pointer to the 2 vectors and a pointer to the date object.


	//read in the data from the booklist.txt file
	while(!bookFile.eof()){
        string aLine;
		getline(bookFile, aLine);
        if(!aLine.empty() )
        {

		istringstream iss(aLine);
		string title, type, dateCheckedOut, user;
		iss >> title;
		// cout << title << " is the Title " << endl;
		iss >> type;
		// cout << type << " is the Type " << endl;
		iss >> dateCheckedOut;
		// cout << dateCheckedOut << " is the date " << endl;
		iss >> user;
		// cout << user << " is the user " << endl;
		books.push_back(new Book(title, type, dateCheckedOut, user));
		// bookFile >> title;
		// cout << title << " is the Title " << endl;
		// bookFile >> type;
		// bookFile >> dateCheckedOut;
		// bookFile >> user;
        // books.push_back(new Book(title, type, dateCheckedOut, user));

        }

	}
	cout <<"books are done populating" <<endl;

	//read in userlist.txt



    UserInterface ui(books, theDate);
	//main process control loop
	do{
		//main program body here
		ui.DisplayLoginMenu();
		//ui.promptForInput();

	}while(!ui.exit());

	//write the user vector to the file

	//write the book vector to the file

	//print exit message and do any necessary cleanup
	cout << "\nThank you for using the library of Valhalla" << endl;
    system("pause");
	return 0;
}
