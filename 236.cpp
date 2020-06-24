#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
    TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL)
            return NULL;
        TreeNode* l=helper(root->left,p,q);//返回左子树中含有的p,q
        TreeNode* r=helper(root->right,p,q);
        if(root==p)
            return p;
        if(root==q)
            return q;
        if(l && r)
            return root;
        else if(l)  return l; //返回找到的
        else if(r)  return r;
        else    return NULL;   //表示没有找到
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};

int main(){


    return 0;
}