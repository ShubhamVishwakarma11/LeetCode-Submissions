class Solution {
public:
    
    
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int num1 = 0;
        int num2 = 1;
        int num = num1 + num2;
        
        for (int i=1;i<=n;i++) {
            num = num1 + num2;
            num2 = num1;
            num1 = num;
        }
        
        return num;
    }
};