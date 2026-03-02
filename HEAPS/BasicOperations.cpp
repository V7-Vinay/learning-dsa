#include <bits/stdc++.h>
using namespace std;
class BinaryHeap{
    public:
    int capacity;
    int size;
    int *arr;
    BinaryHeap(int cap){
        capacity=cap;
        size=0;
        arr=new int[capacity];
    }
    int parent(int  i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
     
    void insert(int key){
        if(size==capacity){
            cout<<"heap overflow"<<endl;
            return;
        }
        arr[size]=key;
        int i=size;
        size++;
        while(i!=0&&arr[parent(i)]>arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    void heapify(int ind){
        int li=left(ind);
        int ri=right(ind);
        int smallest=ind;
        if(li<size&&arr[li]<arr[smallest]){
            smallest=li;
        }
        if(ri<size&&arr[ri]<arr[smallest]){
            smallest=ri;
        }
        if(smallest!=ind){
            swap(arr[ind],arr[smallest]);
            heapify(smallest);
        }
    }
    int getMin(){
        return arr[0];
    }

    int extractMin(){
        if(size<=0){
            return INT_MAX;
        }
        if(size==1){
            size--;
            return arr[0];  
        }
        int min=arr[0];
        arr[0]=arr[size-1];
        heapify(0);
        size--;
        return min;
    }
    void decreaseKey(int i ,int val){
        arr[i]=val;while(i!=0&&arr[parent(i)]>arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);    
        }
    }
    int deleteKey(int i){
        decreaseKey(i,INT_MIN);
        return extractMin();
    }
           
};