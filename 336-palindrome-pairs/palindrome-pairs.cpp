class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        int stringNum; //stores original words array index of that string

        TrieNode(char val){
            this->value = val;
            for(int i = 0; i<26; i++){
                children[i] = 0;
            }
            this->stringNum = -1;
        }    
            
};
class Trie{
    TrieNode* root;

    void insertUtil(TrieNode* root, string &word, int i, int &stringNum){
        if(i >= word.size()){
            root->stringNum = stringNum;
            return;
        }
        int index = word[i]-'a';
        if(!root->children[index]){
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index], word, i+1, stringNum);
    }

    public:
        Trie(){
            root = new TrieNode('-'); //initialize root node
        }
        void insert(string& word, int &stringNum){
            insertUtil(root, word, 0, stringNum);
        }

        bool isPalindrome(string&s, int i, int j){
            while(i <= j){
                if(s[i] != s[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }

        void searchCase2(TrieNode* root, vector<int>&myPalindrome, string s){
            if(root->stringNum != -1){
                if(isPalindrome(s, 0, s.size()-1)){
                    myPalindrome.push_back(root->stringNum);
                }
            }

            for(int i = 0; i<26; i++){
                if(root->children[i] != 0){
                    s.push_back(i+'a');
                    searchCase2(root->children[i], myPalindrome, s);
                    s.pop_back();
                }
            }
        }

        void search(string& word, vector<int>&myPalindrome){
            TrieNode* curr = root;

            //case 1: when a prefix of string word exactly matches with a word in trie
            for(int i = 0; i<word.size(); i++){
                int index = word[i]-'a';

                if(curr->stringNum != -1){
                    //check rest of the search word is palindrome or not
                    if(isPalindrome(word, i, word.size()-1)){
                        myPalindrome.push_back(curr->stringNum);
                    }
                }

                if(curr->children[index]){
                    curr = curr->children[index];
                }
                else return;
            }

            //case 2: search word is a prefix of a word in the trie
            // check remaining subtree in thr trie for the palindrome
            searchCase2(curr, myPalindrome, "");

        }
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;

        Trie trie;
        //insert all words in reverse order and mark its stringNum as index of words array
        for(int i = 0; i<words.size(); i++){
            auto reverseword = words[i];
            reverse(reverseword.begin(), reverseword.end());
            trie.insert(reverseword, i);
        }
        //find palindromic pairs of each one
        for(int i = 0; i<words.size(); i++){
            vector<int>myPalindrome;//stores palindromic pairs of ith word
            trie.search(words[i], myPalindrome);

            for(auto it: myPalindrome){
                if(it != i){
                    ans.push_back({i, it});
                }
            }
        }
        return ans;
    }
};