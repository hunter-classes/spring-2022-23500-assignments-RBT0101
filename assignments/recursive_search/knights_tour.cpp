#include <iostream>
#include <vector>


//Check for boundary errors;
bool outOfBounds(std::vector<std::vector<std::string> >&board, int coordR, int coordC){
	return ((coordR < 0 || coordR >= board.size()) || (coordC < 0 || coordC >= board[1].size()));
}

//Checks if 2D array element exists
bool invalid2DArray(std::vector<std::vector<int> > &memo, int x, int y){
	if (memo[x][y] == 1) return true;
	return false;
}

//Returns a board with padding
std::string padBoard(std::vector<std::vector<std::string> >& board, int maxSize){
		std::string res = "";
		for (auto i: board){
			for (auto v: i){
				while (v.length() <= std::to_string(maxSize).length()) v = " " + v;
				res += v;
			}
		res += "\n";
	}
	
	return res;
}

//Find available moves for knight
void find_knight_moves(std::vector<std::vector<std::string> >& board,  std::vector<std::vector<int> > &memo, int coordR, int coordC, int &prev, int counter, std::vector<std::vector<std::string> >& res){
	int currentRow = coordR;
	int currentCol = coordC;
	if (outOfBounds(board, currentRow, currentCol) || invalid2DArray(memo, currentRow, currentCol)){
		if (counter > prev){
			prev = counter;
			res = board;
		}
		return;
	}
	else{
		memo[currentRow][currentCol] = 1;
		
		std::string appendStr = std::to_string(counter);
		board[currentRow][currentCol] = appendStr + ":";
		
		//up
		find_knight_moves(board, memo, currentRow-1, currentCol-2,  prev, counter+1, res);
		find_knight_moves(board, memo, currentRow-1, currentCol+2, prev, counter+1, res);
		find_knight_moves(board, memo, currentRow-2, currentCol-1,  prev, counter+1, res);
		find_knight_moves(board, memo, currentRow-2, currentCol+1, prev, counter+1, res);
		
		//down
		find_knight_moves(board, memo, currentRow+1, currentCol-2,  prev, counter+1, res);
		find_knight_moves(board, memo, currentRow+1, currentCol+2, prev, counter+1, res);
		find_knight_moves(board, memo, currentRow+2, currentCol-1,  prev, counter+1, res);
		find_knight_moves(board, memo, currentRow+2, currentCol+1, prev, counter+1, res);
		
		memo[currentRow][currentCol] = 0;
		board[currentRow][currentCol] = ".";
	}	
}

//Returns the board with all possible knight moves labeled in order
std::string knight_moves(){
	//Randing board size from [0, 5]
	srand(time(0));
	int rdmBoardSize = rand() % 6;
	int maxSize = rdmBoardSize * rdmBoardSize; //Padding will be used based on max integer 
	
	//Board represented in 2D vector of strings
	std::vector<std::vector<std::string> > board(rdmBoardSize, std::vector<std::string> (rdmBoardSize, "."));
	
	int knightCoordR = 0;
	int knightCoordC = 0;
	
	//Cannot Mod 0
	if (rdmBoardSize != 0){
		knightCoordR = rand() % rdmBoardSize;
		knightCoordC = rand() % rdmBoardSize;
	}
	
	int prev = 0;
	int counter = 1;
	
	//Memoization 
	std::vector<std::vector<int> > memo(rdmBoardSize, std::vector<int> (rdmBoardSize, 0));
	
	//Result	
	std::vector<std::vector<std::string> > res(rdmBoardSize, std::vector<std::string> (rdmBoardSize, "."));
	find_knight_moves(board, memo, knightCoordR, knightCoordC, prev, counter, res);
	
	std::cout << "<!---- Board size range [0,5] !---->"<< std::endl;
	std::cout << "Current selected board size: " << rdmBoardSize << std::endl;
	
	std::cout << "Starting row of the Knight: " << knightCoordR << std::endl;
	std::cout << "Starting column of the Knight: " << knightCoordC << std::endl;
	std::cout << "Output:\n";
		
	//Output
	return padBoard(res, maxSize);
}

int main(){
    std::cout << knight_moves() << std::endl;
    return 0;
}

