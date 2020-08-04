#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* createTree(vector<int>& vec,int i,int len){
    if(vec[i]==-1)
        return NULL;
    TreeNode* root=new TreeNode(vec[i]);
    if(i+1<len)
        root->left=createTree(vec,i+1,len);
    if(i+2<len)
        root->right=createTree(vec,i+2,len);
    return root;
}
class Solution {
    bool helper(TreeNode* l,TreeNode* r){
        if(l==NULL && r==NULL)
            return true;
        else if(l==NULL || r==NULL)
            return false;
        else if(l->val==r->val){
            return helper(l->left,r->right) && helper(l->right,r->left);
        }
        else    return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else    return helper(root->left,root->right);
    }
};
int main(){
    vector<int> vec={1,2,2,-1,3,-1,3};
    TreeNode* root=createTree(vec,0,vec.size());
    Solution s;
    bool res=s.isSymmetric(root);
    cout<<res<<endl;
    return 1;
}