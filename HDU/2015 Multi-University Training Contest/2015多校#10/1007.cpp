/**************************************************************
    Problem: 1901
    User: OceanLight
    Language: C++
    Result: Accepted
    Time:444 ms
    Memory:12416 kb
****************************************************************/
 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <queue>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALLL(x) x.begin(),x.end()
#define SORT(x) sort(ALLL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILLL(x,c) memset(x,c,sizeof(x))
using namespace std;
const double eps = 1e-9;
#define LL long long
#define pb push_back
const int maxn  = 110000;
int num[maxn];
int n , m ;
map<int ,int>mp;
map<int,int>::iterator it;
int op[maxn];
int t[maxn][3];
int tot;
 
struct Node {
    Node *l,*r;
    int sum;
}nodes[maxn*80];
Node *root[maxn];
Node *null;
int C;
void init(){
    C= 0;
    null = &nodes[C++];
    null->l = null->r = null;
    null->sum =0;
    root[0] = null;
    for(int i=1;i<=n;i++){
 
        root[i] = &nodes[C++];
        root[i]->l = null;
        root[i]->r = null;
        root[i]->sum  = 0;
    }
}
Node * update(int pos,int left,int right,Node *root,int val){
     //cout << pos << "  "<<left << "  "<< right <<  "     "<<val<<endl;;
      Node * rt = root;
      if(rt == null){
           rt = &nodes[C++];
           rt->l = null;
           rt->r = null;
           rt->sum = 0;
      }
      if(left == right){
            rt->sum +=val;
            return rt;
      }
      int mid = (left + right)/2;
      if(pos<=mid){
         rt->l = update(pos,left,mid,rt->l,val);
      }else{
          rt->r = update(pos,mid+1,right,rt->r ,val);
      }
      rt->sum = rt->l->sum + rt->r->sum ;
      //cout << pos << "  "<<left << "  "<< right <<  "     "<<val<<"  "<< rt->sum <<endl;
      return rt;
}
 
#define lowbit(k)   k & -k
void inc(int k ,int m,int add) {    //k位置上，加入值m   // m位置上的数+= add
        for(; k <= n; k += lowbit(k))
           root[k] = update(m,1,tot,root[k],add);
}
int l_num,r_num;
Node *ll[maxn],*rr[maxn];
void get(int k,bool left){
       int idx = 0;
        for(; k > 0; k -= lowbit(k)){
            idx++ ;
            if(left){
                 ll[idx] = root[k];
            }else{
                rr[idx] = root[k];
            }
        }
        if(left){
            l_num = idx;
        }else{
            r_num = idx;
        }
}
int query(int left,int right,int k){
       if(left==right){
           return left;
       }
       int l_sum = 0;
       for(int i=1;i<=l_num;i++){
             l_sum += ll[i]->l->sum;
       }
       int r_sum = 0;
       for(int i =1;i<=r_num;i++){
             r_sum += rr[i]->l->sum;
       }
       int a = r_sum - l_sum;
      //cout << a <<endl;
       int mid = (left +right)/2;
       if(a>=k){
            for(int i=1;i<=l_num ;i++){
                ll[i] = ll[i]->l;
            }
            for(int i=1;i<=r_num;i++){
                 rr[i] = rr[i]->l;
            }
            return query(left,mid,k);
       }else{
            for(int i=1;i<=l_num ;i++){
                ll[i] = ll[i]->r;
            }
            for(int i=1;i<=r_num;i++){
                 rr[i] = rr[i]->r;
            }
            return query(mid+1,right,k-a);
       }
      
}
int idx[maxn*2];
void solve(){
    init();
    for(int i=1;i<=n;i++){
        inc(i,mp[num[i]],1);
    }
    //cout << C<<endl;
    for(int i=1;i<=m;i++){
        if(op[i]== 2){
            int left = t[i][0];
            int right = t[i][1];
            int k = t[i][2];
            get(left-1,1);
            get(right,0);
            int ans = query(1,tot,k);
            printf("%d\n",idx[ans]);
        }else{
            int idx = t[i][0];
            int val= t[i][1];
            inc(idx,mp[num[idx]],-1);
            num[idx] = val;
            inc(idx,mp[num[idx]],1);
        }
    }
     
}
 
int main(){
    while(~scanf("%d",&n)){
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            mp[num[i]]=1;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&op[i]);
            if(op[i]== 2){
                 scanf("%d%d%d",&t[i][0],&t[i][1],&t[i][2]);
                 t[i][2]=t[i][1]-t[i][0]+1-t[i][2]+1;
            }else{
                scanf("%d%d",&t[i][0],&t[i][1]);
                mp[t[i][1]]=1;
            }
        }
        tot= 0 ;
        for(it = mp.begin(); it!= mp.end();it++){
            tot ++ ;
             it->second = tot;
             idx[tot] = it->first;
        }
        solve();
    }  
    return 0;
}
