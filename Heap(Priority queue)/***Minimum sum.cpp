lass Solution
{   
    string findSum(string X, string Y) 
    {
        int i = X.size() - 1, j = Y.size() - 1;
        
        string res = "";
        
        int carry = 0;
        while(i >= 0 and j >= 0)
        {
            int digit1 = X[i] - '0';
            int digit2 = Y[j] - '0';
            
            int cal = (digit1 + digit2 + carry) % 10;
            carry = (digit1 + digit2 + carry) / 10;
            
            res = to_string(cal) + res;
            
            i--;
            j--;
        }
        
        while(i >= 0)
        {
            int digit1 = X[i] - '0';
            
            int cal = (digit1 + carry) % 10;
            carry = (digit1 + carry) / 10;
            
            res = to_string(cal) + res;
            
            i--;
        }
        
        while(j >= 0)
        {
            int digit2 = Y[j] - '0';
            
            int cal = (digit2 + carry) % 10;
            carry = (digit2 + carry) / 10;
            
            res = to_string(cal) + res;
            
            j--;
        }
        
        if(carry != 0)
        {
            res = to_string(carry) + res;
        }
        
        for(int i = 0; i < res.size(); i++)
        {
            if(res[i] != '0')
            {
                return res.substr(i);
            }
        }
        
        return "0";
    }
    
    public:
    string solve(int arr[], int n)
    {
        sort(arr, arr + n);
        
        string num1, num2;
        for(int i = 0; i < n; i++)
        {
            
            if(i % 2 == 0)
            {
                num1 += to_string(arr[i]);
            }
            else
            {
                num2 += to_string(arr[i]);
            }
        }
        
        return findSum(num1, num2);
    }
};
