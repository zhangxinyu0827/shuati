//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
//记录当前左上角和右下角，同时记录方向，不同方向不同的遍历方法
//也可以用循环的方法实现
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        
        int x1=0,y1=0; 
        int x2=matrix.size()-1, y2=matrix.at(0).size()-1;
        vector<int> res;
        int yxzs=1;//控制上下左右
        res=sxzy_print(matrix,yxzs,res,x1,x2,y1,y2);
        return res;

    }
    vector<int> sxzy_print(vector<vector<int> > matrix,int yxzs,vector<int> res,int x1,int x2,int y1,int y2) {
        vector<int> res_new;
        res_new.assign(res.begin(), res.end());
        if(x1>x2 || y1>y2)
            return res;
        if(yxzs==1){
            for(int j=y1;j<=y2;j++){
                res_new.push_back(matrix.at(x1).at(j));
            }
            yxzs=2;
            x1++;
        }
        else if(yxzs==2){
            for(int i=x1;i<=x2;i++){
                res_new.push_back(matrix.at(i).at(y2));
            }
            yxzs=3;
            y2--;
        }
        else if(yxzs==3){
            for(int j=y2;j>=y1;j--){
                res_new.push_back(matrix.at(x2).at(j));
            }
            yxzs=4;
            x2--;
        }
        else if(yxzs==4){
            for(int i=x2;i>=x1;i--){
                res_new.push_back(matrix.at(i).at(y1));
            }
            yxzs=1;
            y1++;
        }
            
                
        
        
        return sxzy_print(matrix,yxzs,res_new,x1,x2,y1,y2);
    }
};