//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
//双指针，起着不同的作用
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
 
        /*---------先为链表创建一个头结点---------*/
 
        int firstNumber = pHead->val;
 
        //假设我的头结点数值为-1
        int myFirst = -1;
 
        //万一链表的头结点也为-1，那么我就改成-2
        if (myFirst == firstNumber)
        {
             
            myFirst = -2;
        }
        ListNode *head = new ListNode(myFirst);
        head->next = NULL;
        head->next = pHead;
 
        ListNode *p = head;
        ListNode *q = head->next;
 //p始终指向了可以加入的元素，并且会及时的删除重复的节点，q用来测试是否有重复
        while (q)
        {
            while (q->next && (q->next->val == q->val))
            {
                q = q->next;
            }
            if (p->next != q)//关键步骤，如果p->next != q说明又发生了重复，相当于吧中间干掉
                
            {
                 
                q = q->next;
                p->next = q;
            }
            else//p->next == q 说明没有重复，加入的节点可以后移
            {
                p = q;
                q = q->next;
            }
        }
 
        //返回的时候，注意去掉头结点（自己创建的辅助节点）
        return head->next;
 
    }
};