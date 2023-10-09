
import math


def solution():
    n, x, y = map(int, input().split())
    lcm = math.lcm(x, y)
    countX = n // x - n // lcm
    countY = n // y - n // lcm
    # if countY == countX:
    #     print(0)
    #     return
    sumY = ((1 + countY) * countY) // 2
    sumX = ((n + n - countX + 1) * countX) // 2
    print(sumX - sumY)


for _ in range(int(input())):
    solution()

