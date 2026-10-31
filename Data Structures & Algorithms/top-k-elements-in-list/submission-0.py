class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        most_common=Counter(nums).most_common(k)
        return [item[0] for item in most_common]