class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        // Step 1: Sort the array to leverage the triangle inequality rule
        sort(nums.begin(), nums.end()); // O(n log n) for sorting the array

        int index = 0; // Index to find the first non-zero element
        int ans = 0;   // Counter for the number of valid triangles

        // Step 2: Skip all zero elements because a triangle side cannot be zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                index++; // Increment index for each zero
            } else {
                break; // Stop once a non-zero element is encountered
            }
        }

        // Step 3: Iterate through the sorted array to find valid triangles
        for (int i = index; i < nums.size(); i++) { // First side of the triangle
            for (int j = i + 1; j < nums.size() - 1; j++) { // Second side of the triangle
                // Use binary search to find the first element that is not valid
                auto it = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) 
                          - (nums.begin() + j);

                // `nums[i] + nums[j]` represents the maximum sum for the two sides of the triangle.
                // Subtract `(nums.begin() + j)` to find the count of valid numbers for the third side.

                ans += (it - 1); // Add valid combinations to the answer
            }
        }

        return ans; // Return the total number of valid triangles
    }
};