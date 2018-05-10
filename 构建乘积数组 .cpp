
/*给定一个数组
A[0,1,...,n-1],请构
建一个数组B[0,1,...,n-1],
其中B中的元素
B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res(A.size());
        if(A.size()==0)
            return res;
        res[0]=1;
        int i;
        for(i=1;i<A.size();i++){
            res[i]=res[i-1]*A[i-1];
        }
        int tmp=1;
        for(i=A.size()-2;i>=0;i--){
            tmp=tmp*A[i+1];
            res[i]=res[i]*tmp;
        }
        return res;
    
    }
};