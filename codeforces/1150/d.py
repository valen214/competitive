


n, q = [int(x) for x in input().split(" ")]
word = input()

w1, w2, w3 = [list() for i in range(3)]
w1_last, w2_last, w3_last = -1, -1, -1

for i in range(q):
    cmd = input().split(" ")
    i = int(cmd[1]) - 1
    if cmd[0] == '+':
        c = cmd[2][0]
        [w1, w2, w3][i].append(c)
        
    else:
        [w1, w2, w3][i].pop()