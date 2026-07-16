nums = list(map(int, input().split()))
nums.sort()
print(nums)
'''
k = 0
i = 0
while i < len(nums):
    j = i + 1
    print(i, j)
    if nums[i] == nums[j]:
        j += 1
    else:
        i = j
        k += 1
print(k)
'''
# Correct implementation using 2 pointers to overwrite duplicates
if not nums:
    k = 0
else:
    k = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1]:
            nums[k] = nums[i]
            k += 1
print(nums)
print(k)
# nums[:k] now contains the unique elements
