
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
class Solution
{
    public:
    bool cmp(Item a1,Item a2)
    {
        double v1=(double)a1.value/a1.weight;
        double v2=(double)a2.value/a2.weight;
        return v1>v2;
    }
    double fractionalKnapsack(int W,struct Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        
        int currwt=0;
        double finalvalue=0.0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight + currwt<=W)
            {
                currwt+=arr[i].weight;
                finalvalue+=arr[i].value;
            }
            else
            {
                int remainwt=W-currwt;
                finalvalue+=remainwt*((double)arr[i].value/(double)arr[i].weight);
                break;
            }
        }
        
        return finalvalue;
        // Your code here
    }
        
};
