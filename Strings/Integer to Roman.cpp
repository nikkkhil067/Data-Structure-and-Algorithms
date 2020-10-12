string intToRoman(int num) {
        string ch[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int mp[]= {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string ans;
        while(num)
        {
            for(int i=12;i>=0;i--)
            {
                int q=num/mp[i];
                if(q)
                {
                    while(q--)
                        ans+=ch[i];
                    num%=mp[i];
                    break;
                }
            }   
        }
}
