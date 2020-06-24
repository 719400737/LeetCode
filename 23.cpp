#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
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
public:
    // ListNode* mergeKLists(vector<ListNode*>& lists) {//顺序归并
    //     ListNode* res=NULL;
    //     for(int i=0;i<lists.size();i++){
    //         res=mergeTwoLists(res,lists[i]);
    //     }
    //     return res;
    // }
    ListNode* helper(vector<ListNode*>& lists,int l,int r){
        if(l==r)
            return lists[l];
        if(l>r)
            return NULL;
        return mergeTwoLists(helper(lists,l,(l+r)/2),helper(lists,(l+r)/2+1,r));
        
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {//分治归并                        
        return helper(lists,0,lists.size()-1);
    
    }


};

int main(){


    return 0;
}