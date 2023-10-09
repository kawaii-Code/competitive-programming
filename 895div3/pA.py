
import math


def solution():
    a, b, c = map(int, input().split())
    delta = abs(a - b)
    print(math.ceil(delta / (2*c)))


for _ in range(int(input())):
    solution()
