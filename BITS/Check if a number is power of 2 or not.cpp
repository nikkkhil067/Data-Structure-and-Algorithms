bool isPowerOfTwo(int n)  
{  
    if (n == 0)  
        return 0;  
    while (n != 1)  
    {  
        if (n%2 != 0)  
            return 0;  
        n = n/2;  
    }  
    return 1;  
}  
//Time Complexity : 0(1)
