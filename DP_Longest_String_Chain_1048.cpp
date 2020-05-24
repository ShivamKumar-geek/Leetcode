/*
MEDIUM:
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

*/


class Solution {
public:
    void sort(vector <string >& s, int n) 
{ 
    for (int i=1 ;i<n; i++) 
    { 
        string temp = s[i]; 
  
        // Insert s[j] at its correct position 
        int j = i - 1; 
        while (j >= 0 && temp.length() < s[j].length()) 
        { 
            s[j+1] = s[j]; 
            j--; 
        } 
        s[j+1] = temp; 
    } 
} 
    bool check(string str1 , string str2)
    {
        int flag=0;
        for(int i=0;i<str1.length();i++)
        {
            flag=0;
            for(int j=0;j<str2.length();j++)
                if(str1[i]==str2[j])
                    flag=1;
            if(flag==0)
                return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        sort(words,n);
        //for(int i=0;i<n;i++)
          //  cout<<words[i]<<" ";
        vector < int > dp (n,1);
        //for(int i=0;i<n;i++)
         //   cout<<dp[i]<<" ";
        for(int i=1;i<n;i++)
        {
           //cout<<"found 1"<<" ";
            for(int j=i-1; j>=0 ; j--)
            {
                if(words[j].length()==words[i].length()-1)
                {
                if(check(words[j],words[i]))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
                }
            }
        }
        int su=-1;
            for(int i=0;i<n;i++)
                if(dp[i]>su)
                    su=dp[i];
        return su;
    }
};