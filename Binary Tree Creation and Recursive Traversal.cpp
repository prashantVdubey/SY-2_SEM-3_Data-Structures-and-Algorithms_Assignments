#include <iostream>
using namespace std;


//---------------------------------------------------
// Step 1 : Define Tree Node
//---------------------------------------------------

struct Node
{
    int data;       // Stores data
    Node *left;     // Pointer to left child
    Node *right;    // Pointer to right child
};


//---------------------------------------------------
// Step 2 : Create BinaryTree Class
//---------------------------------------------------

class BinaryTree    // class classname
{
public:

    Node *root;     // Root node of the tree


    //---------------------------------------------------
    // Constructor
    //---------------------------------------------------

    BinaryTree()
    {
        root = NULL;
    }


    //---------------------------------------------------
    // Recursive Function to Create Tree
    //---------------------------------------------------

    Node* createTree()
    {
        int value;

        cout << "\nEnter node value (-1 for No Node): ";
        cin >> value;


        // Base Condition

        if (value == -1)
            return NULL;


        // Create New Node

        Node *newNode = new Node;

        newNode->data = value;


        cout << "Enter Left Child of " << value;
        newNode->left = createTree();


        cout << "Enter Right Child of " << value;
        newNode->right = createTree();


        return newNode;
    }


    //---------------------------------------------------
    // Function to Call Tree Creation
    //---------------------------------------------------

    void buildTree()
    {
        cout << "\nCreate Binary Tree\n";

        root = createTree();
    }


    //---------------------------------------------------
    // Recursive Inorder Traversal
    // Left -> Root -> Right
    //---------------------------------------------------

    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);

        cout << temp->data << " ";

        inorder(temp->right);
    }


    //---------------------------------------------------
    // Recursive Preorder Traversal
    // Root -> Left -> Right
    //---------------------------------------------------

    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";

        preorder(temp->left);

        preorder(temp->right);
    }


    //---------------------------------------------------
    // Recursive Postorder Traversal
    // Left -> Right -> Root
    //---------------------------------------------------

    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);

        postorder(temp->right);

        cout << temp->data << " ";
    }


    //---------------------------------------------------
    // Wrapper Functions
    //---------------------------------------------------

    void displayInorder()
    {
        cout << "\nInorder Traversal : ";

        inorder(root);

        cout << endl;
    }


    void displayPreorder()
    {
        cout << "\nPreorder Traversal : ";

        preorder(root);

        cout << endl;
    }


    void displayPostorder()
    {
        cout << "\nPostorder Traversal : ";

        postorder(root);

        cout << endl;
    }
};


//---------------------------------------------------
// Main Function
//---------------------------------------------------

int main()
{
    BinaryTree tree;    // classname objectname

    int choice;

    do
    {
        cout << "\n================================";
        cout << "\n       BINARY TREE MENU";
        cout << "\n================================";
        cout << "\n1. Create Binary Tree";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter Choice : ";

        cin >> choice;


        switch (choice)
        {
            case 1:

                tree.buildTree();

                break;


            case 2:

                tree.displayInorder();

                break;


            case 3:

                tree.displayPreorder();

                break;


            case 4:

                tree.displayPostorder();

                break;


            case 5:

                cout << "\nProgram Ended Successfully.";

                break;


            default:

                cout << "\nInvalid Choice.";
        }

    } while (choice != 5);


    return 0;
}