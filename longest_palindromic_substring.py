Approach (implemented Dp rules)
Definition : the row and col in the dp table represent the slicing index on the string s (inclusive)
example s = 'babad' -- > dp[2][3] = s[2:3] = ba
Steps :
Fill the diagonal with True, b/c every single character by itself is palindrom
Don't traverse in the bottom part of the diagonal
Becuase, that represent reverse slicing (which is not valid)
Iterate backward starting from the most right bottom cell to top (only on the right side of the digonal)
How ?
Start itertating backward for the outer loop (i) and for the inner loop (j) iterate forward starting from the index of outer loop ) : see the code (the for loops)
- Pick character from the input string based on the at i and j position, If the characters matches : you need to check two conditions
1. If the length of the sub_string is just one (a letter matching is good to be a palindrom)
2. But if the length of the sub_string is > 1
- You need to check if the inner sub_sting is also palindrom
- How ?
- You go to the left bottom corner and check if it is True
- Left bottom corrner represent the inner sub_string of the current_sub_string
-Eg. if dp[i][j]= cur_sub_string = 'ababa' --> True because dp[i+1][j-1] is True
dp[i+1][j-1] = 'bab' = True
.Howerver if dp[i][j]= cur_sub_string = 'abaca' --> False because dp[i+1][j-1] is False
dp[i+1][j-1] = 'bac' = False --> not palindrom
If dp[i+1][j-1] == True:
Ok that means the current sub_string is also palindrom
- Now compare the length of the current_palindrom sub_string with the prvious longest one and take the max
- Else : the characters don't match
Just pass
- Finally return the maximum number in the dp
If this solution/explanation helps you, don't forget to upvote as appreciation
def longestPalindrome(self, s):
        longest_palindrom = ''
        dp = [[0]*len(s) for _ in range(len(s))]
        #filling out the diagonal by 1
        for i in range(len(s)):
            dp[i][i] = True
            longest_palindrom = s[i]
			
        # filling the dp table
        for i in range(len(s)-1,-1,-1):
				# j starts from the i location : to only work on the upper side of the diagonal 
            for j in range(i+1,len(s)):  
                if s[i] == s[j]:  #if the chars mathces
                    # if len slicied sub_string is just one letter if the characters are equal, we can say they are palindomr dp[i][j] =True 
                    #if the slicied sub_string is longer than 1, then we should check if the inner string is also palindrom (check dp[i+1][j-1] is True)
                    if j-i ==1 or dp[i+1][j-1] is True:
                        dp[i][j] = True
                        # we also need to keep track of the maximum palindrom sequence 
                        if len(longest_palindrom) < len(s[i:j+1]):
                            longest_palindrom = s[i:j+1]
                
        return longest_palindrom
