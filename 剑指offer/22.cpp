#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* f=head,*s=f;
        for(int i=0;i<k && f!=NULL;i++)
            f=f->next;
        while(f!=NULL){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};

int main(){



    return 1;
}