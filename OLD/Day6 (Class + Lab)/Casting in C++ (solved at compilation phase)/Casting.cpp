/*
static_cast<> uses sensible, well-defined conversions. For example, the
integer 10 would be converted to the double 10.0.

reinterpret_cast<> just looks at the bits in memory in as if they were
the encoding as a different type. For example, the integer 10 would
look like some number who-knows-what as a double.

*/

void main()
{
   int iVal = 10;
   double dVal=5;
   int *p;

   iVal = dVal;      // Warning: conversion from 'double' to 'int', possible loss of data
   iVal = static_cast<int>(dVal);

//   p = iVal;      // Error: cannot convert from 'int' to 'int *'
   p = reinterpret_cast<int *>(iVal);

//   p = &dVal;        // Error: cannot convert from 'double *' to 'int *'
   p = reinterpret_cast<int *>(&dVal);
}
