/*main cpp version .01*/


//going to include the class files but as of right now i dont know the names
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Book.h"
#include "Date.h"
#include "userInterface.h"

//dont know if this is looked down on but this is how i like to do things. 
using namespace std;





//not going to handle arguments at the cli at this time. 
int main(){
	//declaration of variables
	//the vectors for the lists of books and users respectively
	vector<Book*> books; 
	vector<User*> users;
	
	//our file handler objects. the text files are going to be hard coded. 
	ifStream userFile, bookFile;
	//youll want to inplement some error checking here.
	// userFile.open("userlist.txt");
	// bookFile.open("booklist.txt");
	try
	{
		userfile.open("userlist.txt");
	}
	catch (int e)
	{
		cout << "Could not open user file.\n"; 
		return 0;
	}
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
	UserInterface ui(parameter1, parameter2, parameter3);
	
	//read in the data from the booklist.txt file
	while(!bookFile.eof()){
		string title, type, dateCheckedOut, user;
		bookFile >> title;
		bookFile >> type;
		bookFile >> dateCheckedOut;
		bookFile >> user;
		books.push_back(new Book(title, type, dateCheckedOut, user));
	}
	
	//read in userlist.txt
	while(!userFile.eof()){
		string line; 
		line = userFile.getLine();
		while(!line.eof()){
			//here were going to grab one line at a time so we can grab all the books at the end. 
			
		}
		
	}
	

	
	//main process control loop
	do{
		//main program body here
		ui.drawMenu();
		ui.promptForInput();
						
	}while(!ui.exit());
	
	//write the user vector to the file
	
	//write the book vector to the file
	
	//print exit message and do any necessary cleanup
	cout << "\nThank you for using the library of Valhalla" << endl;
	
	return 0;
}
