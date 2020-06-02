// https://codeforces.com/gym/258366/problem/G
#include <bits/stdc++.h> 
 
#define Fi first
#define Se second
#define PB push_back
#define MP make_pair
#define ll long long
#define PU push
#define clr(a) memset(a,0,sizeof(a))
#define maxn 101
 
using namespace std;
 
int m,n;
 
pair<int, int> start;
map < pair <int, int>, int > a;
 
bool check(int m, int n, map < pair <int, int>, int > a){
	int res = a[make_pair(m, n)];
	if(res==-1)
		return 0;
	return 1;
}
 
int bfs(int m, int n, int k){
    queue <int> res;
    queue < pair < int, int > > q;
	res.push(0);
	q.push(make_pair(0, 0));
	
	while(!q.empty()){
		pair<int, int> curr = q.front();
		int x = curr.first, y=curr.second;
		int ress = res.front();
		a.insert(make_pair(make_pair(x, y),-1));
		if(x+y==k){
			return ress;
		}
		q.pop();
		res.pop();
		
		//Pull out of one in two ones
		if(x!=0&&check(0,y,a)){
			a[make_pair(0,y)]=-1;
			q.push(make_pair(0,y));
			res.push(ress+1);
		}
		if(y!=0&&check(x,0,a)){
			a[make_pair(x,0)]=-1;
			q.push(make_pair(x,0));
			res.push(ress+1);
		}
		
		// Pull in one in two ones
		if(x!=m&&check(m,y,a)){
			a[make_pair(m,y)]=-1;
			q.push(make_pair(m,y));
			res.push(ress+1);
		}
		if(y!=n&&check(x,n,a)){
			a[make_pair(x,n)]=-1;
			q.push(make_pair(x,n));
			res.push(ress+1);
		}
		
		// Extrange together two buckets
		if(y!=n&&x!=0){
			if(x+y>n){
				if(check(x-(n-y),n,a)){
					a[make_pair(x-(n-y),n)]=-1;
					q.push(make_pair(x-(n-y),n));
					res.push(ress+1);
				}
			}
			else{
				if(check(0,x+y,a)){
					a[make_pair(0,x+y)]=-1;
					q.push(make_pair(0,x+y));
					res.push(ress+1);
				}
			}
		}
		if(x!=m&&y!=0){
			if(x+y>m){
				if(check(m,y-(m-x),a)){
					a[make_pair(m,y-(m-x))]=-1;
					q.push(make_pair(m,y-(m-x)));
					res.push(ress+1);
				}
			}
			else{
				if(check(x+y,0,a)){
					a[make_pair(x+y,0)]=-1;
					q.push(make_pair(x+y,0));
					res.push(ress+1);
				}
			}
		}
	}
	return -1;
}
 
int main(){
//	ios::sync_with_stdio(false); cin.tie(0);
	int m,n,k;
	cin>>m>>n>>k;
	int res = bfs(m,n,k);
	cout<<res;
}