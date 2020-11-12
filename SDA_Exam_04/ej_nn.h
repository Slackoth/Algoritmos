#include "size.h"
#include <iostream>
#include "position.h"

using namespace std;

bool checkNumberInCell(int** arr, Position pos) {
    return arr[pos.row - 1][pos.col - 1] == 1 ? true : false;
}