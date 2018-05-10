
/*输入两个链表，找出它们的第一个公共结点。
*/
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL || pHead2==NULL)
            return NULL;
        
        stack<ListNode*> v1;
        stack<ListNode*> v2;
        ListNode* p=pHead1;
        while(p!=NULL){
            v1.push(p);
            p=p->next;
        }
        p=pHead2;
        while(p!=NULL){
            v2.push(p);
            p=p->next;
        }
        ListNode* top1=v1.top();
        ListNode* top2=v2.top();

        ListNode* res=NULL;
        while(top1==top2 && !v1.empty() && !v2.empty()){
            v1.pop();
            v2.pop();
            if(!v2.empty()){
                
                top2=v2.top();
            }
            if(!v1.empty()){
                top1=v1.top();
            
            }
            
            
        }
        if(v1.empty() && v2.empty())
            return top2;
        if(v1.empty())
            return top2->next;
        if(v2.empty())
            return top1->next;
        res = top1->next;
        return res;
            
    }
};