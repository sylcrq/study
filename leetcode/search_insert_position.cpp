
int searchInsert(int A[], int n, int target)
{
    int i = 0;

    for(i=0; i<n; i++)
    {
        if(A[i] >= target)
            break;
    }

    return i;
}
