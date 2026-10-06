class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        a = []

        for i in range(len(nums)):
            a.append([nums[i], i])

        a.sort()

        i = 0
        j = len(a) - 1

        while i < j:
            s = a[i][0] + a[j][0]

            if s < target:
                i += 1

            elif s > target:
                j -= 1

            else:
                x = a[i][1]
                y = a[j][1]

                if x < y:
                    return [x, y]
                else:
                    return [y, x]