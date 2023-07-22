#include<iostream>
using namespace std;
void arrInsertion(int,int,int[][10]);
void arrDeletion(int,int,int[][10]);
int main()
{
    int  m=3,n=2;
    int arr[10][10]={
        {1,2},
        {3,5},
        {6,11}
        };
     //   arrInsertion(m,n,arr);
        arrDeletion(m,n,arr);
        

}
void arrInsertion(int m,int n,int arr[][10])

{
 int i,j,element,temp;
         cout<<"given array = :"<<endl;
         for(i=0;i<m;i++)
         {
            for(j=0;j<n;j++)
            {
                cout<<arr[i][j]<<"  ";
            }cout<<endl;
         }
        cout<<"enter i and j position of element"<<endl;
        cin>>i>>j;
        cout<<"eneter element"<<endl;
        cin>>element;
        int y=j;
        for(int x=i;x<m;x++)
        {
          //  for(int y=j;y<n;y++)
          while(y<n)
            {
                temp=arr[x][y];
                arr[x][y]=element;
                element=temp;
                y++;
            }
            y=0;
        }
        arr[m][0]=element;
        for(int jjj=0;jjj<=m;jjj++)
        {
            for(int dd=0;dd<n;dd++)
            {
                cout<<arr[jjj][dd]<<" ";
            }cout<<endl;
        }
}
void arrDeletion(int m,int n,int arr[][10])
{
 int i,j,element,temp;
         cout<<"given array = :"<<endl;
         for(i=0;i<m;i++)
         {
            for(j=0;j<n;j++)
            {
                cout<<arr[i][j]<<"  ";
            }cout<<endl;
         }
        cout<<"enter i and j position of element to delete"<<endl;
        cin>>i>>j;
      
        int y=j;
        for(int x=i;x<m;x++)
        {
          //  for(int y=j;y<n;y++)
          while(y<n-1)
            {
                // temp=arr[x][y];
                arr[x][y]=arr[x][y+1];
              //  element=temp;
                y++;
            }
            arr[x][y]=arr[x+1][0];
            y=0;
        }
        
        for(int jjj=0;jjj<m;jjj++)
        {
            for(int dd=0;dd<n;dd++)
            {
                cout<<arr[jjj][dd]<<" ";
            }cout<<endl;
        }
}