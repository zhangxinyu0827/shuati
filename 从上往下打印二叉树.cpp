
/*从上往下打印出二叉树的每个节点，同
层节点从左至右打印
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> tmp;//建立一个vector
        vector<int> res;//建立一个vector
        if(root==NULL)
            return res;
        tmp.push(root);
        while(tmp.size()>0){
            if(tmp.front()->left!=NULL)
            	tmp.push((tmp.front()->left));
            if(tmp.front()->right!=NULL)
            	tmp.push((tmp.front()->right));
            
            res.push_back(tmp.front()->val);
            tmp.pop();
        }
        return res;
    }
};
public:
    string LeftRotateString(string str, int n) {
        if(n<=0 || str.size()<n ||str.size()<1)
            return str;
        fanzhuan(&str, 0, str.size()-1);
        fanzhuan(&str, 0, str.size()-n-1);
        fanzhuan(&str, str.size()-n, str.size()-1);
        return str;
        
    }
     void  fanzhuan(string *pstr,int begin,int end){
        if(begin>=end)
            return;
        char tmp;
        while(begin<end){
            tmp=(*pstr)[begin];
            (*pstr)[begin]=(*pstr)[end];;
            (*pstr)[end]=tmp;
            begin++;
            end--;
        }
        
    }
};