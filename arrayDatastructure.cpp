#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Array
{
    int capacity;
    int lastindex;
    int *ptr;
    public:
    void createArray(int cap);
    void append(int data);
    void insert(int index,int data);
    int count();
    int getItem(int index);
    void del(int index);
    void edit(int index,int data);
    int search(int data);

};
int Array::search(int data)
{
    int i;
    for(i=0;i<=lastindex;i++)
        if(ptr[i]=data)
      return i;
      return -1;
    
}
void Array::edit(int index,int data)
{
   if(index<0||index>lastindex)
    {
        cout<<"Operation failed Invalid index";
    }
    else
    ptr[index]=data; 
}
void Array ::del(int index)
{
 if(index<0||index>lastindex)
    {
        cout<<"Operation failed Invalid index";
    }
    else
    {
        int i;
        for(i=index;i<lastindex;i++)
        ptr[i]=ptr[i+1];
        lastindex--;
        
    }
}
int Array :: getItem(int index)
{
    if(index<0||index>lastindex)
    {
        cout<<"Operation failed Invalid index";
    }
    else
    {
      return ptr[index];
    }
}
int Array :: count()
{
    return lastindex+1;
}
void Array :: createArray(int cap)
{
ptr=new int[cap];
capacity=cap;
lastindex=-1;
}
void Array ::append(int data)
{
    if(lastindex+1==capacity)
    {
        cout<<"Operation failed "<<endl;
    }
    else
    lastindex++;
    ptr[lastindex]=data;
}
void Array :: insert(int index, int data)
{
  if(index<0||index>lastindex+1)
  {
    cout<<"Operation failed Invalid index"<<endl;
  }
  else if(capacity==lastindex+1)
  {
   cout<<"Operation failed Invalid index"<<endl; 
  }
  else
  {
    int i;
    for(i=lastindex;i>=index;i--)
    ptr[i]=ptr[i+1];
    lastindex++;
    ptr[index]=data;
  }  
}

 int menu()
{
    int choice;
    cout<<"\n1. append";
    cout<<"\n2. insert";
    cout<<"\n3. del";
     cout<<"\n4. search";
      cout<<"\n5. edit";
       cout<<"\n6. exit";
    cout<<"\nEnter the choice";
    cin>>choice;
    return choice;
}
void viewArrayData(Array &arr)
{
int i;
cout<<endl;
for(i=0;i<arr.count();i++)
{
cout<<arr.getItem(i)<<" ";
}
}
int main()
{
    int index,data;
    Array arr;
    arr.createArray(5);
    while(true)
    {
        system("cls");
        cout<<"Total element in Array"<<arr.count();
        viewArrayData(arr);
        switch (menu())
        {
            case 1:
            cout<<"Enter data to append";
            cin>>data;
            arr.append(data);
            break;
            case 2:
            cout<<"Enter Index & data to insert in Array"<<endl;
            cin>>index>>data;
            arr.insert(index,data);
            break;
            case 3:
            cout<<"Enter index to delete";
            cin>>index;
            arr.del(index);
            break;
            case 4:
            cout<<"Enter data to search";
            cin>>data;
            arr.search(data);
            break;
             case 5:
             cout<<"Enter index and data to edit";
             cin>>index>>data;
            arr.edit(index,data);
            break;
             case 6:
            exit(0);
            break;
            default:
            cout<<"Invalid choice"<<endl;
        }
        getch();
    }
}

