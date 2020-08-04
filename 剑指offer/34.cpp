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
    void helper(TreeNode* root,int sum,int cur){
        path.push_back(root->val);
        cur+=root->val;
        if(root->left==NULL && root->right==NULL && cur==sum)
            res.push_back(path);
        if(root->left)
            helper(root->left,sum,cur);
        if(root->right)
            helper(root->right,sum,cur);
        cur-=root->val;
        path.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return res;
        helper(root,sum,0);
        return res;
    }
};

int main(){



    return 1;
}