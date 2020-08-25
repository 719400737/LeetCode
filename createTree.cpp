#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
Node* createTree(vector<int>& vec,int i,int len){
    if(i>=len || vec[i]==-1)
        return NULL;
    Node* root=new  Node(vec[i]);
    root->left=createTree(vec,i*2+1,len);
    root->right=createTree(vec,i*2+2,len);
    return root;
}
int main(){



    return 1;
}