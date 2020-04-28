#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *temp=head;
        int n=0;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        k=k%n;
        for(;k>0;k--){
            fast=fast->next;
        }
        //fast 领先slow k
        while (fast->next!=NULL)
        {
            /* code */
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;

    }
};

int main(){


    return 0;
}