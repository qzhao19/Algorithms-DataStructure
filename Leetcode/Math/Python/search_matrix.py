
def search_matrix(matrix):

    res = 0
    n_rows = len(matrix)
    n_cols = len(matrix[0])

    zeros_mat = [0 for i in range(n_rows) for i in range(n_cols)]

    for i in range(n_rows):
        for j in range(n_cols):

            if i == 0 or j == 0:
                zeros_mat[i][j] = int(matrix[i][j])

            else:
                if matrix[i][j] =! '0':
                    
            



