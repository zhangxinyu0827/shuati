//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//变相斐波那契,每加一个，要么是n-1的变种，要么是n-2的变种
class Solution {
public:
    int rectCover(int number) {
        //变相斐波那契
        if(number<=0)
            return 0;
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        int num,num1=2,num2=1;//记录当前值，往后数的1,2个值
        for(int i=3;i<=number;i++){
            num=num1+num2;
            num2=num1;
            num1=num;
        }
        return num;

    }
};