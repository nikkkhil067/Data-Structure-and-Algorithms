#include<bits/stdc++.h>
using namespace std;
void longest_palindrome(string str)
{
    int max_length=1;
    int start=0;
    int low,high;
    int len=str.length();
    for(int i=1;i<len;i++)
    {
        low=i-1;
        high=i;
        while(low>=0 && high<len && str[low]==str[high])
        {
            if(max_length<(high-low+1))
            {
                max_length=high-low+1;
                start=low;
            }
            low--;
            high++;
        }
        
        low=i-1;
        high=i+1;
          while(low>=0 && high<len && str[low]==str[high])
        {
            if(max_length<(high-low+1))
            {
                max_length=high-low+1;
                start=low;
            }
            low--;
            high++;
        }
        
    }
    for(int i=start;i<(start+max_length);i++)
    {
        cout<<str[i];
    }
    cout<<"\n";
}
int main()
 {
	int T;
	cin>>T;
	while(T--)
	{
	    string str;
	    cin>>str;
	    longest_palindrome(str);
	}
	return 0;
}
