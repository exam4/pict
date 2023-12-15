#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Node 
{#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Node 
{
	public:
	    int data ;
	    Node *left, *right;
	    
};

//class for functions of Binary Search Tree
class BST
{
	public:
		Node* root;
        //function to create a new node
		Node* newnode(int val)
		{
		    Node *temp = new Node;
		    temp->left = temp->right = NULL;
		    temp->data = val;
		    return temp;
		}

		//function to insert node into BST
		Node* Insert(Node* root , int data)
		{
		    if(!root)
		    {
		        Node* temp ;
		        temp=newnode(data) ;
		        return temp ;
		    }
		    if(data > root->data)
		    {
		        root->right = Insert(root->right , data) ;
		    }
		    else if(data < root->data)
		    {
		        root->left = Insert(root->left , data) ;
		    }
		    return root ;
		}
		
        //function to perfrom inorder traversal
		void Inorder(Node* root)
		{
		    if(!root)
		    {
		        return ;
		    }
		    Inorder(root->left);
		    cout << root->data << " " ;
		    Inorder(root->right) ;
		}
		
        //function to perfrom preorder traversal
		void Preorder(Node* root)
		{
		    if(!root)
		    {
		        return ;
		    }
		     cout << root->data << " " ;
}
	public:
	    int data ;
	    Node *left, *right;
	    
};

//class for functions of Binary Search Tree
class BST
{
	public:
		Node* root;
        //function to create a new node
		Node* newnode(int val)
		{
		    Node *temp = new Node;
		    temp->left = temp->right = NULL;
		    temp->data = val;
		    return temp;
		}

		//function to insert node into BST
		Node* Insert(Node* root , int data)
		{
		    if(!root)
		    {
		        Node* temp ;
		        temp=newnode(data) ;
		        return temp ;
		    }
		    if(data > root->data)
		    {
		        root->right = Insert(root->right , data) ;
		    }
		    else if(data < root->data)
		    {
		        root->left = Insert(root->left , data) ;
		    }
		    return root ;
		}
		
        //function to perfrom inorder traversal
		void Inorder(Node* root)
		{
		    if(!root)
		    {
		        return ;
		    }
		    Inorder(root->left);
		    cout << root->data << " " ;
		    Inorder(root->right) ;
		}
		
        //function to perfrom preorder traversal
		void Preorder(Node* root)
		{
		    if(!root)
		    {
		        return ;
		    }
		     cout << root->data << " " ;
		    Preorder(root->left);
		    Preorder(root->right) ;
		}
		
        //function to perfrom postorder traversal
		void Postorder(Node* root)
		{
		    if(!root)
		    {
		        return ;
		    }
		    Postorder(root->left);
		    Postorder(root->right) ;
		    cout << root->data << " " ;
		}
		
        //to perform search and return height
		int Search(Node* root, int data, int h)
		{
		    if(!root)
		    {
		        return 0 ;
		    }
		    if(data > root->data)
		    {
		        return Search(root->right , data , h + 1);
		    }
		    else if(data < root->data)
		    {
		        return Search(root->left , data , h + 1);
		    }
		    else
		    {
		        return h ;
		    }
		}
		
		void Display_LeafNodes(Node* root)
		{
		    if(!root->left && !root->right)
		    {
		        cout << root->data << " " ;
		        return ;
		    }
		    if(root->left)
		    {
		        Display_LeafNodes(root->left);
		    }
		    if(root->right)
		    {
		        Display_LeafNodes(root->right);
		    }
		}
		
		Node* Find_Min(Node* root)
		{
		    if(!root)
		    {
		        return NULL ;
		    }
		    if(root->left)
		    {
		        return Find_Min(root->left) ;
		    }
		    else
		    {
		        return root ;
		    }
		}
		
		Node* Find_Max(Node* root)
		{
		    if(!root)
		    {
		        return NULL ;
		    }
		    if(root->right)
		    {
		        return Find_Max(root->right) ;
		    }
		    else
		    {
		        return root ;
		    }
		}
		
        //function to delete node with a given value
		Node* Delete(Node* root , int data)
		{
		    Node* temp ;
		    if(!root)
		    {
		        cout << "Element NOT FOUND\n" ;
		        return NULL ;
		    }
		    else if(data < root->data)
		    {
		        root->left = Delete(root->left , data);
		    }
		    else if(data > root->data)
		    {
		        root->right = Delete(root->right , data) ;
		    }
		    else
		    {
		        if(root->left && root->right)
		        {
		            temp = Find_Min(root->right) ;
		            root->data = temp->data ;
		            root->right = Delete(root->right , temp->data) ;
		        }
		        else
		        {
		            temp = root ;
		            if(!root->left)
		            {
		                root = root->right ;
		            }
		            else if(!root->right)
		            {
		                root = root->left;
		            }
		            free(temp);
		        }
		        return root;
		    }
		}
		
        //function to calculate height of tree
		int level(Node *root)
		{
			if(root==NULL)
			{
				return 0;
			}
			else
			{
				if(level(root->right)>level(root->left))	
				{
					return (1+level(root->right));
				}
				else
				{
					return (1+level(root->left));
				}
			}
		}
		
        //to create mirror image of tree
		void mirror(Node* node)
		{
		    if (node == NULL)
		        return;
		    else 
			{
		        Node* temp;
		 
		        /* do the subtrees */
		        mirror(node->left);
		        mirror(node->right);
		 
		        /* swap the pointers in this node */
		        temp = node->left;
		        node->left = node->right;
		        node->right = temp;
		    }
		}
		
};

int main()
{
	BST obj;
	Node* root ;
	int choice,n,s=1;
	Node *bst = NULL ;
	while(true)
	{
		cout<<"\n1. Insert\n2. Display\n3. Search\n4. Display Leaf Nodes\n5. Delete\n6. Height of tree\n7. mirror image\n8. Exit\nEnter your choice : ";
		cin>>choice;
        cout<<endl;
		switch(choice)
		{
			case 1: 
					cout<<"Enter number element to be insert : ";
		            cin >> n ; 
		            cout << "Enter " << n << " elements :\n" ;
		            while(n -- )
		            {
		            	int input ;
		            	cin >> input ;
		                bst=obj.Insert(bst , input) ;
		            }
		            cout << "ELEMENTS ADDED" <<endl;
		            break;
		            
		    case 2:
					cout <<"\nInorder:" ;
            		obj.Inorder(bst);
            		cout <<"\nPreorder:" ;
            		obj.Preorder(bst);
            		cout <<"\nPostorder:" ;
            		obj.Postorder(bst);
            		cout<<endl;
            		break;
            case 3:
            		cout << "\nEnter element to be searched: " ;
			    	int input ;
		            cin >> input ;
		            int h ;
		            h = obj.Search(bst , input , 0) ;
		            if(h)
		            {
		                cout << "\nElement found at height: " << h <<endl;
		            }
		            else
		            {
		            	cout << "\nELEMENT NOT FOUND" ;
		            }
		            break;
		            
		    case 4:
		    		cout << "All leaf nodes of tree are: \n" ;
            		obj.Display_LeafNodes(bst) ;
            		break;
            		
            case 5:
            	cout << "\nEnter element to be deleted: " ;
	            int n ;
	            cin >> n ;
	            bst=obj.Delete(bst , n);
	            cout << "ELEMENT DELETED. Remaining elements are: \n" ;
	            obj.Inorder(bst) ;
	            break;
	            
	        case 6:cout<<"\nheight of tree: "<<obj.level(bst);
	            break;
	            
	        case 7:	obj.mirror(bst);
	            		cout <<"\nInorder:" ;
	            		obj.Inorder(bst);
	            		cout <<"\nPreorder:" ;
	            		obj.Preorder(bst);
	            		cout <<"\nPostorder:" ;
	            		obj.Postorder(bst);
	            		cout<<endl;
	            		break;
	        case 8: s=0;
	        		break;
	            	
            default: cout<<"Invalid choice";
		}
		if(s==0)
		{
			break;
		}
	}
 	return 0;
}
