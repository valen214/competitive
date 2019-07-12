

n, m, r = [int(x) for x in input().split(" ")]
s = min([int(x) for x in input().split(" ")])
b = max([int(x) for x in input().split(" ")])

if b > s:
    print(r // s * b + r % s)
else:
    print(r)