

class Position {
public:
    int x, y;
    
    Position(int x, int y) : x(x), y(y) {

    }

    bool operator== (Position p) {
        return (p.x == x && p.y == y);
    }


    bool operator!= (Position p) {
        return !this->operator==(p);
    }

    
    
};
