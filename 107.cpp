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
    vector<vector<int>> res;
    vector<int> path;
    deque<TreeNode*> d;
public:
    void helper(TreeNode* root){
        if(!root)
            return;
        d.push_back(root);
        TreeNode* last=root;
        TreeNode* tmp;
        while (!d.empty())
        {
            /* code */
            tmp=d.front();
            path.push_back(tmp->val);
            d.pop_front();
            if(tmp->left)
                d.push_back(tmp->left);
            if(tmp->right)
                d.push_back(tmp->right);
            if(tmp==last){
                res.push_back(path);
                path.clear();
                last=d.back();
            }
            
        }
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        helper(root);
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){


    return 0;
}