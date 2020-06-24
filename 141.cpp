#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while (fast!=NULL && fast->next!=NULL)
        {
            if(fast==slow)
                return true;
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
        
    }
};

int main(){


    return 0;
}