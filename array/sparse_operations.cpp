#include<iostream>
using namespace std;
void addSparse(int[10][3],int[10][3],int);
void addSparse(int sparse1[10][3],int sparse2[10][3],
int nonZeros1,int nonZeros2)
{
    int resSparse[100][3],k=0;

for(int i=0;i<nonZeros1;i++)
{
for(int j=i;j<nonZeros2;j++)
{
    if(sparse1[i][0]!=sparse2[j][0])
    break;
    if(sparse1[i][1]<sparse2[j][1])
    {
        //from first sparse  to resSparse
        resSparse[k][0]=sparse1[i][0];
        resSparse[k][1]=sparse1[i][1];
        resSparse[k++][2]=sparse1[i][2];
    }
   else if(sparse1[i][1]==sparse2[j][1])
    {
        resSparse[k][0]=sparse1[i][0];
        resSparse[k][1]=sparse1[i][1];
        resSparse[k++][2]=sparse1[i][2]+sparse2[j][2];
    }
    else
    {
        //from second sparse  to resSparse
        resSparse[k][0]=sparse2[j][0];
        resSparse[k][1]=sparse2[j][1];
        resSparse[k++][2]=sparse2[j][2];
    }
    
}
}
cout<<"Resultant sparse matrix = "<<k<<endl;
for(int i=0;i<k;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<resSparse[i][j]<<" ";
    }cout<<endl;
}
}
int main()
{
    int const row=3,col=4,nonZeros1=4;
int mat1[row][col]={
    {0,3,5,0},
    {0,0,0,3},
    {1,0,0,0}
};
  int const nonZeros2=6;
int mat2[row][col]={
    {0,0,1,3},
    {4,0,0,3},
    {0,1,0,9}
};
int sparse1[nonZeros1][3];
int sparse2[nonZeros2][3];
  int k=0;
    for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        if(mat1[i][j]!=0){
        sparse1[k][0]=i;
        sparse1[k][1]=j;
        sparse1[k++][2]=mat1[i][j];
        }
        
    }
}
 k=0;
    for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        if(mat2[i][j]!=0){
        sparse2[k][0]=i;
        sparse2[k][1]=j;
        sparse2[k++][2]=mat2[i][j];
        }
        
    }
}
cout<<"Sparse Matrix 1 : "<<endl;
for(int i=0;i<nonZeros1;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<sparse1[i][j]<<" ";
    }cout<<endl;
}
cout<<"Sparse Matrix 2 : "<<endl;
for(int i=0;i<nonZeros2;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<sparse2[i][j]<<" ";
    }cout<<endl;
}
cout<<"Addition of sparse Matrices :"<<endl;
if(nonZeros1>nonZeros2)
{
    addSparse(sparse1,sparse2,nonZeros1,nonZeros2);
}
else{
    addSparse(sparse2,sparse1,nonZeros2,nonZeros1);
}

return 0;
}