#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void helper1(Node* root1,Node* root2){
        if(!root1)
            return;
        root1->next=root2;
        if(root2!=NULL)
            helper1(root1->right,root2->left);
    }
    void helper2(Node* root){
        if(!root)
            return;
        helper2(root->left);
        helper2(root->right);
        helper1(root->left,root->right);
    }
    Node* connect(Node* root) {
        helper2(root);
        return root;
    }
};

int main(){


    return 0;
}