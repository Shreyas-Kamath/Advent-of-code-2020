import re
pattern = r"(\d+-\d+) ([a-z]): ([a-z]+)"

ans = 0

def find_index(index_str: str):
    lhs, rhs = index_str.split('-')
    return int(lhs), int(rhs) + 1

with open("data.txt", 'r') as file:
    for line in file:
        line = line.strip()
        match = re.match(pattern, line)
        if match.group(3).count(match.group(2)) in range(*find_index(match.group(1))): ans +=1

print(ans)