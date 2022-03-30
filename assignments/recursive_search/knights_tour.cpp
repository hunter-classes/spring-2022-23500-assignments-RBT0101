#include <iostream>
#include <vector>


<<<<<<< HEAD
//Check for boundary errors;
bool outOfBounds(std::vector<std::vector<std::string> >&board, int coordR, int coordC){
=======
//Check for boundary errors for any given (row, col) based on the board dimensions
bool outOfBounds(std::vector<std::vector<std::string> > board, int coordR, int coordC){
>>>>>>> ff4bb89fa2bcc19cd8320f6d56c0fcaf994e7d67
	return ((coordR < 0 || coordR >= board.size()) || (coordC < 0 || coordC >= board[1].size()));
}

//Checks if 2D array element exists
bool invalid2DArray(std::vector<std::vector<int> > &memo, int x, int y){
	if (memo[x][y] == 1) return true;
	return false;
}

//Returns a board with padding for a better visual output
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
	//Random board size from [0, 5]
	srand(time(0));
	int rdmBoardSize = rand() % 6;
	int maxSize = rdmBoardSize * rdmBoardSize; //Padding will be used based on max integer 
	
	//Board represented in 2D vector of strings
	std::vector<std::vector<std::string> > board(rdmBoardSize, std::vector<std::string> (rdmBoardSize, "."));
	
	//Starting cell (row, col) for the knight
	int knightCoordR = 0;
	int knightCoordC = 0;
	
	//Cannot Mod 0 (results in an error)
	if (rdmBoardSize != 0){
		knightCoordR = rand() % rdmBoardSize;
		knightCoordC = rand() % rdmBoardSize;
	}
	
	/*
		Since there can be many ways to reach base condition, we will need
		two variables to update the board with the most optimized path whenever
		a base condition is reached. To do this, we will evaluate the value of 
		the counter variable in the base case: the higher the value,
		the more steps that the knight can take
	*/
	int prev = 0;
	int counter = 1;
	
	//Memoization to keep track of the cell that have been visited so that the knight does not revist the cell again
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

