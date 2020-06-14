class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> purse;
        for (auto bill : bills) {
            int charge = bill - 5;
            purse[bill]++;
            if (charge) {
                while (charge >= 10 && purse[10]) {
                    purse[10]--;
                    charge -= 10;      
                }
                while (charge >= 5 && purse[5]) {
                    purse[5]--;
                    charge -= 5;
                }
            }
            if (charge) return false;
        }
        return true;
    }
};