# import sys
import math
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

n, k = map(int, input().split())
s = k * (k + 1) // 2
if(s > n):
    print(-1)
else:
    mx = 0
    i = 1
    while(i <= math.sqrt(n)):
        if(n % i == 0):
            if (i * s <= n):
                mx = i
            x = n / i
            if (x * s <= n):
                c = 1
                tot = 0
                count = 0
                while (count < k):
                    if (count == k - 1):
                        print(int(n - tot))
                        quit()
                    tot += c * x
                    print(int(x*c), end=" ")
                    c += 1
                    count += 1
        i += 1
    c = 1
    tot = 0
    count = 0
    while (count < k):
        if (count == k - 1):
            print(int(n - tot))
            quit()
        tot += c * mx
        print(int(mx * c), end=" ")
        c += 1
        count += 1
