#include <iostream>
using namespace std;

int size1 = 0;
int arr[10];

void insert(int value)
{
    size1++;
    int index = size1;
    arr[index] = value;
    while (index > 1)
    {
        int parent = index / 2;
        if (arr[index] > arr[parent])
        {
            int temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;
            index = parent;
        }
        else
        {
            return;
        }
    }
}
void swap_elements(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void deQueue()
{
    int deElement = arr[1];
    arr[1] = arr[size1];
    size1--;

    int index = 1;
    int n=0;
    while (index <= size1)
    {
        
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        cout<<"n = "<<n++;
        //if node has left and right child
        if (leftChild <= size1 && rightChild <= size1)
        {
            if (arr[index] < arr[leftChild] || arr[index] < arr[rightChild])
            {
                if (arr[leftChild] > arr[rightChild])
                {
                    swap_elements(arr[index],arr[leftChild]);
                    index = leftChild;
                }
                else
                {
                    swap_elements(arr[index],arr[rightChild]);
                    index = rightChild;
                }
            }
            else
            {
                break;
            }
        }
        //if node has only left child
        else if (leftChild <= size1 && arr[index] < arr[leftChild])
        {
            swap_elements(arr[index],arr[leftChild]);
            index = leftChild;
        }
        //if node has only right child
        else if (rightChild <= size1 && arr[index] < arr[rightChild])
        {
            swap_elements(arr[index],arr[rightChild]);
            index = rightChild;
        }
        //if queue ended
        else
        {
            break;
        }
    }
}

void display()
{
    for (int i = 1; i <= size1; i++)
    {
        cout << arr[i] << " -- ";
    }
    cout << endl;
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
  deQueue();
// cout<<"Deleted element = "<<deleted<<endl;
    break;
    case 3:
    display();
    break;
    case 4:
    break;

}
    }while(choice!=4);
    return 0;
}