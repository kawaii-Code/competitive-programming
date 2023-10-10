#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

template<typename T>
size_t binary_search(std::vector<T> vector, T element) {
    if (vector.size() == 0) {
        return 0;
    }

    size_t left = 0;
    size_t right = vector.size() - 1;

    while (left < right) {
        size_t middle = (left + right) / 2;
        if (vector[middle] < element) {
            left = middle + 1;
        } else {
            right = middle; // Never subtract 1, because it can underflow
        }
    }

    return (vector[left] == element) ? left : vector.size();
}

typedef long long ll;

// A more understandable (in my opinion) version with signed integers.
template<typename T>
ll binary_search_ll(std::vector<T> vector, T element) {
    if (vector.size() == 0) {
        return 0;
    }

    ll left = 0;
    ll right = vector.size() - 1;

    while (left <= right) {
        ll middle = (left + right) / 2;
        if (vector[middle] < element) {
            left = middle + 1;
        } else if (vector[middle] > element) {
            right = middle - 1;
        } else {
            return middle;
        }
    }

    return -1;
}

template<typename T>
std::string vectorToString(std::vector<T> vector, std::string delimiter = ", ") {
    if (vector.size() == 0) {
        return "[]";
    }

    std::stringstream ss;
    ss << "[";
    for (size_t i = 0; i < vector.size() - 1; i++) {
        ss << vector[i] << delimiter;
    }
    ss << vector[vector.size() - 1] << "]";

    return ss.str();
}

int main() {
    std::vector<int> vector;
    int query;

    vector = {};
    query = 0;
    std::cout << vectorToString(vector) << ", " << query << ": " << binary_search(vector, query) << "\n";

    vector = {1};
    for (int i = 0; i <= 2; i++) {
        query = i;
        std::cout << vectorToString(vector) << ", " << query << ": " << binary_search(vector, query) << "\n";
    }

    vector = {1, 2};
    for (int i = 0; i <= 3; i++) {
        query = i;
        std::cout << vectorToString(vector) << ", " << query << ": " << binary_search(vector, query) << "\n";
    }

    vector = {1, 2, 3};
    for (int i = 0; i <= 4; i++) {
        query = i;
        std::cout << vectorToString(vector) << ", " << query << ": " << binary_search(vector, query) << "\n";
    }

    vector = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i <= 7; i++) {
        query = i;
        std::cout << vectorToString(vector) << ", " << query << ": " << binary_search(vector, query) << "\n";
    }

    vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= 10; i++) {
        query = i;
        std::cout << vectorToString(vector) << ", " << query << ": " << binary_search(vector, query) << "\n";
    }

    vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i <= 11; i++) {
        query = i;
        std::cout << vectorToString(vector) << ", " << query << ": " << binary_search(vector, query) << "\n";
    }
}
