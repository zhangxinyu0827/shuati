
/*输入一个字符串,按字典
序打印出该字符串中字符的所有
排列。例如输入字符串abc,则打印
出由字符a,b,c所能排列出来的所有字符串
abc,acb,bac,bca,cab和cba。
*/
class Solution {
public:
    vector<string> Permutation(string str) {
        
        vector<string> res;
        if(str.empty())
            return res;
        vector<string> *pres = &res;
        sub_per(str,0,pres);
        for(int i=0;i<res.size();i++){
             for(int j=res.size()-1;j>i;j--){
                 if(res[i]==res[j])
                     res.erase(res.begin()+j);
             }
            
        }
         for( int j=res.size()-1;j>-1;j--){
             for( int i=0;i<j;i++){
                 if(res[i]>res[j]){
                     string tmp=res[i];
                     res[i]=res[j];
                     res[j]=tmp;
                 }
             }
        }
            
            
            
        return res;
        
    }
    void sub_per(string str,int beg,vector<string> *pres){
        if(beg==str.size()-1)
            (*pres).push_back(str);
        for(int i=beg;i<str.size();i++){
            char tmp;
            tmp=str[i];
            str[i]=str[beg];
            str[beg]=tmp;
             sub_per(str,beg+1,pres);
            tmp=str[i];
            str[i]=str[beg];
            str[beg]=tmp;
        }
    }
};