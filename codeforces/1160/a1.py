
# python a1.py < a1_1.txt

n = int(input())
x, y, d, p, l, h = [list(a) for a in
        zip(*[[int(x) for x in y.split(" ")]
        for y in [input() for z in range(n)]])]


print(x)
print(y)
print(d)
print(p)
print(l)
print(h)