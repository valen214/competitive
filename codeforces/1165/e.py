
n = int(input())
a = [int(i) for i in input().split(" ")]
b = [int(i) for i in input().split(" ")]

a_idx = {v:i for i, v in enumerate(sorted(range(n), key=lambda k:a[k]))}
b_idx = sorted(range(n), key=lambda k:b[k], reverse=True)

out = 0
for i in range(n):
    for j in range(i, n):
        for k in range(i, j):
            out += a[k] * b[b_idx[a_idx[k]]]

print(out % 998244353)