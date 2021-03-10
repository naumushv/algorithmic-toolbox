#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::ostream;
using std::cout;


ostream& operator<<(ostream& out, vector<vector<int>> twod_arr){
	for (int i=0; i < static_cast<int>(twod_arr.size()); i++){
		for (int j=0; j < static_cast<int>(twod_arr[i].size()); j++){
			out << twod_arr[i][j] << "  ";
		}
		out << std::endl;
	}
	return out;
}

int souveniers(int unit, const vector<int> &item) {
	int cnt = 0;
	int increased_unit = unit +1, increased_items = item.size() +1;
	vector<vector<int>> matrix(increased_unit, vector<int>(increased_items));
	for (int i=1; i < increased_unit; i++){
		for (int j=1; j < increased_items; j++){
			matrix.at(i).at(j) = matrix.at(i).at(j-1);
			if (item.at(j-1) <= i){
				int tmp = matrix.at(i - item.at(j-1)).at(j-1) + item.at(j-1);
				if (tmp > matrix.at(i).at(j))
					matrix.at(i).at(j) = tmp;
			}
			if (matrix.at(i).at(j) == unit) cnt++;
		}
	}
	int res = (cnt < 3) ? 0 : 1;
	return res;
}


int main() {
	  int n;
	  std::cin >> n;
	  vector<int> w(n);
	  int tmp = 0;
	  for (int i = 0; i < n; i++) {
	    std::cin >> w[i];
	  }
	  for (int i = 0; i < n; i++) {
	    tmp += w[i];
	  }
	  if (n < 3){
		  std::cout << "0";
	  }
	  else if (tmp % 3 != 0){
		  std::cout << "0";
	  }
	  else{
		  cout << souveniers(tmp/3, w);
	  }
//	  std::cout << optimal_weight(W, w) << '\n';

}
