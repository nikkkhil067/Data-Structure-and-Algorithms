/*
Given a encoded binary string and a Huffman MinHeap tree, 
your task is to complete the function decodeHuffmanData(), 
which decodes the binary encoded string and return the original string. 

Example 1:

Input :
binaryString = 
0000000000001100101010101011111111010101010
Min Heap Tree =  
                $(20)
              /      \
            /          \
         $(8)            \
       /     \             \
    $(3)      \            $(12)
    /  \       \           /    \
B(1)    D(2)    E(5)    C(6)    A(6)

Output: AAAAAABCCCCCCDDEEEEE

Explanation:
The following chart can be made from the 
given min heap tree.
character    frequency    code
    A             6        00                 
    B             1        110
    C             6        01
    D             2        111    
    E             5        10

Example 2:

Input :
binaryString =
01110100011111000101101011101000111
Min Heap Tree =  
                         $(13)
                      /        \
                    /            \
                  /                \
               $(5)                  \
             /      \                  \
            /        \                   \
         $(3)         \                  $(8)
        /    \         \                /    \
     $(2)     \         \            $(4)     \
    /   \      \         \          /   \      \
f(1)    o(1)    r(1)    g(2)    k(2)    s(2)    e(4)

Output: geeksforgeeks

Explanation:
The following chart can be made from the 
given min heap tree.
character    frequency    code
    f             1        0000                 
    o             1        0001
    r             1        001
    g             2        01    
    k             2        100
    s             2        101
    e             4        11
*/
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;

map<char, string> codes;
map<char, int> freq;

struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

void HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}

void calcFreq(string str, int n)
{
	for (int i=0; i<str.size(); i++)
		freq[str[i]]++;
}

// complete this function
string decodeHuffmanData(struct MinHeapNode* root, string binaryString);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        string encodedString, decodedString;
        calcFreq(str, str.length());
        HuffmanCodes(str.length());
        for (auto i: str)encodedString+=codes[i];
        //cout<<encodedString<<endl;
        decodedString = decodeHuffmanData(minHeap.top(), encodedString);
        cout << decodedString << endl;
    }
	return 0;
}

string decodeHuffmanData(struct MinHeapNode* root, string code)
{
    string res="";
    
    MinHeapNode* cur=root;
    for(int i=0;i<code.length();i++)
    {
        if(cur->data=='$')
        {
            if(code[i]=='0')
            cur=cur->left;
            
            else cur=cur->right;
        }
        
        if(cur->data!='$')
        {
            res=res+cur->data;
            cur=root;
        }
    }
    
    return res;   
}

/*
Time Complexity: O(N log N)
Auxiliary Space: O(1)
*/