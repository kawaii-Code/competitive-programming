def sol_C(testNum):
    sum = 0;
    bin = 1;
    while testNum > 0:
        sum += testNum;
        testNum = testNum >> 1;

    return sum;


MAXNUMBER = 1e16 + 1;

n = int(input())

for t in range(n):
    print(sol_C(int(input())))