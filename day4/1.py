with open("data.txt", 'r') as file:
    content = file.read().split("\n\n")

def test(passport: str, reqs: list[str]) -> bool:
    for req in reqs:
        if req not in passport: return False
    return True

reqs = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]
ans = 0
for passport in content:
    if test(passport, reqs): ans += 1
print(ans)