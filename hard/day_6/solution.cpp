//Write your code here
// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++)
char l[1010],r[1010];
int ct,c[20000][10],fa[20000],s[17000][2010],n,f[2005][17000],ok[2005][17000],l1,l2;
int nt(int x,int y){
	return !c[x][y]?c[x][y]=++ct:c[x][y];
}
void ins(){
	l1=strlen(l+1),l2=strlen(r+1);
	int x=0,y=0;
	if(l1==l2){
		fo(i,1,l1){
			if(x==y){
				fo(j,l[i]-'0'+1,r[i]-'0'-1)
	                s[nt(x,j)][l1-i]++;
                x=nt(x,l[i]-'0');
                y=nt(y,r[i]-'0');
			}
			else{
				fo(j,l[i]-'0'+1,9)
		            s[nt(x,j)][l1-i]++;
                x=nt(x,l[i]-'0');
                fo(j,(i==1),r[i]-'0'-1)
                	s[nt(y,j)][l2-i]++;
                y=nt(y,r[i]-'0');
			}
		}
		s[x][0]++;
		if(x!=y)s[y][0]++;
	}
	else{
		fo(i,1,l1){
			fo(j,l[i]-'0'+1,9)
				s[nt(x,j)][l1-i]++;
			x=nt(x,l[i]-'0');
		}
		fo(i,1,l2){
			fo(j,(i==1),r[i]-'0'-1)
				s[nt(y,j)][l2-i]++;
			y=nt(y,r[i]-'0');
		}
		fo(i,l1+1,l2-1)fo(j,1,9)
			s[nt(0,j)][i-1]++;
		s[x][0]++;
		s[y][0]++;
	}
}
queue<int>q;
void bd(){
    fo(i,0,9)if(c[0][i])
	    q.push(c[0][i]);
    while(!q.empty()){
    	int x=q.front();
    	q.pop();
    	fo(i,0,l2-1)s[x][i]+=s[fa[x]][i];
        fo(i,0,9){
        	if(c[x][i]){
        		q.push(c[x][i]);
        		fa[c[x][i]]=c[fa[x]][i];
			}
			else c[x][i]=c[fa[x]][i];
		}
	}
	fo(i,0,ct)fo(j,1,n)
        s[i][j]+=s[i][j-1];
}
int main(){
	scanf("%s%s%d",l+1,r+1,&n);
	ins();
	bd();
	memset(f,-32,sizeof(f));
	f[0][0]=0;
	fo(i,0,n-1)fo(j,0,ct)if(f[i][j]>=0)
		fo(k,0,9)f[i+1][c[j][k]]=max(f[i+1][c[j][k]],f[i][j]+s[c[j][k]][n-i-1]);
	int r=-1e9;
	fo(i,0,ct)r=max(r,f[n][i]);
	printf("%d\n",r);
	fo(i,0,ct)ok[n][i]=(r==f[n][i]);
	for(int i=n-1;i;i--)
		fo(j,0,ct)fo(k,0,9)
			ok[i][j]|=ok[i+1][c[j][k]]&&(f[i+1][c[j][k]]==f[i][j]+s[c[j][k]][n-i-1]);
	int x=0;
	fo(i,1,n)fo(k,0,9)
		if(ok[i][c[x][k]]&&f[i][c[x][k]]==f[i-1][x]+s[c[x][k]][n-i]){
			printf("%d",k);
			x=c[x][k];
			break;
		}
}