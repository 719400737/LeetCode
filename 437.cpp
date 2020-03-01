int path(TreeNode *root,int sum){//1种情况含有跟节点的和为sum
        int res;
        if(root==NULL)
            return 0;
        int l=path(root->left,sum-root->val);
        int r=path(root->right,sum-root->val);
        res=l+r+(root->val==sum);
        return res;
    }
    int pathSum(TreeNode* root, int sum) {
        //int res;
        if(root==NULL)
            return 0;
        int l=pathSum(root->left,sum);//不含根节点和为sum
        int r=pathSum(root->right,sum);
        return l+r+path(root,sum);
    }
    采用两个函数，函数1局部思考，只考含有根节点的和为sum的情况，
	函数2从全局思考。 
