class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
       queue<pair<string,int>>q;
       q.push({begin,1});
       unordered_set<string>s(word.begin(),word.end());
       s.erase(begin);
       while(!q.empty())
       {
        string w=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(w==end) return steps;
        for(int i=0;i<w.size();i++)
        {
            char org=w[i];
            for(char ch='a';ch<='z';ch++)
            {
              w[i]=ch;
              if(s.find(w)!=s.end())
              {
                s.erase(w);
                q.push({w,steps+1});
              }  
            }
            w[i]=org;
        }
       } 
       return 0;
    }
};