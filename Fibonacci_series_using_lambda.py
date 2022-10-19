"""
What is lambda?
"""
# lambda keyword is used to define an anonymous function

# A lambda function is same as any normal python function, except that it has no name when defining it and is one line of code.

# Lambda functions can have any number of arguments but only one expression. 

# lambda argument(s): expression

# The expression is evaluated and returned.

"""
What is the Fibonacci series?
"""
# It is a series of numbers starting with 0 and 1 where each number is the sum of the two preceding numbers.

# Fibonacci formula: Fn = Fn-1 + Fn-2, where n > 1

# ex: 1, 2, 3, 5, 8, and so on



from functools import reduce    
# importing the required packages


n = int(input('Enter the Number of terms :'))
# Taking input from the user and storing it in a integer variable n

def fibonacci_Series(n):

    return reduce(lambda x, _: x+[x[-1]+x[-2]], range(n-2), [0, 1])   
    
# Initially it is taking two parameters x[-1] and x[-2] i.e 0 and 1 respectively and appending to variable x.
# The same function will be called with next parameters, and then added to the previous result and stored again.

print(fibonacci_Series(n))


