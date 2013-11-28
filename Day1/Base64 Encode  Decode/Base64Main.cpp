#include <iostream>
#include "Base64.h"

void main()
{
   const char chArr[] = "Some have little power to do good, and have likewise little strength to resist evil.(Samuel Johnson)";
   string ret;
   ret = Base64::encode64(chArr, strlen(chArr));
   cout << ret << endl;
   ret = Base64::decode64(ret);
   cout << ret << endl;
}
