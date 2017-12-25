//输入一个链表，反转链表后，输出链表的所有元素。
//记住前一个的和后一个的，不断进行迭代
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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL || pHead->next==NULL)
            return pHead;
        ListNode* p=pHead->next;
        pHead->next=NULL;
        ListNode* p_pre=pHead;
        while(p->next!=NULL){
            ListNode*  ptmp=p->next;
            p->next=p_pre;
            p_pre=p;
            p=ptmp;
        }
        p->next=p_pre;
        return p;

    }
};