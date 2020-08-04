#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int index=0;
    int res=0;
    void helper(TreeNode* root,int k){
        if(root==NULL)
            return;
        helper(root->right,k); //采用中序遍历，因为是二叉搜索树，我们先遍历右节点，
                                //最后遍历左节点，得到的是一个递减序列，我们找到第k个在退出
        index++;
        if(index==k){
            res=root->val;
            return;
        }
        helper(root->left,k);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        helper(root,k);
        return res;
    }
};

int main(){



    return 1;
}