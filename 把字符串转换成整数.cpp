
/*将一个字符串转换成一个整数，
要求不能使用字符串转换整数的库函
数。 数值为0或者字符串不是一个合
法的数值则返回0
*/
class Solution {
public:
    int StrToInt(string str) {
        int is_hefa=1;
        long long num=0;
        int fushu=0;
        int fuhao=0;
        if(str.size()>0){
            
            if(str[0]=='+')
                fuhao=1;
            else if(str[0]=='-'){
                fuhao=1;
                fushu=1;
            }
            if(str.size()-fuhao>0)
                num=getInt(str,fushu,fuhao,&is_hefa);
            else
                is_hefa=0;

        }
        else
            is_hefa=0;
         if(fushu==1)
             return -(int)num;
        else
            return (int)num;

        
    }
    
    long long getInt(string str,int fushu,int fuhao,int *is_hefa){
        long long num=0;
        for(int i=fuhao;i<str.size();i++){
            if(str[i]>='0' && str[i]<='9'){
                num=num*10+str[i]-'0';
                if((fushu==1 && -num<(int)0x80000000) || (fushu==0 && num>0x7FFFFFFF)){
                    num=0;break; *is_hefa=0;
                }
            }
            else
            {
                num=0;break;*is_hefa=0;
            }

        }
        return num;
    }
};