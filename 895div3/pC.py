import math

def gcd(a, b):
    while ((a != 0) and (b != 0)):
        if (a > b):
            a = a % b
        else:
            b = b % a
    return a + b

def eratosphenes(n):
    primes = [True for i in range(n + 1)]

    i = 2;
    while (i <= n):
        if primes[i]:
            j = i + i
            while j <= n:
                primes[j] = False
                j += i
        i += 1

    return primes

def getSomeDiv(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if not(n % i):
            return i

primes = eratosphenes(int(1e7))

def sol_C(l, r):
    if r < 4:
        print(-1)
        return

    for i in range(l, r + 1):
        if not primes[i]: # todo bin search
            div = getSomeDiv(i)
            print(div, i - div)
            return

    print(-1)


MAXNUMBER = 1e7;

# for i in eratosphenes(int(MAXNUMBER)):
#     print(i, end=', ')

for t in range(int(input())):
    l, r = map(int, input().split())
    sol_C(l, r)