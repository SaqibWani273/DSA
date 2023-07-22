#include<iostream>
using namespace std;
class PriorityQue{
    public:
    int priority;
    PriorityQue* next;
    char job;
    PriorityQue(char p,char job){
        this->job=job;
        this->priority=p;
        this->next=NULL;
    }
};
PriorityQue* head1=NULL;
PriorityQue* head2=NULL;
void insert(PriorityQue* head,int headNum,char job,int priority)
{
    auto newNode=new PriorityQue(priority,job);
    if(headNum==1&&head==NULL||newNode->priority<head->priority)
    {
            newNode->next=head1;
            head1=newNode;
            return;
    }
     else if(headNum==2&&head==NULL)
    {
        // head2=newNode;
        // return;
    }
    PriorityQue* ptr=head;
    while(ptr->next!=NULL&&ptr->next->priority<newNode->priority)
    {
        ptr=ptr->next;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
}
void display(PriorityQue* head)
{
    cout<<"Displaying Priority Queue linked list "<<endl;
    
    PriorityQue* ptr=head;
    while(ptr)
    {
        cout<<ptr->job<<" : "<<ptr->priority<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    int choice,headNum,priority;
    char job;
    cout<<"enter choice \n1.Insert\n2.Display\n3.Enque\n4.Dequeu\n5.Exit"<<endl;
    cin>>choice;
    while(choice!=5)
    {


        switch (choice)
    {
    case 1:
        //insert
        cout<<"enter head Number,Priority and Job of node"<<endl;
        cin>>headNum>>priority>>job;
        switch (headNum)
        {
        case 1:
            insert(head1,1,job,priority);
            break;
            case 2:
            insert(head2,2,job,priority);
            break;
        
        default:
            break;
        }
    break;
    case 2:
    int num;
    cout<<"enter head no.:"<<endl;
    cin>>num;
    switch (num)
    {
    case 1:
        display(head1);
        break;
    case 2:
    //display(head2);
        break;
    default:
        break;
    }
        break;
    case 3:
       // polyAdd(head1,head2);
        break;
    default:
        break;

    }
    cout<<"enter choice \n1.Insert\n2.Display\n3.Enque\n4.Deque\n5.Exit"<<endl;
    cin>>choice;
    }
 return 0;
    }
    
   
