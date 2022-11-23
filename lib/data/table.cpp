#include "table.h"

void* Table::Column::deduceType(std::string item) {
    if (type_ == "int") {
        try {
            int val = std::stoi(item);

            return static_cast<void*>(new int(val));
        } catch (std::invalid_argument e) {}
    } else if (type_ == "double") {
        try {
            double val = std::stod(item);

            return static_cast<void*>(new double(val));
        } catch (std::invalid_argument e) {}
    } else if (type_ == "string") {
        return static_cast<void*>(new std::string(item));
    }

    throw std::invalid_argument("The type of item is not aligned with the type of column");
}