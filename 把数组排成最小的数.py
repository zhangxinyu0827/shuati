#输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
#做一个比较函数，判别替换后是否变大
#相当于一个排序

# -*- coding:utf-8 -*-
class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        res=''
        for tmp_i in range(len(numbers)) :
            for tmp_j in range(tmp_i+1,len(numbers)) :
                if bijiao(numbers[tmp_i],numbers[tmp_j])==1 :
                    tmp=numbers[tmp_i]
                    numbers[tmp_i]=numbers[tmp_j]
                    numbers[tmp_j]=tmp
        for tmp_ii in numbers :
            print tmp_ii
            res=res+str(tmp_ii)
        return res
def bijiao(number1,number2):
    if(number1==number2) :
        return 0
    str1=str(number1)
    str2=str(number2)
    if(number1*pow(10,len(str2)) + number2 > number2*pow(10,len(str1)) + number1)  :
        return 1
    else :
        return 0
        
