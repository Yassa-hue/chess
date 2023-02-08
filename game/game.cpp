

#include "game.h"

Game::Game () {
    board = new Board();
    whitePieces = vector<Piece*> ();
    blackPieces = vector<Piece*> ();
    deadWhitePieces = vector<Piece*> ();
    deadBlackPieces = vector<Piece*> ();

    createPieces();
    putPiecesInBoard();
}


Game::~Game() {
    delete board;

    for (size_t i = 0; i < 2*PAWNS_NUM; i++) {
        delete whitePieces[i];
        delete blackPieces[i];
    }
    
}



void Game::createPieces() {
    whitePieces.push_back(new KingPiece(WHIGHT_COLOR, WHITE_KING_INITIAL_POSITION));
    whitePieces.push_back(new QueenPiece(WHIGHT_COLOR, WHITE_QUEEN_INITIAL_POSITION));

    whitePieces.push_back(new BishopPiece(WHIGHT_COLOR, LEFT_WHITE_BISHOP_INITIAL_POSITION));
    whitePieces.push_back(new BishopPiece(WHIGHT_COLOR, RIGHT_WHITE_BISHOP_INITIAL_POSITION));

    whitePieces.push_back(new KnightPiece(WHIGHT_COLOR, LEFT_WHITE_NIGHT_INITIAL_POSITION));
    whitePieces.push_back(new KnightPiece(WHIGHT_COLOR, RIGHT_WHITE_NIGHT_INITIAL_POSITION));

    whitePieces.push_back(new RockPiece(WHIGHT_COLOR, LEFT_WHITE_ROCK_INITIAL_POSITION));
    whitePieces.push_back(new RockPiece(WHIGHT_COLOR, RIGHT_WHITE_ROCK_INITIAL_POSITION));

    for (size_t yCoordinate = 0; yCoordinate < PAWNS_NUM; yCoordinate++) {
        whitePieces.push_back(new PawnPiece(WHIGHT_COLOR, Position(WHITE_PAWNS_X_COORDINATE, yCoordinate)));
    }
    



    blackPieces.push_back(new KingPiece(BLACK_COLOR, BLACK_KING_INITIAL_POSITION));
    blackPieces.push_back(new QueenPiece(BLACK_COLOR, BLACK_QUEEN_INITIAL_POSITION));

    blackPieces.push_back(new BishopPiece(BLACK_COLOR, LEFT_BLACK_BISHOP_INITIAL_POSITION));
    blackPieces.push_back(new BishopPiece(BLACK_COLOR, RIGHT_BLACK_BISHOP_INITIAL_POSITION));

    blackPieces.push_back(new KnightPiece(BLACK_COLOR, LEFT_BLACK_NIGHT_INITIAL_POSITION));
    blackPieces.push_back(new KnightPiece(BLACK_COLOR, RIGHT_BLACK_NIGHT_INITIAL_POSITION));

    blackPieces.push_back(new RockPiece(BLACK_COLOR, LEFT_BLACK_ROCK_INITIAL_POSITION));
    blackPieces.push_back(new RockPiece(BLACK_COLOR, RIGHT_BLACK_ROCK_INITIAL_POSITION));

    for (size_t yCoordinate = 0; yCoordinate < PAWNS_NUM; yCoordinate++) {
        blackPieces.push_back(new PawnPiece(BLACK_COLOR, Position(BLACK_PAWNS_X_COORDINATE, yCoordinate)));
    }
}



void Game::putPiecesInBoard() {
    for (Piece *piece : whitePieces) {
        board->setPiece(piece);
    }
    for (Piece *piece : blackPieces) {
        board->setPiece(piece);
    }
}




void Game::printDeadPieces() {
    cout << "White dead Pieces : " << endl;
    for (Piece *whiteDeadPiece : deadWhitePieces) {
        cout << whiteDeadPiece->getName() << " ";
    }
    cout << endl;

    cout << "Black dead Pieces : " << endl;
    for (Piece *blackDeadPiece : deadBlackPieces) {
        cout << blackDeadPiece->getName() << " ";
    }
    cout << endl;
}



int Game::convertYCoordinateToInt(char yCoordinate) {
    return yCoordinate - 'A';
}





void Game::play() {
    
    
    while (true)  {
        // print board
        board->printBoard();
        
        printDeadPieces();
        
        
        
        // get input

        cout << (board->getCurrentPlayerColor() == WHIGHT_COLOR ? "White" : "Black");

        cout << " Player turn";
        cout << endl;


        cout << "Enter the start and the destination coordinates (-1 for end the game): ";

        int startX, endX;
        char startY, endY;

        cin >> startX;
        
        if (startX == EXIT_CODE) {
            break;
        }

        cin >> startY >> endX >> endY;

        Position startPosition(startX, convertYCoordinateToInt(startY)),
                destinationPosition(endX, convertYCoordinateToInt(endY));



        // apply move
        try {

            Piece *deadPiece = board->applyMove(startPosition, destinationPosition);

            if (deadPiece != nullptr) {
                int deadPieceColor = deadPiece->getColor();

                if (deadPieceColor == WHIGHT_COLOR) {
                    deadWhitePieces.push_back(deadPiece);
                } else {
                    deadBlackPieces.push_back(deadPiece);
                }

            } 

        } catch (GameException err) {
            cout << err.getErrMsg() << endl;
        }





        // // if player wins ends
        // if (board->currentPlayerIsCheckMated()) {
        //     int defeatedPlayerColor = board->getCurrentPlayerColor();
        //     if (defeatedPlayerColor == WHIGHT_COLOR) {
        //         cout << "Black player wins" << endl;
        //     } else {
        //         cout << "White player wins" << endl;
        //     }

        //     break;
        // }

        // Clear screen
        for (size_t i = 0; i < SCREEN_SIZE; i++)
        {
            cout << '\n';
        }
        cout << endl;
        
    }
    
    
}