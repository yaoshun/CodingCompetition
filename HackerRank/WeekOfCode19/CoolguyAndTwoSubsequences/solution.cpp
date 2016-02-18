#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;
int A[200001];
const ll P = 1000000007;

struct SegmentTreeNode {
    int min; 
    int start;
    int end;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode (int st, int ed) {
        start = st;
        end = ed;
        left = right = NULL;
    }
};

SegmentTreeNode* buildTree(int i, int j) {
    SegmentTreeNode* root = new SegmentTreeNode(i, j);
    if (i == j) {
        root->min = A[i];
        return root;
    }

    // In this way, i <= mid < j.
    // mid + 1 <= j.
    int mid = i + (j - i) / 2;
    root->left = buildTree(i, mid);
    root->right = buildTree(mid + 1, j);
    root->min = min(root->left->min, root->right->min);
    return root;
}

int queryTree(SegmentTreeNode* root, int i, int j) {
    if (!root)
        return INT_MAX;
    if (root->end < i || root->start > j || i > j)
        return INT_MAX;
    if (i <= root->start && j >= root->end) {
        return root->min;
    }
    int mid = root->start + (root->end - root->start)/2;
    int leftMin = queryTree(root->left, i, min(j, mid));
    int rightMin = queryTree(root->right, max(i, mid + 1), j);
    return min(leftMin, rightMin);
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    SegmentTreeNode * root = buildTree(0, n);

    // O(N^4 * log N)
    ll ans = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            for (int c = b + 1; c <= n; c++) {
                for (int d = c; d <= n; d++) {
                    ans += (ll)min(queryTree(root,a,b), queryTree(root,c,d)); 
                    ans %= P;
                }
            }
        }
    }
    cout << ans << endl;
}

