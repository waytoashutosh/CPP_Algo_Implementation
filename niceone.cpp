https://codeforces.com/problemset/problem/1336/B
#include<bits/stdc++.h>
using namespace std;
#define nl cout<<"\n";
#define ll long long int
ll sq(ll x,int y)
{
    return (ll)x*x;
}
int getClosest(int val1, int val2, int target) 
{ 
    if (target - val1 >= val2 - target) 
        return val2; 
    else
        return val1; 
}
int findClosest(vector<int>& arr, int n, int target) 
{ 
    // Corner cases 
    if (target <= arr[0]) 
        return arr[0]; 
    if (target >= arr[n - 1]) 
        return arr[n - 1]; 
  
    int i = 0, j = n-1, mid = 0; 
    while (i < j) { 
        mid = i+(j-i)/2;
  
        if (arr[mid] == target) 
            return arr[mid]; 
  
        if (target < arr[mid]) { 
  
            if (mid > 0 && target > arr[mid - 1]) 
                return getClosest(arr[mid - 1], 
                                  arr[mid], target); 
  
            j = mid; 
        } 
  
        else { 
            if (mid < n - 1 && target < arr[mid + 1]) 
                return getClosest(arr[mid], 
                                  arr[mid + 1], target); 
            
            i = mid + 1;  
        } 
    } 
  
    return arr[mid]; 
} 



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {

        int nr,ng,nb;
        

        cin>>nr>>ng>>nb;
        vector<int> r(nr);
        vector<int> g(ng);
        //vector<ll> g1;
        vector<int> b(nb);
        //vector<ll> b1;

        int temp;
        for(int i=0; i<nr; i++)
        {
            cin>>r[i];
            
        }
        
        for(int i=0; i<ng; i++)
        {
            cin>>g[i];
            
            
        }
        
        for(int i=0; i<nb; i++)
        {
            
            cin>>b[i];
            
        }
        
        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(),b.end());
     
        int x,y,z;
        ll ans1=sq(r[0]-g[0],2)+sq(g[0]-b[0],2)+sq(b[0]-r[0],2);
        ll ans2=sq(r[0]-g[0],2)+sq(g[0]-b[0],2)+sq(b[0]-r[0],2);
        ll ans3=sq(r[0]-g[0],2)+sq(g[0]-b[0],2)+sq(b[0]-r[0],2);
        //ll temp1,temp2,temp3,temp4;
        for(int i=0; i<nr; i++)
        {
            x=r[i];

            y=findClosest(g, ng, x);
                
            z=findClosest(b, nb, x);
            //cout<<x<<" "<<y<<" "<<z;nl;
            if(sq(x-y,2)+sq(y-z,2)+sq(z-x,2)<ans1)
            {
                ans1=sq(x-y,2)+sq(y-z,2)+sq(z-x,2);
            }

        }
        //cout<<ans1;nl;
        for(int i=0; i<ng; i++)
        {
            x=g[i];

            y=findClosest(r, nr, x);
                
            z=findClosest(b, nb, x);
            //cout<<x<<" "<<y<<" "<<z;nl;
            if(sq(x-y,2)+sq(y-z,2)+sq(z-x,2)<ans2)
            {
                ans2=sq(x-y,2)+sq(y-z,2)+sq(z-x,2);
               
            }

        }
        //cout<<ans2;nl;
        for(int i=0; i<nb; i++)
        {
            x=b[i];

            y=findClosest(r, nr, x);
                
            z=findClosest(g, ng, x);
            //cout<<x<<" "<<y<<" "<<z;nl;
            if(sq(x-y,2)+sq(y-z,2)+sq(z-x,2)<ans3)
            {
                ans3=sq(x-y,2)+sq(y-z,2)+sq(z-x,2);
               
            }

        }//cout<<ans3;nl;
        cout<<min({ans1,ans2,ans3});nl;
    }



    return 0;
}