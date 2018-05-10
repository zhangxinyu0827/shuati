
/*一个整型数组里除了两个数字之外，
其他的数字都出现了两次。请写程序
找出这两个只
出现一次的数字。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2)
            return;
        int i;
        int res_yihuo=0;
        for( i=0;i<data.size();i++){
            res_yihuo=(res_yihuo^data[i]);
        }
        *num1=0;*num2=0;
        unsigned int ind1=find1(res_yihuo);
        for( i=0;i<data.size();i++){
            if(ind1is1(data[i],ind1))
                *num1=((*num1)^data[i]);
            else
                *num2=((*num2)^data[i]);
        }

    }
     unsigned  int find1(int res_yihuo){
         unsigned int ind=0;
         while((res_yihuo&1)==0 && ind<8*sizeof(int)){
             ind++;
             res_yihuo=res_yihuo>>1;
         }
         return ind;
             
     }
    bool ind1is1(int datai,unsigned int ind1){
        datai=datai>>ind1;
        return (datai&1);
    }
};