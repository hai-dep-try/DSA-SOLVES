F = []
F.append(0)
F.append(input())
F.append(input())
#S = input()
n = 2
#print(F[1])

while n < 10:
    n += 1
    next = F[n-1] + F[n-2]
    F.append(next)
i = int(input())
print(F[i])

