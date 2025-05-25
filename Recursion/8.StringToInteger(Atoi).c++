                                     //String to Integer(ATOI)


class Solution {
public:
    int myAtoi(string s) {
      if(s.length()==0) return 0;   //empty string

      int i=0;
       while(i<s.size() && s[i]==' '){
        i++;
       }
       s=s.substr(i); //remove all leading spaces and string will be updated from i till last.

       int sign=+1;
       long ans=0;
       
       if(s[0]=='-') {
         sign= -1;
         s=s.substr(1); //remove the negative sign
       }
       else if(s[0]=='+'){
        s=s.substr(1); // remove the positive sign
       }

       int MAX=INT_MAX, MIN=INT_MIN;
       // i=(s[0] == '+' || s[0]=='-')? 1:0;
       //if + is there start from index 1 otherwise start from index 0.

       for (char c : s) {
            if (!isdigit(c)) break; // stop if non-digit character encountered
            
            ans = ans * 10 + (c - '0');
            
            // Check for overflow conditions
            if (sign == -1 && -ans < MIN) return MIN;
            if (sign == +1 && ans > MAX) return MAX;
        }
       return (int)(sign*ans);
    }
};
//T.C:O(n)
//S.C:O(1)
