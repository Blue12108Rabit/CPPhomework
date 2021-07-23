#include <iostream>

using namespace std;

class Array{

private:

     int b[4][4];

public:

     Array(int(*p)[4]);

     ~Array();

     void operator++();

     friend void operator--(Array &b);

     void display();

};

Array::Array(int  (*p)[4]){

     for (int c = 0; c < 4;c++)

     for (int d = 0; d < 4; d++)

          b[c][d] = p[c][d];

}

 

Array::~Array(){

 

}

void Array::operator++(){

     int cache[4][4];

     for (int c = 0; c < 4; c++)

     for (int d = 0; d < 4; d++)

          cache[c][d]=b[c][d];

     for (int c = 0; c < 4; c++)

     for (int d = 0; d < 4; d++)

          b[d][3-c]=cache[c][d];

 

}

void operator--(Array &b){

     int cache[4][4];

     for (int c = 0; c < 4; c++)

     for (int d = 0; d < 4; d++)

          cache[c][d] = b.b[c][d];

     for (int c = 0; c < 4; c++)

     for (int d = 0; d < 4; d++)

          b.b[3-d][c] = cache[c][d];

}

void Array::display(){

     for (int c = 0; c < 4; c++)

     for (int d = 0; d < 4; d++)

     {

          cout << b[c][d] << " ,";

          if (d == 3)

               cout << endl;

     }

}

int main(){

 

     int testData[4][4] = {

          1, 2, 3, 4,

          2, 2, 3, 4,

          3, 2, 3, 4,

          4, 2, 3, 4

     };

     Array array(testData);

     ++array;

     array.display();

     cout << endl;

     --array;

     --array;

     array.display();

     getchar();

     getchar();

     return 0;

}