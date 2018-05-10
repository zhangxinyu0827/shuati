
/*输入一颗二叉树和一个整
数，打印出二叉树中结点值
的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶
结点所经过的结点形成一条路径。
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
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        
        
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        vector<int> tmp_path;
        int tmp_sum=0;
        res = findPathMain(res,root,expectNumber,tmp_path,tmp_sum);
        return res;
    }
    vector<vector<int> > findPathMain( vector<vector<int> > res,TreeNode* root,int expectNumber,vector<int> tmp_path,int tmp_sum){
        tmp_path.push_back(root->val);
        tmp_sum=tmp_sum+root->val;
        bool isleaf=(root->left==NULL && root->right==NULL);
        if(isleaf && tmp_sum==expectNumber){
            res.push_back(tmp_path);
        }
        if(root->left!=NULL){
            res = findPathMain(res,root->left,expectNumber,tmp_path,tmp_sum);
        }
        if(root->right!=NULL){
            res = findPathMain(res,root->right,expectNumber,tmp_path,tmp_sum);
        }
        tmp_path.pop_back();
        tmp_sum=tmp_sum-root->val;
        return res;
            
    }
    
    
    
    
};