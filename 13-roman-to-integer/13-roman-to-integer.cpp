class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hash;
        hash.insert({'I',1});
        hash.insert({'V',5});
        hash.insert({'X',10});
        hash.insert({'L',50});
        hash.insert({'C',100});
        hash.insert({'D',500});
        hash.insert({'M',1000});
        
        char last = 'I';
        int num = 0;
        reverse(s.begin(),s.end());
        for (int i=0;i<s.size();i++) {
            char curr = s[i];
            int lastNum = hash[last];
            int currNum = hash[curr];
            
            if (lastNum > currNum) num -= currNum;
            else num += currNum;
            
            last = curr;
        }
        
        return num;
    }
};