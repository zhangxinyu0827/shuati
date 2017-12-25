//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
//同时构建一个最小值的栈，同步更新当前最小值
class Solution {
public:
    stack<int> s;
    stack<int> min_s;
    int min_tmp;
    void push(int value) {
        s.push(value);
        if(s.size()==1)
            min_tmp=value;
        if(value<=min_tmp){
            min_tmp=value;
        }
        min_s.push(min_tmp);
    }
    void pop() {
        s.pop();
        min_s.pop();
    }
    int top() {
        if(!s.empty())
        	return s.top();
        else
            return 0;
    }
    int min() {
        if(s.size()>0)
            return min_s.top();
        else
            return 0;
    }
};