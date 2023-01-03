#include <iostream>
#include "Airport.h"
#include "Control_Tower.h"

int main() {
    Control_Tower control_tower;
    control_tower.Read_Files();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}