
def dfs0(v):
    global colors, paths
    colors[v] = True
    # if all(map(lambda x: colors[x], tree[v])):
    #     paths[v] = 1
    #     return 1
    cnt = 0
    for u in tree[v]:
        if colors[u]:
            continue
        cnt += dfs(u)
    if cnt == 0:
        cnt = 1
    paths[v] = cnt
    return cnt


def dynamoMachine():
    global colors, paths
    leaves = []
    # print(tree)
    i = 1
    for v in tree[2:]:
        i += 1
        if len(v) == 1:
            leaves.append(i)
            paths[i] = 1
            colors[i] = 1
            # print("__", i)
    while leaves:
        v = leaves.pop()
        # print(v)
        colors[v] = 2
        # print(tree[v])
        for u in tree[v]:
            if colors[u] == 2:
                continue
            if colors[u] != 1:
                leaves.append(u)
                colors[u] = 1
            paths[u] += paths[v]
            # print(u, "+=", paths[v])
            break


def solution():
    global n, tree, colors, paths
    n = int(input())
    tree = [[] for i in range(n + 1)]
    # paths = [-1] * (n + 1)
    paths = [0 for i in range(n + 1)]
    # colors = [False] * (n + 1)
    colors = [0 for i in range(n + 1)]
    for i in range(n - 1):
        v, u = map(int, input().split())
        tree[v].append(u)
        tree[u].append(v)

    dynamoMachine()
    # print(*paths)

    q = int(input())
    for i in range(q):
        x, y = map(int, input().split())
        print(paths[x] * paths[y])


for _ in range(int(input())):
    solution()
