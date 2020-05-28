#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        while(l1 && l2){
            if(l1->val > l2->val){
                tail->next=l2;
                l2=l2->next;
            }
            else{ 
                tail->next=l1;
                l1=l1->next;   
            }
            tail=tail->next;
        } 
        if(l1)
            tail->next=l1;
        else
            tail->next=l2;
        return head->next;      
    }
};

 
int main(){
    int a1[]={};
    int a2[]={1};
    cout<<"Creat list"<<endl;
    ListNode *head2=Creat(a2,1);
    ListNode *head1=Creat(a1,0);
    Solution s;
    s.mergeTwoLists(head1,head2);
 
    return 0;
}                   