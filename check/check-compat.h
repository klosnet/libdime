#include <check.h>
#include <stdint.h>
#include <inttypes.h>

/* check <= 0.9.9 doesn't have many of the nice convenience functions. */
#if CHECK_MAJOR_VERSION * 10000 + CHECK_MINOR_VERSION * 100 + CHECK_PATCH_VERSION < 0 * 10000 + 9 * 100 + 10 * 1

#undef _ck_assert_int
#define _ck_assert_int(X, OP, Y) do { \
  intmax_t _ck_x = (X); \
  intmax_t _ck_y = (Y); \
  ck_assert_msg(_ck_x OP _ck_y, "Assertion '%s' failed: %s == %jd, %s == %jd", #X " " #OP " " #Y, #X, _ck_x, #Y, _ck_y); \
} while (0)

#define _ck_assert_uint(X, OP, Y) do { \
  uintmax_t _ck_x = (X); \
  uintmax_t _ck_y = (Y); \
  ck_assert_msg(_ck_x OP _ck_y, "Assertion '%s' failed: %s == %ju, %s == %ju", #X " " #OP " " #Y, #X, _ck_x, #Y, _ck_y); \
} while (0)
#define ck_assert_uint_eq(X, Y) _ck_assert_uint(X, ==, Y)
#define ck_assert_uint_ne(X, Y) _ck_assert_uint(X, !=, Y)
#define ck_assert_uint_lt(X, Y) _ck_assert_uint(X, <, Y)
#define ck_assert_uint_le(X, Y) _ck_assert_uint(X, <=, Y)
#define ck_assert_uint_gt(X, Y) _ck_assert_uint(X, >, Y)
#define ck_assert_uint_ge(X, Y) _ck_assert_uint(X, >=, Y)

#define _ck_assert_ptr(X, OP, Y) do { \
  const void* _ck_x = (X); \
  const void* _ck_y = (Y); \
  ck_assert_msg(_ck_x OP _ck_y, "Assertion '%s' failed: %s == %#p, %s == %#p", #X " " #OP " " #Y, #X, _ck_x, #Y, _ck_y); \
} while (0)

#define ck_assert_ptr_eq(X, Y) _ck_assert_ptr(X, ==, Y)
#define ck_assert_ptr_ne(X, Y) _ck_assert_ptr(X, !=, Y)

#endif