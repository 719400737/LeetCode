#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum;
	    int jinwei=0;
        //ListNode* p1=new ListNode(0);
	    ListNode* prehead=new ListNode(0);
	    ListNode* head=prehead;
        ListNode* p;
	    while(l1  || l2 || jinwei ){
//		     if(!l1){
//		         l1=p1;//val=0 next=NULL;
//		     }
//		     if(!l2)
//		         l2=p1;
            sum=(l1 ? l1->val:0)+(l2 ? l2->val:0)+jinwei;
            //sum=l1->val+l2->val+jinwei;
            jinwei=sum/10;
            p=new ListNode(sum%10);
            head->next=p;
            head=p;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        
	    return prehead->next;
}
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
int main(){
	
	int a1[]={3};
	int a2[]={9,9};
	cout<<"Creat list"<<endl;
	ListNode *l1=Creat(a1,1);
	cout<<"l1 mumber :"<<endl;
//	while(l1){
//		cout<<l1->val<<" ";
//		l1=l1->next;
//	}
	cout<<endl;
	cout<<"Creat list"<<endl;
	ListNode *l2=Creat(a2,2);
	cout<<"l2 mumber :"<<endl;
//	while(l2){
//		cout<<l2->val<<" ";
//		l2=l2->next;
//	}	
	cout<<endl;
	ListNode *l3;
	l3=addTwoNumbers(l1, l2);
	while(l3){
		cout<<l3->val<<" ";
		l3=l3->next;
	}
	return 0;
}
