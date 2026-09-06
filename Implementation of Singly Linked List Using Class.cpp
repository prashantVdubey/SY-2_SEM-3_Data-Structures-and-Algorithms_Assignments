/*
Program : Simple Linked List Operations using Class

Operations:
1. Create List
2. Insert Node
3. Delete Node
4. Display List
5. Exit

===========================================================
*/

#include <iostream>
using namespace std;


//----------------------------
// Step 1 : Define Node
//----------------------------

struct Node
{
    int data;       // Stores the value
    Node *next;     // Pointer to next node
};


//----------------------------
// Step 2 : Create LinkedList Class
//----------------------------

class LinkedList
{
private:

    Node *head;     // Starting node of the list

public:

    // Constructor

    LinkedList()
    {
        head = NULL;
    }


    //----------------------------
    // Create Initial List
    //----------------------------

    void createList()
    {
        int n, value;

        cout << "\nEnter number of nodes : ";
        cin >> n;

        if (n <= 0)
        {
            cout << "Invalid number of nodes.";
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << "Enter value " << i << " : ";
            cin >> value;

            insertEnd(value);
        }

        cout << "\nLinked List Created Successfully.\n";
    }


    //----------------------------
    // Insert Node at End
    //----------------------------

    void insertEnd(int value)
    {
        // Create new node

        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = NULL;


        // If list is empty

        if (head == NULL)
        {
            head = newNode;
            return;
        }


        // Traverse till last node

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }


        // Attach new node

        temp->next = newNode;
    }


    //----------------------------
    // Delete Node by Value
    //----------------------------

    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "\nList is Empty.\n";
            return;
        }

        Node *temp = head;
        Node *previous = NULL;


        // Delete first node

        if (head->data == value)
        {
            head = head->next;

            delete temp;

            cout << "\nNode Deleted.\n";

            return;
        }


        // Search node

        while (temp != NULL && temp->data != value)
        {
            previous = temp;
            temp = temp->next;
        }


        if (temp == NULL)
        {
            cout << "\nValue Not Found.\n";
            return;
        }


        previous->next = temp->next;

        delete temp;

        cout << "\nNode Deleted Successfully.\n";
    }


    //----------------------------
    // Display Linked List
    //----------------------------

    void display()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\nLinked List : ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";

            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};


//----------------------------
// Main Function
//----------------------------

int main()
{
    LinkedList list;

    int choice;
    int value;

    do
    {
        cout << "\n==============================";
        cout << "\n       LINKED LIST MENU";
        cout << "\n==============================";
        cout << "\n1. Create List";
        cout << "\n2. Insert Node";
        cout << "\n3. Delete Node";
        cout << "\n4. Display List";
        cout << "\n5. Exit";
        cout << "\nEnter Choice : ";

        cin >> choice;


        switch (choice)
        {
            case 1:

                list.createList();

                break;


            case 2:

                cout << "\nEnter value to insert : ";
                cin >> value;

                list.insertEnd(value);

                cout << "\nNode Inserted.";

                break;


            case 3:

                cout << "\nEnter value to delete : ";
                cin >> value;

                list.deleteNode(value);

                break;


            case 4:

                list.display();

                break;


            case 5:

                cout << "\nProgram Ended.";

                break;


            default:

                cout << "\nInvalid Choice.";
        }

    } while (choice != 5);


    return 0;
}