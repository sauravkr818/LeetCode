class Solution {
public:
    // TLE solution - recursion
    
   // void solve(string & s, int index, vector < string > & res) {
   //    if (index == s.size()) {
   //      res.push_back(s);
   //      return;
   //    }
   //    for (int i = index; i < s.size(); i++) {
   //      swap(s[i], s[index]);
   //      solve(s, index + 1, res);
   //      swap(s[i], s[index]);
   //    }
   //  }

  string getPermutation(int n, int k) {
    // string s;
    // vector < string > res;
    // //create string
    // for (int i = 1; i <= n; i++) {
    //   s.push_back(i + '0');
    // }
    // solve(s, 0, res);
    // //sort the generated permutations
    // sort(res.begin(), res.end());
    // //make k 0-based indexed to point to kth sequence
    // auto it = res.begin() + (k - 1);
    // return *it;
      
      
      // optimal solution
      
      int fact = 1;
      vector<int>numbers;
      for(int i=1;i<n;i++){
          
          fact = fact*i;
          numbers.push_back(i);
      }
      numbers.push_back(n);
      k = k-1;
      string ans;
      while(true){
          ans = ans + to_string(numbers[k/fact]);
          numbers.erase(numbers.begin() + k/fact);
          if(numbers.size() == 0){
              break;
          }
          k = k % fact;
          fact = fact/numbers.size();
          
      }
      return ans;
  }
};