#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
ListNode* Creat(int a[],int N){ 
	ListNode *tail;
	ListNode *prehead=new ListNode(-1);
	ListNode *head=prehead;
	for(int i=0;i<N;i++){
		tail=new ListNode(a[i]);
		head->next=tail;
		head=tail;
	}
	return prehead->next;
}
class Solution {

public:

    ListNode* mid(ListNode* head){
        if(!(head->next))
            return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        while((temp2->next) && (temp2->next->next!=NULL)){
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        ListNode *temp3=temp1->next;
        temp1->next=NULL;
        return temp3;
    }
    TreeNode* helper(ListNode* head){
        if(!(head))
            return NULL;
        ListNode* tmp=mid(head);//tmp为中间值
        TreeNode* root=new TreeNode(tmp->val);
        if(tmp==head)
            head=NULL;
        root->left=helper(head);
        root->right=helper(tmp->next);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root;
        root=helper(head);
        return root;
    }
};


int main(){
    int a2[]={-10,-3,0,5,9};
	ListNode *head=Creat(a2,5);
    Solution s;
    TreeNode* root;
    root=s.sortedListToBST(head);

    return 0;
}