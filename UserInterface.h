#ifndef UserInterface_H
#define UserInterface_H
#include <string>
#include <vector>
#include <cstdlib>

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
            DisplayMenu();
         }
         void AdvanceDate()
         {
              std::cout << "\nAdvanceDate is called" << endl;
              DisplayMenu();
         }
         //main menu call
        void DisplayMenu()
         {
            //add additional menu options when needed, update if statements to include new choices
            std::cout << "\n----Library System----" << endl;
            std::cout << "\\*------------------*/" << endl;
            std::cout << "To Check In enter 1"<< endl;
            std::cout << "To Check Out enter 2" << endl;
            std::cout << "To Advance Date enter 3" << endl;
            std::cout << "To Exit enter *" << endl;
            std::cout << "\\*------------------*/" << endl;
            //user choice for menu
            //input a simple string (can't use switch set up with a string, using if statements instead)
            //the correct choice will go onto the next function
            //will inform user if the choice is invalid.
            std::cout << "calling for input" << endl;
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
};

#endif // UI_H
