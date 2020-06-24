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
    TreeNode* res;
    void helper(TreeNode* root,TreeNode* p,TreeNode* q){//利用二叉搜索树的特性，左子树比根小，右子树比根大。
        if(root==NULL)
            return;
        else if(root->val>p->val && root->val>q->val)
            helper(root->left,p,q);
        else if(root->val<p->val && root->val<q->val)
            helper(root->right,p,q);
        else res=root;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q);
        return res;
    }
};

int main(){


    return 0;
}