class Solution {
public:
    int maximum69Number (int num) {
        vector<int> vec;
        while (num > 0) {
            int x = num % 10;
            num = num / 10;
            vec.push_back(x);
        }
        int n = vec.size();
        
        
        reverse(vec.begin(), vec.end());
        
        for (int i=0;i<n;i++) {
            if (vec[i] == 6) {
                vec[i] = 9;
                break;
            }
        }
        
        
        
        num = 0;
        for (int i=0;i<n;i++) {
            num += vec[n-1-i] * pow(10, i);
        }
        
        return num;
    }
};