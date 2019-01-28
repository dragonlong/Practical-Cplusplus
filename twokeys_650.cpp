class Solution {
public:
    int minSteps(int n) 
    {
        int i;
        int steps = 0;
        int result = n;
        for (i=2;i<n+1;i++)
        {
            if ((n%i)==0)
            {
                steps = steps + minSteps(n/i)+i;
                return steps;
            }
            
        }
    return 0;
    }
};
