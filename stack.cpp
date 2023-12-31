// Header file

#include <iostream>
#ifndef STACK_H
#define STACK_H
using namespace std;

template <class T>
class Node{
    public:
    T data;
    Node <T>* next;
};

//class to perform operations of stack
template <class T>
class Stack{
    Node <T>* top;
    
    public:
    Stack();
    bool isEmpty();
    void push(T item);
    T pop();
    void display();
    T isTop();
    
    friend class Node<T>;
};

#endif // STACK_H




// Stack file

#include <iostream>
// #include "stack.h"
using namespace std;

template <class T>
Stack <T>::Stack()
{
    top = NULL;  //top initialised to null
}

//function to insert element 
template <class T>
void Stack<T>:: push(T item)
{
    Node<T> *newnode;
    newnode = new Node<T>;
    newnode -> data = item;
    newnode -> next = top;
    top = newnode;       //top updated to newnode
}

//function to delete element
template <class T>
T Stack<T>:: pop()
{
    T item;
    Node<T> *temp;
    if (isEmpty())
    {
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else
    {
        Node<T>* temp;
        temp = top;   //top pointer assigned to temp
        item = temp -> data;
        top = top -> next;  //top updated to next element in stack
        delete temp;  //element is deleted
        return item;
    }
}

//function to display elements of stack
template <class T>
void Stack<T>:: display()
{
        Node<T>* temp;
        temp = top;
        if (isEmpty())
        {
            cout<<"Stack is empty";
        }
        else
        {
            cout<<"Elements of stack are: "<<endl;
            while (temp != NULL)
            {
                cout<<temp -> data<<endl;
                temp = temp -> next;
            }
            cout<<endl;
        }
}

//to check if stack is empty
template <class T>
bool Stack<T>:: isEmpty()
{
    return (top == NULL);
}

//to get the value of top element of stack
template <class T>
T Stack<T>:: isTop()
{
    return (top -> data);
}




// Stack Implementation file

#include <iostream>
#include <string>
// #include "stack.h"
// #include "stack.cpp"  //include definition and functions of stack
using namespace std;

class expression{
    public:
    string infix_to_pre(string pre);
    string infix_to_post(string s);
    int precedence(char c);
    string reverse(string p);
    void eval_postfix(string s);
    void eval_prefix(string s);
};

//function to determine precedence of characters
int expression :: precedence(char c)
{
    if (c == '-' || c == '+'){
        return 1;
    }
    else if (c == '*' || c == '/'){
        return 2;
    }
    else if (c == '^'){
        return 3;
    }
    else{
        return 0;
    }       
}

//function to convert infix expression to postfix 
string expression :: infix_to_post(string s)
{
    Stack<char> st;
    string result;
  
    for (int i = 0; i < s.length(); i++) 
    {
        char c = s[i];
  
        //if character, add to result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }

        //if opening paranthesis, push into stack
        else if (c == '(')
        {
            st.push('(');
        }
        
        // If the scanned character is an ‘)’, pop and add to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') 
        {
            while (st.isTop() != '(') 
            {
                result += st.isTop();
                st.pop();
            }
            st.pop(); // pop opening paranthesis
        }
  
        // If an operator is scanned
        else 
        {
            // If the character is an operator, pop and add operators from the stack
            // to the result until an operator with lower or equal precedence is encountered.
            while (!st.isEmpty() && precedence(s[i]) <= precedence(st.isTop())) 
            {
                result += st.isTop();
                st.pop();
            }
            //push current operator into stack
            st.push(c);
        }
    }
  
    // Pop all the remaining elements from the stack
    while (!st.isEmpty()) 
    {
        result += st.isTop();
        st.pop();
    }
    
    return result;
}

//function to reverse the string
string expression :: reverse(string p){
    string rev = "";
    int len = p.length();
    for (int k = len - 1; k >= 0; k--) 
    { 
        if (p[k] == '(') 
        {
            rev += ')';
        } 
        else if (p[k] == ')') 
        {
            rev += '(';
        } 
        else
        {
            rev += p[k];
        }
    }
    return rev; 
}

//function to convert infix expression to prefix
string expression :: infix_to_pre(string pre)
{       
    string p;
    p = reverse(pre);   
    string convert = reverse(infix_to_post(p));
    return convert;
}

//function to evaluate postfix expression
void expression::eval_postfix(string s) {
    int a;
    int op1, op2;
    Stack<int> st;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
             // If the character is an operator, pop the top two operands from the stack
            op2 = st.isTop();
            st.pop();
            op1 = st.isTop();
            st.pop();
            // Perform the operation and push the result back onto the stack
            switch (s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
            }
        } else {
            // If it's an operand, convert the character to an integer and push it onto the stack.
            a = s[i] - '0';
            st.push(a);
        }
        i++;
    }
    cout << "Result: " << st.isTop() << endl;
}

//function to evaluate prefix expression
void expression::eval_prefix(string s) {
    int a;
    Stack<int> st;
    int i = s.length() - 1;
    while (i >= 0) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            // If the character is an operator, pop the top two operands from the stack
            int op1 = st.isTop();
            st.pop();
            int op2 = st.isTop();
            st.pop();
            // Perform the operation and push the result back onto the stack
            switch (s[i]) {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            }
        }
        else {
            // If it's an operand, convert the character to an integer and push it onto the stack.
            st.push(s[i] - '0');
        }
        i--;
    }
    cout << "Result: " << st.isTop() << endl;
}

int main()
{
    expression ex;
    int ch;
    string infix, prefix, postfix;
    do
    {    
        cout<<"\nMenu for operations"<<endl;
        cout<<"1. Infix to post-fix\n2. Infix to pre-fix\n3. Prefix evaluation\n4. Postfix evaluation\n5. Exit"<<endl;
        cout<<"Choose operation you want to perform: ";
        cin>>ch;
        
        switch(ch)
        {
            case 1: cout<<"\nEnter expression you want to convert: ";
                cin>>infix;
                cout<<"Converted string [POSTFIX]: "<<ex.infix_to_post(infix)<<endl;
                break;
                
            case 2: cout<<"\nEnter expression you want to convert: ";
                cin>>infix;
                cout << "Converted string [PREFIX]: " <<ex.infix_to_pre(infix)<<endl;
                break;

            case 3: 
                cout<<"\nEnter prefix expression: ";
                cin>>prefix;
                ex.eval_prefix(prefix);
                break;

            case 4:
                cout<<"\nEnter postfix expression: ";
                cin>>postfix;
                ex.eval_postfix(postfix);
                break; 
            
            case 5: break;
            
            default: cout<<"Enter valid option"<<endl;
        }
    }while(ch != 5 && ch<5 && ch>0 );
}
