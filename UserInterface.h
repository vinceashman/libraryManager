#ifndef UserInterface_H
#define UserInterface_H
#include "List.h"
#include "Book.h"
#include "Date.h"
#include <vector>
#include <string>
#include <sstream>
//#include "List.h"

using namespace std;

class UserInterface
{
    public:
        UserInterface(vector<Book*> books, Date theDate, vector<vector<string> > theUsers)
         {
            allBooks = books;
            currentDate = theDate;
            userList = theUsers;
            //currentDate.setMonth(8);
            //currentDate.setDay(2);
            //currentDate.setYear(2014);
         }
        virtual ~UserInterface() {}
        bool checkUser(string atype)
        {

            int counter = 0;
             string aUser;
             bool adult = false;
                        for(int k = 0; k < allBooks.size(); k++)
                        {
                           aUser = allBooks[k]->getUser();
                            if(userName == aUser)
                            {
                                counter++;

                            }

                        }
            for(int i = 0; i < userList.size();i++)
            {

                    if(userName == userList[i][0])
                    {
                        if(userList[i][1] == "AD")
                        {
                            adult = true;
                        }
                        else
                        {
                            adult = false;
                        }

                    }

            }

             if(adult == true)
                {
                    if(counter < 6)
                        {
                            return true;
                        }
                        else
                        {
                            std::cout << "Check Out Limit Reached, press enter to continue" << endl;
                            cin.ignore();
                            return false;
                        }
                }
            else if(adult == false && atype =="CB")
                {
                    if(counter < 3)
                        {
                            return true;
                        }
                        else
                        {
                            std::cout << "Check Out Limit Reached, press enter to continue" << endl;
                            cin.ignore();
                            return false;
                        }
                }
                else if(adult == false && atype == "AB")
                {
                   std::cout << "Can't check out an adult media, press enter to continue" << endl;
                   cin.ignore();
                   return false;
                }
                else
                {
                  return false;
                }
        }
        //user checks in book
        //calls menu of books user checked out
        //allow user to select book to check in
        void CheckOut()
         {
             //go through the user's book list and print the list of books with
             //a choice for the user to select which book/media to check in.
             //updates the book list to include the book to show that its available.
             string choice;
             bool check = false;
             string lib = "library";
             int currentCounter = 0;

             do
             {
                  system("cls");
            std::cout << "\nList of Available Media here in Valhalla:"<< endl;
            std::cout <<"|------------------------------------------|" << endl;

            listOfBooks.ListAvailable(allBooks, currentCounter);
            std::cout <<"|------------------------------------------|" << endl;
            if(currentCounter > 0)
            {
                std::cout <<"\nEnter P for previous page " ;
            }
            if(currentCounter <= allBooks.size())
            {
                std::cout <<"\nEnter N for next page " ;
            }
                std::cout <<"\nEnter book name or number to check out:";
                std::cout <<"\nEnter * to return to menu" ;


                choice = promptForInput();
                if ((choice == "p" || choice == "P" )&& currentCounter > 0)
                {
                    currentCounter -= 10;

                }
                else if((choice == "N" || choice == "n") && currentCounter <= allBooks.size())
                {
                    currentCounter += 10;
                }
                else
                {
                    for(int i = 0; i < allBooks.size(); i++)
                    {
                        string title = allBooks[i]->getTitle();
                        string auser = allBooks[i]->getUser();
                        string atype = allBooks[i]->getType();
                      string is;
                      std::ostringstream convert;
                      convert << i;
                      is = convert.str();
                        if (choice == title)
                        {
                            //std::cout << userName << " successfully checked out " << title << endl;
                           check = checkUser(atype);
                            if(check == true)
                                {
                            allBooks[i]->setUser(userName);
                            allBooks[i]->setDate(currentDate);
                            system("cls");
                                }
                        }
                        if(choice == is && auser == lib)
                        {
                           check = checkUser(atype);
                             if(check == true)
                                {
                           //std::cout << userName << " successfully checked out " << title << endl;
                            allBooks[i]->setUser(userName);
                            allBooks[i]->setDate(currentDate);
                                }
                        }
                    }
                }

             }
             while(choice != "*");
             system("cls");
             DisplayMenu();
         }
         //user checks out book checks user number of books checked out
         //if value is legal call check out menu
        string promptForInput()
        {
               string theInput = "";
               std::cout << "\nEnter selection: ";
               std::getline(std::cin,theInput);
               return theInput;
        }

