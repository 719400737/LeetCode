#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
queue<TreeNode*> q;

TreeNode* create(int *a,int N,int invalid){
        int i=0;
        TreeNode* root=new TreeNode(a[i++]);
        q.push(root);

        while(!q.empty() && i<N){
            TreeNode *temp=q.front();
            if(a[i]!=invalid){
                temp->left=new TreeNode(a[i]);
                q.push(temp->left);
            }
            else{
                temp->left=NULL;
            }
            i++;
            if(a[i]!=invalid && i<=N){
                temp->right=new TreeNode(a[i]);
                q.push(temp->right);
            }
            else
            {
                temp->right=NULL;
            }
            
            i++;
            q.pop();
            
        } 
        return root; 
}
// void inorder(TreeNode* root){
//         if(root==NULL)
//             return;
//         cout<<root->val<<" ";
//         inorder(root->left);
//         inorder(root->right);
// }

class Solution {
private:
vector<vector<int>> res;
vector<int> path;
int s=0;

public:
    void inorder(TreeNode* root,int sum){
        if(root==NULL)
            return;
        //cout<<root->val;
        s+=root->val;
        path.push_back(root->val);
        if(!(root->left || root->right) && s==sum){
            res.push_back(path);
            s-=root->val;
            path.pop_back();
            return;
        }   
        // if(s>sum){
        //     s-=root->val;
        //     path.pop_back();
        //     return;
        // }
        inorder(root->left,sum);
        inorder(root->right,sum);
        s-=root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        inorder(root,sum);
        return res;
    }
};

int main(){
    Solution s;

    int a[]={5,4,8,11,0,13,4,7,2,0,0,5,1};
    TreeNode* root=create(a,13,0);
    vector<vector<int>> res;
    res=s.pathSum(root,22);
    return 0;
}