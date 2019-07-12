
t = int(input())
for t in range(t):
    n = int(input())
    d = [int(i) for i in input().split(" ")]
    print(min(d) * max(d))