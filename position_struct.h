

#ifndef POSITION_CLASS_DECLARATION
#define POSITION_CLASS_DECLARATION

// Board diminsion

#define BOARD_SIZE 8
#define BOARD_FIRST_X 0
#define BOARD_LAST_X 7
#define BOARD_FIRST_Y 0
#define BOARD_LAST_Y 7



typedef int PositionRelativeDirection;

#define RIGHT_RELATIVE_DIRECTION 0
#define UPPER_RIGHT_RELATIVE_DIRECTION 1
#define UP_RELATIVE_DIRECTION 2
#define UPPER_LEFT_RELATIVE_DIRECTION 3
#define LEFT_RELATIVE_DIRECTION 4
#define DOWN_LEFT_RELATIVE_DIRECTION 5
#define DOWN_RELATIVE_DIRECTION 6
#define DOWN_RIGHT_RELATIVE_DIRECTION 7
#define INVALID_RELATIVE_DIRECTION -1

#define BOARD_DIRECTIONS_NUM 8

const int X_STEP_IN_DIRECTION [BOARD_DIRECTIONS_NUM] = {0, -1, -1, -1, 0, 1, 1, 1};
const int Y_STEP_IN_DIRECTION [BOARD_DIRECTIONS_NUM] = {1, 1, 0, -1, -1, -1, 0, 1};

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



    bool isOutOfBoard() const {
        return (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE);
    }


    PositionRelativeDirection getDirectionFrom(Position pivotPosition) const {
        if (x == pivotPosition.x && y < pivotPosition.y) {
            return RIGHT_RELATIVE_DIRECTION;
        }

        if (x > pivotPosition.x && y < pivotPosition.y) {
            return UPPER_RIGHT_RELATIVE_DIRECTION;
        }

        if (x > pivotPosition.x && y == pivotPosition.y) {
            return UP_RELATIVE_DIRECTION;
        }

        if (x > pivotPosition.x && y > pivotPosition.y) {
            return UPPER_LEFT_RELATIVE_DIRECTION;
        }

        if (x == pivotPosition.x && y > pivotPosition.y) {
            return LEFT_RELATIVE_DIRECTION;
        }

        if (x < pivotPosition.x && y > pivotPosition.y) {
            return DOWN_LEFT_RELATIVE_DIRECTION;
        }

        if (x < pivotPosition.x && y == pivotPosition.y) {
            return DOWN_RELATIVE_DIRECTION;
        }

        if (x < pivotPosition.x && y < pivotPosition.y) {
            return DOWN_RIGHT_RELATIVE_DIRECTION;
        }

        return INVALID_RELATIVE_DIRECTION;   
    }



    void moveOneStepInDirection(PositionRelativeDirection direction) {

        if (direction != INVALID_RELATIVE_DIRECTION) {
            x += X_STEP_IN_DIRECTION[direction];
            y += Y_STEP_IN_DIRECTION[direction];
        }
        
    }

    
    
};



#endif // POSITION_CLASS_DECLARARION
