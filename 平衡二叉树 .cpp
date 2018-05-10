
/*输入一棵二叉树，
判断该二叉树是否是平衡二叉树。
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth=0;
        int *pd=&depth;
        return sub_isb(pRoot,pd);

    }
    bool sub_isb(TreeNode* pRoot,int *pd){
        if(pRoot==NULL){
            *pd=0;
            return true;
        }
        int left=0;int right=0;
        if(sub_isb(pRoot->left,&left) && sub_isb(pRoot->right,&right)){
            int diff=left-right;
            if(diff>=-1 && diff<=1){
                if(left>right){
                    *pd=1+left;
                }
                else
                {
                    *pd=1+right;
                }
                return true;
            }
        }
        return false;
    }
        
        
    
};