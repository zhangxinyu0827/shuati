#给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
#优化了一个地方，如果当前值大于上一个最大值，大于上一个的第一个值，则更新，否则重新比

# -*- coding:utf-8 -*-
class Solution:
    def maxInWindows(self, num, size):
        # write code here
        if len(num)-size<0 or size==0:
            return []
        
        res_max=[]#[[0]*(len(num)-size+1)];
        for i in range(0,len(num)-size+1):
            if i==0 :
                tmp_max=max(num[i:i+size])
                res_max.append(tmp_max)
                continue
            if num[i+size-1]>=tmp_max and num[i+size-1]>=num[i-1] :
                tmp_max=num[i+size-1]
                res_max.append(tmp_max)
                continue
            tmp_max=max(num[i:i+size])
            res_max.append(tmp_max)
        return res_max
            
            
        