class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         // int Duplicated_Item_Num = 0;
         int j = 0;
         if (nums.size()<=1)return  nums.size();
         for(int i = 0; i < nums.size(); i++){
            if (nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};