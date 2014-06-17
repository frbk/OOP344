#include "Base64.h"

const string Base64::_base64_ = string("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
/*
Char4[0] {0-5} := char3[0] {2-7}
Char4[1] {0-3} := char3[1] {4-7}
Char4[1] {4-5} := char3[0] {0-1}
Char4[2] {0-1} := char3[2] {6-7}
Char4[2] {2-5} := char3[1] {0-3}
Char4[3] {0-5} := char3[2] {0-5}
*/
string Base64::encode64(char const* bytes_to_encode, unsigned int in_len)
{
      string ret;
     int i = 0;
     int j = 0;
     unsigned char char_3[3];
     unsigned char char_4[4];

     while (in_len--)
     {
        char_3[i++] = *(bytes_to_encode++);
        if (i == 3)
        {
           char_4[0] = (char_3[0] & 0xfc) >> 2;
           char_4[1] = ((char_3[0] & 0x03) << 4) | ((char_3[1] & 0xf0) >> 4);
           char_4[2] = ((char_3[1] & 0x0f) << 2) | ((char_3[2] & 0xc0) >> 6);
           char_4[3] = char_3[2] & 0x3f;

           for(i = 0; i < 4 ; i++)
              ret += _base64_[char_4[i]];
           i = 0;
        }
     }

     if (i)
     {
        for(j = i; j < 3; j++)
           char_3[j] = '\0';

        char_4[0] = (char_3[0] & 0xfc) >> 2;
        char_4[1] = ((char_3[0] & 0x03) << 4) | ((char_3[1] & 0xf0) >> 4);
        char_4[2] = ((char_3[1] & 0x0f) << 2) | ((char_3[2] & 0xc0) >> 6);
        char_4[3] = char_3[2] & 0x3f;

        for (j = 0; j < i + 1; j++)
           ret += _base64_[char_4[j]];

        while((i++ < 3))
           ret += '=';

     }
     return ret;
}

string Base64::decode64(string const& encoded_string)
{
      int in_len = encoded_string.size();
      int i = 0;
      int j = 0;
      int in_ = 0;
      string ret;
      unsigned char char_3[3];
      unsigned char char_4[4];

      while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_]))
      {
         char_4[i++] = encoded_string[in_]; in_++;
         if (i ==4)
         {
            for (i = 0; i <4; i++)
               char_4[i] = _base64_.find(char_4[i]);

            char_3[0] = (char_4[0] << 2) | ((char_4[1] & 0x30) >> 4);
            char_3[1] = ((char_4[1] & 0xf) << 4) | ((char_4[2] & 0x3c) >> 2);
            char_3[2] = ((char_4[2] & 0x3) << 6) | char_4[3];

            for (i = 0; (i < 3); i++)
               ret += char_3[i];
            i = 0;
         }
      }

      if (i)
      {
         for (j = i; j <4; j++)
            char_4[j] = 0;

         for (j = 0; j <4; j++)
            char_4[j] = _base64_.find(char_4[j]);
         
         char_3[0] = (char_4[0] << 2) | ((char_4[1] & 0x30) >> 4);
         char_3[1] = ((char_4[1] & 0xf) << 4) | ((char_4[2] & 0x3c) >> 2);
         char_3[2] = ((char_4[2] & 0x3) << 6) | char_4[3];

         for (j = 0; (j < i - 1); j++) ret += char_3[j];
      }
      return ret;
}
