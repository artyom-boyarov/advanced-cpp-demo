#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> input) {
    for (T elem : input) {
        std::cout << elem << "\n";
    }
}

template <typename T>
int arrayLength(T arr) {
    return arr.size();
}

template <typename First, typename Second>
class Pair {
public:
    First first;
    Second second;

    Pair() = default;
    Pair(First f, Second s) : first(f), second(s) {}
    bool compare(First first_comp, Second second_comp) {
        bool first_eq = (first == first_comp);
        bool second_eq = (second == second_comp);
        return first_eq && second_eq;
    }
};

int main() {
    std::vector<int> v1 = {1,2,3,4,5};
    std::vector<char> letters = {'M', 'R', 'O', 'V', 'E', 'R'};
    printVector(v1);
    printVector(letters);

    std::cout << "Size of v1: " << arrayLength(v1) << "\n";


    Pair<int, std::string> p1(1, "One");
    std::cout << "Pair: "<< p1.first << " " << p1.second << "\n";

    p1.compare(1, "Yes");
}