def deletions_to_make_valid_parentheses(s: str) -> int:
    # Stack to keep track of unmatched parentheses
    stack = []
    # Count of deletions needed
    deletions = 0
    # Loop through the string
    for c in s:
        # If the current character is an opening parenthesis, push it onto the stack
        if c == "(":
            stack.append(c)
        # If the current character is a closing parenthesis
        elif c == ")":
            # If the stack is empty, we need to delete this closing parenthesis
            if not stack:
                deletions += 1
            # If the stack is not empty, we can match this closing parenthesis with an opening one
            else:
                stack.pop()
    # At the end of the loop, any remaining opening parentheses in the stack must be deleted
    deletions += len(stack)
    return deletions
