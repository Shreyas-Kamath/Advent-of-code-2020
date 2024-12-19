with open("data.txt", 'r') as file:
    nums = list(map(int, file.read().split('\n')))

target = 2020

for i in range(len(nums)):
    complement_sum = target - nums[i]
    map = dict()
    for j in range(i + 1, len(nums)):
        complement = complement_sum - nums[j]
        if complement in map:
            print(nums[i] * complement * nums[j])
            break
        map[nums[j]] = j

