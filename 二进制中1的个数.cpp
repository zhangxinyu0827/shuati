//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
//方法1，定义一个1，逐渐向左移位，知道溢出为0
///方法2，直接直接干掉最后一个1
class Solution {
public:
     int  NumberOf1(int n) {
         int tmp=1;
         int num=0;
         
         while(tmp!=0){
             if((tmp&n)==tmp)
                 num++;
             //n=n>>1;
             tmp=tmp<<1;//增加到最大时，tmp变成了-0，即反码的0
         }
         /*
          while (n != 0) {
            ++count;
            n = (n - 1) & n;//直接干掉最后一个1，计算量小
        }*/
             
         return num;
     }
};