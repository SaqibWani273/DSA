#include<iostream>
using namespace std;
int main()
{
    int const row=2,col=3;
int zeros=0,mat[row][col]={
    {0,3,5},
    {0,0,0}
};
cout<<"Displaying & checking original matrix"<<endl;

for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        cout<<mat[i][j]<<" ";
        if(mat[i][j]==0)
        zeros++;
    }cout<<endl;
}
int const size=row*col;
if(zeros>size/2)
{
    
    cout<<"It is a Sparse Matrix"<<endl;
    int sparseMat[size/2][3];
    
    cout<<"Making Sparse Matrix"<<endl;
    int k=0;
    for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        if(mat[i][j]!=0){
        sparseMat[k][0]=i;
        sparseMat[k][1]=j;
        sparseMat[k++][2]=mat[i][j];
        }
        
    }
}
cout<<"Displaying Sparse Matrix"<<endl;
for(int i=0;i<size-zeros;i++)
{
    for(int j=0;j<3;j++)
    {
cout<<sparseMat[i][j];
    }cout<<endl;
}
}


    return 0;
}