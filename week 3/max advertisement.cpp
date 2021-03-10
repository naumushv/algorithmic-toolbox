#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool sort_pos(long int i, long int j){
	return i < j;
}

bool sort_neg(long int i, long int j){
	return i > j;
}


int main() {
	long int n;
	long int result = 0;
	cin >> n;
	vector<long int> profit_positive, profit_negative, click_positive, click_negative;

	for (long int i=0; i < n; i++){
		long int tmp;
		cin >> tmp;
		tmp > 0 ? profit_positive.push_back(tmp) : profit_negative.push_back(tmp);
		if (tmp == 0) profit_negative.pop_back();
	}

	for (long int i=0; i < n; i++){
			long int tmp;
			cin >> tmp;
			tmp > 0 ? click_positive.push_back(tmp) : click_negative.push_back(tmp);
			if (tmp == 0) click_negative.pop_back();

	}
	sort(profit_positive.begin(), profit_positive.end(), sort_pos);
	sort(profit_negative.begin(), profit_negative.end(), sort_neg);
	sort(click_positive.begin(), click_positive.end(), sort_pos);
	sort(click_negative.begin(), click_negative.end(), sort_neg);


	while (!profit_positive.empty() && !click_positive.empty()){
		result += profit_positive.back() * click_positive.back();
		profit_positive.pop_back();
		click_positive.pop_back();
	}

	while (!profit_negative.empty() && !click_negative.empty()){
		result += profit_negative.back() * click_negative.back();
		profit_negative.pop_back();
		click_negative.pop_back();
	}

	cout << result;





/*

	for (auto& t:profit_positive){
		cout << t << endl;
	}

	for (auto& t:profit_negative){
			cout << t << endl;
		}
	cout << "end of profit, start click" << endl;

	for (auto& t:click_positive){
			cout << t << endl;
	}
	for (auto& t:click_negative){
				cout << t << endl;
	}
*/

    return 0;
}
