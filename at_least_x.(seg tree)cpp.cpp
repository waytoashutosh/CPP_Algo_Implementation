#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define loop(i,n) for(i=0; i<n; i++)
#define ll long long int
#define deb(x) cout<< #x << " = "<< x <<"\n"
#define print1dv(v) for(auto e: v) { cout<<e<<" ";} 
#define nl cout<<"\n"

struct item
{
    int index, element;
};

struct segtree{

    int size;
    int X;
    vector<item> values;
    

    item NEUTRAL_ELEMENT = {INT_MAX, INT_MAX};

    item single(int e,int lx)
    {
        if(e>=X)
        {
            return {lx,e};
        }
        else
        {
            return {INT_MAX,e};
        }
        
    }

    void init(int n){
        size=1;
        while(size<n) size*=2;

        //now to make the values vector bigger so that it can have the parent values too 
        
        values.resize(size*2);
    }

    //to calculate values from the child elements we will need a function which returns one of the two items

    item merge(item a, item b)
    {
        if(a.element>=X && b.element>=X)
        {
            if(a.index<b.index)
            {
                return a;
            }
            else
            {
                return b;
            }
            
        }
        if(a.element>=X)
        {
            return a;
        }
        if(b.element>=X)
        {
            return b;
        }
        return NEUTRAL_ELEMENT;
    }

    //here x = current node 
    //ans  e = element value to be assgined
    void set(int i, ll e,int x, int lx, int rx) //to recursively reach the leaf node update it and then update other values on backtracking
    {
        if(rx-lx==1)
        {
            values[x] = single(e,lx);
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
        values[x]=merge(values[2*x + 1] ,values[2*x +2]);
        
    }

    void set(int i, ll e)   //using this method we should be able to create or upate the whole tree
    {
        set(i,e,0,0,size);
    }

    //even though the set method can be used to build the segment tree, we can use another build function.
    //using the set function it can be done in   O(n log(n))  but using the build function we can do this in O(n) time
    //since just one traversal of the tree is required.

    void build(vector<int>& v, int x, int lx, int rx)
    {
        if(rx-lx==1)
        {
            if(lx<(int)v.size())
            {
                values[x]=single(v[lx],lx);
            }
                
            
            return;
        }

        int mid = lx + (rx-lx)/2;
        build(v, 2*x+1, lx, mid);
        build(v, 2*x+2, mid, rx);

        values[x] = merge(values[2*x+1], values[2*x+2]);
        return;
    }
    void build(vector<int> &v)
    {
        build(v,0,0,size);
        return;
    }

    item calc(int l, int r,int x ,int lx, int rx)
    {
        if(lx>=r || rx<=l)
        {
            return NEUTRAL_ELEMENT;
        }
        
        if(lx>=l && rx<=r )
        {
            return values[x];
        }
        
        int mid = lx + (rx-lx)/2;

        item s1 = calc(l,r,2*x+1,lx,mid); //to go in the left subtree
        item s2 = calc(l,r,2*x+2,mid,rx); //to go in the right subtree
        return merge(s1,s2);
    }
    item calc(int l, int r)
    {
        return calc(l,r,0,0,size);
       
    }

    int find(x)
    {
        return values[0].index;
    }

};

   


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;

    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    segtree st;
    st.init(n);
    st.X=INT_MIN;
    st.build(v);

    

    int i,k,e,u;
    while(m--)
    {
        cin>>e;

        if(e==1)
        {
            cin>>i>>u;
            v[i]=u;
            
        }
        else
        {
            cin>>k;
            st.X=k;
            st.build(v);
            
            int ans = st.find();
            if(ans!=INT_MAX)
            {
                cout<<ans<<endl;
            }
            else cout<<-1<<endl;
        }
        
    }
 
    return 0;
}
