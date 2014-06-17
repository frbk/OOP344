/*
  This is a pseudocode that you have to convert into a C++ code.
  Also you have to implement all classes to support this pseudocode
  Volume for Sphere = 4*PI*Power(R,3)/3
  Volume for Cube = Power(R,3)
*/

void main()
{
	<type_array>  arr[D3_LENGTH];
	index = 0;
	while 1
	{
		Display "3D object (Sphere-S, Cube-C):"
		Accept Obj_Type
		switch(Obj_Type)
		{
		  when (C)
			{
		      Display "Enter Side"
		      Accept Side
			  arr[index++] = new Cube(Side)
			}
		  when (S)
			{
		      Display "Enter Radius"
		      Accept Rad
			  arr[index++] = new Sphere(Rad)
			}
		}
		if (index Equals D3_LENGTH)
			Exit While
		Display "Continue ?:"
		Accept YN
		if YN NOT Equal "Y"
			Exit While
	}
	for (from First index ; to Last index ; Update index)
	{
		Display arr[.]->getShapeName()
			    arr[.]->getVolume()
	}
}