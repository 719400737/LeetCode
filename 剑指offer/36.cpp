#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
Node* createTree(vector<int>& vec,int i,int len){
    if(i>=len || vec[i]==-1)
        return NULL;
    Node* root=new  Node(vec[i]);
    root->left=createTree(vec,i*2+1,len);
    root->right=createTree(vec,i*2+2,len);
    return root;
}
class Solution {
public:
    Node* helper(Node* root){
        if(root==NULL)
            return root;
        Node* l=treeToDoublyList(root->left);
        Node* temp=l;
        if(temp!=NULL){
            while(temp->right!=NULL)
                temp=temp->right;
            temp->right=root;
            root->left=temp;
        }
        Node* r=treeToDoublyList(root->right);
        temp=r;
        if(temp!=NULL){
            while(temp->left!=NULL){
                temp=temp->left;
            }
            temp->left=root;
            root->right=temp;
        }
        return root;
        
    }
    Node* treeToDoublyList(Node* root) {
        root=helper(root);
        Node* f=root;
        Node* s=root;
        if(root!=NULL){
            while(f->left!=NULL)
                f=f->left;
            while(s->right!=NULL)
                s=s->right;
        }
        s->right=f;
        f->left=s;
        return f;
    }
};

int main(){
    vector<int> vec={4,2,5,1,3};
    Node* root=createTree(vec,0,vec.size());
    Solution s;
    Node* res=s.treeToDoublyList(root);
    cout<<1<<endl;
    return 1;
}