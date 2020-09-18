#include<bits/stdc++.h>
using namespace std;

#define nl cout<<"\n";

int main()
{
    int n;
    cout<<"Longest Increasing Subsequence........\n\n";
    cout<<"Enter the length of array : ";
    cin>>n;

    vector<int> v(n);
    cout<<"Enter the space separated array integers : ";
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    //Solution of LIS

    vector<int> I(n+1);
    vector<int> L(n); 

    I[0]=-100;
    for(int j=1; j<n+1; j++)
    {
        I[j]=100000000;
    }
    vector<int>::iterator x;
    for(int i=0; i<n; i++)
    {
        
         x=lower_bound(I.begin(),I.end(),v[i]);
        
        I[x-I.begin()]=v[i];
        L[i]=x-I.begin();
    }
    for(int i=0; i<=n; i++)
    {
        cout<<I[i]<<" ";
    }
    nl;nl;
    
    for(int i=0; i<n; i++)
    {
        cout<<L[i]<<" ";
    }
    return 0;
}