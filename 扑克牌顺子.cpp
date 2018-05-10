
/*LL今天心情特别好,因为他去买
了一副扑克牌,发现里面居然有2个
大王,2个小王(一副牌原本是54张^
_^)...他随机从中抽出了5张牌,想
测测自己的手气,看看能不能抽到顺
子,如果抽到的话,他决定去买体育彩
票,嘿嘿！！“红心A,黑桃3,小王,大王
,方片5”,“Oh My God!”不是顺子.....L
L不高兴了,他想了想,决定大\小 王可以

看成任何数字,并且A看作1,J为11,Q为12
,K为13。上面的5张牌就可以变成“1,2,3
,4,5”(大小王分别看作2和4),“So Lucky
!”。LL决定去买体育彩票啦。 现在,要求
你使用这幅牌模拟上面的过程,然后告诉
我们LL的运气如何。为了方便起见,你可
以认为大小王是0。
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5)
            return false;
        sort(numbers.begin(), numbers.end());//升
        int num0=0;
        int numGap=0;
        int i;
        for(i=0;i<numbers.size() && numbers[i]==0;i++){
            num0++;
        }
        int small=num0;
        int big=small+1;
        while(big<numbers.size()){
            if(numbers[small]==numbers[big])
                return false;
            numGap=numGap+numbers[big]-numbers[small]-1;
            small=big;
            big++;
        }
        if(numGap>num0)
            return false;
        return true;
        
    }
};