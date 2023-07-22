#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    int const  m1=3,n1=2,m2=2,n2=4;
    int mat1[m1][n1]={
        {1,2},{2,4},{3,1}
        };
    int mat2[m2][n2]={
        {1,2,3,4},{4,1,1,2}
    };
    int resMat[m1][n2];
    cout<<"Matrix 1 :"<<endl;
     for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            cout<<mat1[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl<<"Matrix 2 :"<<endl;
     for(int i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cout<<mat2[i][j]<<" ";
        }cout<<endl;
    }
    //resiltant matrix has m1 rows and n2 columns
    for(int i=0;i<m1;i++)//m1 no.of rows of mat1
    {

        for(int k=0;k<n2;k++)//n2=no.of columns of mat2
        {
            for(int j=0;j<m2;j++)//this is for calcultion of the element
        {
            sum+=mat1[i][j]*mat2[j][k];
        }
        resMat[i][k]=sum;
        sum=0;
        }
        
    }
    cout<<endl<<"Displaying Result Matrix :"<<endl;
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cout<<resMat[i][j]<<" ";
        }cout<<endl;
    }

}