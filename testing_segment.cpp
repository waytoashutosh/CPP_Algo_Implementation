#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct segtree
{
    int n;
    vector<int> v;

    void create(int len){
        n=1;

        while(n<len){
            n=n*2;
        }
        
        
        v.assign(n*2-1,INT_MAX-1);
        
    }


    void build(vector<int>& V){
        
        int y = V.size()-1;

        for(int i = v.size()-1; y!=-1; i--){
            v[i]=V[y];
            y--;
        }
        for(int i=v.size()-1; i>0; i=i-2){
            v[(i-1)/2]=min(v[i],v[i-1]);
        }
    }
    void update(int e, int index,int x, int lx, int rx){
        if(rx-lx==1){
            v[x]=e;
            return;
        }
        int mid = lx+(rx-lx)/2;

        if(index<mid){
            update(e,index, 2*x+1, lx, mid);
        }
        else{
            update(e,index, 2*x+2, mid,rx);
        }

     
        v[x]=min(v[2*x+1], v[2*x+2]);
      
    }

    void update(int val, int index){
        update(val,index,0,0,n);
    }
};


void solve()
{
    
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    segtree st;

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    //now we we need to create the segment tree of the given size.

    st.create(n);
    st.build(v);

    for(int i=0; i<st.v.size(); i++){
        cout<<st.v[i]<<" ";
    }cout<<"\n";
    st.update(-9,4);
    for(int i=0; i<st.v.size(); i++){
        cout<<st.v[i]<<" ";
    }cout<<"\n";
    return 0;
}
