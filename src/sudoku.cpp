class sudoku{
public:
	bool getEmptyCell(int a[9][9], int &x, int &y){
		for(x = 0; x < 9; x++){
			for(y = 0; y < 9; y++){
				if(a[x][y] == 0){ return true; }
			}
		}
		return false;
	}

bool existsInRow(int a[9][9], int x, int num){
	for(int y = 0; y < 9; y++){
		if( a[x][y] == num )
			 return true; 
	}
	return false;
}

bool existsInCol(int a[9][9], int y, int num){
	for(int x = 0; x < 9; x++){
		if( a[x][y] == num ){ return true; }
	}
	return false;
}

bool existsInBox(int a[9][9], int x, int y, int num){

	for( int row = 0; row < 3; row++){
		for ( int col = 0; col < 3; col++ ){ 
			if( a[x+row][y+col] == num ){ return true; }
		}
	}
	return false; 
}
bool isValid(int a[9][9], int x, int y, int num){
	if(!existsInRow(a, x, num) && !existsInCol(a, y, num) && !existsInBox(a, x-x%3, y-y%3, num)){ return true; }
	return false;
} 
bool solvePuzzle(int a[9][9]){

	int x;
	int  y;

	if(!getEmptyCell(a, x, y)){ return true; }

	for( int num = 1; num <= 9; num++){
		if(isValid(a, x, y, num)){
			a[x][y] = num;
			
			if(solvePuzzle(a)){ return true; }else{ a[x][y] = 0; }
		}
	}
	return false;
}
};
