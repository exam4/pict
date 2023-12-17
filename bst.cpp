#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

struct Node
{
     int data;
     Node* lc;
     Node* rc;
};
class mybst
{
      private: Node* root;
      public: void insert(int x);
              void inorder(Node* c);
              Node* getroot();
              bool search();
              void preorder(Node* c);
              void postorder(Node* c);
              int height(Node* c);
              void deletenode();
              void mirrorimage(Node *c);
              void copytree(Node* c,Node* *tree2);
              void leafnodes(Node* c);

      mybst()
      {
         root=NULL;
      }
};
void mybst::insert(int x)
{
    if(root==NULL)
    {
      Node* t=  new Node();
      t->data= x;
      t->lc=NULL;
      t->rc=NULL;
      root=t;
    }
    else
    {
      Node* p=root;
      Node* q=root;
      while(q!=NULL && p->data!=x)
      {
          p=q;
          if(x<p->data)
          {
            q=p->lc;
          }
          else
          {
            q=p->rc;

          }

      }
      if(p->data==x)
      {
        cout<<"duplicate element not allowed"<<endl;
      }
      if(x<p->data)
      {
        Node* t=  new Node();
        t->data= x;
        t->lc=NULL;
        t->rc=NULL;
        p->lc=t;
      }
      else
      {
        Node* t=  new Node();
        t->data= x;
        t->lc=NULL;
        t->rc=NULL;
        p->rc=t;
      }


    }
}
void mybst::copytree(Node* c,Node**tree2)
{

   if(c==NULL)
   {
      *tree2=NULL;
   }
   else
   {
     *tree2 = new Node();
     (*tree2)->data=c->data;
     copytree(c->lc,&((*tree2)->lc));
     copytree(c->rc,&((*tree2)->rc));

   }



}

void mybst::inorder(Node* c)
{

   if(c!=NULL)
   {

      inorder(c->lc);
      cout<<c->data<<" ";
      inorder(c->rc);

   }

}
void mybst::preorder(Node* c)
{

   if(c!=NULL)
   {

      cout<<c->data<<" ";
      preorder(c->lc);
      preorder(c->rc);

   }

}
void mybst::postorder(Node* c)
{

   if(c!=NULL)
   {

      postorder(c->lc);
      postorder(c->rc);
      cout<<c->data<<" ";

   }

}
Node* mybst::getroot()
{
   return root;
}
void mybst::mirrorimage(Node* c)
{
    if(c!=NULL)
    {
        Node* temp = c->rc;
        c->rc=c->lc;
        c->lc=temp;

        mirrorimage(c->lc);
        mirrorimage(c->rc);
    }

}

bool mybst::search()
{
   cout<<"enter element to be searched: "<<endl;
   int x;
   cin>>x;
   Node* t = root;
   while(t!=NULL)
   {

     if(t->data == x)
     {
       return true;
     }
     else
     {
       if(x<t->data)
       {
         t=t->lc;
       }
       else
       {
         t=t->rc;
       }
     }

   }
   return false;

}
int mybst::height(Node* c)
{
  if(c==NULL)return -1;
  else
  {
    return 1+ max(height(c->lc),height(c->rc));
  }
}
void mybst::leafnodes(Node* c)
{
    if(c!=NULL)
    {
        leafnodes(c->rc);
        leafnodes(c->lc);
        if((c->lc==NULL) && (c->rc==NULL))
        {
            cout<<c->data<<" ";
        }
    }

}
void mybst::deletenode()
{
    cout<<"Enter Element to be deleted"<<endl;
    int x;
    cin>>x;
    Node* temp = root;
    Node* fl = root;
    while(temp->data!=x)
    {
        fl=temp;
        if(x<temp->data)
        {
            temp=temp->lc;
        }
        else
        {
            temp=temp->rc;
        }
    }
    if(temp==NULL)
    {
        cout<<"data not found"<<endl;
        return;
    }
    if((temp->lc==NULL) && (temp->rc==NULL))
    {
        if(fl->lc==temp)
        {
            fl->lc=NULL;
        }
        else
        {
            fl->rc=NULL;
        }
    }
    else if(temp->rc==NULL)
    {
        if(fl->rc==temp)
        {
            fl->rc=temp->lc;
        }
        else
        {
            fl->lc=temp->lc;
        }
    }
    else if(temp->lc==NULL)
    {
        if(fl->lc==temp)
        {
            fl->lc=temp->rc;
        }
        else
        {
            fl->rc=temp->rc;
        }
    }
    else
    {
        fl=temp;
        Node* flw = temp;
        flw=temp->lc;
        while((flw->rc)!=NULL)
        {
            fl=flw;
            flw=flw->rc;
        }
        temp->data=flw->data;        
        fl->rc=flw->lc;
    }
}
int main()
{
   mybst b;
   char ch;
   cout<<"enter no. of elements to be inserted"<<endl;
   int n;cin>>n;
   for(int i=0;i<n;i++)
   {
      cout<<"enter element: ";
      int x;cin>>x;
      b.insert(x);
   }
   do
   {
   cout<<"Enter \n1.Insert Element \n2.Display \n3.Find Height \n4.Search Element \n5.Delete Node \n6.Mirror Image \n7.Display leaf nodes \n8.Copy tree"<<endl;
   int choice;
   cin>>choice;
   switch(choice)
   {
     case 1:
     cout<<"enter no. of elements elements to be inserted"<<endl;
     int n;cin>>n;
   for(int i=0;i<n;i++)
   {
      cout<<"enter element: ";
      int x;cin>>x;
      b.insert(x);
   }
   break;

   case 2:
   cout<<"inorder expression: ";
   b.inorder(b.getroot());
   cout<<endl;
   cout<<"postorder expression: ";
   b.postorder(b.getroot());
   cout<<endl;
   cout<<"preorder expression: ";
   b.preorder(b.getroot());
   cout<<endl;
   break;

   case 3:
   cout<<"Height: ";
   cout<<b.height(b.getroot())<<endl;
   break;

   case 4:
   if(b.search())
   {
     cout<<"data found" <<endl;
   }
   else
   {
      cout<<"data not found"<<endl;
   }
   break;
   case 5:
    b.deletenode();
    cout<<"Node Deleted"<<endl;
    break;

   case 6:
    b.mirrorimage(b.getroot());
    break;

   case 7:
       b.leafnodes(b.getroot());
    cout<<endl;
    break;



   case 8:
       Node* t2 = new Node();
    b.copytree(b.getroot(),&t2);
    b.inorder(t2);
    cout<<endl;
     break;




   }
   cout<<"press Y or y to continue"<<endl;
   cin>>ch;

   }while(ch=='y' || ch=='Y');
}
