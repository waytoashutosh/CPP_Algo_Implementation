#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string pattern, word;

    cin>>pattern>>word;


    //first building the lps array fromt the pattern

    int q=1;
    int k=-1;

    int m = pattern.size();
    vector<int> pi(m);
    pi[0]=-1;
    while(q<m){

        if(pattern[k+1]==pattern[q]){
            k++;
            pi[q]=k+1;
            q++;
        }
        else{
            if(k==-1){
                pi[q]=0;
                q++;
            }
            else{
                k=pi[k];
            }
        }
    }
    //now the lps array is prepared.
    //now we will search the main word for the existence of the pattern
    q=0;
    k=-1;

    vector<int> lps(word.size());
    while(q<word.size()){
        if(pattern[k+1]==word[q]){
            k++;
            lps[q]=k+1;
            q++;
        }
        else{
            if(k==-1){
                lps[q]=0;
                q++;
            }
            else{
                k=pi[k];
            }
        }

    }
    for(auto x: lps){
        cout<<x<<" ";
    }cout<<"\n";

    if(*max_element(lps.begin(), lps.end())== m){
        cout<<"Full Pattern Found\n";
    }
    else{
        cout<<"Pattern Found with lenght upto : "<<*max_element(lps.begin(), lps.end());
    }


    return 0;
}
