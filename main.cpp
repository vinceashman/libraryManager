/*main cpp version .01*/


//going to include the class files but as of right now i dont know the names
#include <string>
#include <fstream>
#include <iostream>
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
	cout <<"before book vector creation"<<endl;
	vector<Book*> books;
	cout <<"after book vector creation"<<endl;
	//vector of users;
	vector<vector<string>> users;
	//our file handler objects. the text files are going to be hard coded.
	ifstream bookFile;
	//youll want to inplement some error checking here.
	// userFile.open("userlist.txt");
	//bookFile.open("booklist.txt");
    cout <<"before book opening"<<endl;
	try
	{
		bookFile.open("booklist.txt");
	}
	catch (int e)
	{
		cout << "Could not open book file.\n";
		return 0;
	}
    cout <<"theDate creation"<<endl;
	Date theDate;

	//instantiate ui object. most likely it would take 3 parameters. a pointer to the 2 vectors and a pointer to the date object.


	//read in the data from the booklist.txt file
	cout<<"populating books"<<endl;
	while(!bookFile.eof()){
        cout<<"in while loop!"<<endl;
        string aLine;
        getline(bookFile, aLine);
        if(!aLine.empty() )
        {
        string title, type, dateCheckedOut, user;
		bookFile >> title;
		bookFile >> type;
		bookFile >> dateCheckedOut;
		bookFile >> user;
		books.push_back(new Book(title, type, dateCheckedOut, user));
        }

	}
	cout <<"books are done populating" <<endl;

	//read in userlist.txt
	cout << "Populating userlist" << endl;
	while(!userFile.eof()){
		string aLine;
		getline(userFile, aLine);
		if(!aLine.empty()){
			string name, type;
			userFile >> name;
			userFile >> type;
			//storing the temp vector so we can push the whole thing onto the main users vector.
			vector<string> tempVect;
			tempVect.push_back(name);
			tempVect.push_back(type);
			users.push_back(tempVect);
		}//end if
	}//end while



    UserInterface ui(books, theDate);
	//main process control loop
	do{
		//main program body here
		ui.DisplayLoginMenu();
	}while(!ui.exit());

	//write the user vector to the file
	
	//write the book vector to the file

	//print exit message and do any necessary cleanup
	cout << "\nThank you for using the library of Valhalla" << endl;

	return 0;
}
