#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode* prehead=new ListNode(-1);
        prehead->next=head;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while (fast!=NULL && fast->next!=NULL)
        {
            if(fast==slow)
                break;
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast==slow){
            slow=prehead;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return fast;
        }
        return NULL;
        
    }
};

int main(){


    return 0;
}