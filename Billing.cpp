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
    cout << "\n\t\t\t|_____1) Add The Product_____|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____2) Modify The Product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____3) Delete The Product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____4) Back To Main Menu___|";

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
    cout << "\t\t\t Enter Your Choice \n";

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

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add New Product \n";
    cout << "\n\n\t Product code of the Product \n";
    cin >> pcode;
    cout << "\n\n\t Name of the Product \n";
    cin >> pname;
    cout << "\n\n\t Price of the Product \n";
    cin >> price;
    cout << "\n\n\t Discount of the Product \n";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record Inserted!";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify TheRecord";
    cout << "\n\t\t\t Product Code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nFile Doesn't Exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product New Code :";
                cin >> c;
                cout << "\n\t\t Name OF The Product :";
                cin >> n;
                cout << "\n\t\t Price :";
                cin >> p;
                cout << "\n\t\t Discount :";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record Edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        remove("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record Not Found Sorry! ";
        }
    }
}