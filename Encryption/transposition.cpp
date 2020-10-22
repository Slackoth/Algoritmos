#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

void fillMatrix(char**,string,int,int);
string catEncryption(char**, int, int);

int main(void) {
    string phrase = "THE SKY IS BLUE";
    string code = "312TAC";
    int cols = 3;
    int rows = ceil(phrase.length() / 3.0) + 2; 

    char** matrix = new char*[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new char[cols];
    
    //Filling the 1st & 2nd rows
    int count = code.length() - 1;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = code[count--];
        }
    

    fillMatrix(&(*matrix),phrase,rows,cols);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    cout << catEncryption(matrix,rows,cols);
}


void fillMatrix(char** matrix, string phrase, int rows, int cols) {
    int size = phrase.length();
    int count = 0;
    for(int i = 2; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(count < size) {
                if(phrase[count] != ' ') {
                    matrix[i][j] = phrase[count];
                    //cout << "PTM" <<  count << endl;
                    count++;
                }
                else {
                    //count++;
                    matrix[i][j] = phrase[count + 1];
                    count+=2;
                    //cout << "CTM" <<  count << endl;
                }
            }
            else {
                matrix[i][j] = 'F';
            }
        }
    }


}

string catEncryption(char** matrix, int rows, int cols) {
    string arr[3];
    string word = "";
    for(int i = 0; i < cols; i++) {
        word = "";
        for(int j = 2; j < rows; j++)
            word = word + matrix[j][i]; 
        arr[i] = word;
    }
    
    return arr[1] + arr[0] + arr[2];
}
