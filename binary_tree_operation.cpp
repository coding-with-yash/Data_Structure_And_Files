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
        root=NULL;
    }
    void create();
    void insert(node *,node *);
    
    void display();
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    
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
        int choice2;
        
        cout<<"\n Select Traverse "<<endl;
        cout<<"1. IN-Order Tarverser"<<endl;
        cout<<"2. Pre-Order Tarverser"<<endl;
        cout<<"3. Post-Order Tarverser"<<endl;

        cout<<"Enter the Choice = ";
        cin>>choice2;

        switch(choice2)
        {
            case 1:
                 cout<<"\n IN-Order Tree is = ";
                 inorder(root);
                break;
            case 2:
                 cout<<"\n Pre-Order Tree is = ";
                 preorder(root);
                break;
            case 3:
                 cout<<"\n Post-Order Tree is = ";
                 postorder(root);
                break;
            default:
            cout<<"Wrong Traverser "<<endl;
        }
       
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

// Display PRE-ORDER Traverser
void btree::preorder(node *ptr)
{
    if(ptr!=NULL)
    {
        cout<<"  "<<ptr->data<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

// Display POST-ORDER Traverser
void btree::postorder(node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<"  "<<ptr->data<<"  ";
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
        if((temp->left==NULL) && (temp->right==NULL))
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
     btree b;
     
    int ch,ans;
    char conti;

   cout<<"********* Perform Tree Operation ********* "<<endl;
    do
    {
        cout<<"\t 1. Insert Tree"<<endl;
        cout<<"\t 2. Display Tree"<<endl;
        cout<<"\t 3. Display Leaf Node"<<endl;
        cout<<"\t 4. Find Longest Path (Depth)"<<endl;
        cout<<"Enter the Choice= ";
        cin>>ch;
    
    
        switch(ch)
        {
            case 1:
                do{
                    b.create();
                    cout<<"Do You Want to add More Elements in Tree? (Press 1) => ";
                    cin>>ans;
                  }while(ans==1);
                break;
                
            case 2:
                b.display();
                break;
            case 3:
                b.leaf();
                break;
            case 4:
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
