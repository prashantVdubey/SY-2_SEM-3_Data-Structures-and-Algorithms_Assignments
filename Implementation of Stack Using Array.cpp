#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define MAX_SIZE 5
using namespace std;

int main() 
{
    int item, choice, i;
    int S[MAX_SIZE];
    int top = -1;

    cout << "\nSimple Stack Implementation";

    do 
    {
        cout << "\n\n Stack Main Menu";
        cout << "\n1.Push \n2.Pop \n3.Display \nOthers to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;

        switch (choice) 
        {
            case 1:
                if (top == MAX_SIZE-1)
                    cout << "\n Stack is Full!";
                else 
                {
                    cout << "\nEnter The Value to be pushed : ";
                    cin>>item;
                    top++;
                    cout << "\n Position : " << top << ", Pushed Value :" << item;
                    S[top] = item;
                }
                break;

            case 2:
                if (top == -1)
                    cout << "\n Stack is Empty!";
                else 
                {
                    cout << "\n Position : " << top << ", Popped Value :" << S[top];
                    top--;
                }
                break;

            case 3:
                cout << "\n Stack Size : " << top+1;
                for (i = top; i > -1; i--)
                    cout << "\n Position : " << i << ", Value :" << S[i];
                break;
        }
    } while(choice<4);

    return 0;
}