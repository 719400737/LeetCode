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
// TreeNode* Creat(vector<int> nums,int i,int len){
//         if(i>len || nums[i]==0)
//             return NULL;
//         TreeNode* root=new TreeNode(nums[i]);
//         root->left=Creat(nums,i*2+1,len);
//         root->right=Creat(nums,i*2+2,len);
//         return root;
//     }
class Solution {
    vector<int> res;
    void helper(TreeNode* root){//实质是一个中序遍历
        if(root==NULL)
            return ;
        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return res[k-1];
    }
};
int main(){
    vector<int> vec={5,3,6,2,4,0,0,1};
    TreeNode *root=Creat(vec,0,7);
    Solution s;
    s.kthSmallest(root,3);
    return 0;
}