#ifndef UserInterface_H
#define UserInterface_H
#include <string>
using namespace std;

class UserInterface
{
    public:
        UserInterface() {}
        virtual ~UserInterface() {}
        //user checks in book
        //calls menu of books user checked out
        //allow user to select book to check in
        void CheckIn()
         {
             std::cout << "\nCheckIn is called" << endl;
             DisplayMenu();
         }
         //user checks out book checks user number of books checked out
         //if value is legal call check out menu
        void CheckOut()
         {
            std::cout << "\nCheckOut is called" << endl;
            DisplayMenu();
         }
         string promptForInput()
         {
             string userInput;
             std::cout << "\nEnter selection:" << endl;
             std::getline(std::cin,userInput);
             return userInput;
         }
         //main menu call
        void DisplayMenu()
         {
            //add additional menu options when needed, update if statements to include new choice
            std::cout << "\n----Library System----" << endl;
            std::cout << "\\*------------------*/" << endl;
            std::cout << "To Check In enter 1"<< endl;
            std::cout << "To Check Out enter 2" << endl;
            std::cout << "To Exit enter *" << endl;
            std::cout << "\\*------------------*/" << endl;

            string choice = promptForInput();
            std::cout << "\n";
            //user choice for menu
            //input a simple string (can't use switch with string, use if statements instead)
           if(choice == "1")
           {
              CheckIn();
           }
           else if(choice == "2")
           {
               CheckOut();
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

         }
    private:

};

#endif // UI_H
