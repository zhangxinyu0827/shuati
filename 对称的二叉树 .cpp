
/*请实现一个函数，用来判断一

颗二叉树是不是对称的。注意，如
果一个二叉树同此二叉树的镜像是同样的，
定义其为对称的。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        return sub_pan(pRoot->left,pRoot->right);
    
    }
    bool sub_pan(TreeNode* pleft,TreeNode* pright){
        if(pleft==NULL)
            return (pright==NULL);
        if(pright==NULL)
            return false;
        if(pright->val!=pleft->val)
            return false;
        return   sub_pan(pleft->left,pright->right)  && sub_pan(pleft->right,pright->left);
        
        
        
        
        
        
        
    }
    

};


//法2
//看前序遍历和 对称前序遍历是否一致，注意NULL存下来