
/*在一个长度为n的
数组里的所有数字都在0
到n-1的范围内。 数组中某
些数字是重复的，但不知道有
几个数字是重复的。也不知道每
个数字重复几次。请找出数组中任意
一个重复的数字。 例如，如果输入长度
为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers==NULL || length<=0)
            return false;
        int i;
        for(i=0;i<length;i++){
            if(numbers[i]>=length || numbers[i]<=0)
                return false;
            
        }
        for(i=0;i<length;i++){
            while(numbers[i]!=i){
                if(numbers[i]==numbers[numbers[i]])
                {*duplication=numbers[i];return true;}
                int tmp=numbers[i];
                numbers[i]=numbers[tmp];
                numbers[tmp]=tmp;
            }
        }
        return false;
    }
};