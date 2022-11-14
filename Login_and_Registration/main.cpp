#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;




void login()
{
    string username, password, compareUsername, comparePassword;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream read("dataStorage.txt");
    while (read>>compareUsername>>comparePassword)
    {
        if (username == compareUsername && password == comparePassword) {cout << "Login successful!" << endl; break;}
        else {cout << "Login failed!" << endl; break;}
    }
    
}

void registerUser()
{
    cout << "Register" <<endl;

    string registerUsername, registerPassword, registerPassword2;

    cout << "Enter username: ";
    cin >> registerUsername;
    cout << "Enter password: ";
    cin >> registerPassword;
    cout << "Confirm password: ";
    cin >> registerPassword2;

    if (registerPassword == registerPassword2)
    {
        ofstream ("dataStorage.txt", ios::app) << registerUsername << " " << registerPassword << endl;
        cout << "Registration comepleted successfuly" << endl;
    }
}

void forgotPassword()
{
    string username, searchUsername, searchPassword;
    cout << "If you have forgotten your password, please type your username" << endl;
    cin>> username;
    ifstream search("dataStorage.txt");
    while (search>>searchUsername>>searchPassword)
    {
        if (searchUsername == username) {cout << "Your password is: " << searchPassword << endl; break;}
        else {cout << "Username not found" << endl; break;}
    }
}

void exit()
{
    cout << "Goodbye" <<endl;
    Sleep(15);
    system("exit");
}

int main()
{

    char menuChoice;

    cout << "Welcome" <<endl;
    cout << "1. Login" <<endl;
    cout << "2. Register" <<endl;
    cout << "3. Forgot Password" <<endl;
    cout << "4. Exit" <<endl;

    cout << " Type in your choice: ";
    cin >> menuChoice;
    switch(menuChoice)
    {
        case '1':
            login();
            break;
        case '2':
            registerUser();
            break;
        case '3':
            forgotPassword();
            break;
        case '4':
            exit();
            break;
        default:
            cout << "Invalid choice" <<endl;
        
    }
return 0;
}