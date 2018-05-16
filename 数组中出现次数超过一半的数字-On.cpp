/*数组中有一个数字出现的
次数超过数组长度的一半，
请找出这个数字。例如输入一个
长度为9的数组{1,2,3,2,2,2,5,4,2}
。由于数字2在数组中出现了5次，超过
数组长度的一半，因
此输出2。如果不存在则输出0*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int i;
        if(numbers.size()<1)
            return 0;
        int num=1;
        int cur_n=numbers[0];
        for(i=1;i<numbers.size();i++){
            if(num==0)
                {cur_n=numbers[i];num==1;}
            else
            {
                if(cur_n==numbers[i])
                    num++;
                else
                    num--;
            }

        }
        num=0;
        for(i=0;i<numbers.size();i++){
            if(cur_n==numbers[i])
                num++;
        }
        if(num>numbers.size()*1.0/2)
            return cur_n;
        return 0;

    }
};