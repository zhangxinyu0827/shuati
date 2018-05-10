
/*地上有一个m行和n列的方格。一个机器人
从坐标0,0的格子开始移动，每一次只能向左，
右，上，下四个方向移动一格，但是不能进入
行坐标和列坐标的数位之和大于k的格子。 例
如，当k为18时，机器人能够进入方格（35,37
），因为3+5+3+7 = 18。但是，它不能进入方
格（35,38），因为3+5+3+8 = 19。请问该机器
人能够达到多少个格子？*/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold <0) 
            return 0;
         int *all=new int[rows*cols];
         all[0]=1;
        //不能跳，所以是连续随机游走，如果能跳，则是排列组合
        //第一个1是0位置的。
        return 1+s(0,0,threshold,rows,cols,all)+xx(0,0,threshold,rows,cols,all)+z(0,0,threshold,rows,cols,all)+yy(0,0,threshold,rows,cols,all);
        
    }
    int s(int x,int y,int th, int r, int c,int *all){
        //不能上走的原因，到达上边界，已经走过这个点
        if(x-1<0 || all[(x-1)*c+y]==1 ||((x-1)%10+(x-1)/10+y%10+y/10>th))
            return 0;
        else{
            all[(x-1)*c+y]=1;
            return (1+s(x-1,y,th,r,c,all)+xx(x-1,y,th,r,c,all)+z(x-1,y,th,r,c,all)+yy(x-1,y,th,r,c,all));
    
        }
            
    }
    int xx(int x,int y,int th, int r, int c,int *all){
        //不能下走的原因，到达下边界，已经走过这个点.或者超过了阈值
        if(x+1>=r || all[(x+1)*c+y]==1 ||((x+1)%10+(x+1)/10+y%10+y/10>th))
            return 0;
        else{
            all[(x+1)*c+y]=1;
             return 1+s(x+1,y,th,r,c,all)+xx(x+1,y,th,r,c,all)+z(x+1,y,th,r,c,all)+yy(x+1,y,th,r,c,all);
    
        }
           
    }
    int z(int x,int y,int th, int r, int c,int *all){
         //不能左走的原因，到达左边界，已经走过这个点
        if(y-1<0 || all[x*c+y-1]==1 || (x%10+x/10+(y-1)%10+(y-1)/10>th))
            return 0;
        else{
            all[x*c+y-1]=1;
             return 1+s(x,y-1,th,r,c,all)+xx(x,y-1,th,r,c,all)+z(x,y-1,th,r,c,all)+yy(x,y-1,th,r,c,all);
    
        }
           
    }
    int yy(int x,int y,int th, int r, int c,int *all){
        //不能下走的原因，到达下边界，已经走过这个点.或者超过了阈值
        if( y+1>=c || all[x*c+y+1]==1 || (x%10+x/10+(y+1)%10+(y+1)/10>th))
            return 0;
        else{
            all[x*c+y+1]=1;
            return 1+s(x,y+1,th,r,c,all)+xx(x,y+1,th,r,c,all)+z(x,y+1,th,r,c,all)+yy(x,y+1,th,r,c,all);
    
        }
            
    }
};