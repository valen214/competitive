


class Node:
    def __init__(self, value = None, parent = None):
        self.parent = parent
        self.value = value
        self.child = []


        
n = int(input())

tree = { 0: Node() }

for i in range(n):
    x, y, c = [int(i) for i in range(3)]

    if y not in tree:
        tree[y] = Node()

    if x in tree:
        
    else:
        tree[x] = Node(c)


    if y in tree:
        tree[y].child.append(tree[x])
