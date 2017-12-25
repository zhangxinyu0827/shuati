//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

//逐渐递归的选取即可

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL && pHead2==NULL)
            return NULL;
        if(pHead2==NULL)
            return pHead1;
        if(pHead1==NULL)
            return pHead2;
        struct ListNode *resH;
        if(pHead1->val <=  pHead2->val){
            resH=pHead1;
            pHead1=pHead1->next;
        }
        else{
           	resH=pHead2;
            pHead2=pHead2->next;
        }
		struct ListNode *cur=resH;
        while (pHead1!=NULL && pHead2!=NULL){
             
            if(pHead1->val <= pHead2->val){
                cur->next=pHead1;
                cur=cur->next;
                pHead1=pHead1->next;
                
            }
        	else{
                cur->next=pHead2;
                cur=cur->next;
                pHead2=pHead2->next;
                
        	}
        }
        while(pHead1!=NULL){
            cur->next=pHead1;
            cur=cur->next;
            pHead1=pHead1->next;
        }
        while( pHead2!=NULL){
            cur->next=pHead2;
            cur=cur->next;
            pHead2=pHead2->next;
        }
        return resH;

    }
};