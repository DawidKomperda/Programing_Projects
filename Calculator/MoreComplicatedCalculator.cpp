// The calculator now allows you to select language, it also has been expanded by new functions.

#include<iostream>
#include<math.h>

using namespace std;

void Calculation( float NumberOne, float NumberTwo, char Operation)
{
    switch(Operation)
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
        case 'p':
            cout<<NumberOne << "^" << NumberTwo << " = " << pow(NumberOne,NumberTwo)<<endl;
            break;
    }

}
void CalculationSingleNumber( int NumberOne, char Operation)
{
    switch(Operation)
    { 
        case 's':
            cout<<" √"<<NumberOne<<" = "<< sqrt(NumberOne);
            break;
        case 'l':
            cout<<"Log"<<NumberOne<<" = "<< log(NumberOne);
    }
}
int main()
{
    string language;
    float NumberOne, NumberTwo;
    char Operation;
    cout<<"Please select language / Prosze wybierz jezyk"<<endl<<"EN/PL"<<endl;
    cin>>language;
    if (language == "EN")
    {
        cout<<"If you want to use square or log please enter integer"<<endl;
        cout<<"Enter first number"<<endl;
        cin>>NumberOne;
        cout<<"Choose Operation: ( + , - , * , / , p(power) , s(square) , l(Log)) "<<endl;
        cin>>Operation;
        if (Operation == '%' || Operation== '/' || Operation== '*' || Operation== '+' || Operation== '-'|| Operation== 'p') 
        {
            cout<<"Enter second number"<<endl;
            cin>>NumberTwo;
            Calculation(NumberOne,NumberTwo,Operation);
        }
        else if (Operation == 's' || Operation== 'l')
        {
            CalculationSingleNumber(NumberOne, Operation);
        }
        else
        {
            cout<<"Incorrect operation, please try again "<<endl;;
        }
            
    }
    else if (language == "PL")
    {
        cout<< "Witaj Jezeli chcesz uzyc pierwiastka lub logarytmu prosze podaj liczbe calkowita"<<endl;
        cout<<"Podaj pierwsza liczbe"<<endl;
        cin>>NumberOne;
        cout<<"Wybierz operacje: ( + , - , * , / , p(potega) , s(pierwiastek) , l(Log)) "<<endl;
        cin>>Operation;
        if (Operation == '%' || Operation== '/' || Operation== '*' || Operation== '+' || Operation== '-'|| Operation== 'p') 
        {
            cout<<"Podaj druga liczbe"<<endl;
            cin>>NumberTwo;
            Calculation(NumberOne,NumberTwo,Operation);
        }
        else if (Operation == 's' || Operation== 'l')
        {
            CalculationSingleNumber(NumberOne, Operation);
        }
        else
        {
            cout<<"Niepoprawna operacja, sprobuj ponownie "<<endl;;
        }
           
    }
    else
    {
        cout<<"Program does not support this language / Ten program nie obsługuje tego języka"<<endl;
    }
    system("pause");
}
