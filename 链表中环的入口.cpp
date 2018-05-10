
/*一个链表中包含环，请找出该链表的环的入口结点。
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* meeting(ListNode* pHead){
        if(pHead==NULL)
            return NULL;
        ListNode* pSlow=pHead->next;
        if(pSlow==NULL)
            return NULL;
        ListNode* pFast=pSlow->next;
        while(pFast!=NULL &&pSlow!=NULL){
            if(pSlow==pFast)
                return pSlow;
            pSlow=pSlow->next;
            pFast=pFast->next;
            if(pFast!=NULL)
                pFast=pFast->next;;
            
        }
        return NULL;
            
        
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        
        ListNode* zhong=meeting( pHead);
        if(zhong==NULL)
            return NULL;
        ListNode* tmp=zhong;
        int nodesInLoop=1;
        while(tmp->next!=zhong){
            tmp=tmp->next;
            nodesInLoop++;
        }
        ListNode* pF=pHead;
        ListNode* pL=pHead;
        int i;
        for(i=0;i<nodesInLoop;i++)
            pF=pF->next;
        while(pF!=pL){
            pF=pF->next;
            pL=pL->next;
        }
        return pF;

    }
};