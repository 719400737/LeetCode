#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prehead=new ListNode(-1);
        prehead->next=head;
        ListNode *fast=prehead;
        ListNode *slow=prehead;
        while(n>0){
            fast=fast->next;
            n--;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow->next!=NULL)
            slow->next=slow->next->next;
        return prehead->next;
    }
};

int main(){


    return 0;
}