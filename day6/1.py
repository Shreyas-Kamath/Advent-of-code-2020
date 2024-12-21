with open("data.txt", 'r') as file:
    content = file.read().split("\n\n")

ans = 0

for answers in content:
    _ = answers.replace('\n', '')
    ans += len(set(_))

print(ans)