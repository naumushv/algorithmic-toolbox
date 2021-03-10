
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;

  while (right - left > 1 ){

	  int mid = (left + right)/2;

	  if (a[mid]==x){
		  return mid;
	  }
	  else if (x < a[mid]){
		  right = mid -1;
	  }
	  else {
		  left = mid +1;
	  }
  }
  if (a[left]==x) return left;
  if (a[right]==x)return right;
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
/*
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
*/



int num=0;
while(true){
	++num;
	cout << endl << "*********" <<  num << "*********" << endl;
  int n,m;
  n =rand() % 3*10000 +1;
  m = rand() % 100000 +1;
  vector<int> a,b;

  for (int i=0; i<n;i++){
	  int tmp = rand() % 1000000000 +1;
	  a.push_back(tmp);
  }
  for (int i=0; i<m;i++){
	  int tmp = rand() % 1000000000 +1;
	  b.push_back(tmp);
  }
  sort(a.begin(), a.end());
  /*
  for (auto& t:a){
	  cout << t << "  ";
  }
  cout << "arr a" << endl << endl;
  for (auto& t:b){
  	  cout << t << "  ";
    }
  cout << "arr b" << endl << endl;
*/

  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
	  if (binary_search(a, b[i]) != linear_search(a, b[i])){
//	  cout << i << "      ";
//	  cout << binary_search(a, b[i])  << " ";
//	  std::cout << linear_search(a, b[i]) << ' ';
	  }
  }

}


  return 0;
}

