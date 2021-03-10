#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int64_t MF(const vector<int64_t>& numbers) {
    int64_t max_product = 0, ix1=0, ix2=0;
    int n = static_cast<int>(numbers.size());

    for (int i = 0; i < n-1; i++){
    	if (numbers.at(ix1) < numbers.at(i+1)) {
    		ix1 = i+1;
    	}
    }

    if (ix1 == ix2) ++ix2;
    for (int i = 0; i < n-1; i++){
    	if ((numbers.at(ix2) < numbers.at(i+1)) && i+1!=(ix1)) {
    	    		ix2 = i+1;
		}
    }

    max_product = numbers.at(ix1) * numbers.at(ix2);
    return max_product;
}

int main() {
    int n;
//    int64_t one, two;
//    one = 100000;
//    two = 90000;
//    cout << one * two << endl;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MF(numbers) << "\n";
    return 0;
}
