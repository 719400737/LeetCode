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
    int N=0;
    int res=0;
public:
    void helper(TreeNode* root){
        if(!root)
            return;
        N++;
        res=max(res,N);
        helper(root->left);
        helper(root->right);
        N--;
    }
    int maxDepth(TreeNode* root) {
        helper(root);
        return res;
    }
};

int main(){


    return 0;
}