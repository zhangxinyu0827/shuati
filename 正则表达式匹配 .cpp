
/*请实现一个函数用来匹配包括'
.'和'*'的正则表达式。模式中的
字符'.'表示任意一个字符，而'*'
表示它前面的字符可以出现任意次
（包含0次）。 在本题中，匹配是指
字符串的所有字符匹配整个模式。例如
，字符串"aaa"与模式"a.a"和"ab*ac*a
"匹配，但是与
"aa.a"和"ab*a"均不匹配
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str==NULL || pattern==NULL)
            return false;
        return subM(str,pattern);
    
    }
    bool subM(char* str, char* pattern){
        if(*str=='\0' && *pattern=='\0')
            return true;
        if(*(pattern+1)=='*'){
            if(*str==*pattern || (*pattern=='.'&&  *str!='\0') )
                //对应于用1次，用0次，用多次
                return subM(str+1,pattern+2) ||  subM(str,pattern+2)  || subM(str+1,pattern);
            else
                //不等直接用0次
                return  subM(str,pattern+2);
            
        }
        if(*str==*pattern || (*pattern=='.'&&  *str!='\0') )
            return subM(str+1,pattern+1);
        return false;
            
    }
};