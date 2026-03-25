# cook your dish here
def solve():
    n = int(input())
    b = list(map(int, input().split()))
    max_temp = max(b)
    b.sort()
    possible = True
    for i in range(n - 1):
        if b[i] == b[i + 1] and b[i] != max_temp:
            possible = False
            break
    print("Yes" if possible else "No")

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
