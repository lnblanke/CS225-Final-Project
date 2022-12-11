#include "table.h"

using namespace data;

std::string Table::Column::deduceType(std::string item) const {
    size_t num_cnt = 0, dot_cnt = 0, num_sign = 0;

    for (char c : item) {
        num_cnt += (c >= '0' && c <= '9');
        dot_cnt += (c == '.');
        num_sign += (c == '-');
    }

    if (type_ == "numeric" && dot_cnt <= 1 && num_cnt + num_sign + dot_cnt == item.length()) {
        if (item.empty()) item = "0";
    } else if (type_ != "categorical") {
        throw std::invalid_argument("The type of item is not aligned with the type of column");
    }

    return item;
}

Table::Column::Column(std::string name) {
    name_ = name;
}

void Table::Column::resize(size_t size) { 
    auto sz = items_.size();
    items_.resize(size);
}

std::string Table::Column::get(size_t idx) {
    if (idx >= items_.size()) 
        throw std::invalid_argument("Index for Column.get() exceeds the size");

    if (items_[idx].empty() && type_ == "numeric")
        items_[idx] = "0";

    return items_[idx];
}

void Table::Column::set(size_t idx, std::string item) {
    if (idx >= items_.size()) 
        throw std::invalid_argument("Index for Column.set() exceeds the size");

    if (type_.empty()) {
        if (item == "") {
            return;
        }
        try {
            type_ = "numeric";
            items_[idx] = deduceType(item);
        } catch (std::invalid_argument& e) {
            type_ = "categorical";
            items_[idx] = deduceType(item);    
        }
    } else {
        items_[idx] = deduceType(item);    
    }
}

std::string& Table::Column::operator[](size_t idx) {
    if (idx >= items_.size()) 
        throw std::invalid_argument("Index for Column.operator[idx] exceeds the size");

    return items_[idx];
}

void Table::addColumn(std::string name) {
    for (const auto c : columns) {
        if (c->getName() == name) 
            throw std::invalid_argument("The name of the new column is already occupied");
    }

    auto newc = new Column(name);

    if (! columns.empty()) newc->resize(columns[0]->size());

    columns.push_back(newc);
    names_[name] = newc;
}

void Table::setItem(size_t i, size_t j, std::string item) {
    if (j >= columns.size())
        throw std::invalid_argument("Index for Table.setItem() is out of range");

    columns[j]->set(i, item);
}

std::string Table::getItem(size_t i, size_t j) const {
    if (j >= columns.size())
        throw std::invalid_argument("Index for Table.getItem() is out of range");

    return columns[j]->get(i);    
}

std::string Table::getColName(size_t i) const {
    if (i >= columns.size())
        throw std::invalid_argument("Index for Table.getColName() is out of range");

    return columns[i]->getName();
}

std::string Table::getColType(size_t i) const {
    if (i >= columns.size())
        throw std::invalid_argument("Index for Table.getColType() is out of range");

    return columns[i]->getType();
}

Table::Column& Table::operator[](std::string col_name) {
    if (names_.find(col_name) != names_.end()) {
        return *names_[col_name];
    }

    throw std::invalid_argument("Column with name " + col_name + " is not found");
}

Table::Column& Table::operator[](size_t idx) {
    if (idx >= columns.size())
        throw std::invalid_argument("Index for Table[" + std::to_string(idx) + "] is out of range");

    return *columns[idx];
}

void Table::addRows(size_t num) {
    for (const auto c : columns) {
        c->resize(num);
    }
}

void Table::dropCol(size_t idx) {
    if (idx >= columns.size()) 
        throw std::invalid_argument("Index for Table.dropCol() is out of range");

    columns.erase(columns.begin() + idx);
}

void Table::dropCol(std::string col_name) {
    for (auto it = columns.begin(); it != columns.end(); it++) {
        if ((*it)->getName() == col_name) {
            columns.erase(it);
            return;
        }
    }

    throw std::invalid_argument("Column with name " + col_name + " is not found");
}