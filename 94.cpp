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
class Solution {
private:
    vector<int> vec;
public:
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return vec;
    }
};

int main(){
    Solution s;
    int a[]={1,'#',2,3};
    int index=0;
    TreeNode *root=create(a,4,index,'#');
    vector<int> vec;
    vec=s.inorderTraversal(root);
    for(auto i:vec)
        cout<<i<<" ";
    cout<<endl;
    return 0;
    return 0;
}