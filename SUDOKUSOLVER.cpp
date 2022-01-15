#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int n, int i, int j, int A[][9], int num){
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int col = 0;col<n;col++){
        if(A[i][col] == num || A[col][j] == num){
            return false;
        }
    }
    for(int row = sx;row < sx+rn;row++){
        for(int col = sy; col<sy+rn;col++){
            if(A[row][col] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int n, int i, int j, int A[][9]){
    //Base Cse
    if(i == n){
for(int a = 0;a<n;a++){
    for(int b = 0;b<n;b++){
        cout<<A[a][b]<<" ";
    }
    cout<<endl;
}
cout<<endl;
        return true;
    }
    //Row End
    if(j == n){
        return sudoku(n, i+1,0,A);
    }
    //Already have a value
    if( A[i][j] != 0){
        return sudoku(n,i,j+1,A);
    }
    for(int num = 1;num<=n;num++){
       if(canPlace(n,i,j,A,num)){
           A[i][j] = num;
           if(sudoku(n,i,j+1,A)){
               return true;
           }
       }
    }
    A[i][j] = 0;
    return false;
}


int main()
{
    int n;
    cin>>n;
    int A[9][9];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>A[i][j];
        }
    }
  bool res = sudoku(n,0,0,A);
    
} // namespace std;
