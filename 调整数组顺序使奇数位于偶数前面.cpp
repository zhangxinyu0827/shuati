//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//方法1，重新生成一个空间，先放奇数，后放偶数
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int p=0,q=0;//p指向第一个偶数，即后面的开始
        int max_num=array.size();
        p=0;
        vector<int> tmp;
        tmp.assign(array.begin(), array.end());
        int i=0;
        while(p<max_num){
            if(tmp.at(p)%2==1)
                array.at(i++)=tmp.at(p);
            p++;
        }
        p=0;
        while(p<max_num){
            if(tmp.at(p)%2==0)
                array.at(i++)=tmp.at(p);
            p++;
        }
    }
};