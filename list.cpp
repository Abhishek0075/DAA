#include <iostream>
using namespace std;
void partition(int *data,int begin,int end){
    int pivot = begin;
    int lowerBound = begin;
    int upperBound = end;
    while(pivot>=upperBound or pivot<=lowerBound){
        while (pivot<upperBound)
        {
            if(data[pivot]>data[upperBound]){
                swap(data[pivot],data[upperBound]);
                pivot=upperBound;
                upperBound=end;
                break;
            }else{
                upperBound--;
            }
        }
        while (pivot>lowerBound)
        {
            if(data[pivot]>data[lowerBound]){
                swap(data[pivot],data[lowerBound]);
                pivot=lowerBound;
                lowerBound=begin;
                break;
            }else{
                lowerBound++;
            }
        }
    }
    
}
int main(void) {
    int arr[6]={0,4,5,2,1,10};
    partition(arr,0,6);
}