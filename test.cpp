#include <iostream>
#include <vector>
using namespace std;

class number{
    public:
        void setx(int x){
            this->x = x;
        }
        int getx(){
            return x;
        }

        void sety(int y){
            this->y = y;
        }
        int gety(){
            return y;
        }

    private:
        int x;
        int y;
};

int main(){

    number* mynumbers = new number;

    vector<number*> intlist;

    int x;
    int y;

    cout << "Enter x" << endl;
    cin >> x;
    mynumbers->setx(x);
    cout << "X = " << mynumbers->getx() << endl;
    cout << "Enter y" << endl;
    cin >> y;
    mynumbers->sety(y);
    cout << "Y = " << mynumbers->gety() << endl;

    intlist.push_back(mynumbers);


}