//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
//做一个映射，一旦发现某一个值超过了一半，则停止
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int v_len=numbers.size();
        if(v_len==0)
            return 0;
        
        
        map<int, int> mapStudent; 
        for(int i=0;i<v_len;i++){
            mapStudent[numbers.at(i)]++;
            if( mapStudent[numbers.at(i)]>v_len*1.0/2 )
                return numbers.at(i);
            }
        
  
    	
  
    
        return 0;
    }
};