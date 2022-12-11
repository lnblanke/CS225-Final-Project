#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include <stdexcept>
#include <map>

namespace data {
    class Table {
    private:
        class Column {
        private:
            std::string name_;
            std::vector<std::string> items_;
            std::string type_;

            std::string deduceType(std::string item) const;

        public:
            Column(std::string name);
            void resize(size_t size);
            std::string get(size_t idx);
            void set(size_t idx, std::string item);
            std::string getName() const { return name_; }
            std::string getType() const { return type_; }
            size_t size() const { return items_.size(); }
            std::string& operator[](size_t idx);
        };

        std::vector<Column*> columns;
        std::map<std::string, Column*> names_;

    public:
        Table() = default;
        void addColumn(std::string name);
        void setItem(size_t i, size_t j, std::string item);
        std::string getItem(size_t i, size_t j) const;
        std::string getColName(size_t i) const;
        std::string getColType(size_t i) const;
        Column& operator[](std::string col_name);
        Column& operator[](size_t idx);
        size_t getNumRows() const { return columns.empty()? 0: columns[0]->size(); }
        size_t getNumCols() const { return columns.size(); }
        void addRows(size_t num);
        void dropCol(size_t idx);
        void dropCol(std::string col_name);
    };
}

#endif