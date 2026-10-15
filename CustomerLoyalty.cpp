
#include <iostream>
using namespace std;

int main() {
    int years;

    cout << "Enter the number of loyal years: ";
    cin >> years;

    if (years <= 0 || years > 46) {
        cout << "Please enter years between 1 and 46." << endl;
        return 0;
    }

    long long rewards[46];

    rewards[0] = 0;

    if (years > 1) {
        rewards[1] = 1;
    }

    for (int i = 2; i < years; i++) {
        rewards[i] = rewards[i - 1] + rewards[i - 2];
    }

    cout << "\nCustomer Loyalty Reward Points" << endl;

    for (int i = 0; i < years; i++) {
        cout << "Year " << i + 1 << ": "
             << rewards[i] << " points" << endl;
    }

    return 0;
}
