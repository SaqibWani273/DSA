#include<iostream>
using namespace std;
int front=1;
int rear=8;
int const heapSize=15;
int maxHeap[heapSize]={-1,90,80,40,30,70,35,5,25};
void insert(int prio)
{
    if(rear==heapSize)
    {
        cout<<"Queue is Full already"<<endl;
        return;
    }
    if(front==-1)
    {
        //i.e. if queue is empty
        front=0;
        
    }
    if(rear==-1)
    {
        maxHeap[++rear]=prio;
        return;
    }
    maxHeap[++rear]=prio;
    int newIndex=rear;
    int parentIndex=rear/2;
    
    while(maxHeap[parentIndex]<maxHeap[newIndex]&&newIndex!=front)
    {
        swap(maxHeap[parentIndex],maxHeap[newIndex]);
        newIndex=parentIndex;
        parentIndex/=2;
    }

}
int Deque()
{
    if(front==-1||front>rear)
    {
        cout<<"Queue underflow(empty)"<<endl;
        return -1;
    }
    int frontElement=maxHeap[front];
    maxHeap[front]=maxHeap[rear];
    rear--;
    int index=front;
    while(index<=rear)
    {
        int leftChild=index*2;
        int rightChild=index*2+1;
        //initially set leftchild as larger child
        int largerChild=leftChild;
        //if left child exits
        if(leftChild<=rear)
        {
            //if right exists and is greater than its left
            if(rightChild<=rear&&maxHeap[rightChild]>maxHeap[leftChild])
            {
                largerChild=rightChild;
            }
            //if one of its child is larger 
            if(maxHeap[largerChild]>maxHeap[index])
            {
                swap(maxHeap[largerChild],maxHeap[index]);
                index=largerChild;
            }
            //if none of its child is larger
            else{
                break;
            }
        }
        //=> we are at leaf node with no further child
        else{
                break;
        }
    }
    return frontElement;
}
void display()
{
    if(front==-1||front>rear)
    {
        cout<<"Queue underflow(empty)"<<endl;
        return ;
    }
    cout<<"Displaying queue : "<<endl;
    for(int i=front;i<=rear;i++)
    {
        cout<<maxHeap[i]<<" ";
    }
}
int main()
{
    int choice,data,deleted;
    
    do{
cout<<"enter choice : "<<endl<<
"1.  ENQUE"<<endl<<
"2.  DEQUE"<<endl<<
"3.  Display Queue"<<endl<<
"4.  Exit"<<endl;
cin>>choice;
switch(choice)
{
    case 1:
    cout<<"enter data : "<<endl;
    cin>>data;
    insert(data);
    break;
    case 2:
   deleted=  Deque();
 cout<<"Deleted element = "<<deleted<<endl;
    break;
    case 3:
    display();
    break;
    case 4:
    break;

}
    }while(choice!=4);
}
