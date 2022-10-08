A valid parentheses sequence should satisfy the following properties:
1. The right parenthesis corresponding to each left parenthesis is determined.
2. If the left parenthesis is treated as 1 and the right parenthesis is treated as -1, the parentheses sequence is valid means all prefixes sum >= 0, and the total sequence sum == 0.

According to property 2, if there is a prefix sum <0, it means that there is an extra right parenthesis, and according to property 1, it is impossible to find a matching left parenthesis in front of this extra right parenthesis. Therefore, all enumerations passed through a interval are illegal, and you can directly skip to the next interval and re-enumerate.

The idea of work() function:
Enumerate start position, calculate the prefix sum and cnt from left to right.
1. If you go to position i and got cnt < 0, then let start = i+1, cnt = 0;
2. If cnt > 0, continue to go right i;
3. If cnt= 0, it means that [start,i] is a valid parentheses sequence.
Doing this can get all the cases where the number of left parentheses >= the number of right parentheses.
In order to handle the situation where the number of right parentheses >= the number of left parentheses, you need to do the same process again from right to left.

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = work(s);  
		// In order to handle the situation where the number of right parentheses >= the number of left parentheses, you need to do the same process again from right to left.
        reverse(s.begin(), s.end());  
		// Here is a tip
		// The ASCII of the left parenthesis is 0x28, and that of right parenthesis is 0x29
		// Only the last digit of these ASCII is different and difference is 1. So we can use XOR operation to shift left parenthesis to right parenthesis and vice versa.
        for(auto& c: s) c ^= 1;
        return max(res, work(s));
    }
    
    int work(string s){
        int res = 0;
        for(int i = 0, start = 0, cnt = 0; i < s.size(); i++){
            if(s[i] == '(') cnt++;
            else{
                cnt --;
                if(cnt < 0) start = i+1, cnt = 0;
                else if(!cnt) res = max(res, i-start+1);
            }
        }
        return res;
    }
};
