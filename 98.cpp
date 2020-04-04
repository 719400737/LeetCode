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
 
public:
    bool fun(TreeNode* root, long low, long high) {
        if (root == NULL) return true;
        long num = root->val;
        if (num <= low || num >= high) return false;
        return fun(root->left, low, num) && fun(root->right, num, high);
    }


    bool isValidBST(TreeNode* root) {
        return fun(root,LONG_MIN,LONG_MAX);
    }
};

int main(){
    Solution s;

    return 0;
}