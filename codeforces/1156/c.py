
from bisect import bisect_left
from collections import Counter

n, z = [int(x) for x in input().split(" ")]
x = Counter([int(x) for x in input().split(" ")])
t = sorted(x)

count = 0

left = 0
right = bisect_left(t, t[0]+z)

while right < len(t):
    i = t[left]
    j = t[right]

    if j-i >= z:
        count += 1
        
        x[j] -= 1
        if x[j] == 0:
            t.pop(right)
        
        x[i] -= 1
        if x[i] == 0:
            t.pop(left)
            right -= 1

        if right <= left:
            right = left + 1
    else:
        right += 1

print(count)