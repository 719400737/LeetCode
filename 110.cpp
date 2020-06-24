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
TreeNode* create(int *a,int N,int& index, int invalid){
    TreeNode *root=NULL;
    if(index<N && a[index]!=invalid){
        root=new TreeNode(a[index]);
        root->left=create(a,N,++index,invalid);
        root->right=create(a,N,++index,invalid);
    }
    return root;
    
}
class Solution {

public:
    int helper(TreeNode* root){
        if(root==NULL)
            return -1;
        int res=0;
        int a=helper(root->left);
        int b=helper(root->right);
        res=1+max(a,b);
        return res;
    }
        
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int l=helper(root->left);
        int r=helper(root->right);
        return abs(l-r)<2 && isBalanced(root->left) && isBalanced(root->right);
        
    }
};

int main(){

    int a[]={1,2,3,4,'#','#',4,'#','#',3,'#','#',2};
    int index=0;
    TreeNode *root=create(a,13,index,'#');
    Solution s;
    bool res;
    res=s.isBalanced(root);
    cout<<res<<endl;
    return 0;
}