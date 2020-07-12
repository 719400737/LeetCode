#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prehead=new ListNode(0); //常规链表操作，注意delete
        prehead->next=head;
        ListNode* cur=prehead;
        while(cur->next!=NULL){
            if(cur->next->val==val){
                ListNode* li=cur->next;
                cur->next=cur->next->next;
                delete li;
                continue;
            }
            cur=cur->next;
        }
        ListNode* res=prehead->next;
        delete prehead;
        return res;
    }
};

int main(){


    return 0;
}