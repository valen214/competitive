

n, h, m = [int(i) for i in input().split(" ")]
houses = [h] * n

for i in range(m):
    l, r, x = [int(i) for i in input().split(" ")]
    for i in range(l, r+1):
        if houses[i-1] > x:
            houses[i-1] = x

s = 0
for i in houses:
    s += i ** 2
    
print(s)