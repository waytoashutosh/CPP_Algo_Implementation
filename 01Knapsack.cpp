#include<bits/stdc++.h>
using namespace std;

int KnapSack(int val[], int wt[], int n, int W) 
{ 
    
    int mat[2][W+1]; 
    memset(mat, 0, sizeof(mat)); 
  
    int i = 0; 
    while (i < n) 
    { 
        int j = 0; 
  
        if (i%2!=0) 
        { 
            while (++j <= W) 
            { 
                if (wt[i] <= j) 
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]], mat[0][j] ); 
                else           
                    mat[1][j] = mat[0][j]; 
            } 
  
        } 
  
        else
        { 
            while(++j <= W) 
            { 
                if (wt[i] <= j) 
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]], 
                                     mat[1][j]); 
                else
                    mat[0][j] = mat[1][j]; 
            } 
        } 
        i++; 
    } 
  
    return (n%2 != 0)? mat[0][W] : mat[1][W]; 
}
int main()
{
    //Space Ooptimized 0-1 Knapsack

     int n; 

     cout<<"Enter the number of items : ";
     cin>>n;

    int val[n], wt[n], W; 
    cout<<"Enter the item and corresponding wt: ";
     for(int i=0; i<n ; i++)
     {
         cin>>val[i]>>wt[i];
     }
     cout<<"\nEnter the max weight allowed : ";
     cin>>W;
    cout << KnapSack(val, wt, n, W) << endl;


    return 0;
}