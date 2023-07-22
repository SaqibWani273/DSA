#include<iostream>
using namespace std;
#include <algorithm> 
class stack{
public:
char data;
stack* next;
stack(char _data, stack* _next) {
    data = _data;
    next = _next;
}
stack(){}
};
stack *top=nullptr;

void push(char _data) {
    stack* newNode = new stack(_data, top);
    top = newNode;
}
char pop(){
    if(top==nullptr)
{
return ' ';
}
char data =top->data;
stack* temp=top;
top=top->next;
delete temp;
return data;
}
int isEmpty(){
    return top==nullptr;
}
void displayStack() {
    stack* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << std::endl;
}
int priority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}


int main()
{
string exp;
string prefixExp;
cout<<"enter the infix expression for conversioin to prefix"<<endl;
cin>>exp;
reverse(exp.begin(),exp.end());
cout<<exp<<endl;
// Pushing elements to the stack
    for (char c : exp) {
        
        if(c==')')
        {
            push(c);
        }
        else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        {
if(top==nullptr||top->data==')')
{
    push(c);

}
else if(c=='^')
{
    push(c);
}
else{
    cout<<"iinside else of operators"<<endl;
    while(!isEmpty()&&priority(top->data)>priority(c))
    { 
        cout<<"inside while"<<endl;
prefixExp+=pop();
    }
    cout<<"outside while"<<endl;
    push(c);
}
        }
        else if(c=='(')
        {
          char ch;  
while(top->data!=')')
{
 
prefixExp+=pop();
}
ch=pop();
        }
        else{
            cout<<"inside else"<<endl;
            //=> c is an operand
            prefixExp+=c;
        }
        if(!isEmpty())
        cout<<"top = "<<top->data<<endl;
    }
//add remaining character of stack to prefix expression
while(!isEmpty())
{
    prefixExp+=pop();
}
   reverse(prefixExp.begin(),prefixExp.end());
    std::cout << "prefix expression  "<<prefixExp;
    ;

}


