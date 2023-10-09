
def solution():
    n = int(input())
    res = -1;
    for _ in range(n):
        d, s = map(int, input().split())
        if s % 2 == 0:
            s -= 1
        last_legal_room = d + s // 2
        if res == -1 or res > last_legal_room:
            res = last_legal_room
    # if res != -1:
    print(res)


for _ in range(int(input())):
    solution()
