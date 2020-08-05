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
        if(root==NULL) 
            return NULL;
        if(root==p || root==q) //若root与要查找的一致，root为p或q的最小祖先，意味这找到了一个
            return root;
        TreeNode* res;
        TreeNode* l=helper(root->left,p,q); //去root的左子树找，结果保存在l中，找不到任何一个就返回NULL
        TreeNode* r=helper(root->right,p,q);//同理去root的右子树找
        if(l==NULL || r==NULL) //当有一边没有找到时，意味着另一边即是我们要的答案
            if(l==NULL)
                res=r;
            else    res=l;
        else    res=root;//两边都找到时，root为我们的最小祖先
        return res;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;
        res=helper(root,p,q);
        return res;
    }
};

int main(){



    return 0;
}