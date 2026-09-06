#include <iostream>
using namespace std;

int main()
{
/*C++ program for addition, subtraction, multiplication*/
float a, b, rem;
int ch, q;

cout << "Arithmetic Operatios";
cout << "\n1.Addition\n2.Subtraction\n3.Multiplication";
cout << "\n\nEnter Your Choice:\n";
cin >> ch;

switch (ch)
{
case 1:
{
cout << "\nEnter Two Value Ie:- Value Of A And B ";
cin >> a >> b;
rem = a + b;
cout << "\n Result = " << rem;
cout << "\n";
}
break;

case 2:
{
cout << "\nEnter Two Value Ie:- Value Of A And B";
cin >> a >> b;
rem = a - b;
cout << "\n Result = " << rem;
cout << "\n";
}
break;

case 3:
{
cout << "\nEnter Two Value Ie:- Value Of A And B";
cin >> a >> b;
rem = a * b;
cout << "\n Result = " << rem;
cout << "\n";
}
break;
}

return 0;
}