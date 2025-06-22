class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> v(26,0);
        for(auto& ch:word){
            v[ch - 'a']++;
        }

        sort(begin(v), end(v));

        int n=v.size();
        int ans = INT_MAX;
        
        int l=0, r=0, cur_ele=0;

        while(v[l]==0){l++;}
        r=l;

        while(r<n){

            while((v[r] - v[l]) > k){
                int range = v[l] + k;
                int part_from_other = (n-r) * (range);

                int remaining = word.size() - (cur_ele + part_from_other);
                ans = min(ans, remaining);

                cur_ele -= v[l];
                l++;
            }

            cur_ele+=v[r];

            r++;
        }

        int remaining = word.size() - cur_ele;
        ans = min(ans, remaining);

        return ans;
    }
};