//===========================================================
// Program: Queue Data Structure using Array
// Purpose: To understand Queue operations
// Queue Principle: FIFO (First In First Out)
//===========================================================

#include <iostream>
using namespace std;


//-------------------------
// Queue Size
//-------------------------

const int MAX = 5;


// Queue Array

int queue[MAX];


// Front points to first element

int front = -1;


// Rear points to last element

int rear = -1;


//===========================================================
// Function to Insert Element (Enqueue)
//===========================================================

void enqueue()
{
    int value;

    // Check whether queue is full

    if (rear == MAX - 1)
    {
        cout << "\nQueue Overflow! Queue is Full.\n";
        return;
    }

    // Take input from user

    cout << "Enter element to insert: ";
    cin >> value;

    // If first element is inserted

    if (front == -1)
    {
        front = 0;
    }

    // Move rear one position ahead

    rear++;

    // Store value

    queue[rear] = value;

    cout << value << " inserted successfully.\n";
}


//===========================================================
// Function to Delete Element (Dequeue)
//===========================================================

void dequeue()
{
    // Check whether queue is empty

    if (front == -1 || front > rear)
    {
        cout << "\nQueue Underflow! Queue is Empty.\n";

        // Reset pointers

        front = rear = -1;

        return;
    }

    cout << queue[front] << " deleted successfully.\n";

    // Move front to next element

    front++;

    // If queue becomes empty after deletion

    if (front > rear)
    {
        front = rear = -1;
    }
}


//===========================================================
// Function to Display Queue
//===========================================================

void display()
{
    // Check for empty queue

    if (front == -1)
    {
        cout << "\nQueue is Empty.\n";
        return;
    }

    cout << "\nQueue Elements:\n";

    // Print elements from front to rear

    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }

    cout << endl;
}


//===========================================================
// Main Function
//===========================================================

int main()
{
    int choice;
    char ans;

    do
    {
        cout << "\n===================================";
        cout << "\n QUEUE OPERATIONS";
        cout << "\n===================================";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n===================================";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

        cout << "\n Do you want to continue(Y/y)=";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    return 0;
}