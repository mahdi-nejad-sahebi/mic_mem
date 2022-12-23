/* Include ***********/
#include <math.h>
#include <tests/mm_test_float8.h>



/* Definition ********/



/* API ***************/
static void Error()
{
  while (1)
  {
    /* Error calculation compare to float_t */
    float x1 = 9;
    float x2 = 0;
    float d = 0;
    float err = 0;
    MM_Float8_t y = 0;

    y = MM_Float8_Set(x1);
    x2 = MM_Float8_Get(y);
    d = fabsf(x2 - x1);
    err = (d / x1);

    d = 0;
  }
}

static void Random()
{

}

static void MinAbs()
{

}

static void MaxAbs()
{

}

void Test_Float8()
{
  Random();
  Error();
  MinAbs();
  MaxAbs();
}
