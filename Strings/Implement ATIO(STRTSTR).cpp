int myAtoi(string str) {
        int r=0;
        int sign = 1;
        int i = 0;
        while(i < str.size() && str[i] == ' ') {
            i++;   
        }
        if (i == str.size()) 
          return 0;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } 
        else if (str[i] == '+') {
            i++;
        }
        for (;i<str.size();i++) {
            if (str[i] > '9' || str[i] < '0') {
                return r*sign;
            }
                
            int n = str[i] - '0';
            if (r > (INT_MAX-n)/10) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            r = r*10 + n;
        }
        
        return r*sign;
    }
