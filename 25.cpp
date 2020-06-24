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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        if(!head)
            return prehead->next;
        ListNode* frist=prehead,*second=frist;
        for(int i=0;i<k;i++){
            if(second)
                second=second->next;
            else  return prehead->next;
        }
        ListNode* temp1,*temp2;
        while (second)
        {
            temp1=frist->next;
            temp2=second->next;//将f--t2之间的翻转，但f和t2不动
            frist->next=second;
            for(int i=1;i<k;i++){
                ListNode* temp=temp1;
                while(temp->next!=second)
                    temp=temp->next;
                second->next=temp;
                second=temp;
            }
            temp1->next=temp2;
            frist=temp1;    //更新first和second
            second=frist;
            for(int i=0;i<k;i++){
                if(second)
                    second=second->next;
                else  return prehead->next;
            }         
        }
        return prehead->next;
    }
};

int main(){
  

    return 0;
}