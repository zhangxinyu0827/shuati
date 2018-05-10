
/*输入一个递增排序的数组
和一个数字S，在数组中查找两个
数，是的他们的和正好是S，如
果有多对数字的和等于S，输出两
个数的乘积最小的。
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.size()<1)
            return res;
        int big=array.size()-1;
        int small=0;
        while(small<big){
            if(array[small]+array[big]==sum){
                res.push_back(array[small]);
                res.push_back(array[big]);
                break;
            }
            while(array[small]+array[big]>sum && small<big)
                big--;
            small++;
        }
        return res;
        
    }
};
public:
    string LeftRotateString(string str, int n) {
        if(n<=0 || str.size()<n ||str.size()<1)
            return str;
        fanzhuan(&str, 0, str.size()-1);
        fanzhuan(&str, 0, str.size()-n-1);
        fanzhuan(&str, str.size()-n, str.size()-1);
        return str;
        
    }
     void  fanzhuan(string *pstr,int begin,int end){
        if(begin>=end)
            return;
        char tmp;
        while(begin<end){
            tmp=(*pstr)[begin];
            (*pstr)[begin]=(*pstr)[end];;
            (*pstr)[end]=tmp;
            begin++;
            end--;
        }
        
    }
};