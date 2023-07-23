#include<iostream>
using namespace std;
int main()
{
    int arr[20]={-1,70,55,66,40,50,60,65,35},elements=9;
    cout<<"Given Array :\n";
    for(int i=1;i<elements;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n Its Binary Representation : \n";
    for(int i=0;i<elements;i++)
    {
        //for root node
        if(i==0)
        {
            cout<<"\t"<<arr[1]<<endl;
        }
        else 
        {
            
            int leftChild=2*i;
            int rightChild=2*i+1;
            if(leftChild<elements)
            cout<<"i = "<<i<<","<<arr[leftChild]<<"\t";
            if(rightChild<elements)
            cout<<arr[rightChild]<<'\t'<<endl;
        }
    }
}