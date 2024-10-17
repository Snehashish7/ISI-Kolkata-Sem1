import numpy as np

def is_unitary(matrix):
    # Get the conjugate transpose of the matrix (for real matrices, this is just the transpose)
    conjugate_transpose = np.conjugate(matrix).T
    
    # Calculate U^dagger * U
    product = np.dot(conjugate_transpose, matrix)
    
    # Check if U^dagger * U is approximately equal to the identity matrix
    identity_matrix = np.eye(matrix.shape[0])  # Identity matrix of same size
    return np.allclose(product, identity_matrix)

# Example: Rotation matrix
theta = np.pi / 4  # 45 degrees
U = np.array([[6 + 5j, 6 - 5j], 
              [8 + 6j, 3 - 4j]])

if is_unitary(U):
    print("The matrix is unitary (or orthogonal in this case).")
else:
    print("The matrix is not unitary.")
