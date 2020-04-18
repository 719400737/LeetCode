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
    int num=0;
public:
    bool DFS(TreeNode* root,int sum){
        if(root==NULL)
            return false;
        num+=root->val;
        if(root->left==NULL && root->right==NULL && num==sum)
            return true;
        bool b=DFS(root->left,sum) || DFS(root->right,sum); 
        num-=root->val;
        return b;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        bool res=DFS(root,sum);
        return res;
    }
};

int main(){


    return 0;
}