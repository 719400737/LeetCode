#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool helper(TreeNode* A,TreeNode* B){ //判断B是否为A的子树
        if(B==NULL)
            return true;
        if(A==NULL)
            return false;
        if(A->val==B->val){
            bool r=helper(A->left,B->left) && helper(A->right,B->right);
            return r;
        }
        else    return false;
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL || B==NULL)
            return false;
        return helper(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
};

int main(){



    return 1;
}