/* Include ***********/
#include <mic_mem/mm_float8.h>

//! accordint to the Floating-Point-IEEE-754

/* Definition ********/
typedef union __attribute__((packed, aligned(1)))
{
  uint8_t Mem;

  struct
  {
    uint8_t Sgn : 1;  /* Sign */
    uint8_t Exp : 3;  /* Exponent : 10^(e-2) */
    uint8_t Man : 4;  /* Mantisa */
  };
}Float8_t;

typedef union __attribute__((packed, aligned(4)))
{
  uint32_t Mem;

  struct
  {
    uint8_t  Sgn : 1;   /* Sign */
    uint8_t  Exp : 8;   /* Exponent */
    uint32_t Man : 23;  /* Mantisa */
  };
}Float32_t;



/* API ***************/
float MM_Float8_Get(MM_Float8_t const _val)
{
  Float8_t val = {0U};

  return val.Mem;
}

MM_Float8_t MM_Float8_Set(float const _val)
{
  return 0U;
}
