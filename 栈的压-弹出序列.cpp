//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
//同步做一个栈，看能否按照对应的出栈序列一致，如果正好能完全与弹出栈一致，则是真
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()==0 | popV.size()==0 | pushV.size()!=popV.size())
            return false;
        vector<int> pushV_tmp;
        int V_len=pushV.size();
        int cur_push_p=0;
        int cur_pop_p=0;
        
        while(cur_pop_p<V_len && cur_push_p<V_len ){
            pushV_tmp.push_back(pushV.at(cur_push_p++));
            while(pushV_tmp.size()>0 && cur_pop_p<V_len && popV.at(cur_pop_p)==pushV_tmp.at(pushV_tmp.size()-1)){
                cur_pop_p++;
                pushV_tmp.pop_back();
            }
            
            
        }
        if(cur_pop_p==V_len)
            return true ;
        else
            return false;
    }
};