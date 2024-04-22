#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
void missing(struct Array arr)
{
    
    int diff;
    diff=arr.A[0]-0;
    for(int i=0;i<arr.length;i++)
    {
        if(diff!=arr.A[i]-i)
        {
            printf("missing elemeent %d\n",(diff+i));
            break;
        }
    }
}
void insert(struct Array *arr,int index,int key)
{
    for(int i=arr->length;i>index;i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    arr->length++;
    arr->A[index]=key;
}

void missing1(struct Array arr)
{
    
    int diff;
    diff=arr.A[0]-0;
    for(int i=0;i<arr.length;i++)
    {
        if(diff!=arr.A[i]-i)
        {
            printf("missing elemeent %d\n",(diff+i));
            insert(&arr,i,diff+i);
        }
    }
}
void missing2(struct Array arr)
{
    int diff=arr.A[0]-0;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]-i!=diff)
        {
            while(arr.A[i]-i>diff)
            {
                cout<<"missing element is"<<i+diff<<endl;;
                diff++;
            }
        }
    }
}
int max(Array arr)
{
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}
int min(Array arr)
{
    int min=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    return min;
}

void missing3(struct Array arr)
{
    int c=max(arr);
    int l=min(arr);
    int H[c+1];
    for(int i=0;i<=c;i++)
    {
        H[i]=0;
    }
    for(int i=0;i<arr.length;i++)
    {
        H[arr.A[i]]=1;
    }
    for(int k=l;k<=c;k++)
    {
        if(H[k]==0)
        {
        cout<<k<<endl;
        }

    }
}
void duplicate(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        int LD;
        if(arr.A[i]==arr.A[i+1] && LD!=arr.A[i])
        {
            printf("%d\n",arr.A[i]);
            LD=arr.A[i];
        }
    }
}
void duplicate1(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]==arr.A[i+1])
        {
            int j;
            j=i+1;
            while(arr.A[i]==arr.A[j])
            {
                j++;
            }
            printf("%d is repeating %d times\n",arr.A[i],j-i);
            i=j-1;
        }
    }
}
void duplicate2(struct Array arr)
{
    int h=max(arr);
    int l=min(arr);
    int H[h+1];
    for(int i=0;i<h+1;i++)
    {
        H[i]=0;
    }
    for(int i=0;i<arr.length;i++)
    {
        H[arr.A[i]]++;
    }
    for(int i=l;i<=h;i++)
    {
        if(H[i]>1)
        {
            printf("%d is repeating %d times\n",i,H[i]);
        }
    }
}
void unsortedduplicate(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]!=-1)
        {
        int count=1;
        for(int j=i+1;j<arr.length;j++)
        {
            if(arr.A[i]==arr.A[j])
            {
                count++;
                arr.A[j]=-1;
            }
        }
            if(count>1)
            {
            printf("%d is repeating %d times\n",arr.A[i],count);
            }
        }
    }
}
void sum(struct Array arr,int k)
{
    int c=k;
    for(int i=0;i<arr.length-1;i++)
    {
        for(int j=i+1;j<arr.length;j++)
        {
            if(arr.A[i]+arr.A[j]==c)
            {
                printf("%d + %d=%d\n",arr.A[i],arr.A[j],c);
            }
        }
    }
}
void sum1(struct Array arr,int k)
{
    int h=max(arr);
    int H[h+1];
    int c=k;
    for(int i=0;i<=h;i++)
    {
        H[i]=0;
    }
    for(int i=0;i<arr.length;i++)
    {
        if(H[c-arr.A[i]]==1)
        {
            printf("%d + %d=%d\n",arr.A[i],(c-arr.A[i]),c);
        }
        H[arr.A[i]]=1;
    }
}
void sum2(struct Array arr,int k)
{
    int i=0;
    int j=arr.length-1;
    while(i<j)
    {
        if(arr.A[i]+arr.A[j]==k)
        {
            printf("%d + %d=%d\n",arr.A[i],arr.A[j],k);
            i++;
            j--;
        }
        else
        if(arr.A[i]+arr.A[j]>k)
        j--;
        else
        i++;
    }
}
int main()
{
    Array arr={{2,3,3,3,9,11,11,12,12,12},20,10};
    Array abb={{2,3,1,6,3,2,6,8,4,4,9,3,4},20,13};
    duplicate2(arr);
    duplicate2(abb);
    unsortedduplicate(abb);
    Array add={{2,3,1,4,6,2,3},20,7};
    sum1(add,5);
    Array aee={{2,4,6,6,8,9,10,13},20,8};
    sum2(aee,12);

    return 0;
}