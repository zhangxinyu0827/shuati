
/*请实现一个函数用来判断字符
串是否表示数值（包括整数和小数
）。例如，字符串"+100","5e2","-1
23","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+
-5"和"12e+4.3"都不是。
*/
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string==NULL)
            return false;
        if(*string=='+' || *string=='-')
            string++;
        if(*string=='\0')
            return false;
        bool res=true;
        scanDifit(&string);
        if(*string !='\0'){
            if(*string =='.'){
                string++;
                scanDifit(&string);
                if(*string =='e' || *string =='E')
                    res=scanE(&string);
            }
            else if(*string =='e' || *string =='E')
                    res=scanE(&string);
            else
                res=false;
        }
        return res && *string =='\0';

    }
     void scanDifit(char **string){
         while(**string!='\0' && **string>='0' && **string<='9' )
             (*string)++;
     }
    bool scanE(char **string){
         (*string)++;
        if(**string=='+' || **string=='-')
            (*string)++;
        if(**string=='\0')
            return false;
         scanDifit(string);
        if(**string =='\0'){
            return true;
        }
        return false;
    }
    

};