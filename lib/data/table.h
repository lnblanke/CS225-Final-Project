#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include <stdexcept>

class Table {
private:
    class Column {
    private:
        std::string name_;
        std::vector<void*> items_;
        std::string type_;

        void* deduceType(std::string item);

    public:
        Column(std::string name, std::string type) {
            if (type != "int" &&  type != "double" && type != "string") 
                throw std::invalid_argument("Cannot recognize type");

            name_ = name;
        }

        void resize(size_t size) {
            items_.resize(size);
        }
 
        void* get(size_t idx) {
            if (idx >= items_.size()) 
                throw std::invalid_argument("Index for Column.get() exceeds the size");
        
            return items_[idx];
        }

        void set(size_t idx, std::string item) {
            if (idx >= items_.size()) 
                throw std::invalid_argument("Index for Column.get() exceeds the size");

            items_[idx] = deduceType(item);    
        }

        std::string getName() {
            return name_;
        }

        std::string getType() {
            return type_;
        }

        size_t size() {
            return items_.size();
        }

        void* operator[](size_t idx) {
            if (idx >= items_.size()) 
                throw std::invalid_argument("Index for Column.get() exceeds the size");

            return items_[idx];
        }
    };

    std::vector<Column*> columns;

public:
    Table() = default;

    void addColumn(std::string name, std::string type) {
        auto newc = new Column(name, type);

        if (! columns.empty()) newc->resize(columns[0]->size());
    
        columns.push_back(newc);
    }

    void setItem(size_t i, size_t j, std::string item) {
        if (i >= columns.size())
            throw std::invalid_argument("Index for Table.setItem() is out of range");

        columns[i]->set(j, item);
    }

    void* getItem(size_t i, size_t j) {
        if (i >= columns.size())
            throw std::invalid_argument("Index for Table.setItem() is out of range");

        return columns[i]->get(j);    
    }

    std::string getColName(size_t i) {
        if (i >= columns.size())
            throw std::invalid_argument("Index for Table.setItem() is out of range");
    
        return columns[i]->getName();
    }

    std::string getColType(size_t i) {
        if (i >= columns.size())
            throw std::invalid_argument("Index for Table.setItem() is out of range");
    
        return columns[i]->getType();
    }

    Column* operator[](std::string col_name) {
        for (const auto c : columns) {
            if (c->getName() == col_name) {
                return c;
            }
        }

        throw std::invalid_argument("Column with col_name is not found");
    }

    Column* operator[](size_t idx) {
        if (idx >= columns.size())
            throw std::invalid_argument("Index for Table.setItem() is out of range");
    
        return columns[idx];
    }

    size_t getNumRows() {
        return columns.empty()? 0: columns[0]->size();
    }

    size_t getNumCols() {
        return columns.size();
    }

    void addRows(size_t num) {
        for (const auto c : columns) {
            c->resize(num);
        }
    }
};

#endif