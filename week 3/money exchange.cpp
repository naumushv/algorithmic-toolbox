#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


using namespace std;

int main() {

	int money, ten = 0, five = 0, one = 0;
	cin >> money;
	if (money >= 10){
		ten = money / 10;
		money = money % 10;

	}
	if (money > 4){
		five = money / 5;
		money = money % 5;
	}
	if (money != 0){
		one = money;
	}

	cout << ten + five + one;

  return 0;
}
