    for x = 0 to n do  
        for y = 0 to m do  
            if (x == 0 || y == 0) then   
                LCS(x, y) = 0  
            else if (Ax == By) then  
                LCS(x, y) =  LCS(x - 1,y - 1) + 1  
            else   
                LCS(x, y) = ) max(LCS(x ¨C 1, y) , LCS(x, y ¨C 1))  
            endif  
        endfor  
    endfor  