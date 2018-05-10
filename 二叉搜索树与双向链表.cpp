

/*输入一棵二叉搜索树，将
该二叉搜索树转换成一个排序的
双向链表。要求不能创建任何新的结点，
只能调整树中结点指针的指向。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *res=pRootOfTree;
        while(res)
            res=res->left;
        TreeNode *wei=NULL;
        TreeNode **pwei=&wei;
        conv_sub(pRootOfTree,pwei);
        res=wei;
        while(res && res->left!=NULL)
            res=res->left;
        return res;
        
    }
    void conv_sub(TreeNode * pRootOfTree,TreeNode **pwei){
        if(pRootOfTree==NULL)
            return;
       
        conv_sub(pRootOfTree->left,pwei);
        if(*pwei==NULL)
            *pwei=pRootOfTree;
        else
        {
            (*pwei)->right=pRootOfTree;
            pRootOfTree->left=*pwei;
            *pwei=pRootOfTree;
        }
        conv_sub(pRootOfTree->right,pwei);
        
        
    }
        
        
        
};