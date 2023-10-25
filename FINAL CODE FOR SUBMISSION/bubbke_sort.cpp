#include<iostream>
using namespace std;

void bubble_sort(int arr[],int num)
{
    for(int i=0;i<num-1;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"Array after sorting is: "<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    const int num=9;
    int arr[num]={22,33,44,55,66,77,82,90,78};
    bubble_sort(arr,num);
    return 0;
}
