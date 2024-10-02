import math

t = int(input())

def solve_batch():
    n = int(input())

    min_gold_addition = 0

    gold_distr = list(map(int, input().split()))

    sum_gold = sum(gold_distr)
    max_gold = max(gold_distr)

    if n == 0 or n == 1 or n == 2:
        print(-1)
        return

    poor_criteria = sum_gold / (2 * n)

    new_poor_man = sorted(gold_distr)[int(n / 2)]

    if new_poor_man < poor_criteria:
        print(0)
        return

    min_gold_addition = 2 * n * new_poor_man - sum_gold + 1

    print(min_gold_addition)


for i in range(t):
    solve_batch()