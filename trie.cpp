#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define llu unsigned long long int
#define deb(x) cout<< #x << " = "<< x <<"\n"
#define nl cout<<"\n"

//global word to find out in trie/ insert into trie
string word;


//tire structure
struct trie{
    char c;
    trie* next[26];           //instead of always having all 26 characters spaces we can use unordered_map<char,trie*>
    bool end_of_word;
};

//to create a new node of type trie
trie* create_node(char cha){

    trie* node = new trie(); //(trie*)malloc(sizeof(struct trie));

    node->c = cha;
    node->end_of_word=false;

    for(int i=0;i<26; i++){
        node->next[i]=NULL;
    }

    return node;
}

//inserting a word letter by letter
trie* insert(trie* node , int pos){
    if(pos==word.size()){
        return node;
    }
    if(node->next[word[pos]-'a'] == NULL)  node->next[word[pos]-'a'] = create_node(word[pos]);

    if(pos == word.size()-1) node->end_of_word = true;
    node->next[word[pos]-'a'] = insert(node->next[word[pos]-'a'], pos+1);

    return node;
    
}


//to search the word
bool search(trie* root,int pos){

    if(root==NULL){
        return false;
    }
    if(pos==word.size()-1){
        return root->end_of_word;
    }
    return search(root->next[word[pos]-'a'], pos+1);
}


//to delete a word, and the memory associated with it
trie* del(trie* node, int pos){
    if(pos==word.size()-1 && node->end_of_word==true){
        node->end_of_word=false;

       //if there is no child of node then we want to delet that node.
        int cnt=0;
        for(int i=0; i<26; i++){
            if(node->next[i]!=NULL){
                cnt++;
                break;
            }
        }
        if(cnt==0){
            
            free(node);
            node=NULL; //node pointer is still pointing to that same location even when the space is freed
        }

    }


    if(node->next[word[pos]-'a']!=NULL){

        node->next[word[pos]-'a'] = del(node->next[word[pos]-'a'], pos+1);

        int cnt=0;
        for(int i=0; i<26; i++){
            if(node->next[i]!=NULL){
                cnt++;
                break;
            }
        }

        if(cnt==0){
            free(node);
            node=NULL;
        }
    }

    return node;

    
}



void solve()
{
    trie* root = new trie;  //(trie*)malloc(sizeof(trie)); //you could have used (trie *)malloc(sizeof(trie));
    root->c = '#';
    root->end_of_word=false;

    for(int i=0; i<26; i++){
        root->next[i]=NULL;
    }


    int n;
    cin>>n;

    //now insert the words one by one
    for(int i=0; i<n; i++){
        cin>>word;
        root = insert(root,0);
    }

    word="delete";
    root = del(root,0);
    //cout<<"now start searching for some words\n";

    while(word!="q"){
        cin>>word;
        cout<<word<<" "<<search(root,0);nl;
    }


      
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
    return 0;
}
