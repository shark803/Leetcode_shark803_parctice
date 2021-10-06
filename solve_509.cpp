//最基础的dp，斐波那契数，套用模板就好

class Solution {
public:
    //题目限制   0<=n<=30
	vector<int> memo=vector<int>(31,-1);
    int fib(int n) {
        if(memo[n] != -1) return memo[n];
        if(n == 0) return 0;
        if (n==1) return 1;
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];

    }
};
