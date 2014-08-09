#include <iostream>
using namespace std;

void main()
{
   /*
   Let's define Arr[A][B].
   The position of element Arr[i][j] is accessed directly based on the formula (i*B + j)

   Let's define Arr[A][B][C].
   The position of element Arr[i][j][k] is accessed directly based on the formula (i*B*C + j*C + k)
   */
   char ch3D[3][3][2] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
   cout << "ch3D[1][2][0] = " << (int) ch3D[1][2][0] << endl;
   char *ch1D = reinterpret_cast<char *>(ch3D);
   cout << "ch3D[1][2][0] = ch1D[1*3*2 + 2*2 + 0] = " << (int) ch1D[1*3*2 + 2*2 + 0] << endl;

}
