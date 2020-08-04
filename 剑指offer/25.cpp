#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prehead=new ListNode(0);
        ListNode* cur=prehead;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }
        }
        if(l1!=NULL)
            cur->next=l1;
        else    cur->next=l2;
        ListNode* res=prehead->next;
        delete prehead;
        return res;
    }
};
int main(){



    return 1;
}