#ifndef UserInterface_H
#define UserInterface_H
#include "List.h"
#include "Book.h"
#include "Date.h"
#include <vector>
#include <string>
//#include "List.h"

using namespace std;

class UserInterface
{
    public:
        UserInterface(vector<Book*> books, Date theDate)
         {
            allBooks = books;
            currentDate = theDate;
         }
        virtual ~UserInterface() {}

        //user checks in book
        //calls menu of books user checked out
        //allow user to select book to check in
        void CheckOut()
         {
             std::cout << "\nCheckOut is called" << endl;//temp
             //go through the user's book list and print the list of books with
             //a choice for the user to select which book/media to check in.
             //updates the book list to include the book to show that its available.
             string choice;
             int currentCounter = 0;
             do
             {
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
                std::cout <<"\nEnter * to return to menu" ;

                choice = promptForInput();
                if ((choice == "p" || choice == "P" )&& currentCounter > 0)
                {
                    currentCounter = 0;

                }
                else if((choice == "N" || choice == "n") && currentCounter <= allBooks.size())
                {
                    currentCounter += 10;

                }
                else
                {
                    std::cout << "\nIncorrect entry enter again:";
                }

             }
             while(choice != "*");
         }
         //user checks out book checks user number of books checked out
         //if value is legal call check out menu
        string promptForInput()
        {
               string theInput = "";
               std::cout << "\nEnter selection:" << endl;
               std::getline(std::cin,theInput);
               return theInput;
        }
        void CheckIn()
                 {
            std::cout << "\nCheckIn is called" << endl;//temp
            //go through book list and display which books are available to check out
            //user gives choice to what book they want to use.
            //display in groups of 10?

            //create a user and temp books to hold the books for user to check out menu operations
            string user;
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
            string aUser;
            //oice = promptForInput();//need to figure out how to get matching data from list
                for(unsigned int j = 0; j < allBooks.size(); j++)
                {
                    aUser = allBooks[j]->getUser();
                    if(aUser == userName)
                    {
                        tempBooks.push_back(allBooks[j]);
                    }
                }
            }

            }
            else
            {
            std::cout <<"\nThere was an Error, going back to main menu" << endl;
            }

            DisplayMenu();
         }
         void AdvanceDate()
         {
              std::cout << "\nAdvanceDate is called" << endl;//temp
              DisplayMenu();
         }
        void viewAllBooks()
        {
            std::cout << "\nviewAllBooks is called" << endl;//temp
            std::cout << "\nList of All Media here in Valhalla:"<< endl;
            string choice;
             int currentCounter = 0;
             do
             {
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
                    currentCounter = 0;

                }
                else if((choice == "N" || choice == "n") && currentCounter <= allBooks.size())
                {
                    currentCounter += 10;

                }
                else
                {
                    std::cout << "\Incorrect entry enter again:";
                }

             }
             while(choice != "*");
            DisplayMenu();
        }
        void viewOverDueBooks()
        {
            currentDate.setMonth(6);
            currentDate.setDay(27);
            currentDate.setYear(2014);
            std::cout <<"\nList of Over Due Media here in Valhalla:" << endl;
            std::cout <<"|------------------------------------------|" << endl;
            for (unsigned int i = 0; i < allBooks.size(); i++)
            {
                //check if overdue
                //if(allBooks[i].overDue() == true)
                //{
                  std::cout << "| " << i << allBooks[i] << " |" << endl;
                //}

            }
            std::cout <<"|------------------------------------------|" << endl;
            DisplayMenu();
        }
         //login menu call?
        void DisplayLoginMenu()
        {
        std::cout << "User Login:" << endl;
        userName = promptForInput();
        std::cout << "Welcome to the Library " << userName << endl;
        //got the login name, pass the information for the list
        DisplayMenu();
        }
         //main menu call
        void DisplayMenu()
         {
            //add additional menu options when needed, update if statements to include new choices
            std::cout << "\n|---Library System---|" << endl;
            std::cout << "\\*------------------*/" << endl;
            std::cout << "\nTo Check In enter 1"<< endl;
            std::cout << "To Check Out enter 2" << endl;
            std::cout << "To View All books 3" << endl;
            std::cout << "To View Over Due books 4" << endl;
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
              CheckIn();
           }
           else if(choice == "2")
           {
               CheckOut();
           }
           else if(choice == "3")
           {
               viewAllBooks();
           }
           else if(choice == "4")
           {
              viewOverDueBooks();
           }
           else if(choice == "5")
           {
               AdvanceDate();
           }
           else if(choice == "*")
           {
                return;
           }
           else
           {
              cout << "\nIncorrect choice" << endl;
                DisplayMenu();
           }
            exit();
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
            std::vector<string> bookList; //available books
            std::vector<string> userBookList;
            std::vector<Book*> allBooks; //all media
            Date currentDate;
            List listOfBooks; //temp?
};


#endif // UI_H
