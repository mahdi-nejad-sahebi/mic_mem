/* Include ***********/
#include <math.h>
#include <tests/mm_test_float8.h>



/* Definition ********/



/* API ***************/
//! move to related module
float MM_Rand()
{
  return (rand() / (float)RAND_MAX);
}

float MM_RandRng(float const _a, float const _b)
{
  return (_a + (MM_Rand() * (_b - _a)));
}

static void Error()
{
  uint32_t cnt = 0;
  float sum = 0;
  float min = 100;
  float max = -100;

  while (1)
  {
    /* Error calculation compare to float_t */
//    float x1 = MM_RandRng(-9300, 9300);
    float x1 = MM_RandRng(-1.0F, +1.0F);
    float x2 = 0;
    float d = 0;
    float err = 0;
    MM_Float8_t y = 0;

    y = MM_Float8_Set(x1);
    x2 = MM_Float8_Get(y);
    d = fabsf(x2 - x1);
    err = fabsf(d / x1);

    sum += err;
    cnt++;
    min = (min > err) ? err : min;
    max = (max < err) ? err : max;
    float avg = (sum / cnt);

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
