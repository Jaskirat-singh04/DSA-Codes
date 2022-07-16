#include<iostream>
using namespace std;
// function to search a element in the array linearly
int lsearch(int arr[],int key)
{
        for (int i = 0; i < 5; i++)
    {
        if (key==arr[i])
        return i;
    }
        return -1;
   
}
int main()
{
    int key;
    int a[]={1,2,3,5,11};
    cout<<"Enter the to be searched keu :";
    cin>>key;
    int pos=lsearch(a,key);
    if(pos==-1)
    cout<<"key not present ";
    else 
    cout<<"\nKey at "<<pos;
    
    
}