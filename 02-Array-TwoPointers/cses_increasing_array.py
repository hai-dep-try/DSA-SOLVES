n = int(input())
sum = 0
a = list(map(int, input().split()))
for i in range(1, n):
    if a[i] < a[i - 1]:
        k = a[i-1] - a[i]
        sum += k
        k = 0
        a[i] = a[i-1]

print(sum)
        