#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q){
        //参数传进来时，可以保证p比q小
        TreeNode* res;
        if(p->val==root->val || q->val==root->val)
            res=root;
        else if(q->val<root->val){
            res=helper(root->left,p,q);
        }
        else if(p->val>root->val){
            res=helper(root->right,p,q);
        }
        return res;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;
        if(p->val<q->val)
            res=helper(root,p,q);
        else   
            res=helper(root,q,p);
        return res;
    }
};

int main(){



    return 0;
}