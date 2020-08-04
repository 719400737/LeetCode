#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void helper(TreeNode* root){
        queue<TreeNode*> que;
        if(root==NULL)
            return;
        que.push(root);
        TreeNode* last=root;
        while(!que.empty()){
            TreeNode* cur=que.front();
            path.push_back(cur->val);
            que.pop();
            if(cur->left)   que.push(cur->left);
            if(cur->right)  que.push(cur->right);
            if(cur==last){
                res.push_back(path);
                path.clear();
                last=que.back();
            }
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root);
        return res;
    }
};

int main(){



    return 1;
}