
/*求出1~13的整数中1出现的
次数,并算出100~1300的整数中
1出现的次数？为此他特别数了一
下1~13中包含1的数字有1、10、11

、12、13因此共出现6次,但是对于后
面问题他就没辙了。ACMer希望你们帮
帮他,并把问题更加普遍化,可以很快
的求出任意非负整数区间中1出现的次数。
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
   

int count=0;
    long long i=1;
    for(i=1;i<=n;i*=10)
    {
        //i表示当前分析的是哪一个数位
        int a = n/i,b = n%i;
        count=count+(a+8)/10*i+(a%10==1)*(b+1);
    }
    return count; 
    }
};