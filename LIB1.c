#include <stdio.h>
#include <malloc.h>
#pragma warning (disable: 4996)

typedef struct {
  long hi;
  long lo;
} verylong_t;

typedef enum {
  LESS = -1,
  EQUAL,
  EXCEED
} compare_t;

long power(int n, int x)
{
  if (n == 0) return 1;
  else if (n == 1) return x;
  else return (x*power(n-1, x));
}
verylong_t* FromLong(long* ltest, long* htest)
{

}
long AsLong(verylong_t* vlong)
{

}
verylong_t* Parse(char* str)
{

}
char* Format(verylong_t* vlong)
{

}
verylong_t* Read(FILE* input)
{

}
void Write(verylong_t vlong)
{
  int i = 0;
  int j = 0;
  int a[18] = {0};
  if ((vlong.hi == 0) && (vlong.lo == 0))
  {
    printf("0\n");
    return;
  }
  if ((vlong.hi < 0) && (vlong.lo < 0)) vlong.lo *= -1;
  if (vlong.hi != 0)
  {
    while (i < 9) 
    {
      a[i] = (vlong.lo % power(i+1, 10)) / (power(i, 10));
      i++;
    }
    while ((vlong.hi % power(j, 10)) != vlong.hi)
    {
      a[i] = (vlong.hi % power(j+1, 10)) / (power(j, 10));
      i++;
      j++;
    }
  }
  else 
    while ((vlong.lo % power(i, 10)) != vlong.lo) 
    {
      a[i] = (vlong.lo % power(i+1, 10)) / (power(i, 10));
      i++;
    }
  for (j = i-1; j >= 0; j--) {printf("%i", a[j]);}
  printf("\n");
  return;
}
verylong_t Add(verylong_t* vlong1, verylong_t* vlong2)
{
  verylong_t result;
  result.hi = 0;
  result.lo = 0;
  result.lo = (vlong1->lo + vlong2->lo);
  result.hi = (vlong1->hi + vlong2->hi + result.lo / power(9, 10));
  if (result.lo >= power(9, 10) || result.lo<=-power(9,10))
  { 
    result.lo %=power(9,10);
  }
  if ((result.hi >=power(9, 10)) || (result.hi <=-power(9,10)))
  {
    printf("Out of range.");
    result.hi = 0;
    result.lo = 0;
  }
  return result;
}
verylong_t Sub(verylong_t* vlong1, verylong_t* vlong2)
{
  verylong_t result;
  result.hi = 0;
  result.lo = 0;
  result.lo = (vlong1 -> lo - vlong2 -> lo);
  result.hi = (vlong1 -> hi - vlong2 -> hi - result.lo / power(9, 10));
  if (result.lo >= power(9, 10))
  { 
    result.lo %= power(9,10);
  }
  if ((result.lo < 0) && (result.hi >= 1))
  { 
    result.hi -= 1;
    result.lo = power(9,10) + result.lo;
  }
  if ((result.hi >= power(9, 10)) || (result.hi <= -power(9,10)))
  {
    printf("Out of range.");
    result.hi = 0;
    result.lo = 0;
  }
  return result;
}
verylong_t Mul(verylong_t* vlong1, verylong_t* vlong2)
{

}
verylong_t Div(verylong_t* vlong1, verylong_t* vlong2)
{
  verylong_t result;
  result.hi = 0;
  result.lo = 0;
  if ((vlong2->hi == 0) && (vlong2->lo == 0))
  {
    printf("EXCALIBUR");
    return *vlong2;
  } 
  if (vlong2->hi != 0)
  {
    if (vlong1->lo >= vlong2->lo)
    {
      result.hi = vlong1->hi/vlong2->hi;
    }
    else 
    {
      result.hi = (vlong1->hi-1)/vlong2->hi;
    }
    result.lo = result.hi;
    result.hi = 0;
  }
  else 
  {
    result.hi = vlong1->hi/vlong2->lo;
    result.lo = vlong1->lo/vlong2->lo;
  }
  return result;
}
verylong_t* Negate(verylong_t* vlong)
{
  vlong->hi *=(-1);
  return vlong;
}
verylong_t* Abs(verylong_t* vlong)
{
  if (vlong->hi < 0) vlong->hi *=(-1);
  return vlong;
}
compare_t Compare(verylong_t* vlong1, verylong_t* vlong2)
{
  long hires, lores;
  if (((hires = vlong1->hi - vlong2->hi) == 0) && ((lores = vlong1->lo - vlong2->lo) == 0)) return EQUAL;
  else if (hires < 0) return LESS;
  else if (lores < 0) return LESS;
  else return EXCEED;
  /*if (result = AsLong(Sub(vlong1, vlong2)) == 0) return EQUAL;
  else if (result < 0) return */
}

int main(void)
{
  verylong_t* vlong1;
  verylong_t* vlong2;
  vlong1 = malloc(sizeof(verylong_t));
  vlong1->hi = 1;
  vlong1->lo = 0;
  vlong2 = malloc(sizeof(verylong_t));
  vlong2->hi = 0;
  vlong2->lo = 0;
  while ((vlong1->hi!=0) ||(vlong1->lo!=0) || (vlong2->hi!=0) || (vlong2->lo!=0))
  {
    scanf("%li %li %li %li", &(vlong1->hi), &(vlong1->lo), &(vlong2->hi), &(vlong2->lo));
    //Write(*vlong1);
    Write(Sub(vlong1, vlong2));
    Write(Add(vlong1, vlong2));
    Write(Div(vlong1, vlong2));
  }
  return 0;
}