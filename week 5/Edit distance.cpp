#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::ostream;

void fill_empty_vector(vector<vector<int>>& twod_arr, int n){
	vector<int> put(n);
	for (int i=0; i < twod_arr.size(); i++){
			twod_arr[i] = put;
	}
}

void fill_zeros(vector<vector<int>>& twod_arr){
	//first row
	for (int i=0; i < static_cast<int>(twod_arr[0].size()); i++){
		twod_arr[0][i] = i;
	}
	//and columns
	for (int i=1; i < static_cast<int>(twod_arr.size()); i++){
		twod_arr[i][0] = i;
	}
}

ostream& operator<<(ostream& out, vector<vector<int>> twod_arr){
	for (int i=0; i < static_cast<int>(twod_arr.size()); i++){
		for (int j=0; j < static_cast<int>(twod_arr[i].size()); j++){
			out << twod_arr[i][j] << "  ";
		}
		out << std::endl;
	}
	return out;
}

vector<vector<int>> compute_matrix(const string &str1, const string &str2){
	//if empty
	vector<vector<int>> empty;
	if (str1.size() == 0 || str2.size()==0) return empty;
	vector<vector<int>> res((str1.size()) +1);
	fill_empty_vector(res, (str2.size())+1);
	fill_zeros(res);
	for (int i=1; i < static_cast<int>(str1.size())+1; i++){
		for (int j=1; j < static_cast<int>(str2.size())+1; j++){
			int insert, del, mat, mis;
			insert = res[i-1][j];
			del = res[i][j-1];
			mis = res[i-1][j-1];
			mat = res[i-1][j-1];
			if (str1[i-1] == str2[j-1]){
				res[i][j] = mat;
			}
			else{
				res[i][j] = 1+ std::min({insert, del, mis});
			}
		}
	}

	return res;
}

int edit_distance(const string &str1, const string &str2) {
	auto res =  compute_matrix(str1, str2);
	return res.back().back();
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
