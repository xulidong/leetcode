#include <iostream>

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int cnt = nums.size();
        for (int i = 0; i < cnt; i++) {
            int first = nums[i];
            for (int j = i + 1; j < cnt; j++) {
                int second = nums[j];
                if (target == first + second) {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{ 2, 7, 11, 15 };
    int tar = 92;
    Solution sol;
    vector<int> res = sol.twoSum(nums, tar);
    if (res.size() == 2) {
        cout << res[0] << " "<< res[1] << endl;
    } else {
        cout << "no res" << endl;
    }
    
    return 0;
}