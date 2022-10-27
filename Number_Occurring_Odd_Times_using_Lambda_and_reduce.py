"""
What is lambda?
"""
# lambda keyword is used to define an anonymous function

# A lambda function is same as any normal python function, except that it has no name when defining it and is one line of code.

# Lambda functions can have any number of arguments but only one expression. 

# lambda argument(s): expression

# The expression is evaluated and returned.


"""
What is reduce()?
"""
# This function applies to each element of an iterable collection and returns the reduced value.
# This function is defined in “functools” module.


from functools import reduce
# importing the required packages

lst = [1,1,1,3,3,4,2,4,1,9,2]
# array of positive integers where all numbers occur even number of times except one number (i.e 9 )which occurs odd number of times. 

print (reduce(lambda a, b: a ^ b, lst))
#using reduce() function over the list until the single value is left expression
#reduces the value of a ^ b into single value where a starts from 0 and b from 1.
