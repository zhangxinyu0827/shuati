//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//需要考虑底数为0，其他情况指数为负数
class Solution {
public:
    double Power(double base, int exponent) {
        if(base==0 && exponent<=0) //0 的正整数次幂为0
            return 0;
        if(exponent==0)
            return 1;
        int flag=0;//标记是否是正数次幂
        double res=1;
        if(exponent<0){
            flag=1;
            exponent=-exponent;
        }
        for(int i=1;i<=exponent;i++){
            res=base*res;
        }
        if(flag==1)
            res=1./res;
        return res;

    }
};