#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
private:
vector<vector<int>> res;
vector<int> path;
queue<TreeNode*> q;

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return res;
        q.push(root);
        TreeNode *last=root;
        int i=0;
        while(!q.empty()){
            TreeNode *root=q.front();
            path.push_back(root->val);
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
            q.pop();
            if(last==root){
                if(i)
                    reverse(path.begin(),path.end());
                res.push_back(path);
                path.clear();
                last=q.back();
                i=!i;
            }
        }
        return res;
    }
};

int main(){
    Solution s;

    return 0;
}