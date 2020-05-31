class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    map<int, int> idxDict;
    for (int i = 0; i<nums.size(); i++) {
      if (idxDict.find(target - nums[i]) != idxDict.end()) return {idxDict[target - nums[i]], i};
      idxDict[nums[i]] = i;
    }
    return {};
  }
};