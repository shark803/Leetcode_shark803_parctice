//全排列是经典的回溯问题，回溯问题有非常固定的模板
// 判断终止条件  --> 选择 --> 决策-->取消选择 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>>  res;
            vector<int>current;
            backtrack (res, current, nums);
            return res;
    }
    void backtrack(vector<vector<int>>& res,  vector<int>& current, vector<int>& nums){
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }
        for (auto num: nums){
            if (count(current.begin(),current.end(),num)){
                continue;
            }
            current.push_back(num);
            backtrack(res,current,nums);
            current.pop_back();
        }
    }
};
