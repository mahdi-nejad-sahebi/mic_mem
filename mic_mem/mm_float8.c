/********** Include */
#include <float.h>
#include <math.h>
#include <mic_mem/mm_float8.h>

//! accordint to the Floating-Point-IEEE-754

/********** Definition */
typedef enum __attribute__((packed))
{
  EXP_10_N = 0,  /* 10 ^ (-2) */
  EXP_10_0,      /* 10 ^ (0) */
  EXP_10_1,      /* 10 ^ (1) */
  EXP_10_2,      /* 10 ^ (2) */
}Exponent_t;

typedef union __attribute__((packed, aligned(1)))
{
  uint8_t Mem;

  struct
  {
    uint8_t Sgn : 1;  /* Sign */
    uint8_t Exp : 3;  /* Exponent : 10^(e-2) */
    uint8_t Man : 4;  /* Mantisa */
  }__attribute__((packed, aligned(1)));
}Float8_t;


/*
 *  Float 16
 * Exp : 5. emin = -14, emax=15
 *
 *
 * F32
 * Exp:8, emin = -126, emax= 127
 *
 */

typedef union __attribute__((packed, aligned(4)))
{
  float Mem;

  struct
  {
    uint8_t  Sgn : 1;   /* Sign */
    uint8_t  Exp : 8;   /* Exponent */
    uint32_t Man : 23;  /* Mantisa */
  }__attribute__((packed, aligned(4)));
}Float32_t;



/********** API */
float MM_Float8_Get(MM_Float8_t const _f8)
{
  Float8_t* const f8 = (Float8_t*)&_f8;
  Float32_t f32 = {0U};

  f32.Sgn = f8->Sgn;

  if (0U == f8->Exp)
  {
    f32.Mem = f8->Man * 0.01F;
    f32.Mem *= 3.0F;
  }
  else
  {
    f32.Mem = f8->Man;

    uint8_t pow = (f8->Exp - 1U);

    while (pow)
    {
      f32.Mem *= 10.0F;
      pow--;
    }
    f32.Mem *= 3.0F;
  }

  return f32.Mem;
}

MM_Float8_t MM_Float8_Set(float const _f32)
{
  Float8_t f8 = {0U};
  Float32_t* const f32 = (Float32_t*)&_f32;

  f8.Sgn = f32->Sgn;

  float const val = fabsf(_f32);
  if (val < 1.0F)
  {
    float t1 = val / 3.0F;
    float t2 = t1 * 100.0F;
    f8.Man = (uint8_t)t2;
    f8.Exp = 0U;//EXP_10_N;
  }
  else
  {
    uint8_t pow = 0U;
    float t1 = (val / 3.0F);

    while (t1 > 31.0F)
    {
      t1 *= 0.1F;
      pow++;
    }
    f8.Man = (uint8_t)t1;
    f8.Exp = (pow + 1U);
  }


  return f8.Mem;
}
