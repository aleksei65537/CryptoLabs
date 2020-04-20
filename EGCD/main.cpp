#include "EGCD.hpp"
#include <iostream>
#include <string>

int main() {
    long a;
    long b;

    std::cout << ">>> Enter a: ";
    std::cin >> a;

    std::cout << ">>> Enter b: ";
    std::cin >> b;

    EGCD<long> e(a, b);

    std::cout << ">>> GCD equal to " << e.d << ", s equal to " << e.s <<
        ", t equal to " << e.t << std::endl;

    std::cout << ">>> Resulting equation: ";

    std::cout << e.s << " * " << a << " + " << e.t << " * " << b << " = "
        << e.d << std::endl;

    return 0;
}
