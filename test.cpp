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

vector<number*> intlist;

for(int i = 0; i < 2; ++i){
    number* mynumbers = new number;


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

    for(int i = 0; i < intlist.size(); ++i){
        cout << "x = " << intlist[i]->getx() << endl;
        cout << "y = " << intlist[i]->gety() << endl;
        delete intlist[i];
    }


}