with open("data.txt", 'r') as file:
    nums = list(map(int, file.read().split('\n')))

target = 2020
map = dict()

for index, num in enumerate(nums):
    complement = target - num
    if complement in map:
        print(complement * num)
        break
    map[num] = index