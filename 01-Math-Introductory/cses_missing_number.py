n = int(input())
a = list(map(int, input().split()))
#print(a)
sum = 0
for i in range(len(a)):
    sum += a[i]
print(int(((n + 1)*n/2) - sum))