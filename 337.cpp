#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<TreeNode*,int> m; //本题如果直接使用递归，则不能通过时间限制
                                    //因为会产生重复计算，可以使用备忘录，map保存节点对应的值
    int helper(TreeNode* root){
        if(root==NULL)
            return 0;
        int res=0;
        if(m.count(root))
            return m[root];
        else{
            res+=root->val;
            int l1=0,r1=0;
            if(root->left!=NULL)
                l1=helper(root->left->left)+helper(root->left->right); //决定偷该家，则起两个子树不能偷
            if(root->right!=NULL)
                r1=helper(root->right->left)+helper(root->right->right);

            int l2=helper(root->left);//不偷该家，则两个子树则可以偷
            int r2=helper(root->right); 
            res=max(res+l1+r1,l2+r2);
        }

        m.insert({root,res});    
        return res;

    }
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=helper(root);
        return res;
    }
};

int main(){


    return 0;
}