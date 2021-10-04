class Solution {
public:
    bool isUnique(string astr) {
        unordered_set<char>   astr_set;
        bool ans = true;
        for(auto ch : astr){
           if (astr_set.find(ch) != astr_set.end()){
                ans = false;
                break;
           } else{
                astr_set.insert(ch);
           }
            
        }
        return ans;

    }
}
