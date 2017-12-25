 //用两个栈实现队列 
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
//将元素入栈到栈1，弹栈时，2栈有元素则弹，没有则将1栈导到2栈

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int res;
        if(stack2.size()>0){
            res = stack2.top();
            stack2.pop();
            return res;
        }
           
        while(stack1.size()>0){
            stack2.push(stack1.top());
            stack1.pop();
        }
            

        res= stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};