
/*小明很喜欢数学,有一天他
在做数学作业时,要求计算出9~
16的和,他马上就写出了正确答案
是100。但是他并不满足于此,他在想
究竟有多少种连续的正数序列的和为
100(至少包括两个数)。没多久,他就得
到另一组连续正数和为100的序列:18,1
9,20,21,22。现在把问题交给你,你
能不能也很快的找出所有和为S
的连续正数序列? Good Luck!
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum<3)
            return res;
        int small=1;
        int big=2;
        int mid=(1+sum)/2;
        int curSum=small+big;
        while(small<mid){
            if(curSum==sum){
                vector<int> res_i;
                for(int i=small;i<=big;i++)
                    res_i.push_back(i);
                res.push_back(res_i);
            }
            while(curSum>sum && small<mid){
                curSum=curSum-small;
                small++;
                if(curSum==sum){
                    vector<int>  res_i;
                    for(int i=small;i<=big;i++)
                        res_i.push_back(i);
                    res.push_back(res_i);
                }
            }
            big++;
            curSum=curSum+big;
                
        }
        return res;
    }
};