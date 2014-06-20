#ifndef UserInterface_H
#define UserInterface_H

//#include "book.h"
#include <vector>
#include <string>
using namespace std;

class UserInterface
{
    public:
        UserInterface()
         {

         }
        virtual ~UserInterface() {}


        //get available bookList
        void getBookList()
        {
            //call and get the list of available books
        }
        //get books from user
        void getUserBooks()
        {
            //get the inventory of the user
        }
        //user checks in book
        //calls menu of books user checked out
        //allow user to select book to check in
        void CheckIn()
         {
             std::cout << "\nCheckIn is called" << endl;
             //go through the user's book list and print the list of books with
             //a choice for the user to select which book/media to check in.
             //updates the book list to include the book to show that its available.
             if(userBookList.size() > 0)
             {
             std::cout <<"\nList of Media checked out by" << userName <<":" << endl;
             std::cout <<"|------------------------------------------|" << endl;
             for(unsigned int i = 0; i < userBookList.size(); i++)
             {
              std::cout << "| " << i << userBookList[i] << " |" << endl;
             }
             std::cout <<"|------------------------------------------|" << endl;
             std::cout <<"Select a item to check in:" << endl;
             }
             else
             {
             std::cout <<"\nThere was an Error, going back to main menu" << endl;
             }

             DisplayMenu();
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
        void CheckOut()
         {
            std::cout << "\nCheckOut is called" << endl;
            //go through book list and display which books are available to check out
            //user gives choice to what book they want to use.
            //display in groups of 10?
            if(bookList.size() > 0)
            {
            std::cout <<"\nList of Available Media here in Valhalla:" << endl;
            std::cout <<"|------------------------------------------|" << endl;
            for(unsigned int i = 0; i < bookList.size(); i++)
            {
              std::cout << "| " << i << bookList[i] << " |" << endl;
            }
            std::cout <<"|------------------------------------------|" << endl;
             std::cout <<"Select a item to check out:" << endl;
             //call option to select media
             //check if the user is adult or child
             //check if the user already reached media.

            }
            else
            {
            std::cout <<"\nThere was an Error, going back to main menu" << endl;
            }
            DisplayMenu();
         }
         void AdvanceDate()
         {
              std::cout << "\nAdvanceDate is called" << endl;
              DisplayMenu();
         }

        void viewOverDueBooks()
        {
            std::cout <<"\nList of Over Due Media here in Valhalla:" << endl;
            std::cout <<"|------------------------------------------|" << endl;
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
            std::cout << "To View Over Due books 3" << endl;
            std::cout << "To Advance Date enter 4" << endl;
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
              viewOverDueBooks();
           }
           else if(choice == "4")
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

         }//end of displaymenu function

    private:
            //adding a username variable for now to pass to other objects..
            //unless main handles this..
            std::string userName;
            std::vector<string> bookList; //available books
            std::vector<string> userBookList;
};

#endif // UI_H
