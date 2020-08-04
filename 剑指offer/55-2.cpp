#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool res=true;
    int helper(TreeNode* root){  //树的问题必定是递归，
        if(root==NULL)
            return 0;
        int l=1+helper(root->left);//左子树的长度
        int r=1+helper(root->right);//右子树的长度
        if(abs(l-r)>1)
            res=false;
        return max(l,r); //该节点返回自己最长子树的长度
    }
public:
    bool isBalanced(TreeNode* root) {
        int a=helper(root);
        return res;
    }
};

int main(){



    return 1;
}