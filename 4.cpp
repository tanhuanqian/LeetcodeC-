#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int l = nums2.size();
        if (l > n) {
            swap(nums1, nums2);
            swap(n,l);
        }

        int total = n + l;
        int half = (total + 1) / 2;
        int start = 0, end = n;

        while (start <= end) {
            int mid1 = (start + end) / 2;
            int mid2 = half - mid1;

            int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int right1 = (mid1 < n) ? nums1[mid1] : INT_MAX;
            int right2 = (mid2 < l) ? nums2[mid2] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            } else if (left1 > right2) {
                end = mid1 - 1;
            } else {
                start = mid1 + 1;
            }
        }
        return -1;  // This should never happen if the inputs are valid
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
