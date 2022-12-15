#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;
int partition(int *data,int begin,int end){
    int pivot = data[begin];
    int lowerBound = begin;
    int upperBound = end;
    int temp;
    while(lowerBound<upperBound){
        while(data[lowerBound]<=pivot){
            lowerBound++;
        }
        while(data[upperBound]>pivot){
            upperBound--;
        }
        if(lowerBound<upperBound){
            temp = data[lowerBound];
            data[lowerBound]=data[upperBound];
            data[upperBound]=temp;
        }
    }
    temp = data[begin];
    data[begin] = data[upperBound];
    data[upperBound] = temp;
    return upperBound;
}

void quickSort(int *data,int begin,int end){
    int loc;
    if(begin<end){
        loc = partition(data,begin,end);
        quickSort(data,begin,loc-1);
        quickSort(data,loc+1,end);
    }
}

void printArray(int *data,int num){
    for (int i = 0; i < num; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
int main(void){
    auto start = high_resolution_clock::now();
    srand ( time(NULL) );
    int num= 5 + rand() % 10;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        arr[i]=4 + rand() % 30;
    }
    cout<<"Before sorting : ";
    printArray(arr,num);
    
    quickSort(arr,0,num);
    cout<<"After sorting : ";
    printArray(arr,num);    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"Time taken : ";
    cout<<duration.count()<<"ms"<<endl;

}