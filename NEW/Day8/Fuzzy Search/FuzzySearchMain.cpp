
// Pseudo Code
for (i=0 ; i<=t.Length ; i++)
{
   prev1[i]=i;
}
for (i=0 ; i<s.Length ; i++)
{
   curr[0]=i+1;
   for (j=0 ; j<t.Length ; j++)
   {
      if (s[i] == t[j])
         cost = 0;
      else
         cost = 1;
      curr[j+1] = Min(prev1[j+1] + 1,         // deletion
                      Min(curr[j] + 1,        // insertion
                          prev1[j] + cost     // substitution
                         )
                     );
   }
   ptemp=curr;
   curr=prev1;
   prev1=ptemp;
}

    a b c                a a c
  0 1 2 3              0 1 2 3
a 1 0 1 2            a 1 0 1 2
b 2 1 0 1            b 2 1 1 2
c 3 2 1 0            c 3 2 2 1

    a c b                a b
  0 1 2 3              0 1 2
a 1 0 1 2            a 1 0 1
b 2 1 1 2            b 2 1 0
c 3 2 1 2            c 3 2 1

