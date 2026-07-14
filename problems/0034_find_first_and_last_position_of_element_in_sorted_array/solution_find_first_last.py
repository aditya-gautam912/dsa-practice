from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def find_bound(is_left: bool) -> int:
            left, right = 0, len(nums) - 1
            bound = -1

            while left <= right:
                mid = (left + right) // 2

                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    bound = mid
                    if is_left:
                        right = mid - 1
                    else:
                        left = mid + 1

            return bound

        return [find_bound(True), find_bound(False)]
