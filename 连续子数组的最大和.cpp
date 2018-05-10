
/*HZ偶尔会拿些专业问题
来忽悠那些非计算机专业的同学
。今天测试组开完会后,他又发话
了:在古老的一维模式识别中,常常
需要计算连续子向量的最大和,当向量
全为正数的时候,问题很好解决。但是
,如果向量中包含负数,是否应该包含
某个负数,并期望旁边的正数会弥补
它呢？例如:{6,-3,-2,7,-15,1,2,2}
,连续子向量的最大和为8(从第0个开始
,到第3个为止)。你会不会被他忽
悠住？(子向量的长度至少是1)
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res=-10000;
        int sum_tmp=0;
        if(array.size()<=0)
            return 0;
        for(int i=0;i<array.size();i++){
            if(sum_tmp<=0)
                sum_tmp=array[i];
            else
                sum_tmp=sum_tmp+array[i];
            if(sum_tmp>res)
                res=sum_tmp;
            
        }
        return res;
    
    }
};