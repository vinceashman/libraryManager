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
	}
    catch (int e)
	{
		cout << "Could not open user file.\n";
	}
	
	

	//read in the data from the booklist.txt file
	cout<<"populating books"<<endl;
	while(!bookFile.eof()){
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

	}
	cout <<"books are done populating" <<endl;

	//read in userlist.txt
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

	//main process control loop
	do{
		//main program body here
		ui.DisplayLoginMenu();
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
	
	
	return 0;
}
