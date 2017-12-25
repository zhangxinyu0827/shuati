//操作给定的二叉树，将其变换为源二叉树的镜像。
//输入描述:

//二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

//将每一个节点的左右子树交换即可，直到遍历所有节点
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL )
            return;
        if(pRoot->left==NULL && pRoot->right==NULL )
            return;
        TreeNode *ptmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=ptmp;
        Mirror(pRoot->left );
        Mirror(pRoot->right );

    }
};