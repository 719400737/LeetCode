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
    
    vector<int> BFS(TreeNode* root){
        vector<int> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int m=qu.size();
            for(int i=0;i<m;i++){
                TreeNode* temp=qu.front();
                if(i==m-1)
                    res.push_back(temp->val);
                qu.pop();
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }

        }
        return res;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        return BFS(root);
    }
};
int main(){


    return 0;
}