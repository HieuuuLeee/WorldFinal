#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}

const int COLINEAR = 0;
const int CW = 1;
const int CCW = 2;

const int INSIDE = 0;
const int OUTSIDE = 1;
const int ONEDGE = 2;

struct point {
    ld x, y;
    point(ld xloc, ld yloc) : x(xloc), y(yloc) {}
    point() {}
    point& operator= (const point& other) {
        x = other.x, y = other.y;
        return *this;
    }
    bool operator== (const point& other) const {
        return abs(other.x - x) < prec && abs(other.y - y) < prec;
    }
    bool operator!= (const point& other) const {
        return !(abs(other.x - x) < prec && abs(other.y - y) < prec);
    }
    bool operator< (const point& other) const {
        return (x < other.x ? true : (x == other.x && y < other.y));
    }
};

struct vect {
    ld i, j;
};

struct segment {
    point p1, p2;
    segment(point a, point b) : p1(a), p2(b) {}
    segment() {}
};

ld crossproduct(point a, point b, point c) {
    vect ab, ac;
    ab.i = b.x - a.x;
    ab.j = b.y - a.y;
    ac.i = c.x - a.x;
    ac.j = c.y - a.y;
    return (ab.i * ac.j - ab.j * ac.i);
}

ld dotproduct(point a, point b, point c) {
    vect ab, bc;
    ab.i = b.x - a.x;
    ab.j = b.y - a.y;
    bc.i = c.x - b.x;
    bc.j = c.y - b.y;
    return (ab.i * bc.i + ab.j * bc.i);
}

int orientation(point p, point q, point r) {
    int val = (int) crossproduct(p, q, r);
    if(val == 0) return COLINEAR;
    return (val > 0) ? CW : CCW;
}

bool onsegment(point p, segment s) {
    return (p.x <= max(s.p1.x, s.p2.x) && p.x >= min(s.p1.x, s.p2.x) &&
            p.y <= max(s.p1.y, s.p2.y) && p.y >= min(s.p1.y, s.p2.y));
}

ld pointsquareddist(point a, point b) {
    return pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
}

