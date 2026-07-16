n, m = map(int, input().split())
adj = [] * 300000
for i in range(m):
    u, v = map(int, input().split())
    adj[v].append(u)
q = int(input())
A = [False] * (n + 1)
while q > 0:
    q -= 1
    a, b = map(int, input().split())
    
    if a == 1:
        color(b)
    def color(u):
        if A[u] == True:
            return 
        A[u] = True
        for v in adj[u]:
            color(v)
    if a == 2:
        if A[b] == True: print("Yes")
        else: print("No")

        

