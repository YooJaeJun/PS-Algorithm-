from sys import stdin

def solution(n):
    ans = 0
    for i in range(n):
        num = int(stdin.readline());
        ans = ans + int(num)
    if ans < 0:
        print('-')
    elif ans > 0:
        print('+')
    else:
        print('0')

for i in range(0, 3):
    n = int(stdin.readline());
    solution(int(n))