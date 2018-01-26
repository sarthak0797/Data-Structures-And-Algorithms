#include <bits/stdc++.h>
using namespace std;
class heap
{
    public:
    vector <int> arr;
    public:
    void insert(long long int k);
    void delete_key(long long int i);
    int print_min() { return arr[0]; }
    long long int parent(long int i) { return (i-1)/2; }
    long int l_child(long int i) { return (i*2)+1; }
    long long int r_child(long int i) { return (i*2)+2; }
    void decrease(long int i, long int val);
    void heapify(long long int i);
};
void heap::insert(long long int k)
{
    arr.push_back(k);
    long long int size = arr.size() - 1;
    while(size != 0 && arr[parent(size)] > arr[size])
    {
        swap(arr[size], arr[parent(size)]);
        size = parent(size);
    }
}
void heap::delete_key(long long int key)
{
    long int size = arr.size() ;
    long long int i = 999;
    while(size >= 0)
    {
        if(arr[size] == key)
        {
            i = size;
            break;
        }
        size--;
    }
    decrease(i, INT_MIN);
}
void heap::heapify(long long int i)
{
    long long int l = l_child(i);
    long long int r = r_child(i);
    long long int smallest = i;
    if(l < arr.size() && arr[l] < arr[i])
        smallest = l;
    if(r< arr.size() && arr[r] < arr[smallest])
        smallest = r;
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(smallest);
    }
}
void heap::decrease(long int i, long int val)
{
    long int size = arr.size() - 1;
    
    arr[i] = val;
    while(i >= 0 && arr[parent(i)] > arr[i] )
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
    arr[0] = arr[size];
    arr.erase(arr.begin()+size);
    heapify(0);
}
void swap(long int *a, long int *b)
{
    long int temp = *a;
    *a = *b;
    *b = *a;
}
int main() {  
    heap h;
    long int test;
    cin >> test;
    while(test--)
    {
        long long int choice, num;
        cin >> choice;
        if(choice == 1)
        {
            cin >> num;
            h.insert(num);
        }
        if(choice == 2)
        {
            cin >> num;
            h.delete_key(num);
        }
        if(choice == 3)
        {
            cout << h.print_min() << endl;
        }
    }
    return 0;
}
