
from bisect import *

n = int(input())
l = [int(i) for i in input().split(" ")]
l.sort()

out = 1
i = bisect_left(l, out)
last_i = i
while i != n:
    out += 1
    i = bisect_left(l, out, last_i+1)
    last_i = i

print(out-1)
