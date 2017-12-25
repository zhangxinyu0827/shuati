//输入一个链表，输出该链表中倒数第k个结点。
//2个指针，一个先走k步，另一个开始走


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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int tmp=1;
        ListNode* p=pListHead;
        ListNode* q=pListHead;
        while(p!=NULL){
            p=p->next;
            
            if(tmp>k)
                q=q->next;
            tmp++;
        }
        if(tmp<=k)
            return NULL;
        return q;
    }
};