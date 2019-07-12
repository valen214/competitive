
n = int(input())
s = list(input())

s = {k: v for k, v in enumerate(s)}

l = 0
r = 1
out = 0

while r < n:
    if s[l] == s[r]:
        del s[r]
        r += 1
        out += 1
    else:
        l = r + 1
        r = l + 1

if (n - out) % 2:
    out += 1
    if r-1 in s:
        del s[r-1]
    else:
        del s[l]





print(out)
print("".join([c for k, c in s.items()]))