        //Check if user has any books checked out at all. If the user has a checked out book call the list bookscheckedout function
        //prompt a menu for user to select what to check in
        void CheckIn()
                 {
            //go through book list and display which books are available to check out
            //user gives choice to what book they want to use.
            //display in groups of 10?
            //create a user and temp books to hold the books for user to check out menu operations
            string user;
            string lib = "library";
            std::vector<Book*> tempBooks;
            bool userHasBook = false;
            string choice;
            if(allBooks.size() > 0)
            {
                for(unsigned int i = 0; i < allBooks.size(); i++)
                {
                    //check user has anything checked out at all
                    user = allBooks[i]->getUser();
                    if(user == userName)
                    {
                        userHasBook = true;
                    }

                }

            if(userHasBook == true)
            {

            std::cout <<"\nList of Media checked out by " << userName <<":" << endl;
            std::cout <<"|------------------------------------------|" << endl;
            listOfBooks.BooksCheckedOut(allBooks, userName);
            std::cout <<"|------------------------------------------|" << endl;
            std::cout <<"Select a item to check out:" << endl;
            //oice = promptForInput();//need to figure out how to get matching data from list
            std::cout <<"\nEnter book name or number to check out:";
            std::cout <<"\nEnter * to return to menu" ;


                choice = promptForInput();
                if (choice == "*")
                {
                    system("cls");
                    DisplayMenu();
                }

                else
                {
                     string title;
                     string auser;
                    for(int i = 0; i < allBooks.size(); i++)
                    {
                      title = allBooks[i]->getTitle();
                      auser = allBooks[i]->getUser();
                        Date resetDate;
                        resetDate.setDay(0);
                        resetDate.setMonth(0);
                        resetDate.setYear(0000);
                      string is;
                    std::ostringstream convert;
                      convert << i;
                      is = convert.str();
                        if(choice == title)
                        {
                            std::cout << userName << " successfully checked out " << title << endl;
                            allBooks[i]->setUser(lib);
                            allBooks[i]->setDate(resetDate);
                        }
                        if(choice == is && auser == userName)
                        {
                           std::cout << userName << " successfully checked out " << title << endl;
                            allBooks[i]->setUser(lib);
                            allBooks[i]->setDate(resetDate);
                        }

                    }

                    if(title != choice && choice != "*")
                    {

                        system("cls");
                        CheckIn();
                    }
                }
            }
            else
            {
                std::cout <<"\nThere is nothing checked out by " << userName << endl;
                DisplayMenu();
            }


            }


         }
         //advances the date by a day and automatically adjusts the month/day/year
         void AdvanceTheDate()
         {
              currentDate.AdvanceDate();
              system("cls");
              DisplayMenu();
         }

         //calls the list AllBooks function that displays all media in the library in sets of 10
        void viewAllBooks()
        {

            string choice;
             int currentCounter = 0;

             do
             {
                 system("cls");
            std::cout << "\nList of All Media here in Valhalla:"<< endl;
            std::cout <<"|------------------------------------------|" << endl;

            listOfBooks.AllBooks(allBooks, currentCounter);
            std::cout <<"|------------------------------------------|" << endl;
            if(currentCounter > 0)
            {
                std::cout <<"\nEnter P for previous page " ;
            }
            if(currentCounter <= allBooks.size())
            {
                std::cout <<"\nEnter N for next page " ;
            }
                std::cout <<"\nEnter * to return to menu" ;

                choice = promptForInput();
                if ((choice == "p" || choice == "P" )&& currentCounter > 0)
                {
                    currentCounter -= 10;

                }
                else if((choice == "N" || choice == "n") && currentCounter <= allBooks.size())
                {
                    currentCounter += 10;

                }
                else if (choice == "*")
                {
                    //std::cout << "\Incorrect entry enter again:";
                }

             }
             while(choice != "*");
             system("cls");
            DisplayMenu();
        }

