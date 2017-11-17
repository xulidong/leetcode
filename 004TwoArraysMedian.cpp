/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int index1 = 0;
        int index2 = 0;
        while (index1 < nums1.size() || index2 < nums2.size()) {
            if (index1 == nums1.size()) {
                nums.push_back(nums2[index2]);
                index2 += 1;
            }
            else if (index2 == nums2.size()) {
                nums.push_back(nums1[index1]);
                index1 += 1;
            } 
            else {
                if (nums1[index1] < nums2[index2]) {
                    nums.push_back(nums1[index1]);
                    index1 += 1;
                } else {
                    nums.push_back(nums2[index2]);
                    index2 += 1;
                }
            }
            
        }
        
        if (nums.size() % 2 == 0) {
            int mid = nums.size() / 2;
            return double(nums[mid - 1] + nums[mid]) / 2;
        } else {
            int mid = (nums.size() - 1)/ 2;
            return nums[mid];
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1{1, 3};
    vector<int> nums2{2};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3{1, 2};
    vector<int> nums4{3, 4};

    cout << sol.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}