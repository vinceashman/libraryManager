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

	vector<vector<string> > users;

	//our file handler objects. the text files are going to be hard coded.
	ifstream bookFile, userFile;
	ofstream outBook, outUser;
	
	
	try
	{
		bookFile.open("booklist.txt");
	}
	catch (int e)
	{
		cout << "Could not open book file.\n";
		return 0;
	}
	try
	{
		userFile.open("userlist.txt");
	}
	catch (int e)
	{
		cout << "Could not open user file.\n";
	}
	
	Date theDate;

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

        }

	}
	cout <<"books are done populating" <<endl;

	//populate the user vector
	cout << "Populating userlist" << endl;
	while(!userFile.eof()){
		string name, type;
		userFile >> name;
		userFile >> type;
		//storing the temp vector so we can push the whole thing onto the main users vector.
		vector<string> tempVect;
		tempVect.push_back(name);
		tempVect.push_back(type);
		users.push_back(tempVect);
		//}//end if
	}//end while
	
    UserInterface ui(books, theDate);
	//main process control loop
	do{
		//main program body here
		ui.DisplayLoginMenu();
		//ui.promptForInput();

	}while(!ui.exit());

	//close the book files
	userFile.close();
	bookFile.close();
	
	
	//opens the files to write to them.
	outUser.open("userList.txt", std::ofstream::trunc);
	outBook.open("bookList.txt", std::ofstream::trunc);
	
	//write the user vector to the file
	for(int i = 0; i < users.size(); i++){
		outUser << users[i][0] << " " << users[i][1] << endl;
	}
	
	//write the book vector to the file
	for(int i = 0; i < books.size(); i++){
		Date tempDate = books[i]->CalcDueDate();
		outBook << books[i]->getTitle() << " " << books[i]->getType() << " " << tempDate.getMonth() << tempDate.getDay() << tempDate.getYear() << " " << books[i]->getUser() << endl;
	}
	
	outUser.close();
	outBook.close();
	
	//print exit message and do any necessary cleanup
	cout << "\nThank you for using the library of Valhalla" << endl;
    system("pause");
	return 0;
}
