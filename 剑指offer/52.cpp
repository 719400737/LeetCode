#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode* temp=headA,*res=NULL;
        while(temp!=NULL){
            s.insert(temp);
            temp=temp->next;
        }       
        temp=headB;
        while(temp!=NULL){
            if(s.count(temp)){
                res=temp;
                break;
            }
            temp=temp->next;
        }
        return res;
    }
};

int main(){



    return 1;
}