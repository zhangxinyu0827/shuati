
/*汇编语言中有一种移位指
令叫做循环左移（ROL），现在
有个简单的任务，就是用字符串

模拟这个指令的运算结果。对于
一个给定的字符序列S，请你把其
循环左移K位后的序列输出。例如
，字符序列S=”abcXYZdef”,要求输
出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
*/
class Solution {
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