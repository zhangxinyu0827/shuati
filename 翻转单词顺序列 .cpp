
/*牛客最近来了一
个新员工Fish，每天早晨
总是会拿着一本英文杂志，写些句子在
本子上。同事Cat对Fish写的内容颇感兴趣
，有一天他向Fish借来翻看，但却读不懂它的
意思。例如，“student. a am I”。后来才意
识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对
一一的翻转这
些单词顺序可不在行，你能帮助他么？。
*/
class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size()<1)
            return str;
        int begin=0;
        int end=str.size()-1;
        fanzhuan(&str,begin,end);
        begin=0;
        end=0;
        while(begin<str.size()){
            if(str[begin]==' '){
                begin++;
                end++;
            }
            else if(str[end]==' '){
                fanzhuan(&str,begin,end-1);
                end++;
                begin=end;
            }
            else if(end==str.size()-1){
                fanzhuan(&str,begin,end);
                break;
            }
                
            
            else
                end++;
        }
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