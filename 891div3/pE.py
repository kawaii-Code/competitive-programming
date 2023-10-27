def sol_E(n, x):
    s = 0
    for elem in x:
        s += elem
    old_x = x
    x = sorted(x)
    ans = {}
    # print(s)
    last_elem = 1
    for i in range(len(x)):
        dist = x[i] -last_elem;
        numLess = i
        numGreatOrEqual = len(x) - i
        f = s + numLess * dist - numGreatOrEqual * dist
        s = f
        last_elem = x[i]
        ans[x[i]] = f
    for i in range(len(old_x)):
        print(ans[old_x[i]])


for t in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    sol_E(n, x)
