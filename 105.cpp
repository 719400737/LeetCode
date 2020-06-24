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
    vector<int> preorder;
    vector<int> inorder;
    map<int,int> m;
public:
    TreeNode* helper(int preStart,int preEnd,int inStart,int inEnd){//i is pre order, j is in order
        if(preStart>preEnd || inStart>inEnd)
            return NULL;

        TreeNode* root=new TreeNode(preorder[preStart]);

        int inRoot=m[preorder[preStart]];
        int numsLeft=inRoot-inStart;
 
        root->left=helper(preStart+1,preStart+numsLeft,inStart,inRoot-1);
        
        root->right=helper(preStart+numsLeft+1,preEnd,inRoot+1,inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder=preorder;
        this->inorder=inorder;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=helper(0,preorder.size()-1,0,inorder.size()-1);
        return root;

    }
};


int main(){
    vector<int> v1={3,9,20,15,7};
    vector<int> v2={9,3,15,20,7};
    Solution s;
    TreeNode* root;
    root=s.buildTree(v1,v2);

    return 0;
}