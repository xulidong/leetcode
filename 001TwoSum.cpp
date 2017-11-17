/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
*/

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