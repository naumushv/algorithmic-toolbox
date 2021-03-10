#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> vec = {0, 1, 2, 2}, act = {1, 2, 3};

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence(n+1), answ;
  if (n <= 3)
  {
	  if (n == 0) return answ;
	  answ.push_back(1);
	  if (n == 2) answ.push_back(2);
	  if (n == 3) answ.push_back(3);
	  return answ;
  }
  else {
//	  sequence(vec.begin(), sequence.end());
	  for (int i=0; i < vec.size(); i++){
		  sequence[i] = vec[i];
	  }

	  for (int i=4; i <= n; i++){
		  int opt1, opt2 = i, opt3 = i;
		  opt1 = sequence[i-1];
		  if (i % 3 == 0) opt3 = sequence[i/3];
		  if (i % 2 == 0) opt2 = sequence[i/2];
		  int it = std::min({opt1, opt2, opt3});
		  sequence[i] = it+1;
	  }
	  answ.push_back(n);
	  for (int i=n; i > 1;){
		  int opt1, opt2 = i, opt3 = i;
		  opt1 = sequence[i-1];
		  if (i % 3 == 0) opt3 = sequence[i/3];
		  if (i % 2 == 0) opt2 = sequence[i/2];
		  int it = std::min({opt1, opt2, opt3});
		  i = (it == opt2) ? i/2 : (it == opt1) ? i-1 : i/3;
//		  answ.push_back(sequence[i]);
		  answ.push_back(i);
	  }
  }

//  reverse(sequence.begin(), sequence.end());
  reverse(answ.begin(), answ.end());
  return answ;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
