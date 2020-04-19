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
    int res=INT_MIN;
public:
    int helper(TreeNode* root){
        if(!root)
            return 0;        
        int l=max(0,helper(root->left));
        int r=max(0,helper(root->right));
        res=max(res,l+r+root->val);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int a=helper(root);
        return res;    
    }
};

int main(){


    return 0;
}