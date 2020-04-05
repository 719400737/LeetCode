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

void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->val;
        inorder(root->right);
}

class Solution {
public:
    //把右子树放在左子树的最右子树上，
    //吧左子树放在右字数上
    //左子树变空
    //根变为根的右节点
    TreeNode* findright(TreeNode* root){
        while(root->right)
            root=root->right;
        return root;
    }
    void insert(TreeNode* root){
        
        if(!(root->left))
            return;    
        TreeNode* temp=findright(root->left);
        temp->right=root->right;
        root->right=root->left;
        root->left=NULL;
    }

    void flatten(TreeNode* root) {
        while (root)
        {
            insert(root);
            root=root->right;
        }
        
    }
};

int main(){
    Solution s;

    return 0;
}