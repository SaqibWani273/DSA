#include<iostream>
using namespace std;
int main()
{
    int arr[20]={-1,70,30,55,40,35,25,60,50},elements=9;
    int current,left,right,temp;;
    cout<<"Given Array :\n";
    for(int i=1;i<elements;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"Heapifying the binary tree... \n";
    for(int i=1;i<elements;i++)
    {
        current=i;
        left=i*2;
        right=i*2+1;
        //check for left sub-tree
        while(left<elements&&arr[current]<arr[left])
        {
            current=left;
            left*=2;
            
        }
        //swap 
        temp=arr[i];
        arr[i]=arr[current];
        arr[current]=temp;
        //check for right sub-tree
        current=i;
        while(right<elements&&arr[current]<arr[right])
        {
            current=right;
            right*=2+1;
        }
        //swap 
        temp=arr[i];
        arr[i]=arr[current];
        arr[current]=temp;
        
    }
cout<<"Max Heap Array :\n";
    for(int i=1;i<elements;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}