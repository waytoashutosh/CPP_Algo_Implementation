#include<bits/stdc++.h>
using namespace std;

struct treeNode
{
    int val;
    treeNode *left, *right;
};

//creating the tree using levelorder traversal 
//if node is null just keep the value in array as INT_MAX
//ex vector<int> level = {4,1,6,0,INT_MAX,5,7};
//treeNode* root = buildTree(level,0);

treeNode* createNode(int va){
    treeNode *temp = (treeNode*)malloc(sizeof(treeNode));
    temp->val=va;
    return temp;
}

treeNode* buildTree(vector<int> & v,int i){

    if(i>=v.size()) return NULL;
    if(v[i]==INT_MAX) return NULL;

    treeNode *t = createNode(v[i]);

    t->left = buildTree(v,2*i+1);
    t->right = buildTree(v, 2*i+2);
    return t;
    
}

vector<int> pre;
void preorder(treeNode* root){
    if(root==NULL) return;

    
    cout<<root->val<<" ";
    pre.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}

int leftlim;
vector<vector<int>> f;
void solve(vector<int>& ve, int i, int j, vector<int> &ans){
    

    if(i<=leftlim && j<ve.size()){

        ans.push_back(ve[j]);
        solve(ve,i,j+1,ans);
        ans.pop_back();

        ans.push_back(ve[i]);
        solve(ve,i+1,j,ans);
        ans.pop_back();
    }
    else if(i<=leftlim){
        ans.push_back(ve[i]);
        solve(ve,i+1,j,ans);
        ans.pop_back();

    }
    else if(j<ve.size()){
        ans.push_back(ve[j]);
        solve(ve,i,j+1,ans);
        ans.pop_back();
    }
    else{
        f.push_back(ans);
        return;
    }
}
int size_of_tree(treeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+ size_of_tree(root->left)+size_of_tree(root->right);
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<int> v = {10,5,20,2,4,INT_MAX,30};

    treeNode *root = buildTree(v,0);

    preorder(root);
    int leftsize = size_of_tree(root->left);
   
    leftlim = leftsize;
    cout<<"\n";
    cout<<leftsize<<" "<<"\n";

    vector<int> a ={root->val};
    solve(pre,1,leftsize+1,a);
    
    for(int i=0; i<f.size(); i++){
        for(int j=0; j<f[i].size(); j++){
            cout<<f[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
