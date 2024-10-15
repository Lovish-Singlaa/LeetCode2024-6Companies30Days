#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();

    if (n < 4) return result; // If less than 4 elements, no solution possible

    // Sort the array to make handling duplicates easier
    sort(nums.begin(), nums.end());

    // Traverse through the array and apply the 2-pointer approach
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for first number

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for second number

            // Two pointers for the remaining two numbers
            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for third and fourth numbers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < target) {
                    left++; // Need a larger sum, move the left pointer
                } 
                else {
                    right--; // Need a smaller sum, move the right pointer
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << " are: " << endl;
    for (const auto& quad : result) {
        cout << "[";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
