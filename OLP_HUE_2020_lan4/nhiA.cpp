#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);
#define ll long long
using namespace std;

int main(){
	char a[5][5];
	int flag = 1;
	for(int i=0;i<5;i++){
	    for(int j=0;j<5;j++)
	        cin >> a[i][j];
	}
	for(int i=0;i<5;i++){
	    if(!flag)break;
	    for(int j=0;j<5;j++){
	        if(a[i][j]=='k'){
	            if(i<4 && j<3){
	                if(a[i+1][j+2]=='k'){
	                    flag = 0;
	                    break;
	                }
	                else a[i+1][j+2]='k';
	            }
	            if(i>0 && j<3){
	                if(a[i-1][j+2]=='k'){
	                    flag = 0;
	                    break;
	                }
	                else a[i-1][j+2]='k';
	            }
	            if(i>1 && j>0){
	                if(a[i-2][j-1]=='k'){
	                    flag = 0;
	                    break;
	                }
	                else a[i-2][j-1]='k';
	            }
	            if(i>1 && j<4){
	                if(a[i-2][j+1]=='k'){
	                    flag = 0;
	                    break;
	                }
	                else a[i-2][j+1]='k';
	            }
	            if(i<3 && j<4){
	                if(a[i+2][j+1]=='k'){
	                    flag = 0;
	                    break;
	                }
	                else a[i+2][j+1]='k';
	            }
	            if(i<3 && j>0){
	                if(a[i+2][j-1]=='k'){
	                    flag = 0;
	                    break;
	                }
	                else a[i+2][j-1]='k';
	            }
	            if(j>1 && i<4){
	                if(a[i+1][j-2]=='k'){
	                    flag = 0;
	                    break;
	                }
	                else a[i+1][j-2]='k';
	            }
	            if(j>1 && i>0){
	                if(a[i-1][j-2]=='k'){
	                    flag = 0;
	                    break;
	                }
	                else a[i-1][j-2]='k';
	            }
	        }
	    }
	}
	cout << (flag ? "valid" : "invalid");
    return 0;
}