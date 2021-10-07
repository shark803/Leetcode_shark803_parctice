// 考虑有重复的全排列，一个简单的做法，肯定是加一个set
// 另外，因为有重复，所以先排序，在利用swap来改善标准的回溯法的框架

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>>  res;
            set<vector<int>>  res_set;
            vector<int> cur;
            int start = 0;
            sort(nums.begin(),nums.end());
            backTrack(res, res_set, cur, nums, start);
            
            return res;
    }
    void backTrack( vector<vector<int>>&  res,set<vector<int>>& res_set,  \
    vector<int>& cur, vector<int>& nums, int  start){
        if (cur.size() == nums.size()){
            if (res_set.find(cur) == res_set.end()){
                res.push_back(cur);
            }
            res_set.insert(cur);
            return;
        }
        for (int j = start; j <  nums.size();j++){
            if (j == start || j> start && nums[j] != nums[start]){
                swap(nums[start],nums[j]);
                cur.push_back(nums[start]);
                backTrack(res, res_set,cur,nums,start+1);
                cur.pop_back();
                swap(nums[start],nums[j]);

            }
        }
    }
};
