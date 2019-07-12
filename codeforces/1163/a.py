
n, m = [int(i) for i in input().split(" ")]

lines = n
nodes = n

nodes -= m
lines -= (m*2) # 7 - 2*2 = 3 # nodes: 5

ans = -1
if m == 0 or m == 1:
    if n == 0:
        ans = 0
    else:
        ans = 1
elif lines <= 0:
    ans = n - m
else:
    ans = nodes - lines
    
print(ans)