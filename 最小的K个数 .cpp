
/*输入n个整数，找出其中最小的
K个数。例如输入4,5,1,6,2,7,3,
8这8个数字
，则最小的4个数字是1,2,3,4,。
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
        vector<int> res;
        int num=input.size();
        if(input.size()<=0 || k<=0 || k>num)
            return res;
        
        int start=0;
        int end=num-1;
        vector<int> *pinput=&input;
        int ind=Partion2( pinput,  num, start,  end);
        while(ind!=k-1){
            if(ind>k-1){
                end=ind-1;
                ind=Partion2( pinput,  num, start,  end);
            }
            else{
                start=ind+1;
                ind=Partion2( pinput,  num, start,  end);
            }
        }
        for(int i=0;i<k;i++)
            res.push_back(input[i]);
        
        
        return res;
    }
    int Partion2(vector<int> *pinput, int num,int start, int end){
        int small=start-1;//记录比轴值小的最后一个数的位置，最后一个作为轴值
        for(int ind=start;ind<end;ind++){
            if((*pinput)[ind]<(*pinput)[end]){
                small++;
                if(small!=ind)//说明中间间隔了大的值，吧当前小值和大值交换
                {
                    int tmp=(*pinput)[ind];
                    (*pinput)[ind]=(*pinput)[small];
                    (*pinput)[small]=tmp;
                }
            }
        }
        small++;
        int tmp=(*pinput)[end];
        (*pinput)[end]=(*pinput)[small];
        (*pinput)[small]=tmp;
        return small;//最终轴值的位置
    }
};