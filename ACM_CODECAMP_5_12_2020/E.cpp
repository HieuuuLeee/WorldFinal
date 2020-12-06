#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    double time[5],sum=0;
    for(int i=0;i<5;i++){
        cin >> time[i];
        if(i!=4)sum+=time[i];
    }
    double mi = *min_element(time,time+4), ma = *max_element(time,time+4);
    sum -=mi;
    //cout << mi <<' ' << ma <<' '<<sum;
    if(ceilf(sum/3*100)/100 <= ceilf(time[4]*100)/100) cout << "infinite";
    else{
        double nhi = time[4]*3 - sum + ma;
        //cout<<nhi<<"\n";
        if(ceilf(nhi*100)/100>=ceilf(mi*100)/100)printf("%.2f",ceilf(nhi*100)/100);
        else cout <<"impossible";
    }
    return 0;
}