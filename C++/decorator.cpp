#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

const constexpr long n = 1000000;

template<typename Func>
auto time_decorator(Func && f) {
    return [f](auto && ... params) -> auto {
        auto start = chrono::steady_clock::now();
        auto result = f(params...);
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        return make_pair<>(result, duration);
    };
}

auto forLoop = time_decorator([](const vector<int> & v) -> auto {
    unsigned long count = 0;
    for(size_t i = 0, size = v.size(); i < size; i++)
        count += v[i];
    return count;
});

auto forEach = time_decorator([](const vector<int> & v) -> auto {
    unsigned long count = 0;
    for(const auto & x : v)
        count += x;
    return count;
});

auto forLoopIterators = time_decorator([](const vector<int> & v) -> auto {
    unsigned long count = 0;
    for(auto it = v.begin(), end = v.end(); it != end; ++it)
        count += *it;
    return count;
});

template<typename T, typename U>
inline ostream& operator<<(ostream & out, const pair<T, U> & p) {
    return out << "result: " << p.first << "\nelapsed time: " << p.second << " nanoseconds" << endl;
}



int main_decorator() {

    vector<int > v;
    for(size_t i = 0; i < n; i++)
        v.push_back(100);

    cout << "Classical for-loop:\n" << forLoop(v) << endl;
    cout << "Range-based loop:\n" << forEach(v) << endl;
    cout << "For-loop with iterators:\n" << forLoopIterators(v) << endl;

    return 0;
}