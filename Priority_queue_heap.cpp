#include<iostream>
using namespace std;
int H[10];
int size=-1;
int parent(int i)
{
 return (i-1)/2;
}
int leftchild(int i)
{
 return((2*i)+1);
}
int rightchild(int i)
{
 return((2*i)+2);
}
void shiftup(int i)
{
 while(i>0 && H[parent(i)]<H[i])
 {
  swap(H[parent(i)],H[i]);
  i=parent(i);
 }
}
void shiftdown(int i)
{
 int maxindex=i;
 int l=leftchild(i);
 if(l<=size && H[i]>H[maxindex])
 {
  maxindex=1;

 }
 int r=rightchild(i);
 if(l<=size && H[i]>H[maxindex])
 {
  maxindex=r;
 }
 if(i!=maxindex)
 {
  swap(H[i],H[maxindex]);
  shiftdown(maxindex);
 }
}
void insert(int p)
{
 size=size+1;
 H[size]=p;
 shiftup(size);
}
int extractmax()
{
 int result=H[0];
 H[0]=H[size];
 size=size-1;
 shiftdown(0);
 return result;
}
void changepriority(int i,int p)
{
 int oldp=H[i];
 H[i]=p;
 if(p>oldp)
 {
  shiftup(i);
 }
 else
 {
 shiftdown(i);
 }
}
int getmax()
{
 return H[0];
}
void remove(int i)
{
 H[i]=getmax()+1;
 shiftup(i);
 extractmax();
}
int main()
{
 int n,a[20];

 cout<<"\n How Many Elements Do you want to insert => ";
 cin>>n;
 
 cout<<"\n Enter the Elements: ";
 for(int i=0; i<n; i++)
 {
  cin>>a[i];
 }

  for(int i=0; i<n; i++)
 {
  insert(a[i]);
 }

// insert(45);
// insert(20);
// insert(14);
// insert(12);
// insert(31);
// insert(7);
// insert(11);
// insert(13);
// insert(7);

 int i=0;
 cout<<endl;

//Priority Queue
 cout<<"Priority Queue =";
 while(i<=size)
 {
  cout<<H[i]<<" ";
  i++;
 }
 cout<<"\n";
 cout<<endl;

//Minimum Priority
 cout<<"Node with maximum priority => "<<extractmax()<<"\n";
 
 cout<<endl;



//Maximum Priority
 cout<<"Priority queue after extracting maximum => ";
 int j=0;
 while(j<=size)
 {
  cout<<H[j]<<" ";
  j++;
 }
 cout<<"\n";
 cout<<endl;


// Change Priority 
 int change_index_priority,change_value_priority;

 cout<<"Enter the index for Changing Priority=> ";
 cin>>change_index_priority;

 cout<<"Enter the value for Changing Priority=> ";
 cin>>change_value_priority;


 //changepriority(2,49);   
 changepriority(change_index_priority,change_value_priority);

 cout<<"priority queue after priority change => ";
 int k=0;
 while(k<=size)
 {
  cout<<H[k]<<" ";
  k++;
 }

 cout<<"\n";
 cout<<endl;

//Remove Priority 

 int re;

 cout<<"Enter the Elements index you want to Remove=> ";
 cin>>re;

 remove(re);

 cout<<"priority queue after removing the element => ";
 int l=0;
 while(l<=size)
 {
  cout<<H[l]<<" ";
  l++;
 }
 cout<<endl;
 
 cout<<endl;
 return 0; 
}


//OUTPUT
//
//How many Elements You want to insert= 9
//
//Enter Priority Queue =45 31 14 13 20 7 11 12 7
//
//
//Node with maximum priority => 45
//
//Priority queue after extracting maximum => 7 31 14 13 20 7 11 12
//
//priority queue after priority change => 49 31 7 13 20 7 11 12
//
//priority queue after removing the element => 49 31 7 13 20 7 11 12
//
//














