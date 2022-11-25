#include<bits/stdc++.h>
using namespace std;

int buildTreeUtils(vector<int> &segtree, vector<int> &arr, int sl, int sr, int ind)
{
    if(sl==sr)
    {
        segtree[ind]=arr[sl];
        return segtree[ind];
    }

    int mid=(sl+sr)/2;

    segtree[ind]= buildTreeUtils(segtree,arr,sl,mid,2*ind+1) +  buildTreeUtils(segtree,arr,mid+1,sr,2*ind+2);

    return segtree[ind];
}

void buildTree(vector<int> &segtree, int s, vector<int> &arr, int n)
{
    buildTreeUtils(segtree, arr, 0, n-1, 0);
}

void updateUtils(vector<int> &segtree, int sl, int sr, int changeValue, int index, int i)
{
    if(index>=sl && index<=sr)
    {
        segtree[i]+=changeValue;
        if(sl==sr)
            return ;
        int mid= (sl+sr)/2;
        updateUtils(segtree, sl, mid, changeValue, index, 2*i+1);
        updateUtils(segtree, mid+1, sr, changeValue, index, 2*i+2);
    }
    return ;
}

void update(vector<int> &segtree, vector<int> &arr, int index, int val)
{
    int changeValue= val-arr[index];
    arr[index]= val;
    int n=arr.size();
    updateUtils(segtree, 0, n-1, changeValue, index, 0);
}

int RangeSum(vector<int> &segtree,int sl, int sr, int ql, int qr, int i)
{
    if(qr<sl || sr<ql)
        return 0;
    else if(ql<=sl && sr<=qr)
        return segtree[i];
    else{
        int mid= (sl+sr)/2;
        return RangeSum(segtree,sl, mid, ql, qr,2*i+1) + RangeSum(segtree,mid+1, sr, ql, qr,2*i+2);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) 
        cin>>arr[i];
    size_t s=pow(2,ceil(log2(n))+1)-1;
    vector<int> segtree(s,0);

    buildTree(segtree, s,arr, n);

    for(int i=0 ;i<s; i++)
        cout<<segtree[i]<<" ";

    int Q;
    cin>>Q;
    while(Q--)
    {
        int c;
        cin>>c;
        int l,r,index,val;
        switch(c)
        {
            case 1:
                  cin>>index>> val;
                  update(segtree, arr, index, val);
                  for(int i=0 ;i<s; i++)
                    cout<<segtree[i]<<" ";
                  break;
            case 2:
                cin>>l>>r;
                cout<<RangeSum(segtree,0, n-1, l, r,0)<<endl;
                break;
            default:
                  cout<<"Invalid"<<endl;
        }
    }
}
