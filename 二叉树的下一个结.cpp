
/*给定一个二叉树和其中的一个结点
，请找出中序遍历顺序的下一个结点并且
返回。注意，树中的结点不仅包含左右子结
点，同时包含指向父结点的指针。
*/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        
        if(pNode->right!=NULL){//右面不空，就是右边的最左节点
            TreeLinkNode* pR=pNode->right;
            while(pR->left!=NULL)
                pR=pR->left;
            return pR;
            
            
        }
        else if(pNode->next!=NULL){//此时右面是空的，看他是父节点的右子树还是左子树
            //如果是左子树，直接返回父节点，否则向上迭代直到是父节点的左子树，返回父节点
            TreeLinkNode* pF=pNode->next;
            while(pF!=NULL && pF->left!=pNode){
                pNode=pF;
                pF=pNode->next;
            }
            return pF;
            
        }
        return NULL;
        
    }
};