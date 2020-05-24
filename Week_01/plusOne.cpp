class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i>=0&&carry; i--){
            if(digits[i]+carry>=10){
                digits[i] = (digits[i]+carry)%10;
                carry=1;
            }
            else{
                digits[i] += carry;
                carry = 0;
            }
        }
        if(carry)digits.insert(digits.begin(), 1);
        return digits;
    }
};