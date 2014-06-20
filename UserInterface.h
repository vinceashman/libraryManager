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
        //user checks in book
        //calls menu of books user checked out
        //allow user to select book to check in
        void CheckIn()
         {
             std::cout << "\nCheckIn is called" << endl;
             //go through the user's book list and print the list of books with
             //a choice for the user to select which book/media to check in.
             //updates the book list to include the book to show that its available.
             std::cout <<"\nList of Available Books here in Valhalla:" << endl;
             std::cout <<"|------------------------------------------|" << endl;
             std::cout <<"|                                          |" << endl;
             std::cout <<"|------------------------------------------|" << endl;
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
            //display in groups of 10
            std::cout <<"\nList of Available Books here in Valhalla:" << endl;
            std::cout <<"|------------------------------------------|" << endl;
            std::cout <<"|                                          |" << endl;
            std::cout <<"|------------------------------------------|" << endl;
            DisplayMenu();
         }
         void AdvanceDate()
         {
              std::cout << "\nAdvanceDate is called" << endl;
              DisplayMenu();
         }
         //login menu call?
        void DisplayLoginMenu()
        {
        std::cout << "User Login:" << endl;
        string userName = promptForInput();
        std::cout << "Welcome to the Library " << userName << endl;
        //pass information to list?
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
            std::cout << "To Advance Date enter 3" << endl;
            std::cout << "To Exit enter *" << endl;
            std::cout << "\n\\*------------------*/" << endl;
            //user choice for menu
            //input a simple string (can't use switch set up with a string, using if statements instead)
            //the correct choice will go onto the next function
            //will inform user if the choice is invalid.            
            string choice = promptForInput();
            
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
            string userName;
};

#endif // UI_H
