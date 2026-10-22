#include <iostream>
using namespace std;

class mattrix{
    public:

    int mat[4][4];

    void input(){
        cout << "enter mattrix elements:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin>>mat[i][j];
            }
        }
    }

    void spiral(){

        int top=0;
        int bottom =3;
        int right =3;
        int left=0;

        //left to right
        for(int j=0;j<=right;j++){
            cout<<mat[top][j];
        }
        top--;

        //top to bottom
        for(int i=0;i<=bottom;i++){
            cout<<mat[i][right];
        }
        right--;

        //right to left
        for(int j=right;j>=left;j--){
            cout<<mat[bottom][j];
        }
        left++;

        //bottom to top
        for(int i=bottom;i<=top;i--){
            cout<<mat[i][left];
        }
        bottom--;
    }
};

int main(){
    mattrix obj;
    obj.input();
    obj.spiral();

    return 0;
}
