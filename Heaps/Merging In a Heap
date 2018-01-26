#include <bits/stdc++.h>
using namespace std;
class heap
{
    public:
    vector <int> arr;
    public:
    void insert(long long int k);
    void mul();
    long long int parent(long int i) { return (i-1)/2; }
    long int l_child(long int i) { return (i*2)+1; }
    long long int r_child(long int i) { return (i*2)+2; }
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
void heap::mul()
{
    long int size = arr.size() -1;
    long long int k = arr[0];
    arr[0] = arr[size];
    arr.erase(arr.begin() + size);
    heapify(0);
    arr[0] = (1 * k) + (arr[0] * 2);
    heapify(0);
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
void swap(long int *a, long int *b)
{
    long int temp = *a;
    *a = *b;
    *b = *a;
}
int main() {
    heap h;
    long int n, k;
    cin >> n >>k;
    while(n--)
    {
        long long int num;
        cin >> num;
        h.insert(num);
    }
    long int c = 0;
    do
    {
        if(h.arr.size() == 1 && h.arr[0] < k)
        {
            c = -1;
            break;
        }
        else if(h.arr[0] >= k)
            break;
        else
        {
            h.mul();
            c++;
        }
    }while(h.arr[0] < k);
    cout<<c;
    return 0;
}
//Merging elements in a heap until all the elements become greater than desired value
