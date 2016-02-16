#include<iostream>
#include<algorithm>
using namespace std;

const int N=100099;
const int lg=18;
const long long P=1000000007;
long long p10[lg];
long long a[lg][N*2];
long long b[N*2],bb[N*2],bi[N];
long long s[N];
int f[N],zero;
int n,q;
char c[N];


int getlen(long long &k){
    int m;
    int l=1;
    int r=n;
    while (l<r){
        m=(l+r)/2;
        if (k<=s[m]) r=m; else l=m+1;
    }
    k-=s[l-1];
    return l;
}

int getind(int len, int k){
    int m,sum;
    int l=1;
    int r=n;
    while (l<r){
        m=(l+r)/2;
        sum=0;
        for (int i=m;i>0;i&=i-1) sum+=f[i];
        if (sum<k) l=m+1; else r=m;
    }
    return l;
}

long long getnum(int ind,int len){
    long long ans=0;
    for (int i=0;i<lg;i++)
    if (len&(1<<i)){
        ans=(ans*p10[i]+a[i][ind])%P;
        ind+=(1<<i);
    }
    return ans;
}

void input(){
    scanf("%d%d",&n,&q);
    scanf("%s",c+1);
}

void sol(){
    p10[0]=10;
    for (int i=1;i<lg;i++) p10[i]=p10[i-1]*p10[i-1]%P;

    for (int i=1;i<=n;i++) b[i]=a[0][i]=c[i]-'0';

    for (int i=1,k=0;i<=n;i++){
        k+=(b[i]>0);
        if (b[i]==0) zero++;
        s[n-i+1]=k;
    }

    for (int i=2;i<=n;i++) s[i]+=s[i-1];

    for (int j=1;j<lg;j++){
        for (int i=1;i<=n;i++) bb[i]=b[i]=b[i]*N+b[i+(1<<(j-1))];
        sort(bb+1,bb+n+1);
        for (int i=1;i<=n;i++) b[i]=lower_bound(bb+1,bb+n+1,b[i])-bb;
        for (int i=1;i<=n;i++) a[j][i]=(a[j-1][i]*p10[j-1]+a[j-1][i+(1<<(j-1))])%P;
    }

    for (int i=1;i<=n;i++) bi[b[i]]=i;

    int clen=0;

    for (int i=1;i<=n;i++)
    if (c[i]!='0')
        for (int j=b[i];j<N;j=(j<<1)-(j&(j-1)))
            f[j]++;

    while (q--){
        long long k;
        scanf("%lld",&k);
        if (k<=zero){
            printf("0\n");
            continue;
        } else
            k-=zero;
        int len=getlen(k);
        while (clen+1<len){
            clen++;
            if (c[n-clen+1]!='0')
            for (int j=b[n-clen+1];j<N;j=(j<<1)-(j&(j-1)))
                f[j]--;
        }
        int ind=getind(len,k);
        printf("%lld\n",getnum(bi[ind],len));
    }

}

int main() {
    input();
    sol();
    return 0;
}

