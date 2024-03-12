def solve():
    n= 92.0
    ans = 0.0
    for i in range(1, 2019):
        ans = ans + i**n
    ans = ans**(1.0/n)
    print(ans)
    return


def main():
    T = 1
    # T = int(input())
    for i in range(T):
        solve()


main()
