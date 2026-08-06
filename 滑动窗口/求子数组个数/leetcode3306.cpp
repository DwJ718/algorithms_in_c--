#include<bits/stdc++.h>//万能头文件
using namespace std;
int main() {

   return 0;
}

class Solution {
public:
    long long countOfSubstrings(string word, int k) 
    {
        int n=word.size();
        int ll=0,lr=0;
        vector<int> cnt_1(26,0);
        vector<int> cnt_2(26,0);
        int s1=0;
        int s2=0;
        long long ans=0;
        for(int r=0;r<n;r++)
        {
            cnt_1[word[r]-'a']++;
            if(word[r]!='a'&&word[r]!='e'&&word[r]!='i'&&word[r]!='o'&&word[r]!='u')
                s1++;
            while(cnt_1[0]&&cnt_1[4]&&cnt_1[8]&&cnt_1[14]&&cnt_1[20]&&s1>=k+1)
            {
                cnt_1[word[ll]-'a']--;
                if(word[ll]!='a'&&word[ll]!='e'&&word[ll]!='i'&&word[ll]!='o'&&word[ll]!='u')
                    s1--;
                ll++;
            }
            //
            cnt_2[word[r]-'a']++;
            if(word[r]!='a'&&word[r]!='e'&&word[r]!='i'&&word[r]!='o'&&word[r]!='u')
                s2++;
            while(cnt_2[0]&&cnt_2[4]&&cnt_2[8]&&cnt_2[14]&&cnt_2[20]&&s2>=k)
            {
                cnt_2[word[lr]-'a']--;
                if(word[lr]!='a'&&word[lr]!='e'&&word[lr]!='i'&&word[lr]!='o'&&word[lr]!='u')
                    s2--;
                lr++;
            }
        ans+=lr-ll;
        }
        return ans;
    }
};