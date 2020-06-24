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
    /*void helper(TreeNode* root){//递归实现
        if(root==NULL)
            return;
        helper(root->left);
        helper(root->right);
        res.push_back(root->val);
    }*/

    vector<int> helper(TreeNode* root){
        stack<TreeNode*> st;
        if(root==NULL)
            return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            res.push_back(temp->val);
            if(temp->left)  st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return helper(root);
        
    }
};

int main(){


    return 0;
}