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
TreeNode* create(int *a,int N,int& index, int invalid){
    TreeNode *root=NULL;
    if(index<N && a[index]!=invalid){
        root=new TreeNode(a[index]);
        root->left=create(a,N,++index,invalid);
        root->right=create(a,N,++index,invalid);
    }
    return root;
    
}
void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->val;
        inorder(root->right);
}

class Solution {
public:
    vector<TreeNode*> createzishu(int start,int end){
        vector<TreeNode*> res;
        if(start<end)
            res.push_back(NULL);
        for(int i=star;i<=end;i++){
            //i为根，
            vector<TreeNode*> left=createzishu(start,i-1);
            vector<TreeNode*> right=createzishu(i+1,end);
            for(auto l:left){
                for(auto r:right){
                    TreeNode *root=new TreeNode(i);
                    root->left=l;//保存好root的左右子树，在讲root放进入
                    root->right=r;
                    res.push_back(root);
                }
            }

        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {    
        vector<TreeNode*> res;
        if(n=0)
            return res;   
        res=createzishu(1,n);
        return res;
    }
};

int main(){
    Solution s;
    int a[]={1,'#',2,3};
    int index=0;
    TreeNode *root=create(a,4,index,'#');
    inorder(root);
    cout<<endl;
    return 0;
}