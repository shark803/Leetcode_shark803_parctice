//经典的动态规划  递归 +memorization
//这里采用一个hash表记录中间结果，避免重复的子结构的计算

class Solution {
public:
    unordered_map <int, int>    memo; 
    int coinChange(vector<int>& coins, int amount) {
          if (memo.find(amount) != memo.end()){
              return memo[amount];
          }
           if (amount == 0) 
           {
               return 0;
           }
           if (amount <0) {
               return -1;
           }
           int ans = INT_MAX;
           for (auto coin : coins){
               int  ans_tmp = coinChange(coins, amount-coin);
               if (ans_tmp == -1){
                   continue;
               }
               ans = min(ans, 1 + ans_tmp);
           }
           if (ans == INT_MAX){
               memo[amount] = -1;
           } else{
               memo[amount] = ans;
           }
            return memo[amount];
    }
};
