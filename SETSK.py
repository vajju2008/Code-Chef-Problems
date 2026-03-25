# cook your dish here
# To determine if $S$ is a valid "resultant set," we must consider the elements not in 
import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    ptr = 1
    
    for _ in range(T):
        N = int(input_data[ptr])
        K = int(input_data[ptr+1])
        ptr += 2
        B = [0] + [int(x) for x in input_data[ptr:ptr+N]]
        ptr += N
        
        if sum(B) == 0:
            print("No")
            continue
            
        possible = True
        for i in range(1, N + 1):
            if B[i] == 1:
                for j in range(i + 1, min(i + K + 1, N + 1)):
                    if B[j] == 1:
                        possible = False
                        break
            else:
                covered = False
                for j in range(max(1, i - K), min(N + 1, i + K + 1)):
                    if B[j] == 1:
                        covered = True
                        break
                if not covered:
                    possible = False
            
            if not possible:
                break
        
        print("Yes" if possible else "No")

solve()