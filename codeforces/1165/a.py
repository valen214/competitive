

n, x, y = [int(i) for i in input().split(" ")]
l = input()

out = 0
for i in range(x):
    c = l[len(l) - i - 1]
    if i == y:
        if c == '0':
            out += 1
    elif c == '1':
        out += 1

print(out)