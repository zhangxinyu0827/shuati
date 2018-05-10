
/*在数组中的两个数字，
如果前面一个数字大于后
面的数字，则这两个数字
组成一个逆序对。输入一个
数组,求出这个数组中的逆序
对的总数P。并将P对1000000
007取模的结果输出。 
即输出P%1000000007
*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int> data_tmp(data);
        vector<int> *pdata_tmp=&data_tmp;
        vector<int> *pdata=&data;
        long long num=0;

        num=sub_find(pdata ,pdata_tmp,0,data.size()-1);
        
        return num%1000000007;
        
    }
    long long sub_find(vector<int> *pdata ,vector<int> *pdata_tmp,int s,int e){
        if(s==e){
            (*pdata_tmp)[s]=(*pdata)[s];
            return 0;
        }
        if(s==e-1){
            if((*pdata)[s]>(*pdata)[e]){
                (*pdata_tmp)[s]=(*pdata)[e];
                (*pdata_tmp)[e]=(*pdata)[s];
                return 1;
            }
            (*pdata_tmp)[s]=(*pdata)[s];
            (*pdata_tmp)[e]=(*pdata)[e];
            return 0;
        }
        int mid=(e-s)/2;
        long long ln=sub_find(pdata_tmp,pdata,s,s+mid);
        long long rn=sub_find(pdata_tmp,pdata,s+mid+1,e);
        int i=s+mid;
        int j=e;
        int i_tmp=e;
        long long count=0;
        while(i>=s && j>=s+mid+1){
            if((*pdata)[i]>(*pdata)[j]){
                count=count+j-s-mid;
                (*pdata_tmp)[i_tmp--]=(*pdata)[i--];
            }
            else
                (*pdata_tmp)[i_tmp--]=(*pdata)[j--];
            
        }
        for(;i>=s;i--)
            (*pdata_tmp)[i_tmp--]=(*pdata)[i];
        for(;j>=s+mid+1;j--)
            (*pdata_tmp)[i_tmp--]=(*pdata)[j];
        return (count%1000000007+ln%1000000007+rn%1000000007)%1000000007;
        
    }
};