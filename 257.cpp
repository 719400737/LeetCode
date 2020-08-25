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
        if(root->left==NULL && root->right==NULL){
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        if(root->left) helper(root->left);

        if(root->right) helper(root->right);

        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if(root==NULL)
            return vec;
        helper(root);
        for(auto i:res){
            string s="";
            for(int j=0;j<i.size()-1;j++){
                s+=to_string(i[j]);
                s+="->";
            }
            s+=to_string(i[i.size()-1]);
            vec.push_back(s);
        }
        return vec;

    }
};

int main(){

    

    return 0;
}