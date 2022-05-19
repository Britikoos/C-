using namespace std;

class myForwardIterator : public vector<int>::iterator {
    using T = vector<int>::iterator;
    using T::T;
public:

    auto operator--(int) const = delete;

    auto operator--() const = delete;

    auto operator-(difference_type __n) const = delete;

    myForwardIterator(vector<int>::iterator it) : T(it) {}
};
