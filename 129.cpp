#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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
int sum=0;
int pre=0;

public:
    void DFS(TreeNode *root){
        if(root==NULL)
            return;
        pre=pre*10+root->val;

        if(!(root->left || root->right)){
            sum+=pre;
            pre=(pre-root->val)/10;
            return;
        }            
        DFS(root->left);
        DFS(root->right);
        pre=(pre-root->val)/10;
    }
    int sumNumbers(TreeNode* root) {
        
        DFS(root);
        return sum;
    }
};
int main(){
    Solution s;

    return 0;
}