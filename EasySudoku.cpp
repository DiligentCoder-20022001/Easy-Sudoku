#include<iostream>
using namespace std;
bool findUnassigned(int grid[9][9],int &row,int &col)
{
    int i,j;
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(grid[row][col]==0)
            return true;
        }
    }
    return false;
}
bool rowUsed(int grid[9][9],int num,int row)
{
    int i;
    for(i=0;i<9;i++)
    {
        if(grid[row][i]==num)
        return true;
    }
    return false;
}
bool colUsed(int grid[9][9],int num,int col)
{
    int i;
    for(i=0;i<9;i++)
    {
        if(grid[i][col]==num)
        return true;
    }
    return false;
}
bool boxUsed(int grid[9][9],int num,int row,int col)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grid[i+row][j+col]==num)
            return true;
        }
    }
    return false;
}
bool isSafe(int grid[9][9],int row,int col,int num)
{
    if(!rowUsed(grid,num,row) && !colUsed(grid,num,col) && !boxUsed(grid,num,row-(row%3),col-(col%3)))
    return true;
    else
    return false;
}
bool solve(int grid[9][9])
{
    int i,j;
    if(!findUnassigned(grid,i,j))
    return true;
    for(int num=1;num<=9;num++)
    {
        if(isSafe(grid,i,j,num))
        {
            grid[i][j]=num;
            if(solve(grid))
            return true;
            grid[i][j]=0;
        }
    }
    return false;
}
void print(int grid[9][9])
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int grid[9][9];
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            cin>>grid[i][j];
        }
        if(solve(grid)==true)
        {
            print(grid);
        }
        else
        cout<<"-1";
        cout<<endl;
    }
}