        //call the list ListOverdue function that will display all lover due media in the library
        void viewOverDueBooks()
        {

            std::cout <<"\nList of Over Due Media here in Valhalla:" << endl;
            std::cout <<"|------------------------------------------|" << endl;

                listOfBooks.ListOverdue(allBooks, 0, currentDate);

            std::cout <<"|------------------------------------------|" << endl;
            std::cout << "Enter * to return to menu" << endl;
            string choice;
            choice = promptForInput();
            if(choice == "*")
            {
            system("cls");
            DisplayMenu();
            }
            else
            {

            system("cls");
           viewOverDueBooks();
            }
        }
         //login menu call?
        void DisplayLoginMenu(vector<vector<string> > users)
            {
            std::cout << "|--------Library--------|" << endl;
            std::cout << "User Login:" << endl;
            //check if user is existing or new
            //check age associated with user
            //ask for age for new users and automatically assign child/adult status
		    bool inList = false;
		    while(!inList){
			    userName = promptForInput();
			    cout << "the user input is " << userName << endl;
			    //determines if the user is actually in the list
			    for(int i = 0; i < users.size(); i++){
    				cout << "from users " << users[i][0] << endl;
    				if(userName == users[i][0]){
					    inList = true;
				    }
			    }
			    std::cout << "Please enter a valid user name" << endl;

		    }
		//got the login name, pass the information for the list
         system("cls");
        DisplayMenu();
        }
         //main menu call
        void DisplayMenu()
         {
            //add additional menu options when needed, update if statements to include new choices
            std::cout << "Welcome to the Library " << userName << endl;
            std::cout << "\n|---Library System---|" << endl;
            std::cout << "\n|---" << currentDate.getMonth() <<"/" << currentDate.getDay() <<"/" <<currentDate.getYear() << "---|" << endl;
            std::cout << "\\*------------------*/" << endl;
            std::cout << "\nTo Check In enter 1"<< endl;
            std::cout << "To Check Out enter 2" << endl;
            std::cout << "To View All Media 3" << endl;
            std::cout << "To View Over Due Media 4" << endl;
            std::cout << "To Advance Date enter 5" << endl;
            std::cout << "To Exit enter *" << endl;
            std::cout << "\n\\*------------------*/" << endl;
            //user choice for menu
            //input a simple string (can't use switch set up with a string, using if statements instead)
            //the correct choice will go onto the next function
            //will inform user if the choice is invalid.
            std::string choice = promptForInput();

            std::cout << "\n";

           if(choice == "1")
           {
               system("cls");
              CheckIn();
           }
           else if(choice == "2")
           {
               system("cls");
               CheckOut();
           }
           else if(choice == "3")
           {
               system("cls");
               viewAllBooks();
           }
           else if(choice == "4")
           {
               system("cls");
              viewOverDueBooks();
           }
           else if(choice == "5")
           {
               system("cls");
               AdvanceTheDate();
           }
           else if(choice == "*")
           {
               system("cls");
                 exit();
           }
           else
           {
              system("cls");
                DisplayMenu();
           }

         }//end of displaymenu function
    bool exit()
    {
        return true;
    }
    private:
            //adding a username variable for now to pass to other objects..
            //unless main handles this..
            std::string userName;
            //simple placeholders for now
            std::vector<Book*> allBooks; //all media
            vector<vector<string> > userList;
            Date currentDate;
            List listOfBooks; //temp?
};


#endif // UI_H
