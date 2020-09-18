#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define loop(i,n) for(i=0; i<n; i++)
#define ll long long int
#define deb(x) cout<< #x << " = "<< x <<"\n"
#define print1dv(v) for(auto e: v) { cout<<e<<" ";} 

struct item{

    ll seg, pref, suf, sum;

};

struct segtree{

    int size;
    vector<item> values;
    

    item NEUTRAL_ELEMENT = {0,0,0,0};

    item single(int e)
    {
        if (e>0) return {e,e,e,e};

         return {0,0,0,e};
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
        return {
            max({a.seg, b.seg, a.suf + b.pref}),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum+a.suf),
            a.sum+b.sum

        };
    }

    //here x = current node 
    //ans  e = element value to be assgined
    void set(int i, ll e,int x, int lx, int rx) //to recursively reach the leaf node update it and then update other values on backtracking
    {
        if(rx-lx==1)
        {
            values[x] = single(e);
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
    //using the set function it can be done in   n log(n)  but using the build function we can do this in log n time
    //since just on traversal of the tree is required.

    void build(vector<int>& v, int x, int lx, int rx)
    {
        if(rx-lx==1)
        {
            if(lx<(int)v.size())
            {
                values[x]=single(v[lx]);
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
    st.build(v);

    cout<<st.calc(0,n).seg<<endl;

    int i,e;
    while(m--)
    {
        cin>>i>>e;
        st.set(i,e);
        cout<<st.calc(0,n).seg<<endl;
    }
 
    return 0;
}
