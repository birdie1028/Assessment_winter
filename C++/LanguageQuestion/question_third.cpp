/**
 * @file question_third.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 /*
 执行一个 C++ 函数 findLongestIncreasingSubsequence，将整数向量作为输入，
 并返回最长递增子序列的长度。该函数不仅要找到长度，还要打印实际的子序列。

例如，给定输入向量[10, 22, 9, 33, 21, 50, 41, 60, 80]
函数应输出：
Longest Increasing Subsequence: 10, 22, 33, 50, 60, 80
Length of Longest Increasing Subsequence: 6

确保执行效率高，能处理较大的输入向量。考虑使用动态编程或其他优化算法来解决问题。

提示：最长递增子序列（LIS）问题是在给定序列中找到最长子序列的问题，
 */



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LongestIncreasingSubsequence 
{
public:
    static pair<int, vector<int>> findLongestIncreasingSubsequence(const vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return {0, {}};

        vector<int> dp(n, 1); 

        int maxLength = 1;
        int endIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) 
            {
                if (nums[i] > nums[j]) 
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > maxLength) 
                    {
                        maxLength = dp[i];
                        endIndex = i;
                    }
                }
            }
        }

        vector<int> longestSubsequence;
        longestSubsequence.push_back(nums[endIndex]);
        int len = maxLength - 1;
        for (int i = endIndex - 1; i >= 0; --i) {
            if (dp[i] == len && nums[i] < longestSubsequence.back()) 
            {
                longestSubsequence.push_back(nums[i]);
                len--;
            }
        }
        reverse(longestSubsequence.begin(), longestSubsequence.end());

        return {maxLength, longestSubsequence};
    }
};

int main() 
{
    vector<int> input = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    auto result = LongestIncreasingSubsequence::findLongestIncreasingSubsequence(input);

    cout << "Longest Increasing Subsequence: ";
    for (int num : result.second) 
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of Longest Increasing Subsequence: " << result.first << endl;

    return 0;
}
