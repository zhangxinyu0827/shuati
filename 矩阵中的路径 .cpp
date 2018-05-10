
/*请设计一个函数，用来判断在一个矩阵中是
否存在一条包含某字符串所有字符的路径。路
径可以从矩阵中的任意一个格子开始，每一步可
以在矩阵中向左，向右，向上，向下移动一个格
子。如果一条路径经过了矩阵中的某一个格子，
则该路径不能再进入该格子。 例如 a b c e s 
f c s a d e e 矩阵中包含一条字符串"bcced"的
路径，但是矩阵中不包含"abcb"路径，因为字符
串的第一个字符b占据了矩阵中的第一行
第二个格子之后，路径不能再次进入该格子。*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        
        if(str==NULL || matrix==NULL)
            return false;
        int i,j;
        bool res=false;
        for(i=0;i<rows;i++)
            for(j=0;j<cols;j++)
            {
                if(matrix[i*cols+j]==str[0])
                {
                    int *bj=new int[cols*rows];
                    bj[i*cols+j]=1;
                    //判断在当前位置能否上下左右走
                    res=p_sxzy(matrix,rows,cols,str,bj,i,j,0);
                    if(res==true)
                        return res;
                    
                }
            }
        return res;
        
    
    }
    
    bool p_sxzy(char* matrix, int rows, int cols, char* str,int* bj,int i,int j,int cur)
    {
        bool res=false;
        if(str[cur+1]== '\0')
            return true;
        //上下左右
        if((i-1>=0) && (bj[(i-1)*cols+j]==0) && (matrix[(i-1)*cols+j]==str[cur+1])){
            bj[(i-1)*cols+j]=1;
            res=p_sxzy(matrix,rows,cols,str,bj,i-1,j,cur+1);
        }
        if(res==true)
            return res;
        if((i+1<rows) && (bj[(i+1)*cols+j]==0) && (matrix[(i+1)*cols+j]==str[cur+1])){
            bj[(i+1)*cols+j]=1;
            res=p_sxzy(matrix,rows,cols,str,bj,i+1,j,cur+1);
        }
        if(res==true)
            return res;
        if((j-1>=0) && (bj[(i)*cols+j-1]==0) && (matrix[(i)*cols+j-1]==str[cur+1])){
            bj[(i)*cols+j-1]=1;
            res=p_sxzy(matrix,rows,cols,str,bj,i,j-1,cur+1);
        }
        if(res==true)
            return res;
        if((j+1<cols) && (bj[(i)*cols+j+1]==0) && (matrix[(i)*cols+j+1]==str[cur+1])){
            bj[(i)*cols+j+1]=1;
            res=p_sxzy(matrix,rows,cols,str,bj,i,j+1,cur+1);
        }
        if(res==true)
            return res;
        return res;
    }
        
        
        


};