/* ------------------------------------------------------------------|
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。



示例 1:

输入: [1, 2, 0]
输出 : 3
示例 2 :

	输入 : [3, 4, -1, 1]
	输出 : 2
	示例 3 :

	输入 : [7, 8, 9, 11, 12]
	输出 : 1


	提示：

	你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
------------------------------------------------------------------*/

/*	排序方法				
*	时间复杂度为O(nlogn)，不满足题目要求
*	执行用时：4 ms, 在所有 C++ 提交中击败了60.43%的用户
*	内存消耗：9.7 MB, 在所有 C++ 提交中击败了18.54%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_map>

using namespace std;

int firstMissingPositive(vector<int>& nums) 
{
	size_t len = nums.size();

	if (len == 0)
	{
		return 1;
	}
	if (len == 1)
	{
		return (nums[0] == 1) ? 2 : 1;
	} 

	sort(nums.begin(), nums.end());


	if (nums[0] > 1)
	{
		return 1;
	}

	for (int i = 0; i < len; i++)
	{
		if (nums[i] <= 0)
		{
			continue;
		}
		else
		{
			if (i == len - 1)
			{
				if (nums[i] > 1 && nums[i - 1] <= 0)
				{
					return 1;
				}
				return nums[i] + 1;
			}
			if (nums[i] > 1 && nums[i - 1] <= 0)
			{
				return 1;
			}
			if (nums[i] == nums[i + 1] - 1 || nums[i] == nums[i + 1])
			{
				continue;
			}
			else
			{
				return nums[i] + 1;
			}
		}
	}
	return 1;
}
