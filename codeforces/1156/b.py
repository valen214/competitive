
from collections import Counter

def diffone(a, b):
    return abs(ord(a) - ord(b)) == 1

T = int(input())
for i in range(T):
    s = Counter(input())
    t = sorted(s)

    out = [t.pop()]
    last = 0
    while len(t):
        c = t.pop()

        if not diffone(c, out[0]):
            out.insert(0, c)
        elif not diffone(c, out[-1]):
            out.append(c)
        elif (diffone(c, out[len(out) // 2 - 1]) or
                diffone(c, out[len(out) // 2]) ):
                
            if last == c:
                t.insert(0, c)
                break
            last = c
            t.insert(0, c)
        else:
            out.insert(len(out) // 2, c)


    if len(t):
        print("No answer")
    else:
        print("".join([c * s[c] for c in out]))