#include<iostream>
using namespace std;
int front=1;
int rear=8;
int const heapSize=15;
int maxHeap[heapSize]={-1,70,50,60,40,35,25,55,30};
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
    int temp;
    while(maxHeap[parentIndex]<maxHeap[newIndex]&&newIndex!=front)
    {
        temp=maxHeap[parentIndex];
        maxHeap[parentIndex]=maxHeap[newIndex];
        maxHeap[newIndex]=temp;
        newIndex=parentIndex;
        parentIndex/=2;
    }

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
  //  deleted=  deque();
 // cout<<"Deleted element = "<<deleted<<endl;
    break;
    case 3:
    display();
    break;
    case 4:
    break;

}
    }while(choice!=4);
}
