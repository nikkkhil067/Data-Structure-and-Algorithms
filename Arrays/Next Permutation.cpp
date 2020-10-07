//Next Permutation
/*
1) An sequence sorted in descending order does not have next permutation. For example edcba” does not have next permutation.
2) For a sequence which is not sorted in descending order for example “abedc”, we can follow below steps.
……….a) Traverse from right and find the first item that is not following the descending order. 
        For example in “abedc”, the character ‘b’ does not follow the descending order.
……….b) Swap the found character with closest greater (or smallest greater) element on right side of it. 
        In case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, string becomes “acedb”.
……….c) After swapping, sort the string after the position of character found in step a.
         After sorting the substring “edb” of “acedb”, we get “acbde” which is the required next permutation.

Optimizations in step b) and c)
a) Since the sequence is sorted in decreasing order,
     we can use binary search to find the closest greater element.
c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), 
    we can get the sequence sorted (in increasing order) after reversing it.
*/
#include <iostream> 
using namespace std; 
  
void swap(char* a, char* b) 
{ 
    if (*a == *b) 
        return; 
    *a ^= *b; 
    *b ^= *a; 
    *a ^= *b; 
} 
void rev(string& s, int l, int r) 
{ 
    while (l < r) 
        swap(&s[l++], &s[r--]); 
} 
  
int bsearch(string& s, int l, int r, int key) 
{ 
    int index = -1; 
    while (l <= r) { 
        int mid = l + (r - l) / 2; 
        if (s[mid] <= key) 
            r = mid - 1; 
        else { 
            l = mid + 1; 
            if (index == -1 || s[index] >= s[mid]) 
                index = mid; 
        } 
    } 
    return index; 
} 
  
bool nextpermutation(string& s) 
{ 
    int len = s.length(), i = len - 2; 
    while (i >= 0 && s[i] >= s[i + 1]) 
        --i; 
    if (i < 0) 
        return false; 
    else { 
        int index = bsearch(s, i + 1, len - 1, s[i]); 
        swap(&s[i], &s[index]); 
        rev(s, i + 1, len - 1); 
        return true; 
    } 
} 
  
// Driver code 
int main() 
{ 
    string s = { "abedc" }; 
    bool val = nextpermutation(s); 
    if (val == false) 
        cout << "No Word Possible" << endl; 
    else
        cout << s << endl; 
    return 0; 
} 
/*
Time Complexity:
In the worst case, the first step of next_permutation takes O(n) time.

Binary search takes O(logn) time.

Reverse takes O(n) time.

Overall time complexity is O(n).
Where n is the length of the string.
*/
