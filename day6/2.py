
with open("data.txt", 'r') as file:
    content = file.read().split("\n\n")

ans = 0

for answers in content:
    if "\n" not in answers: ans += len(answers)
    else:
        individual = answers.split("\n")
        ans += len(set(individual[0]).intersection(*(set(_) for _ in individual[1:])))
        
print(ans)