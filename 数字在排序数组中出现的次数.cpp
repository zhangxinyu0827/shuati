
/*统计一个数字在排序数组中出现的次数
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int num=0;
        int len=data.size();
        if(len>0){
            int first=getFirstK(data,0,len-1,k);
            int last=getLastK(data,0,len-1,k);
            if(first>-1 && last>-1)
                num=last-first+1;
        }
        return num;
            
    }
    int getFirstK(vector<int> data,int s,int e, int k){
        
        int m=(e+s)/2;
        while(1){
            if(s>e)
                return -1;
            if(data[m]==k){
                if(m==0  || data[m-1]<k)
                    return m;
                else{
                    e=m-1;
                    m=(e+s)/2;
                }
            }
            else if(data[m]>k){
                e=m-1;
                m=(e+s)/2;
            }
            else{
                s=m+1;
                
                m=(e+s)/2;
            }
                
                
        }
        
    }
    
     int getLastK(vector<int> data,int s,int e, int k){
        
        int m=(e+s)/2;
        while(1){
            if(s>e)
                return -1;
            if(data[m]==k){
                if( m==data.size()-1  || data[m+1]>k)
                    return m;
                else{
                    s=m+1;
                    m=(e+s)/2;
                }
            }
            else if(data[m]>k){
                e=m-1;
                m=(e+s)/2;
            }
            else{
                s=m+1;
                m=(e+s)/2;
            }
                
                
        }
        
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