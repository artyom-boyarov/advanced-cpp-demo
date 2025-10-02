
#include <memory>
#include <string>
#include <iostream>
#include <vector>

struct Student {
    std::string name;
    std::string uniqname;
    int age;
};

int main() {
    // Unique pointers

    std::unique_ptr<int> ptr1 = std::make_unique<int>(5);

    std::cout << *ptr1 << "\n";
    std::cout << *(ptr1.get()) << "\n";

    int val = *ptr1;

    std::cout << val << "\n";

    //std::unique_ptr<int> ptr2 = ptr1;
    std::unique_ptr<int> ptr2 = std::move(ptr1);

    ptr1.reset(new int(10));

    std::unique_ptr<Student> student_ptr = std::make_unique<Student>();
    student_ptr->age = 20;
    student_ptr->name = "JJ McCarthy";
    student_ptr->uniqname = "jjnine";

    // Shared pointers

    std::shared_ptr<double> shr1 = std::make_shared<double>(23.023);

    {
        std::shared_ptr<double> shr2 = shr1;
        std::cout << *shr2 << "\n";
    }

    std::cout << *shr1 << "\n";

    std::vector<std::shared_ptr<int> > vec;
    vec.push_back(std::shared_ptr<int>(new int(9)));
    vec.push_back(std::shared_ptr<int>(new int(5)));
    vec.push_back(std::shared_ptr<int>(new int(7)));
    int& z = *vec[1];
    std::cout << "z is: " << z << std::endl;
    std::shared_ptr<int> copied = vec[1]; // works!
    std::cout << "*copied: " << *copied << std::endl;
    std::shared_ptr<int> moved = std::move(vec[1]); // works!
    std::cout << "*moved: " << *moved << std::endl;
}

