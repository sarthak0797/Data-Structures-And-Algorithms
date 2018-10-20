#include <bits/stdc++.h>
using namespace std;

int tree[3*100000];

void build(int arr[], int node, int st, int en)
{
    if(st == en)
    {
        tree[node] = arr[st];
    }
    else
    {
        int mid = (st + en) / 2;
        build(arr, 2*node, st, mid);
        build(arr, 2*node + 1, mid+1, en);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

int query(int node, int st, int en, int l, int r)
{
    if(r < st || l > en)
        return INT_MAX;
    if(r >= en && l <= st)
        return tree[node];

    int mid = st + en;
    mid /= 2;
    return (min(query(2*node, st, mid, l, r), query(2*node + 1, mid + 1, en, l, r)));
}

void update(int node, int st, int en, int ind, int val)
{
    if(st == en)
    {
        tree[node] = val;
    }
    else
    {
        int mid = st + en;
        mid /= 2;
        if(ind >= st && ind <= mid)  update(2*node, st, mid, ind, val);
        else    update(2*node + 1, mid + 1, en, ind, val);
        tree[node] = min(tree[2*node], tree[2*node + 1]);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n+2];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int x = ceil((double)log2(n));
    int last = 2 * pow(2, x) - 1;
    for(int i = 0; i <= last; i++) tree[i] = INT_MAX;
    build(arr, 1, 1, n);
    while(q--)
    {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if(ch == 'q')
        {
            cout << query(1, 1, n, a, b) << endl;
        }
        else
        {
            update(1, 1, n, a, b);
            arr[a] = b;
        }
    }
}
