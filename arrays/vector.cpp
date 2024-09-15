#include<iostream>
#include<conio.h>
using namespace std;

class Vector{
    private:
        int* data;
        int size_;
        int capacity_;

        void resize(int newCapacity){
            int *newData = new int[newCapacity];
            for(int i = 0; i < size_; ++i)
                *(newData + i) = *(data + i);   // Using pointer arithmetic. Equals to newData[i] = data[i]
            delete[] data;
            data = newData;
            capacity_ = newCapacity;
        }
    public:

        Vector(){
            capacity_ = 16;
            size_ = 0;
            data = new int[capacity_];
        }

        ~Vector(){
            delete[] data;
            capacity_ = 0;
            size_ = 0;
        }

        int size(){ 
            return size_; 
        }
        int capacity(){ 
            return capacity_; 
        }
        int is_empty(){ 
            return size_ == 0; 
        }

        int at(int index){
            if(index < 0 || index >= size_)
                throw out_of_range("El indice esta fuera de rango");

            return *(data + index); // using pointer arithmetic. Equals to data[index]
        }

        void push(int item){
            if(size_ == capacity_)
                resize(capacity_*2);
            
            *(data + size_) = item;
            size_++;                
        }

        void insert(int index, int item){
            if(index < 0 || index >= size_)
                throw out_of_range("Index out of range");

            if(size_ == capacity_)
                resize(capacity_*2);

            for(int i = size_; i > index; --i)
                *(data + i) = *(data + i - 1);
            
            *(data + index) = item;
            size_++;
        }

        void prepend(int item){ 
            insert(0,item); 
        }

        int pop(){
            if(is_empty())
                throw out_of_range("Vector is empty");
            
            int item = *(data + size_ - 1);  // item = data[size_ -1];
            size_ --;

            if(size_ > 0 || size_ == capacity_/4)
                resize(capacity_/2);
            
            return item;
        }

        void delete_at(int index){
            if(index < 0 || index >= size_)
                throw out_of_range("Out of range");
            
            for(int i = index; i < size_-1; ++i)
                *(data + i) = *(data + i + 1);
            size_--;

            if(size_ > 0 || size_ == capacity_/4)
                resize(capacity_/2);
        }

        void remove(int item){
            for(int i=0; i < size_; ++i)
                if(*(data + i) == item){
                    delete_at(i);
                    --i;
                }
        }

        int find(int item){
            for(int i = 0; i < size_; ++i)
                if(*(data + i) == item)
                    return i;
            return -1;
        }
};

int main(){
    Vector arr;
    
    cout << "Size: " << arr.size() << endl;
    cout << "Capacity: " << arr.capacity() << endl;
    arr.push(5);
    arr.push(1);
    arr.push(2);
    arr.push(4);
    cout << "Size: " << arr.size() << endl;
    for(int i = 0; i < arr.size(); ++i)
        cout << "Arr["<<"i"<<"] = " << arr.at(i) << endl;
    cout << "Capacity: " << arr.capacity() << endl;
     cout << "Pop, item: " << arr.pop() << endl;
    cout << "Capacity: " << arr.capacity() << endl;




}