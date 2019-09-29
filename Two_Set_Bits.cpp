#include <iostream>
#include <cmath>
using namespace std;

const static uint64_t K = 1e9 + 7;

const uint64_t power(int a, int b) {
    uint64_t ans = a, res = 1;
    while(b != 0) {
        if(b & 1)
            res = ((res % K) * (ans % K)) % K;
        ans = ((ans % K) * (ans % K)) % K;
        b >>= 1;
    }
    return (res % K);
}


uint64_t nearest_bit_finder(uint64_t n) {
    // Required bit from which to explore for the required number:
    return ceil((((-1) + sqrt((8 * n) + 1)) / 2));
}

uint64_t natural_number_sum(uint64_t n) {
    return ((n * (n - 1)) / 2) + 1;
}

const uint64_t nth_number_in_sequence(uint64_t &max_power, uint64_t &diff) {
    return (power(2, max_power) + power(2, diff)) % K;
}

int main() {
    // Test Cases - t
    uint64_t t; cin >> t;
    while(t--) {
        // Nth number of the sequence
        uint64_t n; cin >> n;

        // Find the nearest bit from which we can find the Nth number in the sequence:
        uint64_t b = nearest_bit_finder(n);

        // Find actual amount of numbers that can be in the sequence till Nth set bit:
        uint64_t max_num_in_seq = natural_number_sum(b);

        // Find the Nth number in the sequence:
        uint64_t difference = n - max_num_in_seq;
        cout << nth_number_in_sequence(b, difference) << "\n";
    }
}