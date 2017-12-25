//把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
//当前丑数一定是从原来的丑数乘以2 3 5 得来的，记录第一个超过当前数的丑数即可

class Solution {
public:
    int Min(int n1,int n2,int n3)
{
    int min=(n1<n2)?n1:n2;
    min=(min<n3)?min:n3;
    return min;
}
    int GetUglyNumber_Solution(int index) {
    int n=index;
    if(n<=0)
        return 0;

    int *u=new int[n];
    u[0]=1;//1为第一个丑数

    int t2=0;//记录M2的下标
    int t3=0;
    int t5=0;

    for(int i=1;i<n;i++)
    {
        while(u[t2]*2<=u[i-1])//查找到新的M2，即乘以2后第一个大于M的数
            t2++;
        while(u[t3]*3<=u[i-1])
            t3++;
        while(u[t5]*5<=u[i-1])
            t5++;
        int min=Min(u[t2]*2,u[t3]*3,u[t5]*5);
        u[i]=min;
        
    }

    return u[n-1];
    }
};
