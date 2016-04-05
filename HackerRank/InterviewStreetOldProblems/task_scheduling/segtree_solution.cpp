#include<stdio.h>
#include<algorithm>

const int LEN=0x40000, leaf=LEN/2;

// The tree structure is embeded in the array.
// however the tree element is put in the struct.
struct Node {
    int v, mx;
}st[LEN];

int sl, sr, dv;
void Add(int n, int l, int r) {
    if(st[n].v!=0&&n<leaf) {
        int v=st[n].v;
        st[n*2].v+=v;
        st[n*2].mx+=v;
        st[n*2+1].v+=v;
        st[n*2+1].mx+=v;
        st[n].v=0;
    }
    if(l>=sr||r<=sl) return;
    if(sl<=l&&r<=sr) {
        st[n].v+=dv;
        st[n].mx+=dv;
    } else {
        int mid=(l+r)/2;
        Add(n*2, l, mid);
        Add(n*2+1, mid, r);
        st[n].mx=std::max(st[n*2].mx, st[n*2+1].mx);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i=leaf;i<leaf*2;i++) {
        st[i].v=st[i].mx=-(i-leaf+1);
    }
    for(int i=leaf-1;i>0;i--) {
        st[i].mx=std::max(st[i*2].mx, st[i*2+1].mx);
    }

    for(int i=0;i<T;i++) {
        int D, M;
        scanf("%d%d", &D, &M);
        D--;
        sl=D; sr=leaf; dv=M;
        Add(1, 0, leaf);
        printf("%d\n", std::max(0, st[1].mx));
    }
}
