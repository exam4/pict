#include <iostream>
#include "stack.h"

using namespace std;

struct Root
{
    char exp;
    Root *lc;
    Root *rc;
};

class Conversion
{
private:
    string postfix;
    Root *root;

public:
    void inorderrec(Root *r);
    void postorderrec(Root *r);
    void preorderrec(Root *r);
    void inorder(Root *r);
    void postorder(Root *r);
    void preorder(Root *r);
    void etree();
    Root *getroot();

    Conversion()
    {
        cout << "Enter Postfix expression: ";
        cin >> postfix;
    }
};
      
void Conversion::etree()
{
    Stack<Root *> r;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isalpha(postfix[i]))
        {
            Root *temp = new Root();
            temp->exp = postfix[i];
            r.push(temp);
        }
        else
        {
            Root *temp = new Root();
            temp->exp = postfix[i];
            temp->rc = r.pop();
            temp->lc = r.pop();
            r.push(temp);
        }
    }
    root = r.peep();
}

Root *Conversion::getroot()
{
    return root;
}

void Conversion::inorderrec(Root *r)
{
    if (root == NULL)
    {
        cout << "Tree not created yet" << endl;
        return;
    }
    if (r != NULL)
    {

        inorderrec(r->lc);
        cout << r->exp;
        inorderrec(r->rc);
    }
}

void Conversion::postorderrec(Root *r)
{
    if (root == NULL)
    {
        cout << "Tree not created yet" << endl;
        return;
    }
    if (r != NULL)
    {

        postorderrec(r->lc);
        postorderrec(r->rc);
        cout << r->exp;
    }
}

void Conversion::preorderrec(Root *r)
{
    if (root == NULL)
    {
        cout << "Tree not created yet" << endl;
        return;
    }
    if (r != NULL)
    {

        cout << r->exp;
        preorderrec(r->lc);
        preorderrec(r->rc);
    }
}

void Conversion::inorder(Root *r)
{
    Stack<Root *> i;
    do
    {
        while (r != NULL)
        {
            i.push(r);
            r = r->lc;
        }
        if (!i.isEmpty())
        {
            Root *x = i.pop();
            cout << x->exp;
            r = x->rc;
        }

    } while ((r != NULL) || (!i.isEmpty()));

    cout << endl;
}

void Conversion::postorder(Root *r)
{
    if (r == NULL)
    {
        cout << "Tree not created yet" << endl;
        return;
    }
    Stack<Root *> rx;
    Stack<Root *> o;
    Root *temp = new Root();
    temp->exp = '$';
    o.push(temp);
    rx.push(temp);

    rx.push(r);

    while (rx.peep()->exp != '$')
    {
        Root *curr = rx.pop();
        o.push(curr);

        if (curr->lc)
        {
            rx.push(curr->lc);
        }
        if (curr->rc)
        {
            rx.push(curr->rc);
        }
    }
    while (o.peep()->exp != '$')
    {
        Root *temp = o.pop();
        cout << temp->exp;
    }
    cout << endl;
}
void Conversion::preorder(Root *r)
{
    if (r == NULL)
    {
        cout << "Tree not created yet" << endl;
        return;
    }
    Stack<Root *> rx;
    Stack<Root *> o;
    Root *temp = new Root();
    temp->exp = '$';
    o.push(temp);
    rx.push(temp);

    rx.push(r);

    while (rx.peep()->exp != '$')
    {
        Root *curr = rx.pop();
        cout << curr->exp;

        if (curr->rc)
        {
            rx.push(curr->rc);
        }
        if (curr->lc)
        {
            rx.push(curr->lc);
        }
    }
    cout << endl;
}
int main()
{
    Conversion t;
    t.etree();
    int rep = 0;
    do
    {
        cout << "What do you want to do? 1.Inorder 2.Postorder 3.Preorder" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Recurssive Inorder: ";
            t.inorderrec(t.getroot());
            cout << endl;
            cout << "Non Recurssive Inorder: ";
            t.inorder(t.getroot());
            break;
        case 2:
            cout << "Recurssive Postorder: ";
            t.postorderrec(t.getroot());
            cout << endl;
            cout << "Non Recurssive Postorder: ";
            t.postorder(t.getroot());
            break;
        case 3:
            cout << "Recurssive Preorder: ";
            t.preorderrec(t.getroot());
            cout << endl;
            cout << "Non Recurssive Preorder: ";
            t.preorder(t.getroot());
            break;
        }
        cout << "Do you want to continue? 1.Yes 2.No" << endl;
        cin >> rep;
    } while (rep == 1);
}
