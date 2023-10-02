
def solution():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    if n % 2:
        a.pop(n // 2)
        n -= 1
    return sum(a[n // 2:]) - sum(a[:n // 2])


for _ in range(int(input())):
    print(solution())
