#include <iostream>
#include <stack>
using namespace std;


//-----------------------------------------------------
// Node class representing each node of the BST
//-----------------------------------------------------

class Node
{
public:

    int data;
    Node *left;
    Node *right;


    // Constructor to initialize a node

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};


//-----------------------------------------------------
// Binary Search Tree Class
//-----------------------------------------------------

class BST
{
private:

    Node *root;


    //-------------------------------------------------
    // Recursive function to insert a node
    //-------------------------------------------------

    Node* insert(Node *root, int value)
    {
        // If tree is empty, create first node

        if (root == NULL)
        {
            return new Node(value);
        }


        // Insert into left subtree

        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }


        // Insert into right subtree

        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }


        // Duplicate values are not allowed

        else
        {
            cout << "Duplicate value not inserted.\n";
        }


        return root;
    }


public:

    //-------------------------------------------------
    // Constructor
    //-------------------------------------------------

    BST()
    {
        root = NULL;
    }


    //-------------------------------------------------
    // Create BST
    //-------------------------------------------------

    void createBST()
    {
        int n, value;

        cout << "Enter number of nodes: ";
        cin >> n;

        cout << "Enter node values:\n";


        for (int i = 1; i <= n; i++)
        {
            cin >> value;

            root = insert(root, value);
        }
    }


    //-------------------------------------------------
    // Non-Recursive Inorder Traversal
    //-------------------------------------------------

    void inorderNonRecursive()
    {
        stack<Node*> S;

        Node *current = root;

        cout << "Non-Recursive Inorder Traversal: ";


        while (current != NULL || !S.empty())
        {
            // Move to leftmost node

            while (current != NULL)
            {
                S.push(current);

                current = current->left;
            }


            // Visit node

            current = S.top();

            S.pop();

            cout << current->data << " ";


            // Move to right subtree

            current = current->right;
        }


        cout << endl;
    }


    //-------------------------------------------------
    // Non-Recursive Preorder Traversal
    //-------------------------------------------------

    void preorderNonRecursive()
    {
        if (root == NULL)
        {
            return;
        }


        stack<Node*> S;

        S.push(root);

        cout << "Non-Recursive Preorder Traversal: ";


        while (!S.empty())
        {
            Node *current = S.top();

            S.pop();

            cout << current->data << " ";


            // Push right child first

            if (current->right != NULL)
                S.push(current->right);


            // Push left child next

            if (current->left != NULL)
                S.push(current->left);
        }


        cout << endl;
    }
};


//-----------------------------------------------------
// Main Function
//-----------------------------------------------------

int main()
{
    BST tree;


    // Create BST

    tree.createBST();


    // Display Non-Recursive Inorder Traversal

    tree.inorderNonRecursive();


    // Display Non-Recursive Preorder Traversal

    tree.preorderNonRecursive();


    return 0;
}