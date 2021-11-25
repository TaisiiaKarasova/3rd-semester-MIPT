#include <iostream>
#include <cmath>
#include <vector>
class Cell final {
public:
    char v;
    unsigned short int h;
    Cell(): Cell('A',1) {}
    Cell(char v, unsigned short int h): v(v), h(h) {}
};

class Piece{
public:
    virtual bool available (Cell c) const = 0;
    ~Piece() = default;
};

class King: public Piece {
public:
    Cell location;
    King (Cell location): location(location) {};
    bool available (Cell another) const
    {
        int difference_h = another.h - location.h;
        if (difference_h < 0) difference_h = -difference_h;

        int difference_v = another.v - location.v;
        if (difference_v < 0) difference_v = -difference_v;
        if (((difference_h == 1) && (difference_v == 1)) || ((difference_h == 0) && (difference_v == 1)) || ((difference_h == 1) && (difference_v == 0)))
            return true;
        else
            return false;
    }
};

class Rook: public Piece {
public:
    Cell location;
    Rook (Cell location): location(location) {};
    bool available (Cell another) const
    {
        if ((another.h - location.h)*(another.v - location.v) == 0)
            if (((another.h - location.h)==0) && ((another.v - location.v) == 0))
            {
                return false;
            }
            else return true;
        else return false;
    }
};

class Bishop: public Piece {
public:
    Cell location;
    Bishop (Cell location): location(location) {};
    bool available (Cell another) const
    {
        int difference_h = another.h - location.h;
        if (difference_h < 0) difference_h = -difference_h;

        int difference_v = another.v - location.v;
        if (difference_v < 0) difference_v = -difference_v;
        if (((another.h - location.h)*(another.v - location.v) != 0) && (difference_h == difference_v))
            return true;
        else
            return false;
    }
};

class Queen: public Piece {
public:
    Cell location;
    Queen (Cell location): location(location) {};

    bool available (Cell another) const
    {
        int difference_h = another.h - location.h;
        if (difference_h < 0) difference_h = -difference_h;

        int difference_v = another.v - location.v;
        if (difference_v < 0) difference_v = -difference_v;
        if (((another.h - location.h)*(another.v - location.v) == 0) || (((another.h - location.h)*(another.v - location.v) != 0) && (difference_h == difference_v)))
            return true;
        else
            return false;
    }
};

std::vector<bool> are_available(Cell c, std::vector<Piece*> const &pieces);

int main() {
    std::vector<Piece*> pieces;
    pieces.push_back(new King(Cell('A',1)));
    pieces.push_back(new Queen(Cell('B',2)));
    pieces.push_back(new Rook(Cell('C',3)));
    pieces.push_back(new Bishop(Cell('D',4)));

    for(auto b : are_available(Cell('A',1),pieces))
        std::cout << b << ' ';
    std::cout << std::endl;

    for (auto p : pieces)
        delete p;

    return 0;
}
