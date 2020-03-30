#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *prehead=new ListNode(-1);
        prehead->next=head;
        ListNode *first=prehead;
        ListNode *second=first;
        ListNode *tmp;
        //head<x时
        while(second->next!=NULL){
            while(first->next&&first->next->val<x)
                first=first->next;
            second=first;
            while(second->next&&second->next->val>=x)
                second=second->next;
            if(second->next==NULL)
                return prehead->next;
            tmp=first->next;
            first->next=second->next;
            first=first->next;
            second->next=second->next->next;
            first->next=tmp;
        }
        return prehead->next;
    }
};

int main(){
    Solution s;
    int a2[]={2,1};
    cout<<"Creat list"<<endl;
	ListNode *head=Creat(a2,2);
    head=s.partition(head,2);
	cout<<"l2 mumber :"<<endl;
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
    cout<<endl;
    return 0;
}