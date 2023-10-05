#include <iostream>
#include "header.h"

int sum(int i) {
    int result = 0;
    for (int j = 1; j <= i; ++j) {
        result += j;
    }
    return result;
}