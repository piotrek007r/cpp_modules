Steps to Evaluate RPN

Read the expression left to right, token by token.

A token is either a number (0–9) or an operator (+, -, *, /).

If the token is a number:
→ Push it onto the stack.

If the token is an operator (+, -, *, /):

Pop the top two numbers from the stack.

The first popped is b (the right operand).

The second popped is a (the left operand).

Apply the operator: a operator b.

Push the result back onto the stack.

Repeat until all tokens have been processed.

At the end:

The stack should contain exactly one number → this is the final result.

If the stack is empty or contains more than one number → it’s an error.

Error handling:

Division by zero.

Insufficient operands for an operator.

Invalid tokens (anything that is not a number or supported operator).