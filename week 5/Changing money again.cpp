#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec = {0,1,2,1,1,2,2};

int get_change(int m) {
	if (m <=6) return vec[m];
	else{
		for (int i=7; i <= m; i++){
			int it = min({vec[i-1], vec[i-3], vec[i-4]});
			vec.push_back(it+1);
		}
	}

	return vec[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
