def matrix_score(matrix):
    # Get the number of rows and columns in the matrix
    rows = len(matrix)
    columns = len(matrix[0])
    # Initialize the score to 0
    score = 0
    # Loop through all the columns
    for j in range(columns):
        # Initialize the number of ones to 0
        ones = 0
        # Loop through all the rows
        for i in range(rows):
            # If the current element is 1, increment the number of ones
            if matrix[i][j] == 1:
                ones += 1
        # Add the maximum number of ones to the score
        score += max(ones, rows - ones) * (2 ** (columns - j - 1))
    # Return the score
    return score


def toggle_row(matrix, row):
    # Get the number of columns in the matrix
    columns = len(matrix[0])
    # Loop through all the columns
    for j in range(columns):
        # Toggle the current element
        matrix[row][j] = 1 - matrix[row][j]


def toggle_column(matrix, column):
    # Get the number of rows in the matrix
    rows = len(matrix)
    # Loop through all the rows
    for i in range(rows):
        # Toggle the current element
        matrix[i][column] = 1 - matrix[i][column]


def score_after_flipping_matrix(matrix):
    # Get the number of rows and columns in the matrix
    rows = len(matrix)
    columns = len(matrix[0])
    # Initialize the maximum score to the score of the original matrix
    max_score = matrix_score(matrix)
    # Loop through all the rows
    for i in range(rows - 1, -1, -1):
        # Loop through all the columns
        for j in range(columns):
            # Toggle the current row
            toggle_row(matrix, i)
            # Get the score of the matrix after toggling the current row
            score = matrix_score(matrix)
            # If the score is greater than the current maximum score, update the maximum score
            if score > max_score:
                max_score = score
            # Otherwise, toggle the current row back to its original state
            else:
                toggle_row(matrix, i)
            # Toggle the current column
            toggle_column(matrix, j)
            # Get the score of the matrix after toggling the current column
            score = matrix_score(matrix)
            # If the score is greater than the current maximum score, update the maximum score
            if score > max_score:
                max_score = score
            # Otherwise, toggle the current column back to its original state
            else:
                toggle_column(matrix, j)
    # Return the maximum score
    return max_score
