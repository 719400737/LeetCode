#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* helper(TreeNode* t1,TreeNode* t2){
        if(t1==NULL && t2==NULL)
            return NULL;
        int num=0;
        if(t1) num+=t1->val;
        if(t2) num+=t2->val;
        TreeNode* root=new TreeNode(0);
        root->val=num;
        root->left=helper(t1?t1->left:NULL,t2?t2->left:NULL);
        root->right=helper(t1?t1->right:NULL,t2?t2->right:NULL);
        return root;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return helper(t1,t2);
    }
};

int main(){


    return 0;
}