
/*输入一个复杂链表（每个
节点中有节点值，以及两个指针
，一个指向下一个节点，另一个特
殊指针指向任意一个节点），返回结
果为复制后复杂链表的head。（注意
，输出结果中请不要返回参数中的节点引用，
否则判题程序会直接返回空）
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* res=NULL;
        if(pHead==NULL)
            return res;
        RandomListNode* pCur=pHead;
        RandomListNode *pTmp;
        while(pCur!=NULL){
            pTmp=new  RandomListNode(pCur->label);
            pTmp->label=pCur->label;
            pTmp->next=pCur->next;
            pTmp->random=NULL;
            pCur->next=pTmp;
            pCur=pTmp->next;
        }
        pCur=pHead;
        while(pCur!=NULL){
            if(pCur->random!=NULL)
                pCur->next->random=pCur->random->next;
            pCur= pCur->next->next;
        }
        res=pHead->next;
        pCur=pHead;
        while(pCur!=NULL){
            pTmp=pCur->next->next;
            if(pCur->next->next==NULL)
                pCur->next->next=NULL;
            else
                pCur->next->next=pTmp->next;
            
            pCur->next=pTmp;
            pCur=pTmp;
        }
        return res;
            
        
    }
};