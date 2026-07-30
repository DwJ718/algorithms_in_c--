#include<bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
public:
    vector<int> tops;//投票时刻最多票的选手，同票取最近被投的
    vector<int> times;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) 
    {
        unordered_map<int,int> votCounts;
        votCounts[-1] = -1;//初始化小的一个方便后面比较
        int top = -1;
        for(auto& p:persons)
        {
            votCounts[p]++;
            if(votCounts[p] >= votCounts[top])//>=
            {
                top = p;
            }
            tops.emplace_back(top);
        }
        this->times = times;
    }
    
    int q(int t) 
    {
        int pos = upper_bound(times.begin(),times.end(),t) - times.begin() - 1;
        return tops[pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

 /*
 #include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
    vector<int> tops;
    vector<int> sortedTimes;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();

        struct Vote {
            int t;     // time
            int idx;   // input order (用于同一时刻取“最近投票”)
            int p;     // person
        };

        vector<Vote> v;
        v.reserve(n);
        for (int i = 0; i < n; i++) {
            v.push_back({times[i], i, persons[i]});
        }

        // 按时间升序；同时间按 idx 升序（后投的 idx 更大，会在后面）
        sort(v.begin(), v.end(), [](const Vote& a, const Vote& b) {
            if (a.t != b.t) return a.t < b.t;
            return a.idx < b.idx;
        });

        unordered_map<int,int> cnt;
        int top = -1;

        tops.clear();
        sortedTimes.clear();

        for (auto &x : v) {
            cnt[x.p]++;

            int topVotes = (top == -1 ? 0 : cnt[top]);
            int pVotes = cnt[x.p];

            // 平局时：最近投到的人获胜
            if (pVotes >= topVotes) top = x.p;

            tops.push_back(top);
            sortedTimes.push_back(x.t);
        }
    }

    int q(int t) {
        int pos = upper_bound(sortedTimes.begin(), sortedTimes.end(), t) - sortedTimes.begin() - 1;
        return pos >= 0 ? tops[pos] : -1;
    }
};
//当时间并非递增时的写法
 */