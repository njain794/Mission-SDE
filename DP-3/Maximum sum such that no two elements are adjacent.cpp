//https://practice.geeksforgeeks.org/viewSol.php?subId=ce677628f41e1a89aad8391995a5c5b1&pid=701417&user=namanjain41

int incl=arr[0];
int excl=0;

for(int i=1;i<n;i++)
{
    int a=excl+arr[i];
    int b=max(incl,excl);

    incl=a;
    excl=b;
}
return max(incl,excl);
