#ifndef BASE64
#define BASE64

#include <string>
using namespace std;

class Base64
{
   static string const _base64_;

public:

   static inline bool is_base64(unsigned char c)
   {
      return (isalnum(c) || (c == '+') || (c == '/')); 
   }
   static string encode64(char const* bytes_to_encode, unsigned int in_len);
   static string decode64(string const& encoded_string);
};

#endif