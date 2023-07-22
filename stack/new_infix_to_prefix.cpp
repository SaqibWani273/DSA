//rules:
/*
1. if operand add to postfix expression
2. if ( push to stack
3. if operator 
  i) and stack is empty or top == (  push to stack.
  ii) and its priority> priority of top ,push to stack
  iii) and its priority<priority of top,pop from stack to postfix and 
  repeat 3.
  iv)and its priority = priority of top 
       a)if associativity is left to right pop and repeat 3.
       b) else push to stack
4.if ) pop and add that to postfix till top!=( , also pop (
5.if infix expression ends and stack !empty pop and add to postfix
*/
#include<iostream>
using namespace std;
class stack{
    public:
    char data;
    stack* next;
    stack(char data,stack* next)
    {
        this->data=data;
        this->next=next;
    } 
};
stack* top1=NULL;
 void push(stack* top,int topNum,char data)
 {
    auto newNode=new stack(data,top);
    top1=newNode;
    
 }
 char pop()
 {
    if(top1!=NULL)
    {
        stack* ptr=top1;
        top1=top1->next;
        char top=ptr->data;
        delete(ptr);
        return top;
    }
    return ' ';
 }
 int getPrecedence(char ch)
 {
    switch (ch)
    {
    case '/':
    case '*':
        return 4;
    case '+':
    case '-':
        return 3;
    case '^':
        return 5;
    
    default:
        return 0;
    }
 }
//  bool rightAssoc(char op1)
//  {
//     return op1=='^';
//  }
 int main()
 {
    string infixExp,postfixExp="";
    cout<<"enter infix expression\n";
    cin>>infixExp;
    int last=infixExp.length()-1;
    for(int ch=last;ch>=0;ch--)
    {
        if(top1)
        {
            cout<<"top1 : "<<top1->data<<" , char = "<<infixExp[ch]<<endl;
        }

        
        if(infixExp[ch]==')')
        {
            push(top1,1,infixExp[ch]);
        }
        else if(infixExp[ch]=='+'||infixExp[ch]=='-'||
        infixExp[ch]=='*'||infixExp[ch]=='/'||infixExp[ch]=='^')
        {
             
            
             if(infixExp[ch]=='^')
            {
                  while(top1!=NULL&&top1->data!=')'&&
            getPrecedence(infixExp[ch])<=getPrecedence(top1->data))
            {
                postfixExp+=pop();
            }
            
            }
           else
           {
                 while(top1!=NULL&&top1->data!=')'&&
            getPrecedence(infixExp[ch])<getPrecedence(top1->data))
            {
                postfixExp+=pop();
            }
            
           }
           push(top1,1,infixExp[ch]);
           
           
        }
        else if(infixExp[ch]=='(')
        {
            while(top1!=NULL&&top1->data!=')')
            {
                postfixExp+=pop();
            }
            if(top1==NULL)
            {
                cout<<"Not a valid infix expression \n";
                break;
            }
            char dummy=pop();
        }
        //in case of an operand
        else
        {
            postfixExp+=infixExp[ch];
        }
    }
    while(top1!=NULL)
    {
        postfixExp+=pop();
    }
    cout<<"The prefix Expression : "<<endl;
    last=postfixExp.length()-1;
    for(int ch=last;ch>=0;ch--)
    {
        cout<<postfixExp[ch];
    }
    

    return 0;
 }
