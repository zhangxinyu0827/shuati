//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项,n<=39
//循环实现
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        int i;
        int f1=1;
        int f2=1;
        int f;
        for(i=3;i<=n;i++){
            f=f1+f2;
            f2=f1;
            f1=f;
        }
        return f;
            
            

    }
};