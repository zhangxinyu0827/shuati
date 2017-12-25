// 	二维数组中的查找 
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int hang_size = array.size();
        int lie_size =array.at(0).size();
        if(hang_size<=0|| lie_size<=0)
            return 0;
        int i=0;
        int j=lie_size-1;
       
        while(i<hang_size && j>=0){
            if(array.at(i).at(j)==target)
            	return 1;
            if(array.at(i).at(j)>target)
            {j--; continue;}
            if(array.at(i).at(j)<target)
            {i++;continue;}
                
        }
       
        
        return 0;
    }
};