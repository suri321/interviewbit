int countPainters(vector<int> &C,int len)
{
    int n=C.size();
    int count=1;
    long long int total=0;
    for(int i=0;i<n;i++)
    {
        total=total+C[i];
        if(total>len)
        {
            count++;
            total=C[i];
        }
    }
    return count;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int sum=0;
    for(int i=0;i<C.size();i++)sum+=C[i];
    int max_e=*max_element(C.begin(),C.end());
    long long int beg=max_e;
    long long int end=sum;
    while(beg<end)
    {
        long long int mid=beg+(end-beg)/2;
        long long int reP=countPainters(C,mid);
        if(reP<=A)
        {
            end=mid;
        }
        else 
            beg=mid+1;
    }
    long long int p=B;
    return (beg*p)%10000003;
}
