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
    vector<int> res;
    /*void helper(TreeNode* root){//用递归实现
        if(root==NULL)
            return;
        res.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }*/
    vector<int> helper(TreeNode* root){//用栈迭代实现，每次先将右节点push
        stack<TreeNode*> st;
        if(root==NULL)
            return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            res.push_back(temp->val);
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return res;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        return helper(root);
    }
};
int main(){


    return 0;
}