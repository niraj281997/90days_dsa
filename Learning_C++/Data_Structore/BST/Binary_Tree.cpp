#include <iostream>
using namespace std;

#define INFINITE 1U // Infinite loop macro
enum {
    Add_node = 1,
    Delete_node,
    Print_node,
    Search_node,
} Operation;

typedef struct Binary_Tree {
    int val;
    struct Binary_Tree *left, *right;
} BT;

// Messages for user interaction
char epos[] = "\nEnter the operation: ";
char opr[] = "\n1. Add\n2. Print\n3. Search ";
char onum[] = "\nEnter the number: ";

// Function to create a new binary tree node
BT* create(int n) {
    BT* tra = new BT;
    tra->val = n;
    tra->left = tra->right = nullptr;
    return tra;
}

// Function to add a node to the binary tree
BT* f_add_BT(BT** head, int n) {
    if (*head == nullptr) {
        *head = create(n);
        return *head;
    }
    if (n < (*head)->val) {
        (*head)->left = f_add_BT(&((*head)->left), n);
    } else {
        (*head)->right = f_add_BT(&((*head)->right), n);
    }
    return *head;
}

// Function to print the binary tree (inorder traversal)
void f_print_BT(BT* head) {
    if (head == nullptr) {
        return;
    }
    f_print_BT(head->left);
    cout << head->val << " "; // Add space for better readability
    f_print_BT(head->right);
}


void f_Search(BT *head,int n )
{
    if(head==nullptr)
    {
        cerr<<"No  data present";
        return ;
    }
    else 
    {
        if(head->val==n)
            cerr<<"Found the node"<<endl;
        else if(n>head->val)
            f_Search(head->right,n);
        else 
        f_Search(head->left,n);

    }
    return;
}
// Main function
int main() {
    BT* head = nullptr;
    int choice; // Variable for operation selection
    int num;    // Variable for user input

    while (INFINITE) {
        // Display operations
        fputs(opr, stdout);
        fputs(epos, stdout);
        cin >> choice; // User selects operation

        switch (choice) {
        case Add_node:
            fputs(onum, stdout);
            cin >> num; // Take input for node value
            f_add_BT(&head, num);
            break;

        case Print_node:
            f_print_BT(head);
            cout << endl; // Add newline for better formatting
            break;
        case Search_node:
            fputs(onum, stdout);
            cin >> num; // Take input for node value
            f_Search(head,num);
            break;

        default:
            cout << "Invalid operation selected! Exiting program.\n";
            return 0; // Break the infinite loop and exit
        }
    }

    return 0;
}
