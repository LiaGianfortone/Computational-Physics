import numpy as np
from scipy import mean
import matplotlib
import matplotlib.pyplot as plt
import timeit


# multiplies n x n matrix A with vector x

def matmult(A, x) :
    n = len(x)
    b = np.zeros(n, dtype=np.int)
    
    for i in np.arange(n) :
        for j in np.arange(n) :
            b[i] += (A[i, j] * x[j])

    return b



# creates Hadamard matrix of size 2^k

def hadmat(k) :
    H = np.array([[1]])

    for i in np.arange(0, k) :
        H = np.concatenate((np.concatenate((H, H), axis=1), np.concatenate((H, -1 * H), axis=1)), axis=0)

    return H




# multiplies Hadamard matrices with better efficiency than matmult() by utilizing symmetry

def hadmatmult(H, x) :
    n = len(H)
    x1 = x[:(n // 2)]
    x2 = x[(n // 2):]

    if (n > 2)  :                    # recursive calls
        h = H[:(n // 2), :(n // 2)]	
        hx1 = hadmatmult(h, x1)
        hx2 = hadmatmult(h, x2)
        b = np.concatenate((hx1 + hx2, hx1 - hx2), axis=0)
    
    else :                          # bottom
        b1 = x1 + x2
        b2 = x1 - x2
        b = np.array(np.concatenate((b1, b2), axis=0))
        
    return b



# time matmult and hadmatmult with k*k Hadamard array and k-length vector with Timeit

N = 4

matmulttimes = np.zeros(N)
hadmatmulttimes = np.zeros(N)

for k in np.arange(1, N + 1) :
    x = np.random.randint(2**k, size=2**k)
    H = hadmat(k)
    
    #times matmult()
    tm = timeit.Timer(lambda: matmult(H, x))
    matmulttimes[k - 1] = mean(tm.repeat(repeat=3, number=1))
    
    #times hadmatmult()
    th = timeit.Timer(lambda: hadmatmult(H, x))
    hadmatmulttimes[k - 1] = mean(th.repeat(repeat=3, number=1))


fig = plt.figure()
ax1 = fig.add_subplot(111)
ax1 = fig.add_subplot(111)
matplotlib.rc('text', usetex = True)

ax1.plot([2**k for k in np.array(np.arange(1, N + 1))], matmulttimes, marker='s', linestyle='--', color='b', clip_on='false', label='matmult')
ax1.plot([2**k for k in np.array(np.arange(1, N + 1))], hadmatmulttimes, marker='o', linestyle='--', color='r', clip_on='false', label='hadmatmult')

plt.xlabel('\it{n}', fontsize=16)
plt.ylabel('time [s]', fontsize=16)
plt.title('Time for Hadamard Matrix - Vector Multiplication')
plt.legend(loc='upper left')
plt.savefig('matmulttime.pdf')
plt.show()





