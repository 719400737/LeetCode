

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tag=0;
        ListNode* prehead=new ListNode(0);
        ListNode* head=prehead;
        while(l1 || l2){
            int sum=0;
            if(l1){
                sum+= l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+= l2->val;
                l2=l2->next;
            }
            sum+=tag;
            tag=sum/10;
            sum%=10;
            head->next=new ListNode(sum);
            head=head->next;
        }
        if(tag){
            head->next=new ListNode(1);
        } 
    return prehead->next;    
    }
}

