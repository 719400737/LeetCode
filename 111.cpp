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
int mi=INT_MAX;
int num=0;
public:
    void DFS(TreeNode* root){
        if(root)
            num++;
        else
            return;
        if(root->left==NULL && root->right==NULL){
            mi=min(mi,num);
            return;
        }
        DFS(root->left);
        if(root->left!=NULL)
            num--;
        DFS(root->right);
        if(root->right!=NULL)
            num--;
            
        
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        DFS(root);
        return mi;
    }
};

int main(){

    int a[]={1,2,4,'#','#',5,'#','#',3};
    int index=0;
    TreeNode *root=create(a,9,index,'#');
    Solution s;
    int res;
    res=s.minDepth(root);
    cout<<res;
    return 0;
}