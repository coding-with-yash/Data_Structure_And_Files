#include<iostream>
using namespace std;

struct node
{
    node *left;
    node *right;
    int data;

    node *root;
    node *nn;
};

class btree
{
    node *root,*nn,*temp,*parent;
    
    public:
    btree()
    {
        node *root=NULL;
    }
    void create();
    void insert(node *,node *);
    
    void display();
    void inorder(node *);
    
    void leaf();
    void display_leaves(node *);

    void longestPath();
    int depth(node *);
};

// Create Tree
void btree::create()
{
    nn=new node();
    nn->left=NULL;
    nn->right=NULL;

    cout<<"\t Enter the Tree Elements= ";
    cin>>nn->data;

    if(root==NULL)
    {
        root=nn;
        cout<<"\t Root Data Is ADDED"<<endl;
    }
    else
    {
        insert(root,nn);
    }
}

// Insert Elements In Tree 
void btree::insert(node *root,node *nn)
{
    char choice;
    cout<<"\t Where you want to insert the elements Right/Left= ";
    cin>>choice;
    
    if(choice=='r'|| choice=='R')
    {
        if(root->right == NULL)
        {
            root->right=nn;
            cout<<"\t Right Node is Connected"<<endl;
        }
        else
        {
            insert(root->right,nn);
        }
    }
    else
    {
        if(root->left == NULL)
        {
            root->left=nn;
            cout<<"\t Left Node is Connected"<<endl;
        }
        else
        {
            insert(root->left,nn);
        }
    }

}

// Display Trees
void btree::display()
{
    if(root==NULL)
    {
        cout<<"\n Tree is Empty..."<<endl;
    }
    else
    {
        cout<<"\n Tree is = "<<endl;
        inorder(root);
    }
}

// Display IN-ORDER Traverser
void btree::inorder(node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<"  "<<ptr->data<<"  ";
        inorder(ptr->right);
    }
}

//Call Leaves Function
void btree::leaf()
{
    display_leaves(root);
}

// Display Leaves
void btree::display_leaves(node *temp)
{
    if(root==NULL)
    {
        cout<<"\n Tree Is Empty"<<endl;
    }
    if(temp!=NULL)
    {
        if((root->left==NULL && root->right==NULL))
        {
            cout<<"  "<<temp->data;
        }
        else
        {
            display_leaves(temp->left);
            display_leaves(temp->right);
        }
    }

}

//LongestPath
void btree::longestPath()
{
    if(root==NULL)
    {
        cout<<"\n Tree is Empty"<<endl;
    }
    else
    {
        int ldepth = depth(root);
        int rdepth = depth(root);

        if(ldepth>rdepth)
        {
            cout<<"\n The Depth of Tree is = "<<ldepth;
        }
        else
        {
            cout<<"\n The Depth of Tree is = "<<rdepth;
        }
    }
}

// Checking Depth of Tree
int btree::depth(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int ldepth = depth(root->left);
        int rdepth = depth(root->right);

        if(ldepth>rdepth)
        {
            return(ldepth+1);
        }
        else
        {
            return(rdepth+1);
        }
    }
}

// Main Function 
int main()
{
    int ch;
    char conti;

    btree b;

    node *t;

   cout<<"********* Perform Tree Operation ********* "<<endl;
    do
    {
        cout<<"\t 1. Create Tree"<<endl;
        cout<<"\t 2. Display Tree"<<endl;
        cout<<"\t 3. Display Leaf"<<endl;
        cout<<"\t 4. Find Longest Path"<<endl;
        cout<<"Enter the Choice= ";
        cin>>ch;
    
    
        switch(ch)
        {
            case 1:
                t = new node();
                b.create();
                break;
                
            case 2:
                t = new node();
                b.display();
                break;
            case 3:
                t = new node();
                b.leaf();
                break;
            case 4:
                t = new node();
                b.longestPath();
                break;
            default:
                cout<<"Wrong Choice"<<endl;
        }
        cout<<"\n Do You Want to Continues= (Y/N)= ";
        cin>>conti;
    } while (conti == 'Y' || conti == 'y');
   

return 0;
}