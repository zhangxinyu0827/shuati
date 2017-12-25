//从尾到头打印链表
//输入一个链表，从尾到头打印链表每个节点的值。
//先用栈遍历存下来，然后弹栈就可以了
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        vector<int> res_tmp;
        if(head==NULL)
            return res;
        ListNode* p=head;
       
        while(p!=NULL){
            res_tmp.push_back(p->val);
            p=p->next;
        }
        int tmp_val;
        while(res_tmp.size()>0){
            tmp_val=res_tmp.back();
            res_tmp.pop_back();
            res.push_back(tmp_val);
        }
        return res;
           
        
    }
};