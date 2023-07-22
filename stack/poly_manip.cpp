#include<iostream>
using namespace std;
class Node{
    public:
    int coeff;
    int exp;
    Node* next;
    Node(int coff,int exp,Node* next)
    {
        this->coeff=coff;
        this->exp=exp;
        this->next=next;
    }
};
Node* head1=NULL;
Node* head2=NULL;
Node* head3=NULL;
void insert(Node* head,int headNum,int coff,int exp)
{
    auto newNode=new Node(coff,exp,NULL);
    if(headNum==1&&head==NULL)
    {
            head1=newNode;
            return;
    }
     else if(headNum==2&&head==NULL)
    {
        head2=newNode;
        return;
    }
    else if(headNum==3&&head==NULL)
    {
        head3=newNode;
        return;
    }
    Node* ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
}
void display(Node* head)
{
    cout<<"Displaying linked list with head = "
    <<head->coeff<<"x^"<<head->exp<<endl;
    Node* ptr=head;
    while(ptr)
    {
        cout<<ptr->coeff<<"x^"<<ptr->exp<<"+";
        ptr=ptr->next;
    }
}
void  polyAdd(Node* temp1,Node* temp2){
    cout<<"Adding polynomials \n";
    Node* ptr1=temp1;Node* ptr2=temp2;
while(ptr1!=NULL && ptr2!=NULL)
{
 
   
if(ptr1->exp>ptr2->exp)
{
  
     insert(head3,3,ptr1->coeff,ptr1->exp);
     ptr1=ptr1->next;
}
else if(ptr1->exp==ptr2->exp)

{
    
    int coff=ptr1->coeff+ptr2->coeff;
    if(coff!=0)
    {
        insert(head3,3,coff,ptr1->exp);
    }
    ptr1=ptr1->next;
    ptr2=ptr2->next;
   
}
else{
     insert(head3,3,ptr2->coeff,ptr2->exp);
     ptr2=ptr2->next;
}
}
Node* head3Ptr=head3;
    while(head3Ptr->next)
    {

        head3Ptr=head3Ptr->next;
    }
if(ptr1)
{  
    head3Ptr->next=ptr1;
}
if(ptr2)
{
    head3Ptr->next=ptr2;

}

}


int main()
{
    int choice,coff,exp,headNum;
    cout<<"enter choice \n1.Insert\n2.Display\n3.Add Polynomials\n4.Exit"<<endl;
    cin>>choice;
    while(choice!=4){

        switch (choice)
    {
    case 1:
        //insert
        cout<<"enter head Number,coeff and exponent of x"<<endl;
        cin>>headNum>>coff>>exp;
        switch (headNum)
        {
        case 1:
            insert(head1,1,coff,exp);
            break;
            case 2:
            insert(head2,2,coff,exp);
            break;
            case 3:
            insert(head3,3,coff,exp);
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
    display(head2);
        break;
        case 3:
    display(head3);
        break;
    default:
        break;
    }
        break;
    case 3:
        polyAdd(head1,head2);
        break;
    default:
        break;

    }
    cout<<"enter choice \n1.Insert\n2.Display\n3.Add Polynomials\n4.Exit"<<endl;
    cin>>choice;
    }
    
    return 0;
}