
/*请实现一个函数用来找出字符流中第一
个只出现一次的字符。例如，当从字符流
中只读出前两个字符"go"时，第一个只出现
一次的字符是"g"。当从该字符流中读出前六
个字符“google"时，第
一个只出现一次的字符是"l"。。
*/
class Solution
{
public:
    Solution(){
        ind=0;
        for(int i=0;i<256;i++)
            jishu[i]=-1;
        
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        if(jishu[ch]==-1)
            jishu[ch]=ind;
        else
            jishu[ch]=-2;//有重复
        ind++;
        
         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch='#';
        int min_ind=10000;
        for(int i=0;i<256;i++){
            if(jishu[i]>=0 && jishu[i]<min_ind){
                ch=char(i);
                min_ind=jishu[i];
            }
                
        }
        return ch;
            
    
    }
    private:
    int ind;
    int jishu[256];

};