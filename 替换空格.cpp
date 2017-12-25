//替换空格
//请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
//先统计数目，然后生成空间，最后从后往前来替换
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==NULL |  length<=0)
            return;
        int kongge_num=0;
        int orige_num=0;
        int i=0;
        while(str[i]!='\0'){
            if(str[i]==' ')
                kongge_num++;
            orige_num++;
            i++;
        }
        int new_length=orige_num+kongge_num*2;
        if(new_length>length)
            return;
        int j=new_length;
        str[j--]='\0';
        for(i=orige_num-1;i>=0;i--)
             if(str[i]==' ')
             {
                 str[j--]='0';
                 str[j--]='2';
                 str[j--]='%';
             }
             else
             {
                 str[j--]=str[i];
                 
             }
        
	}
};