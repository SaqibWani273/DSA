#include<iostream>
using namespace std;
int const qSize=5;
int que[qSize];
int front=-1,rear=-1;
void enque(int data)
{
    if(front==0&&rear==qSize-1||front-rear==1)
    {
        cout<<"Circular Queue is FULL Already\n";
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    if(rear==qSize)
    {
        rear=0;
    }
    que[rear]=data;

}
int deque()
{
    if(front==-1)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    int data=que[front];
    if(front==rear)
        {
            //=> only one element is present in queue
            front=-1;
            rear=-1;
        }
    else
    {
        
        front++;
        cout<<"front = "<<front<<endl;
        //=> check if front now exceeds que capacity
        if(front==qSize)
        {
            front=0;
        }
    }
        return data;
}
void display()
{
    cout<<"Displaying Circular Queue\n";
    if(front==-1)
    {
        cout<<"Circular Queue is Empty\n";
        return;
    }
    //=> we've circularly added new elements to it
    if(front>rear)
    {
        for(int i=front;i<qSize;i++)
        {
            cout<<que[i]<<",";
        }
        for(int i=0;i<=rear;i++)
        {
            cout<<que[i]<<",";
        }
    }
    else
    {
        for(int i=front;i<=rear;i++)
    {
        cout<<que[i]<<",";
    }
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
    enque(data);
    break;
    case 2:
    deleted=  deque();
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