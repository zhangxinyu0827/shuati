
/*输入某二叉树的前序遍历和
中序遍历的结果，请重建出
该二叉树。假设输入的前序遍
历和中序遍历的结果中都不含重复的数字。

例如输入前序遍历序列{1,2,4,7,3,5,6,8}和
中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode *root=NULL;
        if(pre.size()<=0 || vin.size()<=0 || pre.size()!= vin.size())
            return root;
        root=new TreeNode(pre.at(0));
        vector<int> pre_l, vin_l,pre_r,vin_r;
        int i=0;
        for( i=0;i<pre.size();i++){
            if(vin.at(i)==pre.at(0))
                break;
            pre_l.push_back(pre.at(i+1));
            vin_l.push_back(vin.at(i));
            
        }
         for(i=i+1;i<pre.size();i++){
            pre_r.push_back(pre.at(i));
            vin_r.push_back(vin.at(i));
            
        }
            
        
        root->left=reConstructBinaryTree(pre_l,vin_l);
        root->right=reConstructBinaryTree(pre_r,vin_r);
        return root;

    }
   
};