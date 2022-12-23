/********** Include */
#ifndef __MM_FLOAT8_H__
#define __MM_FLOAT8_H__
#include <stdint.h>


/********** Definition */
typedef uint8_t MM_Float8_t;


/********** API */
float       MM_Float8_Get(MM_Float8_t const _val);
MM_Float8_t MM_Float8_Set(float const _val);
//! get max abs
//! get min abs greater than 0

#endif /* __MM_FLOAT8_H__ */
