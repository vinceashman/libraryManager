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
<<<<<<< HEAD
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
=======
	cout <<"before book vector creation"<<endl;
	vector<Book*> books;
	cout <<"after book vector creation"<<endl;
	//vector of users;
	vector<vector<string> > users;
	//our file handler objects. the text files are going to be hard coded.
	ifstream bookFile, userFile;
	
	//output objects
	ofstream outUser, outBook;
	
	cout <<"theDate creation"<<endl;
	Date theDate;
		
	//reading the files into memory. 
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
	
	//reading in the userfile 
	try{
		userFile.open("userlist.txt");
>>>>>>> master
	}
    catch (int e)
	{
<<<<<<< HEAD
		cout << "Could not open book file.\n";
		return 0;
	}

	Date theDate;

	//instantiate ui object. most likely it would take 3 parameters. a pointer to the 2 vectors and a pointer to the date object.

=======
		cout << "Could not open user file.\n";
	}
	
	
>>>>>>> master

	//read in the data from the booklist.txt file
	cout<<"populating books"<<endl;
	while(!bookFile.eof()){
<<<<<<< HEAD
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
=======
        cout<<"in while loop!"<<endl;
        //string aLine;
        //getline(bookFile, aLine);
        //if(!aLine.empty() )
        //{
        string title, type, dateCheckedOut, user;
		bookFile >> title;
		bookFile >> type;
		bookFile >> dateCheckedOut;
		bookFile >> user;
		books.push_back(new Book(title, type, dateCheckedOut, user));
        //}
>>>>>>> master

	}
	cout <<"books are done populating" <<endl;

	//read in userlist.txt
<<<<<<< HEAD



    UserInterface ui(books, theDate);
=======
	cout << "Populating userlist" << endl;
	while(!userFile.eof()){
		//string aLine;
		//getline(userFile, aLine);
		//if(!aLine.empty()){
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

	//instantiate UI object. 
    UserInterface ui(books, theDate);

>>>>>>> master
	//main process control loop
	do{
		//main program body here
		ui.DisplayLoginMenu();
<<<<<<< HEAD
		//ui.promptForInput();

	}while(!ui.exit());

	//write the user vector to the file

	//write the book vector to the file

	//print exit message and do any necessary cleanup
	cout << "\nThank you for using the library of Valhalla" << endl;
    system("pause");
=======
	}while(!ui.exit());
	
	userFile.close();
	bookFile.close();
	
	//open the files for writing out. 
	//files are opened in truncate mode so the existing data is replaced. 
	outUser.open("userList.txt", std::ofstream::trunc);
	outBook.open("bookList.txt", std::ofstream::trunc);
	
	//write the book vector to the file
	for(int i = 0; i < books.size(); i++){
		Date tempDate = books[i]->CalcDueDate();
		outBook << books[i]->getTitle() << " " << books[i]->getType() << " " << tempDate.getMonth() << tempDate.getDay() << tempDate.getYear() << " " << books[i]->getUser() << endl;
	}
	
	//write the user vector to the file
	for(int i = 0; i < users.size(); i++){
		outUser << users[i][0] << " " << users[i][1] << endl;
	}
	
	//close the output files. 
	outUser.close();
	outBook.close();
	
	//print exit message and do any necessary cleanup
	cout << "\nThank you for using the library of Valhalla" << endl;
	
	
>>>>>>> master
	return 0;
}
