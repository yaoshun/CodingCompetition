void KMPlps(const string& s, vector<int>& lps) {
  int n = s.size();
  lps.resize(n);
  
  lps[0] = 0;
  int i = 1;
  int len = 0;
  
  while (i < n) {
    if (s[i] == s[len]) {
      lps[i] = len + 1;
      len++;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}
