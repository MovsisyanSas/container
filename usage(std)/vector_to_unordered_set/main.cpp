#include <iostream>
#include <vector>
#include <set>

void fill(std::vector<int>& vec, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        vec.push_back(rand() % 10);
    }
}

void remove_dupl(std::vector<int>& vec) {
    std::set<int> st;
    for (std::vector<int>::iterator ptr = vec.begin(); ptr != vec.end(); ++ptr) {
        st.insert(*ptr);
    }
    vec.clear();
    for (std::set<int>::iterator ptr = st.begin(); ptr != st.end(); ++ptr)
    {
        vec.push_back(*ptr);
    }
}

template<typename T>
void print(std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}

void print(std::set<int>& st) {
    for (std::set<int>::iterator it = st.begin(); it != st.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void delete_odd_nums(std::vector<int>& vec) {
    std::vector<int>::iterator ptr = vec.begin();

    while (ptr != vec.end()) {
        if (*ptr % 2 != 0) {
            ptr = vec.erase(ptr);
        }
        else {
            ptr++;
        }
    }
}

int main() {
    std::vector<int> vec;
    fill(vec,10);
    
    print(vec);
    delete_odd_nums(vec);
    print(vec);
    std::cout << std::endl;

    std::vector<int> vec2;
    fill(vec2, 10);

    std::cout << "with duplicates: ";
    print(vec2);

    
    remove_dupl(vec2);

    std::cout << "without duplicates: ";
    print(vec2);
    return 0;
}
