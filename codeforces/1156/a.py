

n = int(input())
a = [int(x) for x in input().split(" ")]

pts = 0
last = a[0]
for i in a[1:]:
    if last == 1:
        if i == 2:
            pts += 3
        elif i == 3:
            pts += 4
    elif last == 2:
        if i == 1:
            pts += 3
        elif i == 3:
            pts = -1
            break
    elif last == 3:
        if i == 1:
            pts += 4
        elif i == 2:
            pts = -1
            break
    last = i


if pts < 0:
    print("Infinite")
else:
    print("Finite")
    print(pts)