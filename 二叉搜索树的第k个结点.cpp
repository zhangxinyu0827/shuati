
/*给定一颗二叉搜索树，
请找出其中的第k大的结点。
例如， 5 / \ 3 7 /\ /\ 2 
4 6 8 中，按结点数值大小顺
序第三个结点的值为4。*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL || k<=0)
            return NULL;
        return find( pRoot,  k);
        
    }
    TreeNode* find(TreeNode* pRoot, int &k){
        TreeNode* target=NULL;
        if(pRoot->left!=NULL){
            target=find( pRoot->left,  k);
        }
        if(target==NULL){//每一次target==NULL代表了一次返回
            if(k==1)
                target=pRoot;
            k--;
        }
        if(target==NULL && pRoot->right!=NULL){
            target=find( pRoot->right,  k);
        }
                
        return target;
    }

    
};

private:
        vector<int> min;
        vector<int> max;
public:
        void Insert(int num)
        {
           if(((min.size()+max.size())&1)==0)//偶数时 ，放入最小堆
           {
              if(max.size()>0 && num<max[0])
              {
                // push_heap (_First, _Last),要先在容器中加入数据，再调用push_heap ()
                 max.push_back(num);//先将元素压入容器
                 push_heap(max.begin(),max.end(),less<int>());//调整最大堆
                 num=max[0];//取出最大堆的最大值
                 //pop_heap(_First, _Last)，要先调用pop_heap()再在容器中删除数据
                 pop_heap(max.begin(),max.end(),less<int>());//删除最大堆的最大值
                 max.pop_back(); //在容器中删除
              }
              min.push_back(num);//压入最小堆
              push_heap(min.begin(),min.end(),greater<int>());//调整最小堆
           }
           else//奇数时候，放入最大堆
           {
              if(min.size()>0 && num>min[0])//if是需要先先在另一个堆过一遍的，否则直接加就可
              {
                // push_heap (_First, _Last),要先在容器中加入数据，再调用push_heap ()
                 min.push_back(num);//先压入最小堆
                 push_heap(min.begin(),min.end(),greater<int>());//调整最小堆
                 num=min[0];//得到最小堆的最小值（堆顶）
                 //pop_heap(_First, _Last)，要先调用pop_heap()再在容器中删除数据
                 pop_heap(min.begin(),min.end(),greater<int>());//删除最小堆的最大值
                 min.pop_back(); //在容器中删除
              }
              max.push_back(num);//压入数字
              push_heap(max.begin(),max.end(),less<int>());//调整最大堆
           }   
        }
        /*获取中位数*/      
        double GetMedian()
        {
            int size=min.size()+max.size();
            if(size<=0) //没有元素，抛出异常
                return 0;//throw exception("No numbers are available");
            if((size&1)==0)//偶数时，去平均
                return ((double)(max[0]+min[0])/2);
            else//奇数，去最小堆，因为最小堆数据保持和最大堆一样多，或者比最大堆多1个
                return min[0];
        }

};