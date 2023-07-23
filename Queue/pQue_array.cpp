#include<iostream>
using namespace std;
int const size1=10;
int myQueue[size1];
int front=-1,rear=-1;
//insert
void enque(int priority){
    
    if(rear==size1)
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
        myQueue[++rear]=priority;
        return;
    }
    rear++;
    int i;
    for( i=rear-1;i>=front;i--)
    {
        if(priority>myQueue[i])
        {
            myQueue[i+1]=priority;
            break;
        }
        myQueue[i+1]=myQueue[i];
    }
    if(i==front-1)
    {
        myQueue[front]=priority;
    }
    
}
int deque()
{
    
    if(front==-1||front>rear)
    {
        cout<<"Queue underflow(empty)"<<endl;
        return -1;
    }
    return myQueue[front++];
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
        cout<<myQueue[i]<<" ";
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