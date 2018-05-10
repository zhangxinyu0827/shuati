
/*输入一个整数数组，
判断该数组是不是某二叉搜
索树的后序遍历的结果。如果
是则输出Yes,否则输出No。假
设输入的数组的任意两个数字都互不相同。
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        //根据为节点分为2部分，前面都小，后面都大
        if(sequence.size()==0)
            return false;
        if(sequence.size()==1)
            return true;
        vector<int> vz;
        vector<int> vy;
        int i;
        for( i=0;i<sequence.size()-1;i++){
            if(sequence[i]<sequence[sequence.size()-1])
                vz.push_back(sequence[i]);
            else
                break;
        }
        for(;i<sequence.size()-1;i++){
            if(sequence[i]>sequence[sequence.size()-1])
                vy.push_back(sequence[i]);
            else
                return false;
        }
        if(vz.size()==0)
            return VerifySquenceOfBST(vy);
        else if(vy.size()==0)
            return VerifySquenceOfBST(vz) ;
        else
             return VerifySquenceOfBST(vz) & VerifySquenceOfBST(vy);

       
    }
        
};