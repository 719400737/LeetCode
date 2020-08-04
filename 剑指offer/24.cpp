#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* CreateList(vector<int> vec){
    if(vec.size()==0)
        return NULL;
    ListNode* prehead=new ListNode(-1);
    ListNode* cur=prehead;
    for(int i=0;i<vec.size();i++){
        cur->next=new ListNode(vec[i]);
        cur=cur->next;
    }
    ListNode* res=prehead->next;
    delete prehead;
    return res;
}
class Solution {
    ListNode* res;
    ListNode* helper(ListNode* head){
        if(head->next==NULL){
            res=head;
            return head;
        }
        helper(head->next)->next=head;
        head->next=NULL;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        helper(head);
        return res;
    }
};

int main(){
    vector<int> v={1,2,3,4,5};
    ListNode* head=CreateList(v);
    Solution s;
    ListNode* res=s.reverseList(head);


    return 1;
}