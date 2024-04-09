/*
Program name: BalancedParentheses.cpp
Programmer: Tyler Davies
Date: 10-28-21
Version: 1.0
Description: This program contains a StringStack class which creates a dynamic stack which stores 
             the characters of a user's entered string. It contains a member function to determine
             whether the string entered has balanced parentheses.
*/

#include<iostream>
#include<string>
using namespace std;

//This class contains a dynamic stack to store the characters of a user's string. Each node holds a
//char and a pointer to the next node. The class also has a pointer to hold the top and first nodes.
class StringStack
{
private:
    struct StackNode
    {
        char value;
        StackNode *next;
    };
    StackNode *top, *first;    //Need to store first node's address to compare values with the top node.
public:
    StringStack();
    void push(char);
    void pop(char &);
    bool isEmpty() const;
    bool isBalancedParentheses() const;
    ~StringStack();
};

//The constructor prompts the user to enter a string. It then iterates through the string, storing
//each character in a new node using the push member function.
StringStack::StringStack()
{
    string temp;
    top = NULL;
    first = NULL;
    cout << "Enter a string with or without parentheses: " << endl;
    getline(cin, temp);

    for (unsigned int i = 0; i < (temp.size()); i++)    //String function size will return an unsigned integer.
        push(temp.at(i));
}

//This function dynamically creates a newNode and stores a character val in that node. If the stack is
//empty, the newNode is made the top node; otherwise, the newNode is pushed onto the top of the stack.
void StringStack::push(char val)
{
    StackNode *newNode;
    newNode = new StackNode;
    newNode->value = val;
    if (isEmpty())
    {
        top = newNode;
        first = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

//This function takes the top node's value and stores it into its parameter which is passed-by-reference.
//If the stack is empty, it will print a message for the user indicating that the stack is empty.
void StringStack::pop(char &val)
{
    StackNode *temp;
    if (isEmpty())
        cout << "Stack is empty." << endl;
    else
    {
        val = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

//This function checks if there is a top node. If there is, the stack is not empty; otherwise it is empty.
bool StringStack::isEmpty() const
{
    if (!top)
        return true;
    else
        return false;
}

/*
This function checks the character stored in the first node to make sure it is either a single or double
parentheses. If it is, it then checks if the character stored in the top node is the same. It will return
true only if both are parentheses of the same type; meaning the string entered contains balanced parentheses.
*/
bool StringStack::isBalancedParentheses() const
{
    if ((first->value == '\"') || (first->value == '\''))
    {
        if (first->value == top->value)
            return true;
        else
            return false;
    }
    else
        return false;
}

//The destructor traverses the stacked linked list, deleting each node.
StringStack::~StringStack()
{
    StackNode *nodePtr, *next;
    nodePtr = top;
    while (nodePtr != NULL)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
}

/*
The main function initializes a StringStack object; where the constructor asks the user to enter a
string. It then uses the object's isBalancedParentheses function to test that the string entered
contains balanced parentheses. Afterwhich, it prints a message indicating the results.
*/
int main()
{
    StringStack userString;

    if (userString.isBalancedParentheses())
        cout << "\nThe string contains balanced parentheses!" << endl;
    else
        cout << "\nThe string does not contain balanced parentheses!" << endl;
    
    exit(0);
}