#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> preorder,inorder;
    TreeNode* helper(int prestart,int preend,int instart,int inend){
        if(prestart>preend)
            return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        if(prestart==preend){
            return root;
        }
        else{
            int temp=preorder[prestart];
            int in_index=find(inorder.begin(),inorder.end(),temp)-inorder.begin();
            int len_left=in_index-instart;
            root->left=helper(prestart+1,prestart+len_left,instart,in_index-1);
            root->right=helper(prestart+len_left+1,preend,in_index+1,inend);
        }
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder=preorder;
        this->inorder=inorder;
        TreeNode* res=helper(0,preorder.size()-1,0,preorder.size()-1);
        return res;
    }
};

int main(){



    return 1;
}