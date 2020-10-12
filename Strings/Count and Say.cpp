string countAndSay(int n) {
    if(n == 1) return "1";
    if(n == 2)  return "11";
    string s = countAndSay(n-1), res = "";
    int i = 0;
    while(i < s.size()) {
         int j = i;
         while(j < s.size() and s[j] == s[i])
              j++;
         res += to_string(j - i) + s[i];
         i = j;
   }
   return res;
 }
