#include <cassert>
#include "visit.hpp"

auto main() -> int {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    assert(input);
    assert(output);

    output << visit(input);

    input.close();
    output.close();
    return 0;
}