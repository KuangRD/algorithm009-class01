class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dum_dict;
        for(int i = 0; i<nums.size();i++){
            if(dum_dict.find(target-nums[i]) != dum_dict.end()){
                return {dum_dict[target-nums[i]], i};
            }else{
                dum_dict[nums[i]] = i;
            }
        }
        return {};
    }
};