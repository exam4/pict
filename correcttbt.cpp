#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *lc;
    Node *rc;
    int lt;
    int rt;
};

class tbt
{
private:
    Node *root = new Node();
    Node *head = new Node();

public:
    Node* makenode(int key);
    void insert(Node *head, Node *temp);
    void inorder(Node *head);
    void preorder(Node *head);
};


Node* tbt ::makenode(int key)
{

    Node *temp = new Node();
    temp -> data = key;
    temp->lc = temp->rc = NULL;
    temp->lt = temp->rt = 0;
    return temp;
}

void tbt ::insert(Node *root, Node *temp)
{
    if (root == NULL){
        temp = makenode(-999);
    }
    if (temp->data <= root->data)
    {
        if (root->lt == 0)
        {
            temp->lc = root->lc;
            temp->rc = root;
            root->lc = temp;
            root->lt = 1;
        }
        else
        {
            insert(root->lc, temp);
        }
    }
    else
    {
        if (root -> rt == 0){
            temp -> rc = root -> rc;
            temp -> lc = root;
            root -> rc = temp;
            root -> rt = 1;
        }
        else{
            insert (root -> rc, temp);
        }
    }
}

void tbt :: inorder(Node *head){
    Node *t = head -> lc;

    do{
        while (t -> lt == 1){
            t = t -> lc;
        }
        cout<<t -> data << " ";
        while (t->rt == 0){
            t = t -> rc;
            if (t == head){
                return;                
            }
            cout << t-> data << " ";
        }               
        t = t -> rc;
    }
    while (t!= head);
    cout << endl;
}

void tbt :: preorder(Node *head){
    Node *t = head -> lc;
    do{
        while (t -> lt != 0){
            cout<<t -> data<<" ";
            t = t -> lc;
        }
        cout<<t -> data<<" ";
        while (t -> rc == NULL || t -> rc -> lt == 1){
            t = t -> rc;
            if (t == head){
                return;
            }
        }
        t = t -> rc;
    } 
    while (t != head);  
    cout<<endl;  
}

int main(){
    tbt t;
    int option, ele, rootval, num;

    cout<<"Enter root value"<< endl;
    cin>>rootval;
    t.root = t.makenode(rootval);
    t.head->lc = t.root;
    t.root->lc = t.head;
    t.root->rc = t.head;
    cout<<"How many elements do you want to enter in tree?"<<endl;
    cin>>num;

    for (int i=1; i<=num; i++){
        Node *node = new Node();
        cout<<"Enter element "<<(i)<<"- ";
        cin>>ele;
        node = t.makenode(ele);
        t.insert(t.root, node);
    }

    do {
        cout<<"Enter traversal:\n1. INORDER TRAVERSAL\n2. PREORDER TRAVERSAL\n3. EXIT"<<endl;
        cin>>option;

        switch (option){
            case 1:
                 cout<<"----Inorder Traversal----"<<endl;
                 t.inorder(t.head);
                  break;

            case 2:
                 cout<<"----Preorder Traversal----"<<endl;
                 t.preorder(t.head);
                  break;    

            case 3:
                  break;    

            default:
                  cout<<"Enter valid input"<<endl;
        }

    }while(option != 3);

}