ld pointdist(point a, point b) {
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

bool straddle(segment s1, segment s2) {
    ld cross1 = crossproduct(s1.p1, s1.p2, s2.p1);
    ld cross2 = crossproduct(s1.p1, s1.p2, s2.p2);
    if((cross1 > 0 && cross2 > 0) || (cross1 < 0 && cross2 < 0)) return false;
    if(cross1 == 0 && cross2 == 0 && orientation(s1.p2, s2.p1, s2.p2) != COLINEAR) return false;
    return true;
}

vector<point> lineLineIntersect(point a, point b, point c, point d){
    vector<point> v;
    point res;
    int x1 = a.x, x2 = b.x, x3 = c.x, x4 = d.x;
    int y1 = a.y, y2 = b.y, y3 = c.y, y4 = d.y;

    if((x1-x2)*(y3-y4) - (x3-x4)*(y1-y2) != 0){
        res.x = ((x1*y2-x2*y1)*(y3-y4) - (x3*y4-x4*y3)*(x1-x2)) / ((x1-x2)*(y3-y4) - (x3-x4)*(y1-y2));
        res.y = ((x1*y2-x2*y1)*(y3-y4) - (x3*y4-x4*y3)*(y1-x2)) / ((x1-x2)*(y3-y4) - (x3-x4)*(y1-y2));    
        v.pb(res);
    }
    return v;
}

vector<point> intersect(segment s1, segment s2) {
    vector<point> res;
    point a = s1.p1, b = s1.p2, c = s2.p1, d = s2.p2;
    if(orientation(a,b,c) == 0 && orientation(a,b,d) == 0 &&
       orientation(c,d,a) == 0 && orientation(c,d,b) == 0) {
        point min_s1 = min(a,b), max_s1 = max(a,b);
        point min_s2 = min(c,d), max_s2 = max(c,d);
        if(min_s1 < min_s2) {
            if(max_s1 < min_s2) return res;
        }
        else if(min_s2 < min_s1 && max_s2 < min_s1) return res;
        point start = max(min_s1,min_s2), end = min(max_s1,max_s2);
        if(start == end) res.pb(start);
        else {
            res.pb(min(start,end));
            res.pb(max(start,end));
        }
        return res;
    }
    ld x1 = (b.x-a.x);
    ld y1 = (b.y-a.y);
    ld x2 = (d.x-c.x);
    ld y2 = (d.y-c.y);
    ld u1 = (-y1 * (a.x-c.x) + x1 * (a.y-c.y)) / (-x2 * y1 + x1 * y2);
    ld u2 = (x2 * (a.y-c.y) - y2 * (a.x-c.x)) / (-x2 * y1 + x1 * y2);
    if(u1 >= 0 && u1 <= 1 && u2 >= 0 && u2 <= 1) {
        res.pb(point((a.x + u2 * x1), (a.y + u2 * y1)));
    }
    return res;
}

ld linepointdist(segment s, point p, bool issegment) {
    if(s.p1 == s.p2) {
        if(p == s.p1) return 0;
        return pointdist(p, s.p1);
    }
    if(issegment) {
        if(dotproduct(s.p1, s.p2, p) > 0) return pointdist(s.p2, p);
        if(dotproduct(s.p2, s.p1, p) > 0) return pointdist(s.p1, p);
    }
    return abs(crossproduct(s.p1,s.p2,p) / pointdist(s.p1,s.p2));
}

vector<point> convexhull(vector<point>& X, bool onedge = false) {
    vector<point> hull;
    ll N = X.size();
    vector<bool> used(N, false);
    int p = 0;
    for(int i = 1; i < N; i++) if(X[i].x < X[p].x) p = i;
    int start = p;
    do {
        int n = -1;
        ld dist = onedge ? iinf : 0;
        for(int i = 0; i < N; i++) {
            if(i == p || used[i]) continue;
            if(n == -1) n = i;
            ld cross = crossproduct(X[p], X[i], X[n]);
            ld d = pointsquareddist(X[i], X[p]);
            if(cross < 0 || (cross == 0 &&
                ((onedge && d < dist) || (!onedge && d > dist)))) {
                n = i;
                dist = d;
            }
        }
        p = n;
        used[p] = true;
        hull.pb(X[p]);
    } while(start != p);
    return hull;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ll cross(const pair<ll, ll> &O, const pair<ll, ll> &A, const pair<ll, ll> &B){
    return ((A.fi - O.fi)*(B.se - O.se) - (A.se - O.se)*(B.fi - O.fi));
}
 
vector<pair<ll, ll>> convexHull(vector<pair<ll, ll>> &points){
    ll n = points.size();
     if(n < 4)
            return points;
    ll k = 0;
    vector<pair<ll, ll>> H(2*n);
    sort(all(points));
 
    for(ll i = 0; i < n; i++){
            while(k > 1 && cross(H[k-2], H[k-1], points[i]) <= 0)
                k--;
            H[k++] = points[i];
    }
 
    for(ll i = n-1, t = k+1; i > 0; --i){
            while(k >= t && cross(H[k-2], H[k-1], points[i-1]) <= 0)
                k--;
            H[k++] = points[i-1];
    }
    H.resize(k-1);
    return H;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

ld polyarea(vector<point>& p) {
    ld result = 0;
    for(int i = 0, j = 1, n = p.size(); i < n; i++, j = (i+1)%n)
        result += (p[i].x * p[j].y) - (p[i].y * p[j].x);
    return result / 2.0;
}

int insidepoly(vector<point> poly, point p) {
    bool inside = false;
    point outside(iinf, p.y);
    vector<point> intersection;
    for(uint i = 0, j = poly.size()-1; i < poly.size(); i++, j=i-1) {
        if(p == poly[i] || p == poly[j]) return ONEDGE;
        if(orientation(p,poly[i],poly[j]) == COLINEAR &&
           onsegment(p,segment(poly[i],poly[j]))) return ONEDGE;
        intersection = intersect(segment(p,outside), segment(poly[i],poly[j]));
        if(intersection.size() == 1) {
            if(poly[i] == intersection[0] && poly[j].y <= p.y) continue;
            if(poly[j] == intersection[0] && poly[i].y <= p.y) continue;
            inside = !inside;
        }
    }
    return inside ? INSIDE : OUTSIDE;
}

int main() {
    //file();
    fast();

    int n;
    while(cin >> n && n != 0) {
        set<point> s;
        for(int i = 0; i < n; i++) {
            point p;
            cin >> p.x >> p.y;
            s.insert(p);
        }

        vector<point> v;
        for(auto i : s) {
            v.pb(i);
        }

        if(v.size() > 2) {
            vector<point> hull = convexhull(v);
            reverse(all(hull));
            cout << hull.size() << endl;
            for(auto& i : hull) {
                cout << i.x << " " << i.y << enld;
            }
        }
        else {
            cout << v.size() << endl;
            for(auto& i : v) {
                cout << i.x << " " << i.y << enld;
            }
        }
    }

    point a(1,1), b(4,4), c(3,1), d(4,2);

    vector<point> p = lineLineIntersect(a,b,c,d);
    if(p.size() == 0) cout<<"no intersection!!";
    else cout<<p[0].x<<" "<<p[0].y;

    return 0;
}