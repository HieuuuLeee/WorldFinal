#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pp push
#define et empty
#define mp make_pair

#define For(i,a,b) for (int i=a;i<=b;++i)
#define Fod(i,b,a) for (int i=b;i>=a;--i)
#define Forl(i,a,b) for (ll i=a;i<=b;++i)
#define Fodl(i,b,a) for (ll i=b;i>=a;--i)

typedef int64_t ll;
typedef uint64_t ull;

#define prno                             cout<<"NO\n"
#define pryes                            cout<<"YES\n"
#define pryon                            pryes; else prno;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define prarr(a,n)            For(i,1,n)cout<<a[i]<<" "; brln;
#define bitcount(n)         __builtin_popcountll(n)

#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)
#define fast              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll MOD = 1000000007;
const int MAX = 1000005;

struct pt{
	int x,y;
};

bool cw(pt a, pt b, pt c){
	int ax = a.x - b.x, ay = a.y - b.y;
	int bx = c.x - b.x, by = c.y - b.y;
	int check = ax*by - ay*bx;
	return check>0;
}

bool ccw(pt a, pt b, pt c){
	int ax = a.x - b.x, ay = a.y - b.y;
	int bx = c.x - b.x, by = c.y - b.y;
	int check = ax*by - ay*bx;
	return check<0;
}

bool cmp(pt a, pt b){
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

int n,x,y;
vector<pt> pts;

void convexHull(){
	if(pts.size()==1) return;
    sort(all(pts),&cmp);

	vector<pt> up, down;
	pt pl = pts[0], ph = pts.back();
	up.pb(pl); down.pb(pl);
	For(i,0,pts.size()-1){
		if(i==pts.size()-1 || cw(up[0],pts[i],pts[pts.size()-1])){
			while(up.size()>=2 && !cw(up[up.size()-2],up.back(),pts[i])) up.pop_back();
			up.pb(pts[i]);
		}
		if(i==pts.size()-1 || ccw(down[0],pts[i],pts[pts.size()-1])){
			while(down.size()>=2 && !ccw(down[down.size()-2],down.back(),pts[i])) down.pop_back();
			down.pb(pts[i]);
		}
	}

	// cout<<up.size()<<" "<<down.size(); brln;
	pts.clear();
	for(auto i:up) pts.pb(i);
	Fod(i,down.size()-2,1) pts.pb(down[i]);
	if(pts[0].x == pts.back().x && pts[0].y == pts.back().y) pts.pop_back();
}


int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    while((cin >> n,n)){
    	pts.clear();
	    For(i,1,n){
	    	cin>>x>>y;
	    	pts.pb({x,y});
	    }
	    convexHull();
	    reverse(all(pts));
	    // cout<<cw(pts[0],pts[1],pts[2])<<"\n";
	    cout<<pts.size()<<"\n";
	    for(auto i:pts) cout<<i.x<<" "<<i.y<<"\n";
    }
}