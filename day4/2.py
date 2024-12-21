import re

birth_year = re.compile(r"(byr:(192[0-9]|19[3-9][0-9]|200[0-2]))")
issue_year = re.compile(r"(iyr:(201[0-9]|2020))")
expir_year = re.compile(r"(eyr:(202[0-9]|2030))")
height = re.compile(r"(hgt:(1[5-8][0-9]|19[0-3])cm\b|hgt:(59|6[0-9]|7[0-6])in)")
hair_color = re.compile(r"(hcl:(#[0-9a-f]{6}))")
eye_color = re.compile(r"(ecl:(amb|blu|brn|gry|grn|hzl|oth))")
passport_id = re.compile(r"(pid:(\d{9})\b)")

reqs = [birth_year, issue_year, expir_year, height, hair_color, eye_color, passport_id]

with open("data.txt", 'r') as file:
    content = file.read().split("\n\n")

def test(passport: str, reqs: list[str]) -> bool:
    for req in reqs:
        if not re.search(req, passport): return False
    return True

ans = 0

for passport in content:
    if test(passport, reqs): ans += 1
print(ans)