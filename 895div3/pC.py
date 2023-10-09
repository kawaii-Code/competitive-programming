
isPrime = [True] * (n + 1)
for i in range(2, n + 1):
    if not isPrime[i]:
        continue
    for j in range(i + i, n + 1, i):
        if
