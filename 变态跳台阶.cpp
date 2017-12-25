//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
//f(n)=f(n-1)+f(n-2)...+f(1)+1
class Solution {
public:
    int jumpFloorII(int number) {
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        int tmp_sum=3,num;
        for(int i=3;i<=number;i++){
            num=tmp_sum+1;
            
            tmp_sum=tmp_sum+num;
        }
        return num;
            
        

    }
};