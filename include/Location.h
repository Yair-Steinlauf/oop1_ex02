#pragma once

struct Location
{
    int row;
    int col;
    Location() : row(0), col(0) {}
    explicit Location(int row, int col) : row(row), col(col) {}
    bool operator==(const Location& other) const {
        return row == other.row && col == other.col;
    }
};
