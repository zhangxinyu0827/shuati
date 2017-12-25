//旋转数组的最小数字 
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
//找到第一个变小的邻接点
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
            return 0;
        //int min=rotateArray.at(0);
        int i;
        for(i=1;i<rotateArray.size();i++){
            if(rotateArray.at(i-1)>rotateArray.at(i))
                break;
            
        }
        if(i==rotateArray.size())
            return rotateArray.at(0);
        return rotateArray.at(i);
            
    }
};