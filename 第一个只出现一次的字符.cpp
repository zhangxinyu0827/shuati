
/*在一个字符串(1<=字符
串长度<=10000，全部由字
母组成)中找到第一个只出
现一次的字符,并返回它的位置
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int res=-1;
        int hashTable[256];
        int i;
        for(i=0;i<256;i++){
            hashTable[i]=0;
        }
        for(i=0;i<str.size();i++){
            hashTable[str[i]]=hashTable[str[i]]+1;
        }
        for(i=0;i<str.size();i++){
            if(hashTable[str[i]]==1){
                res=i;
                break;
            }
        }
        return res;
    }
};