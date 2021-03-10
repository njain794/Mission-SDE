class Solution {
public:
    string symbol(int n)
    {
        switch(n)
        {
            case 1:
                return "I";
                break;
            case 4:
                return "IV";
                break;
            case 5:
                return "V";
                break;
            case 9:
                return "IX";
                break;
            case 10:
                return "X";
                break;
            case 40:
                return "XL";
                break;
            case 50:
                return "L";
                break;
            case 90:
                return "XC";
                break;
            case 100:
                return "C";
                break;
            case 400:
                return "CD";
                break;
            case 500:
                return "D";
                break;
            case 900:
                return "CM";
                break;
            case 1000:
                return "M";
                break;
            default:
                return "";
                break;   
        }
    }
    string intToRoman(int num) 
    {
        int arr[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        
        string ans="";
        while(num>0)
        {
            int idx=upper_bound(arr,arr+13,num)-1-arr;
            int change=arr[idx];
            ans+=symbol(change);
            num-=arr[idx];
        }
        return ans;
    }
};
