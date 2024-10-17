import numpy as np

def conjugate(matrix):
    # Applying conjugation element-wise for each element in the matrix
    tempMat = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
    
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            tempMat[i][j] = complex(matrix[i][j].real, -matrix[i][j].imag)
    return tempMat

def transpose(matrix):
    tempMat = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            tempMat[i][j] = matrix[j][i]
    return tempMat

def multiply(matrix1, matrix2):
    #since matrix1 is square(say NXN) then matrix2 which is matrix1^dagger is also (N X N)
    matMul = [[0 for _ in range(len(matrix1[0]))] for _ in range(len(matrix1))]
    for i in range(len(matrix1)):
        for j in range(len(matrix1[0])): 
            for k in range(len(matrix1)):
                matMul[i][j] += matrix1[i][k]*matrix2[k][j]
    return matMul

def getIdentity(N): #we want to get (NXN) identity matrix
    I = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if(i == j):
                I[i][j] = 1
            else: I[i][j] = 0
    return I


def is_unitary(matrix):
    conjugate_transpose = transpose(conjugate(matrix))
    
    # Calculating U^dagger * U
    product = multiply(conjugate_transpose, matrix)
    
    # Checking if U^dagger * U is approximately equal to the identity matrix
    identity_matrix = getIdentity(matrix.shape[0])  # Identity matrix of the same size
    return np.allclose(product, identity_matrix) #checks if the matrix is very close to Identity matrix

# Example: Complex matrix
N = int(input("Enter the dimension of the matrix:\n"))
U = [[0 for _ in range(N)] for _ in range(N)]
print("Enter a (NXN) matrix\n")
for i in range(N):
    for j in range(N):
        U[i][j] = complex(input(f"Enter element at U[{i}][{j}]: "))
if is_unitary(np.array(U)):
    print("The matrix is unitary.")
else:
    print("The matrix is not unitary.")
