#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t________________________________\n";
    cout << "\t\t\t\t                                \n";
    cout << "\t\t\t\t      Supermarket Main Menu     \n";
    cout << "\t\t\t\t                                \n";
    cout << "\t\t\t\t________________________________\n";
    cout << "\t\t\t\t                                \n";

    cout << "\t\t\t\t|    1) Administrator   |\n";
    cout << "\t\t\t\t|                       |\n";
    cout << "\t\t\t\t|    2) Buyer           |\n";
    cout << "\t\t\t\t|                       |\n";
    cout << "\t\t\t\t|    3) Exit            |\n";
    cout << "\t\t\t\t|                       |\n";
    cout << "\t\t\t\t Please Select!";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email \n";
        cin >> email;
        cout << "\t\t\t Password \n";
        cin >> password;

        if (email = "admin@gmail.com" &&password = "admin@123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email/Password";
        }
        break;

    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please Select From The Given Options";
    }
    }

    goto m;
}

void shopping::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator Menu";
    cout << "\n\t\t\t|_____1) Add the product_____|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____2) Modify the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____3) Delete the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____4) Back to main menu___|";

    cout << "\n\n\t Please Enter Your Choice ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid Choice!";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t Buyer \n";
    cout << "\t\t\t_______________\n";
    cout << "\t\t\t               \n";
    cout << "\t\t\t1) Buy Product \n";
    cout << "\t\t\t               \n";
    cout << "\t\t\t2) Go Back     \n";
    cout << "\t\t\t Enter your choice \n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();

    default:
        cout << "Invalid Choice!";
    }
    goto m;
}