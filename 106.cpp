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
    vector<int> postorder;
    vector<int> inorder;
    map<int,int> m;
public:
    TreeNode* helper(int inStart,int inEnd,int postStart,int postEnd){
        if(inStart>inEnd || postStart<postEnd)
            return NULL;
        TreeNode* root=new TreeNode(postorder[postStart]);
        int index=m[postorder[postStart]];
        int numright=inEnd-index;

        root->left=helper(inStart,index-1,postStart-numright-1,postEnd);
        root->right=helper(index+1,inEnd,postStart-1,postStart-numright);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder=postorder;
        this->inorder=inorder;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=helper(0,inorder.size()-1,postorder.size()-1,0);
        return root;
    }

};

int main(){
    vector<int> v1={9,3,15,20,7};
    vector<int> v2={9,15,7,20,3};
    Solution s;
    TreeNode* root;
    root=s.buildTree(v1,v2);

    return 0;
}