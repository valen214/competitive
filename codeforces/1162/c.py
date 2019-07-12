

n, k = [int(i) for i in input().split(" ")]

l = [[-1, -1] for i in range(n)]
x = [int(i)-1 for i in input().split(" ")]

total = n * 3 - 2 # left, unchanged, right, -head, -tail

# 13
# 10
for i, v in enumerate(x):
    if l[v] == [-1, -1]:
        total -= 1
        l[v][:] = [i, i]
    elif i < l[v][0]:
        l[v][0] = i
    elif i > l[v][1]:
        l[v][1] = i
        

for i, v in enumerate(l):
    if i == 0:
        continue
    
    if 0 <= v[0] < l[i-1][1]:
        total -= 1
    
    if 0 <= l[i-1][0] < v[1]:
        total -= 1

print(total)