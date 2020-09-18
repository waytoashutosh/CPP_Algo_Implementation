#include<bits/stdc++.h>
using namespace std;

#define nl cout<<"\n";
int block;
struct query
{
    int l,r,i;
};
bool comp(query x, query y)
{
    if(x.l/block != y.l/block)
    {
        //sort by block
        return x.l/block < y.l/block;
    }
    return x.r < y.r;
}
vector<int> coun;

void add(int x)
{
    
}
void remove(int x)
{

}


int main(){

    
    int n, t;
    cin>>n>>t;
    coun.resize(1000001);
    block=sqrt(n);
    //cout<<"Block Size : "<<block;nl;
    
    vector<int> v(n+1);

    for(int i=1; i<=n; i++){
    
        cin>>v[i];
    }
    
    vector<query> q(t);
    
    for(int j=0; j<t; j++)
    {
        cin>>q[j].l>>q[j].r;
        q[j].i=j;
    }
    
    sort(q.begin(),q.end(),comp);

    for(int j=0; j<t; j++)
    {
        cout<<q[j].i<<" "<< q[j].l<<" "<<q[j].r;nl;
    }

    int currentl=0,currentr=0;
    int L,R,k=0;
    
    while(k<t)
    {
        L=q[k].l;
        R=q[k].r;

        if(currentl<L)
        {
            while(currentl<L)
            {
                remove(currentl);
                currentl++;
            }
            
        }
        else if(currentl>L)
        {
            while(currentl>=L)
            {
                add(currentl);
                currentl--;
            }
        }
        if(currentr<R)
        {
            while(currentr<=R)
            {
                add(currentr);
                currentr++;
            }
        }
        else if(currentr>R)
        {
            while(currentr>R)
            {
                remove(currentr);
                currentr--;
            }
        }

        k++;
        
    }





    return 0;
}