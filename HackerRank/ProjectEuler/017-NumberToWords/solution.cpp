#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

string hundredStr(ll num) {
    vector<string> arr1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    vector<string> arr2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    // Deal with the number less than 100 first.
    string ret;
    ret = num%100 < 20 ? arr1[num%100] : arr2[(num%100)/10] + (num%10 ? " " + arr1[num%10] : "");

    // Deal with the number less than 1000 based on the previous results.
    if (num > 99) {
        ret = arr1[num/100] + " Hundred" + (num%100 ? " " + ret : "");
    }
    return ret;
}
    
string numberToWords(ll num) {
    string ret;
    vector<string> strarr = {"Thousand", "Million", "Billion"};
    ret=hundredStr(num % 1000);
    for (int i = 0; i < 3; i++) {
        num /= 1000;
        ret = num%1000 ? hundredStr(num % 1000) + " " + strarr[i] + " " + ret : ret;
    }

    // When the following part is all zero, there is a
    // trailing space problem.
    while (ret.back() == ' ')
        ret.pop_back();
    return ret.empty() ? "Zero" : ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        cout << numberToWords(n) << endl;
    }
    return 0;
}
