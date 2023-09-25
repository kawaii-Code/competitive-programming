# By Makima

def cn2(n):
    return (n * (n - 1)) // 2

def solution(test):
    left = 0;
    right = MAXNUMBER - 1;
    f = False;
    while (left < right):
        mid = (left + right) // 2;
        tcn = cn2(mid);
        if (tcn < test):
            left = mid + 1;
        else:
            right = mid;

    if (cn2(left) == test):
        f = True;
        return int(left);
    if (not f):
        while (cn2(left) > test):
            left -= 1;
    left += test - cn2(left);
    return int(left);


MAXNUMBER = 2648956421 + 1;

n = int(input())

for i in range(n):
    print(solution(int(input())))
