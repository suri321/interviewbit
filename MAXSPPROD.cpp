int Solution::maxSpecialProduct(vector<int> &A) {
    long long int n=A.size();
    long long int arr[n],arr2[n];
    memset(arr,0,sizeof(arr));
    memset(arr2,0,sizeof(arr2));
    
    for(int i=1;i<n-1;i++)
    {
        int j=i-1;
        if(A[i]<A[i-1])
            arr[i]=i-1;
        else
        {
            while(j>0 and A[i]>=A[j])
            {
                j=arr[j];
            }
            arr[i]=j;
        }
    }
    arr2[n-1]=n-1;
    for(int i=n-2;i>0;i--)
    {
        int j=i+1;
        if(A[i]<A[i+1])
            arr2[i]=i+1;
        else
        {
            while(j<n-1 and A[i]>=A[j] )
            {
                j=arr2[j];
                if(j==0)
                    break;
            }
            if(j==0)
                arr2[i]=0;
            else if(j==n-1 and A[i]>=A[j])
                arr2[i]=0;
            else
                arr2[i]=j;
        }
    }
    long long int ans=0;
    for(int i=1;i<n-1;i++)
    {
        long long int temp=(arr[i]*arr2[i]);
        if(ans<temp)
            ans=temp;
    }
    return ans%1000000007;
}
