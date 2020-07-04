def solution(A):
    ans = 1
    mn =  -float('inf')
    zeroC = 0
    negC = 0

    if len(A) == 1:
        return str(A[0])

    for N in A:
        if N < 0:
            mn = max( mn, N)
            negC+=1
        if N == 0:
            zeroC+=1
            continue
        
        ans*=N
    
    if zeroC == len(A):
        return str(0)
    
    if negC & 1:
        if (negC == 1 and zeroC > 0 and negC+ zeroC == len(A)): 
            return str(0)

        ans = str(int(ans/mn))
    
    return ans

print( solution([2, 0, 2, 2, 0]))