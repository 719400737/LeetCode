#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool helper(TreeNode* root1,TreeNode* root2){
        if(root1 && root2){
            if(root1->val==root2->val)
                return helper(root1->left,root2->right) && helper(root1->right,root2->left);
            else
               return false;

        }
        else if(root1 || root2){
            return false;
        }
        else if(!root1 && !root2)
            return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
          return true;
        return helper(root->left,root->right);
    }
};
int main(){

    

    return 0;
}