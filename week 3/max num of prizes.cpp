#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;


vector<long> candie(long& n){
	vector<long> result;
	long sum =0;
	for (long i=0; i < n; i++){
		sum += i+1;
		if (sum > n){
			sum -= i+1;
			if (n - sum != 0){
				result.at(result.size()-1) += n-sum;
			}
			return result;
		}
		result.push_back(i+1);
	}

}

void out(vector<long>& segments){
	for (size_t i=0; i < segments.size(); i++){
		cout << segments[i];
		if (i!= segments.size()-1) cout << " ";
	}
}



int main() {
  long n;
  cin >> n;

  vector<long> result = candie(n);
  cout << result.size() << endl;
  out(result);


 return 0;
}
