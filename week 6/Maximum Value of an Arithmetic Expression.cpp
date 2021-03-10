#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <climits>
#include <algorithm>
using std::vector;
using std::string;
using std::max;
using std::min;
using std::ostream;

ostream& operator<<(ostream& out, vector<vector<long long>> twod_arr){
	for (int i=0; i < static_cast<int>(twod_arr.size()); i++){
		for (int j=0; j < static_cast<int>(twod_arr[i].size()); j++){
			out << twod_arr[i][j] << "  ";
		}
		out << std::endl;
	}
	return out;
}

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  }
}

long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int size = (length + 1) / 2;
  vector<vector<long long>> max(size, vector<long long> (size));
  for (int i = 0; i < size; i++)
  {
	  max.at(i).at(i) = std::stoll(exp.substr(2*i,1));
  }

  auto min = max;

//  std::cout << max;

  for (int s = 0; s < size - 1; s++)
  {
	  for (int i = 0; i < size - s - 1; i++)
	  {
		  int j = i + s + 1;
		  long long minVal = LLONG_MAX;
	      long long maxVal = LLONG_MIN;
		  for (int k = i; k < j; k++ )
	      {
			  long long a = eval(min[i][k],min[k + 1][j],exp[2 * k + 1]);
			  long long b = eval(min[i][k],max[k + 1][j],exp[2 * k + 1]);
			  long long c = eval(max[i][k],min[k + 1][j],exp[2 * k + 1]);
			  long long d = eval(max[i][k],max[k + 1][j],exp[2 * k + 1]);
			  minVal = std::min(minVal,std::min(a,std::min(b,std::min(c,d))));
			  maxVal = std::max(maxVal,std::max(a,std::max(b,std::max(c,d))));
	      }
		  min[i][j] = minVal;
		  max[i][j] = maxVal;
	  }
  }

//  std::cout << max;

  return max[0][size - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
