# cook your dish here
import sys

def solve():
 
    input_data = sys.stdin.read().split()
    
    if not input_data:
        return

    iterator = iter(input_data)
    num_test_cases = int(next(iterator))

    for _ in range(num_test_cases):
        try:
            n = int(next(iterator))
            # Read the arrays in the codzz
            arr = []
            for _ in range(n):
                arr.append(int(next(iterator)))

            # We assume the cost is 0 
            ans = 0
            
            # Walk backwards from the last index n-1 down to 0
            # remember: arr uses 0-based indexing, so value 1 should be at index 0
            for i in range(n - 1, -1, -1):
                correct_value = i + 1
                
                # If the value here is NOT what it should be...
                if arr[i] != correct_value:
                    # The cost is the value of the element currently here
                    ans = arr[i]
                    # We found the rightmost error. One sort fixes everything.
                    break 
            
            print(ans)
            
        except StopIteration:
            break

if __name__ == '__main__':
    solve()