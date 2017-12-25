//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//分2步，1找根节点相同的，2递归的看是否完全一致

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res=false;
        if(pRoot1==NULL || pRoot2==NULL)
            return res;
        if(pRoot1->val==pRoot2->val)
            res=match_t1_t2(pRoot1,pRoot2);
        if(!res)
            res=HasSubtree(pRoot1->left, pRoot2);
        if(!res)
            res=HasSubtree(pRoot1->right, pRoot2);
        return res;

    }
    bool match_t1_t2(TreeNode* pRoot1, TreeNode* pRoot2)
    {

        if(pRoot2==NULL)
            return true;
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val==pRoot2->val)
            return (match_t1_t2(pRoot1->left,pRoot2->left) && match_t1_t2(pRoot1->right,pRoot2->right));
        else
            return false;


    }
};
