#include <ranges>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return std::ranges::binary_search(
            std::views::iota(std::vector<vector<int>>::size_type{},
                             matrix.size() * matrix[0].size()),
            target, {}, [&matrix](size_t i) {
                return matrix[i / matrix[0].size()][i % matrix[0].size()];
            });
    }
};