#include <iostream>

using namespace std;

const int ROW=6;
const int COL=4;

//Prototypes
void loading(int& r, int& c, int mat[ROW][COL]);
void print(int r, int c, const int mat[ROW][COL]);
void mainDiagonal(int r, const int mat[ROW][COL]);
int sumMD(int r, const int mat[ROW][COL]);
void antiDiagonal(int r, int c, const int mat[ROW][COL]);
int sumAD(int r, int c, const int mat[ROW][COL]);
void search(int r, int c, const int mat[ROW][COL]);
int sumRow(int r, int c, const int mat[ROW][COL]);
int sumCol(int r, int c, const int mat[ROW][COL]);

//Main program
int main(int argc, char** argv) {
	int mat[ROW][COL]; 
	int r, c;
	loading(r, c, mat);
	print(r, c, mat);
	if(r==c) {
		mainDiagonal(r, mat);
		cout<<"The sum of the elements of the main diagonal is: "<<sumMD(r, mat)<<endl;
		antiDiagonal(r, c, mat);
		cout<<"The sum of the elements of the antidiagonal is: "<<sumAD(r, c, mat)<<endl;
	}
	search(r, c, mat);
	cout<<"The sum of the elements of the chosen row is: "<<sumRow(r, c, mat)<<endl;
	cout<<"The sum of the elements of the chosen column is: "<<sumCol(r, c, mat)<<endl;
	return 0;
}

//Implementations
void loading(int& r, int& c, int mat[ROW][COL]){
	do {
		cout<<"Enter the number of rows to manage: ";
		cin>>r;
		if(r<0 || r>ROW) cout<<"You have entered an invalid number!"<<endl;
	} while (r<0 || r>ROW);
	
    do {
		cout<<"Enter the number of columns to manage: ";
		cin>>c;
		if(c<0 || c>COL) cout<<"You have entered an invalid number!"<<endl;
	} while (c<0 || c>COL);
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cout<<"Insert element ("<<i<<","<<j<<"): ";
			cin>>mat[i][j];
		}
	}	
}

void print(int r, int c, const int mat[ROW][COL]) {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cout<<mat[i][j];
			cout<<"\t";
		}
		cout<<endl;
	}		
}

void mainDiagonal(int r, const int mat[ROW][COL]) {
	cout<<"The elements of the main diagonal are: ";
	for (int i=0; i<r; i++) {
		cout<<mat[i][i]<<" ";
	}
	cout<<endl;
}

int sumMD(int r, const int mat[ROW][COL]) {
	int mainDiagonal=0;
	for (int i=0; i<r; i++) {
		mainDiagonal+=mat[i][i];
	}
	return mainDiagonal;
}

void antiDiagonal(int r, int c, const int mat[ROW][COL]) {
	cout<<"The elements of the antidiagonal are: ";
	for (int i=0, j=c-1; i<r; i++, j--) {
		cout<<mat[i][j]<<" ";
	}
	cout<<endl;
}

int sumAD(int r, int c, const int mat[ROW][COL]) {
	int antiDiagonal=0;
	for (int i=0, j=c-1; i<r, j>=0; i++, j--) {
		antiDiagonal+=mat[i][j];
	}
	return antiDiagonal;
}

void search(int r, int c, const int mat[ROW][COL]) {
	int num, counter=0;
	cout<<"Which number do you want to look for? ";
	cin>>num;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if(mat[i][j]==num) counter++;
		}
	}
	cout<<"The number "<<num<<" is present "<<counter<<" times."<<endl;
}

int sumRow(int r, int c, const int mat[ROW][COL]) {
	int row, sumR=0;
	do {
		cout<<"Enter the row whose elements you want to sum: ";
		cin>>row;
		if(row<0 || row>r) cout<<"You have entered an invalid row!"<<endl;
	} while (row<0 || row>r);
	for (int i=0; i<c; i++) {
		sumR+=mat[row][i];
	}
	return sumR;
}

int sumCol(int r, int c, const int mat[ROW][COL]) {
	int column, sumC=0;
	do {
		cout<<"Enter the column whose elements you want to sum: ";
		cin>>column;
		if(column<0 || column>c) cout<<"You have entered an invalid column!"<<endl;
	} while (column<0 || column>c);
	for (int i=0; i<r; i++) {
		sumC+=mat[i][column];
	}
	return sumC;
}
