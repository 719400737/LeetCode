#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {//使用归并排序的思想，将链表排序分配分割和归并两个步骤，
                //其中分割时用到了递归
    ListNode* merge(ListNode* h1,ListNode* h2){//两个有序链表的归并
        ListNode* prehead=new ListNode(0);
        ListNode* cur=prehead;
        while(h1!=NULL && h2!=NULL){
            if(h1->val<h2->val){
                cur->next=h1;
                cur=h1;
                h1=h1->next;
            }
            else{
                cur->next=h2;
                cur=h2;
                h2=h2->next;
            }
        }
        if(h1)
            cur->next=h1;
        else    cur->next=h2;
        ListNode* res=prehead->next;
        delete prehead;
        return res;
    }
    ListNode* Merge_sort(ListNode* head){//递归程序
        ListNode* fast=head,*slow=head,*tmp=slow;
        if(fast==NULL || fast->next==NULL)
            return slow;
        while (fast!=NULL && fast->next!=NULL)//找到链表的中点
        {
            fast=fast->next->next;
            tmp=slow;
            slow=slow->next;
        }
        tmp->next=NULL;       //将链表断为两个链表
        head=Merge_sort(head);
        slow=Merge_sort(slow);
        return merge(head,slow);
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode* res=Merge_sort(head);
        return res;
    }
};
int main(){


    return 0;
}