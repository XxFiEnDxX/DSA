#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxConsecutiveElements(vector<int>& nums) {
    int n = nums.size();
    
    // Sort the array
    sort(nums.begin(), nums.end());

    int maxElements = 0;
    int currentElements = 0;

    for (int i = 0; i < n; ++i) {
        // Increment the element by at most 1
        nums[i] = min(nums[i], i + 1);

        if (nums[i] > currentElements) {
            currentElements++;
            maxElements = max(maxElements, currentElements);
        }
    }

    return maxElements;
}

int main() {
    // vector<int> nums = {2, 1, 5, 1, 1};
    vector<int> nums = {3,2,6,1,4};
    int result = maxConsecutiveElements(nums);
    cout << result << endl;

    return 0;
}
