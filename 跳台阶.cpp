//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//变种的斐波那契
class Solution {
public:
    int jumpFloor(int number) {
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        int num1=2,num2=1,num=0;
        for(int i=3;i<=number;i++){
            num=num1+num2;
            num2=num1;
            num1=num;
        }
        return num;
            
        
    }
};