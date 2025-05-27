class Solution
{
	// unordered map to store previously computed substrings
	unordered_map<string,bool> mp;

public:
	bool isScramble(string s1, string s2)
	{
		int n = s1.size();
		// check if the two strings are equal
		if (s1 == s2)
		{
			return true;
		}
		// initialize frequency vectors for s1, s2, and current substring
		vector a(26, 0), b(26, 0), c(26, 0);
		// check if the current substring has already been computed
		if (mp.count(s1 + s2))
		{
			return mp[s1 + s2];
		}
		// check all possible splits of the two strings
		for (int i = 1; i <= n - 1; i++)
		{
			int j = n - i;
			// update frequency vectors for s1, s2, and current substring
			a[s1[i - 1] - 'a']++;
			b[s2[i - 1] - 'a']++;
			c[s2[j] - 'a']++;
			// check if the current substring has the same characters
			if (a == b && isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
			{
				// if the substrings are scrambled versions of each other, return true
				mp[s1 + s2] = true;
				return true;
			}
			// check if the current substring and its complement have the same characters
			if (a == c && isScramble(s1.substr(0, i), s2.substr(j)) && isScramble(s1.substr(i), s2.substr(0, j)))
			{
				// if the substrings are scrambled versions of each other, return true
				mp[s1 + s2] = true;
				return true;
			}
		}
		// if none of the splits result in scrambled versions, return false
		mp[s1 + s2] = false;
		return false;
	}
};