#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ifstream infile ("PracticeInput.txt");
    string s;
    string t;
    getline(infile, s);
    getline(infile, t);

    string Robots = s.substr(0, s.find(':'));
    string seqs = s.substr(s.find(':') + 1);
    string Robott = t.substr(0, t.find(':'));
    string seqt = t.substr(t.find(':') + 1);

    int cnts = 0;
    int cntt = 0;
    int i;
    for (int i = 0; i < 100000; i++) {
        int inds = i % seqs.size();
        int indt = i % seqt.size();
        if (seqs[inds] == seqt[indt]) {
            continue;
        } else if (seqs[inds] == 'R' && seqt[indt] == 'S') {
            cnts++;
        } else if (seqs[inds] == 'S' && seqt[indt] == 'P') {
            cnts++;
        } else if (seqs[inds] == 'P' && seqt[indt] == 'R') {
            cnts++;
        } else {
            cntt++;
        }

        if (cnts - cntt >= 5) {
            cout << (i+1) << " "<< Robots << endl;
            return 0;
        } else if (cntt - cnts >= 5){
            cout << (i + 1)<< " " << Robott << endl;
            return 0;
        }
    }
    cout << 100000 << " " << ":DRAW:";
    return 0;
}
