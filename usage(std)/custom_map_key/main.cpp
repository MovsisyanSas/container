#include <iostream>
#include <map>
#include <unordered_map>

struct A {
    int a;
    A() : a(0) {}
    A(int i) : a(i) {}
    bool operator == (const A& obj) const {
        return this->a == obj.a;
    }
    bool operator < (const A& obj) const {
        return this->a < obj.a;
    }
    bool operator != (const A& obj) const {
        return this->a != obj.a;
    }
    bool operator > (const A& obj) const {
        return this->a > obj.a;
    }
    bool operator >= (const A& obj) const {
        return this->a >= obj.a;
    }
    bool operator <= (const A& obj) const {
        return this->a <= obj.a;
    }
    struct Hash {
        std::size_t operator()(const A& a) const {
            return std::hash<int>{}(a.a);
        }
    };
};

std::ostream& operator << (std::ostream& os, const std::pair<A, int>& p) {
    os << "(" << p.first.a << ", " << p.second << ")";
    return os;
}

int main() {
    std::map<A, int> mp;
    mp.insert(std::make_pair(A(1), 1));
    mp.insert(std::make_pair(A(2), 2));
    mp.insert(std::make_pair(A(5), 5));
    mp.insert(std::make_pair(A(4), 4));
    mp.insert(std::make_pair(A(3), 3));

    for (int i = 0; i < mp.size(); i++)
    {
        std::cout << mp[i] << ' ';
    }
    std::cout << std::endl;

    std::unordered_map<A, int, A::Hash> ump;
    ump.insert(std::make_pair(A(1), 1));
    ump.insert(std::make_pair(A(2), 2));
    ump.insert(std::make_pair(A(5), 5));
    ump.insert(std::make_pair(A(4), 4));
    ump.insert(std::make_pair(A(3), 3));

    for (int i = 0; i < ump.size(); i++)
    {
        std::cout << ump[i] << ' ';
    }
    return 0;
}
