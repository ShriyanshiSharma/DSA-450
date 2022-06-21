// Non Repeating Numbers
/*
Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.

Example 1:
Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.

Example 2:
Input:
N = 1
arr[] = {2, 1, 3, 2}
Output:

1 3
Explanation:
1 3 occur exactly once.

Your Task:
You do not need to read or print anything. 
Your task is to complete the function singleNumber() which takes the array as input parameter and returns a list of two numbers which occur exactly once in the array. The list must be in ascending order.

Expected Time Complexity: O(N)
Expected Space Complexity: O(1)
*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        int a = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            a = a ^ nums[i];
        }
        int r = a & ~(a-1);
        int x = 0, y =0;
        for(int i = 0 ;i<n ;i++){
            if(nums[i] & r) x = x^nums[i];
            else y = y ^ nums[i];
        }
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(),ans.end());
        return ans;
    }
};