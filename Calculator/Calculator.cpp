// Simple calculator
#include<iostream>
using namespace std;

int main()
{
    char Operator;
    int NumberOne, NumberTwo;
    cout<<"Selecet operation ( + , - , * , / ) "<<endl;
    cin>>Operator;
    cout<<"Please enter two numbers"<<endl;
    cin>>NumberOne>>NumberTwo;
    switch(Operator)
    {
        case '+':
            cout<<NumberOne << " + " << NumberTwo<< " = "<< NumberOne+NumberTwo<<endl;
            break;
        case '-':
            cout<<NumberOne << " - " << NumberTwo<< " = "<< NumberOne-NumberTwo<<endl;
            break;
        case '*':
            cout<<NumberOne << " * " << NumberTwo<< " = "<< NumberOne*NumberTwo<<endl;
            break;
        case '/':
            cout<<NumberOne << " / " << NumberTwo<< " = "<< NumberOne/NumberTwo<<endl;
            break;
    }
    system("pause");
}
