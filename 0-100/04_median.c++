#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums;

    for (int x : nums1) nums.push_back(x);
    for (int x : nums2) nums.push_back(x);

    sort(nums.begin(), nums.end());

    int n = nums.size();

    if (n % 2 == 1) {
        return nums[n / 2];
    }

    return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
}

int main() {
    int m, n;

    cout << "Enter size of first array: ";
    cin >> m;

    vector<int> nums1(m);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n;

    vector<int> nums2(n);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    cout << "Median = " << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}