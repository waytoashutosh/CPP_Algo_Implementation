#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define loop(i,n) for(i=0; i<n; i++)
#define ll long long int
#define llu unsigned long long int
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout<< #x << " = "<< x <<"\n"
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),e.end()
#define fitr(it,a) for(auto it = a.begin(); it!=a.end(); it++)
#define mod 1e9+7
#define print1dv(v) for(auto e: v) { cout<<e<<" ";} 
#define nl cout<<"\n"
typedef vector<int> vi;
typedef vector<long long int> vll;


struct segtree{

    int size;
    vector<long long> mins;
    
    void init(int n){
        size=1;
        while(size<n) size*=2;

        //now to make the mins vector bigger so that it can have the parent mins too 
        
        mins.assign(size*2,INT_MAX-1);
    }

    //here x = current node 
    //ans  e = element value to be assgined
    void set(int i, ll e,int x, int lx, int rx) //to recursively reach the leaf node update it and then update other values on backtracking
    {
        if(rx-lx==1)
        {
            mins[x] = e;
            return;
        }

        int mid = lx + (rx-lx)/2;

        if(i<mid)
        {
            set(i, e, 2*x+1, lx, mid); //to go left
        }
        else
        {
            set(i, e, 2*x+2, mid, rx); //to go right
        }
        mins[x]=min((int)mins[2*x + 1] ,(int)mins[2*x +2]);
        
    }

    void set(int i, ll e)   //using this method we should be able to create or upate the whole tree
    {
        set(i,e,0,0,size);
    }

    ll minim(int l, int r,int x ,int lx, int rx)
    {
        if(lx>=r || rx<=l)
        {
            return INT_MAX;
        }
        
        if(lx>=l && rx<=r )
        {
            return mins[x];
        }
        
        int mid = lx + (rx-lx)/2;

        ll s1 = minim(l,r,2*x+1,lx,mid); //to go in the left subtree
        ll s2 = minim(l,r,2*x+2,mid,rx); //to go in the right subtree
        return min(s1,s2);
    }
    ll minim(int l, int r)
    {
        return minim(l,r,0,0,size);
       
    }

};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
   
    int n, m;
    cin>>n>>m;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    //Now just initialize the segment tree.
    segtree st;
    st.init(n); //to initialize the tree with size of power of two

   //now we need to assign all the values to the tree
   for(int i=0; i<n;  i++)
   {
       st.set(i,v[i]);
   }


   //now solving the queries.
   //print1dv(st.mins);nl;
   int p,a,b;
   while(m--)
   {
       
       cin>>p;
        if(p==1)
        {
            cin>>a>>b;
            st.set(a-1,b);
            
        }
        else
        {
            cin>>a>>b;
            cout<<st.minim(a-1,b-1)<<endl;
        }
        
        
   }
   
   

   
    return 0;
}
