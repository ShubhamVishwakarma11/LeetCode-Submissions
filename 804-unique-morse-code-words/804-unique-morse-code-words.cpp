class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> hash;
        
        for (auto it: words) {
            string s = "";
            for (char c: it) {
                // s.push_back(arr[c-'a']);
                string str = arr[c-'a'] ;
                s += str;
            }
            // cout << it << endl;
            hash.insert(s);
        }
        
        return hash.size();
    }
};