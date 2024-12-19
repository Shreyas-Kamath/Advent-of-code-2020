import re
pattern = r"(\d+-\d+) ([a-z]): ([a-z]+)"

ans = 0

def xor(password: str, range: str, char: str) -> bool:
    lhs, rhs = range.split('-')
    return (password[int(lhs) - 1] == char) != (password[int(rhs) - 1] == char)

with open("data.txt", 'r') as file:
    for line in file:
        line = line.strip()
        match = re.match(pattern, line)
        lhs, rhs = match.group(1).split('-')
        if xor(match.group(3), match.group(1), match.group(2)): ans += 1

print(ans)