#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::ostream;


ostream& operator<<(ostream& out, vector<vector<int>> twod_arr){
	for (int i=0; i < static_cast<int>(twod_arr.size()); i++){
		for (int j=0; j < static_cast<int>(twod_arr[i].size()); j++){
			out << twod_arr[i][j] << "  ";
		}
		out << std::endl;
	}
	return out;
}

int figuire_out_optimal(vector<vector<int>>& shit);


int optimal_weight(int W, const vector<int> &w) {
	int current_weight;
	int increased_n = w.size() +1, increased_vec_size = W +1;
	vector<vector<int>> matrix(increased_n, vector<int>(increased_vec_size));
	for (int i=1; i < increased_n; i++){
		for (int j=1; j < increased_vec_size; j++){
			//0 index rows and columns are filled with zeroes
//			if (j == 0) matrix[i][j] = 0;
			//consider recurrence formula
			//value(w, i) = max{ value(w-wi, i-1) + vi, value(w, i-1) }
			//next line checks for a better solution for a given cell in terms of capacity
			if (w[i-1] <= j){
				matrix[i][j] = std::max(w[i - 1] + matrix[i - 1][j - w[i - 1]],  matrix[i - 1][j]);
			}
			else
				matrix[i][j] = matrix[i - 1][j];
		}
	}

  return matrix.back().back();
}

int main() {
	  int n, W;
	  std::cin >> W >> n;
	  vector<int> w(n);
	  for (int i = 0; i < n; i++) {
	    std::cin >> w[i];
	  }
	  std::cout << optimal_weight(W, w) << '\n';

}
