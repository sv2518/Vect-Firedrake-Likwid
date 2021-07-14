#include <complex.h>
#include <math.h>
#include <petsc.h>
#include <stdint.h>
#define LOOPY_CALL_WITH_INTEGER_TYPES(MACRO_NAME) \
    MACRO_NAME(int8, char) \
    MACRO_NAME(int16, short) \
    MACRO_NAME(int32, int) \
    MACRO_NAME(int64, long)
#define LOOPY_DEFINE_FLOOR_DIV_POS_B(SUFFIX, TYPE) \
    static inline TYPE loopy_floor_div_pos_b_##SUFFIX(TYPE a, TYPE b) \
    { \
        if (a<0) \
            a = a - (b-1); \
        return a/b; \
    }
LOOPY_CALL_WITH_INTEGER_TYPES(LOOPY_DEFINE_FLOOR_DIV_POS_B)
#undef LOOPY_DEFINE_FLOOR_DIV_POS_B
#undef LOOPY_CALL_WITH_INTEGER_TYPES
#define BYTES8 (8*8)
typedef double double8 __attribute__ ((vector_size (BYTES8)));
#define BYTES4 (8*4)
typedef int int8 __attribute__ ((vector_size (BYTES4)));

void wrap_form0_cell_integral_otherwise(int const start, int const end, double *__restrict__ dat2, double const *__restrict__ dat1, double const *__restrict__ glob0, double const *__restrict__ dat0, int const *__restrict__ map0, int const *__restrict__ map1)
{
  double8 form_form0_cell_integral_otherwise __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_0 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_1 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_10 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_11 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_12 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_13 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_14 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_15 __attribute__ ((aligned (64)));
  double const form_form0_cell_integral_otherwise_16[4] __attribute__ ((aligned (64))) = { 0.041666666666666664, 0.041666666666666664, 0.041666666666666664, 0.041666666666666664 };
  double const form_form0_cell_integral_otherwise_17[4 * 4] __attribute__ ((aligned (64))) = { 0.13819660112500914, 0.585410196624969, 0.138196601125011, 0.13819660112501098, 0.13819660112500912, 0.13819660112501092, 0.585410196624969, 0.13819660112501098, 0.13819660112500914, 0.13819660112501095, 0.138196601125011, 0.585410196624969, 0.5854101966249672, 0.13819660112501092, 0.138196601125011, 0.13819660112501098 };
  double8 form_form0_cell_integral_otherwise_18 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_19 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_2 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_20 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_21 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_22[4] __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_23 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_24 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_25 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_26 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_27 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_28 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_29 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_3 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_30 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_31 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_32 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_33 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_34 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_35 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_36 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_37 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_38 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_39 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_4 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_40 __attribute__ ((aligned (64)));
  double const form_form0_cell_integral_otherwise_41[4] __attribute__ ((aligned (64))) = { -1.0, 0.0, 0.0, 1.0 };
  double8 form_form0_cell_integral_otherwise_42 __attribute__ ((aligned (64)));
  double const form_form0_cell_integral_otherwise_43[4] __attribute__ ((aligned (64))) = { -1.0, 0.0, 1.0, 0.0 };
  double8 form_form0_cell_integral_otherwise_44 __attribute__ ((aligned (64)));
  double const form_form0_cell_integral_otherwise_45[4] __attribute__ ((aligned (64))) = { -1.0, 1.0, 0.0, 0.0 };
  double8 form_form0_cell_integral_otherwise_5 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_6 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_7 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_8 __attribute__ ((aligned (64)));
  double8 form_form0_cell_integral_otherwise_9 __attribute__ ((aligned (64)));
  double8 t0[4] __attribute__ ((aligned (64)));
  double8 t1[4 * 3] __attribute__ ((aligned (64)));
  double8 t2[4] __attribute__ ((aligned (64)));
  double8 const zero_vec_float64 = { 0.0 };

  {
    /* initial slab for 'n_outer' */
    /*   */
  }
  {
    int const n_outer = start + -1 * ((7 + 7 * start) / 8);

    if (-1 + end + -1 * start >= 0)
    {
      for (int i2 = 0; i2 <= 3; ++i2)
        t2[i2] = zero_vec_float64;
      for (int i0 = 0; i0 <= 3; ++i0)
      {
        for (int i1 = 0; i1 <= 2; ++i1)
          for (int n_batch = start + -8 * n_outer; n_batch <= (-8 + end + -8 * n_outer >= 0 ? 7 : -1 + end + -8 * n_outer); ++n_batch)
            t1[(3 * i0 + i1)][n_batch] = dat1[3 * map1[32 * n_outer + 4 * n_batch + i0] + i1];
        for (int n_batch = start + -8 * n_outer; n_batch <= (-8 + end + -8 * n_outer >= 0 ? 7 : -1 + end + -8 * n_outer); ++n_batch)
          t0[i0][n_batch] = dat0[map0[32 * n_outer + 4 * n_batch + i0]];
      }
      for (int n_batch = start + -8 * n_outer; n_batch <= (-8 + end + -8 * n_outer >= 0 ? 7 : -1 + end + -8 * n_outer); ++n_batch)
      {
        /* no-op (insn=form__start) */
        /*   */
      }
      form_form0_cell_integral_otherwise_20 = zero_vec_float64;
      form_form0_cell_integral_otherwise = -1.0 * t1[0];
      form_form0_cell_integral_otherwise_0 = form_form0_cell_integral_otherwise + t1[3];
      form_form0_cell_integral_otherwise_1 = -1.0 * t1[1];
      form_form0_cell_integral_otherwise_2 = form_form0_cell_integral_otherwise_1 + t1[7];
      form_form0_cell_integral_otherwise_3 = -1.0 * t1[2];
      form_form0_cell_integral_otherwise_4 = form_form0_cell_integral_otherwise_3 + t1[11];
      form_form0_cell_integral_otherwise_5 = form_form0_cell_integral_otherwise_1 + t1[10];
      form_form0_cell_integral_otherwise_6 = form_form0_cell_integral_otherwise_3 + t1[8];
      form_form0_cell_integral_otherwise_7 = form_form0_cell_integral_otherwise_2 * form_form0_cell_integral_otherwise_4 + -1.0 * form_form0_cell_integral_otherwise_5 * form_form0_cell_integral_otherwise_6;
      form_form0_cell_integral_otherwise_8 = form_form0_cell_integral_otherwise + t1[6];
      form_form0_cell_integral_otherwise_9 = form_form0_cell_integral_otherwise_3 + t1[5];
      form_form0_cell_integral_otherwise_10 = form_form0_cell_integral_otherwise_5 * form_form0_cell_integral_otherwise_9;
      form_form0_cell_integral_otherwise_11 = form_form0_cell_integral_otherwise_1 + t1[4];
      form_form0_cell_integral_otherwise_12 = form_form0_cell_integral_otherwise + t1[9];
      form_form0_cell_integral_otherwise_13 = form_form0_cell_integral_otherwise_11 * form_form0_cell_integral_otherwise_6 + -1.0 * form_form0_cell_integral_otherwise_2 * form_form0_cell_integral_otherwise_9;
      form_form0_cell_integral_otherwise_14 = form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_13 + form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_7 + form_form0_cell_integral_otherwise_8 * (form_form0_cell_integral_otherwise_10 + -1.0 * form_form0_cell_integral_otherwise_11 * form_form0_cell_integral_otherwise_4);
      #pragma omp simd
      for (int n_batch_simd = start + -8 * n_outer; n_batch_simd <= (-8 + end + -8 * n_outer >= 0 ? 7 : -1 + end + -8 * n_outer); ++n_batch_simd)
        form_form0_cell_integral_otherwise_15[n_batch_simd] = fabs(form_form0_cell_integral_otherwise_14[n_batch_simd]);
      for (int form_j = 0; form_j <= 3; ++form_j)
        form_form0_cell_integral_otherwise_22[form_j] = zero_vec_float64;
      for (int form_ip = 0; form_ip <= 3; ++form_ip)
      {
        form_form0_cell_integral_otherwise_18 = zero_vec_float64;
        for (int form_i = 0; form_i <= 3; ++form_i)
          form_form0_cell_integral_otherwise_18 = form_form0_cell_integral_otherwise_18 + form_form0_cell_integral_otherwise_17[4 * form_ip + form_i] * t0[form_i];
        form_form0_cell_integral_otherwise_19 = form_form0_cell_integral_otherwise_16[form_ip] * form_form0_cell_integral_otherwise_15;
        form_form0_cell_integral_otherwise_20 = form_form0_cell_integral_otherwise_20 + form_form0_cell_integral_otherwise_19;
        form_form0_cell_integral_otherwise_21 = form_form0_cell_integral_otherwise_19 * glob0[0] * form_form0_cell_integral_otherwise_18;
        for (int form_j_0 = 0; form_j_0 <= 3; ++form_j_0)
          form_form0_cell_integral_otherwise_22[form_j_0] = form_form0_cell_integral_otherwise_22[form_j_0] + form_form0_cell_integral_otherwise_17[4 * form_ip + form_j_0] * form_form0_cell_integral_otherwise_21;
      }
      form_form0_cell_integral_otherwise_23 = 1.0 / form_form0_cell_integral_otherwise_14;
      form_form0_cell_integral_otherwise_24 = form_form0_cell_integral_otherwise_7 * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_25 = -1.0 * t0[0];
      form_form0_cell_integral_otherwise_26 = form_form0_cell_integral_otherwise_25 + t0[1];
      form_form0_cell_integral_otherwise_27 = (form_form0_cell_integral_otherwise_10 + form_form0_cell_integral_otherwise_11 * -1.0 * form_form0_cell_integral_otherwise_4) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_28 = form_form0_cell_integral_otherwise_25 + t0[2];
      form_form0_cell_integral_otherwise_29 = form_form0_cell_integral_otherwise_13 * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_30 = form_form0_cell_integral_otherwise_25 + t0[3];
      form_form0_cell_integral_otherwise_31 = form_form0_cell_integral_otherwise_29 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_24 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_27 * form_form0_cell_integral_otherwise_28;
      form_form0_cell_integral_otherwise_32 = (form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_6 + form_form0_cell_integral_otherwise_4 * -1.0 * form_form0_cell_integral_otherwise_8) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_33 = (form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_4 + form_form0_cell_integral_otherwise_9 * -1.0 * form_form0_cell_integral_otherwise_12) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_34 = (form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_9 + -1.0 * form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_6) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_35 = form_form0_cell_integral_otherwise_34 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_32 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_33 * form_form0_cell_integral_otherwise_28;
      form_form0_cell_integral_otherwise_36 = (form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_5 + -1.0 * form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_2) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_37 = (form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_11 + -1.0 * form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_5) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_38 = (form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_2 + -1.0 * form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_11) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_39 = form_form0_cell_integral_otherwise_38 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_36 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_37 * form_form0_cell_integral_otherwise_28;
      form_form0_cell_integral_otherwise_40 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_38 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_29 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_34) * form_form0_cell_integral_otherwise_20;
      form_form0_cell_integral_otherwise_42 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_37 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_27 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_33) * form_form0_cell_integral_otherwise_20;
      form_form0_cell_integral_otherwise_44 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_36 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_24 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_32) * form_form0_cell_integral_otherwise_20;
      for (int form_j_1 = 0; form_j_1 <= 3; ++form_j_1)
        t2[form_j_1] = t2[form_j_1] + form_form0_cell_integral_otherwise_41[form_j_1] * form_form0_cell_integral_otherwise_40 + form_form0_cell_integral_otherwise_43[form_j_1] * form_form0_cell_integral_otherwise_42 + form_form0_cell_integral_otherwise_22[form_j_1] + form_form0_cell_integral_otherwise_45[form_j_1] * form_form0_cell_integral_otherwise_44;
      for (int n_batch = start + -8 * n_outer; n_batch <= (-8 + end + -8 * n_outer >= 0 ? 7 : -1 + end + -8 * n_outer); ++n_batch)
      {
        /* no-op (insn=statement4) */
        /*   */
      }
      for (int i3 = 0; i3 <= 3; ++i3)
        for (int n_batch = start + -8 * n_outer; n_batch <= (-8 + end + -8 * n_outer >= 0 ? 7 : -1 + end + -8 * n_outer); ++n_batch)
          dat2[map0[32 * n_outer + 4 * n_batch + i3]] = dat2[map0[32 * n_outer + 4 * n_batch + i3]] + t2[i3][n_batch];
    }
  }
  {
    /* bulk slab for 'n_outer' */
    /*   */
  }
  for (int n_outer = 1 + start + -1 * ((7 + 7 * start) / 8); n_outer <= -2 + (7 + end) / 8; ++n_outer)
  {
    for (int i2 = 0; i2 <= 3; ++i2)
      t2[i2] = zero_vec_float64;
    for (int i0 = 0; i0 <= 3; ++i0)
    {
      for (int i1 = 0; i1 <= 2; ++i1)
        for (int n_batch = 0; n_batch <= 7; ++n_batch)
          t1[(3 * i0 + i1)][n_batch] = dat1[3 * map1[32 * n_outer + 4 * n_batch + i0] + i1];
      for (int n_batch = 0; n_batch <= 7; ++n_batch)
        t0[i0][n_batch] = dat0[map0[32 * n_outer + 4 * n_batch + i0]];
    }
    for (int n_batch = 0; n_batch <= 7; ++n_batch)
    {
      /* no-op (insn=form__start) */
      /*   */
    }
    form_form0_cell_integral_otherwise_20 = zero_vec_float64;
    form_form0_cell_integral_otherwise = -1.0 * t1[0];
    form_form0_cell_integral_otherwise_0 = form_form0_cell_integral_otherwise + t1[3];
    form_form0_cell_integral_otherwise_1 = -1.0 * t1[1];
    form_form0_cell_integral_otherwise_2 = form_form0_cell_integral_otherwise_1 + t1[7];
    form_form0_cell_integral_otherwise_3 = -1.0 * t1[2];
    form_form0_cell_integral_otherwise_4 = form_form0_cell_integral_otherwise_3 + t1[11];
    form_form0_cell_integral_otherwise_5 = form_form0_cell_integral_otherwise_1 + t1[10];
    form_form0_cell_integral_otherwise_6 = form_form0_cell_integral_otherwise_3 + t1[8];
    form_form0_cell_integral_otherwise_7 = form_form0_cell_integral_otherwise_2 * form_form0_cell_integral_otherwise_4 + -1.0 * form_form0_cell_integral_otherwise_5 * form_form0_cell_integral_otherwise_6;
    form_form0_cell_integral_otherwise_8 = form_form0_cell_integral_otherwise + t1[6];
    form_form0_cell_integral_otherwise_9 = form_form0_cell_integral_otherwise_3 + t1[5];
    form_form0_cell_integral_otherwise_10 = form_form0_cell_integral_otherwise_5 * form_form0_cell_integral_otherwise_9;
    form_form0_cell_integral_otherwise_11 = form_form0_cell_integral_otherwise_1 + t1[4];
    form_form0_cell_integral_otherwise_12 = form_form0_cell_integral_otherwise + t1[9];
    form_form0_cell_integral_otherwise_13 = form_form0_cell_integral_otherwise_11 * form_form0_cell_integral_otherwise_6 + -1.0 * form_form0_cell_integral_otherwise_2 * form_form0_cell_integral_otherwise_9;
    form_form0_cell_integral_otherwise_14 = form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_13 + form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_7 + form_form0_cell_integral_otherwise_8 * (form_form0_cell_integral_otherwise_10 + -1.0 * form_form0_cell_integral_otherwise_11 * form_form0_cell_integral_otherwise_4);
    #pragma omp simd
    for (int n_batch_simd = 0; n_batch_simd <= 7; ++n_batch_simd)
      form_form0_cell_integral_otherwise_15[n_batch_simd] = fabs(form_form0_cell_integral_otherwise_14[n_batch_simd]);
    for (int form_j = 0; form_j <= 3; ++form_j)
      form_form0_cell_integral_otherwise_22[form_j] = zero_vec_float64;
    for (int form_ip = 0; form_ip <= 3; ++form_ip)
    {
      form_form0_cell_integral_otherwise_18 = zero_vec_float64;
      for (int form_i = 0; form_i <= 3; ++form_i)
        form_form0_cell_integral_otherwise_18 = form_form0_cell_integral_otherwise_18 + form_form0_cell_integral_otherwise_17[4 * form_ip + form_i] * t0[form_i];
      form_form0_cell_integral_otherwise_19 = form_form0_cell_integral_otherwise_16[form_ip] * form_form0_cell_integral_otherwise_15;
      form_form0_cell_integral_otherwise_20 = form_form0_cell_integral_otherwise_20 + form_form0_cell_integral_otherwise_19;
      form_form0_cell_integral_otherwise_21 = form_form0_cell_integral_otherwise_19 * glob0[0] * form_form0_cell_integral_otherwise_18;
      for (int form_j_0 = 0; form_j_0 <= 3; ++form_j_0)
        form_form0_cell_integral_otherwise_22[form_j_0] = form_form0_cell_integral_otherwise_22[form_j_0] + form_form0_cell_integral_otherwise_17[4 * form_ip + form_j_0] * form_form0_cell_integral_otherwise_21;
    }
    form_form0_cell_integral_otherwise_23 = 1.0 / form_form0_cell_integral_otherwise_14;
    form_form0_cell_integral_otherwise_24 = form_form0_cell_integral_otherwise_7 * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_25 = -1.0 * t0[0];
    form_form0_cell_integral_otherwise_26 = form_form0_cell_integral_otherwise_25 + t0[1];
    form_form0_cell_integral_otherwise_27 = (form_form0_cell_integral_otherwise_10 + form_form0_cell_integral_otherwise_11 * -1.0 * form_form0_cell_integral_otherwise_4) * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_28 = form_form0_cell_integral_otherwise_25 + t0[2];
    form_form0_cell_integral_otherwise_29 = form_form0_cell_integral_otherwise_13 * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_30 = form_form0_cell_integral_otherwise_25 + t0[3];
    form_form0_cell_integral_otherwise_31 = form_form0_cell_integral_otherwise_29 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_24 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_27 * form_form0_cell_integral_otherwise_28;
    form_form0_cell_integral_otherwise_32 = (form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_6 + form_form0_cell_integral_otherwise_4 * -1.0 * form_form0_cell_integral_otherwise_8) * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_33 = (form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_4 + form_form0_cell_integral_otherwise_9 * -1.0 * form_form0_cell_integral_otherwise_12) * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_34 = (form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_9 + -1.0 * form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_6) * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_35 = form_form0_cell_integral_otherwise_34 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_32 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_33 * form_form0_cell_integral_otherwise_28;
    form_form0_cell_integral_otherwise_36 = (form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_5 + -1.0 * form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_2) * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_37 = (form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_11 + -1.0 * form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_5) * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_38 = (form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_2 + -1.0 * form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_11) * form_form0_cell_integral_otherwise_23;
    form_form0_cell_integral_otherwise_39 = form_form0_cell_integral_otherwise_38 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_36 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_37 * form_form0_cell_integral_otherwise_28;
    form_form0_cell_integral_otherwise_40 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_38 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_29 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_34) * form_form0_cell_integral_otherwise_20;
    form_form0_cell_integral_otherwise_42 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_37 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_27 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_33) * form_form0_cell_integral_otherwise_20;
    form_form0_cell_integral_otherwise_44 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_36 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_24 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_32) * form_form0_cell_integral_otherwise_20;
    for (int form_j_1 = 0; form_j_1 <= 3; ++form_j_1)
      t2[form_j_1] = t2[form_j_1] + form_form0_cell_integral_otherwise_41[form_j_1] * form_form0_cell_integral_otherwise_40 + form_form0_cell_integral_otherwise_43[form_j_1] * form_form0_cell_integral_otherwise_42 + form_form0_cell_integral_otherwise_22[form_j_1] + form_form0_cell_integral_otherwise_45[form_j_1] * form_form0_cell_integral_otherwise_44;
    for (int n_batch = 0; n_batch <= 7; ++n_batch)
    {
      /* no-op (insn=statement4) */
      /*   */
    }
    for (int i3 = 0; i3 <= 3; ++i3)
      for (int n_batch = 0; n_batch <= 7; ++n_batch)
        dat2[map0[32 * n_outer + 4 * n_batch + i3]] = dat2[map0[32 * n_outer + 4 * n_batch + i3]] + t2[i3][n_batch];
  }
  {
    /* final slab for 'n_outer' */
    /*   */
  }
  {
    int const n_outer = loopy_floor_div_pos_b_int32(-1 + end, 8);

    if (-1 + 8 * n_outer + -1 * start >= 0)
    {
      for (int i2 = 0; i2 <= 3; ++i2)
        t2[i2] = zero_vec_float64;
      for (int i0 = 0; i0 <= 3; ++i0)
      {
        for (int i1 = 0; i1 <= 2; ++i1)
          for (int n_batch = 0; n_batch <= -1 + end + -8 * n_outer; ++n_batch)
            t1[(3 * i0 + i1)][n_batch] = dat1[3 * map1[32 * n_outer + 4 * n_batch + i0] + i1];
        for (int n_batch = 0; n_batch <= -1 + end + -8 * n_outer; ++n_batch)
          t0[i0][n_batch] = dat0[map0[32 * n_outer + 4 * n_batch + i0]];
      }
      for (int n_batch = 0; n_batch <= -1 + end + -8 * n_outer; ++n_batch)
      {
        /* no-op (insn=form__start) */
        /*   */
      }
      form_form0_cell_integral_otherwise_20 = zero_vec_float64;
      form_form0_cell_integral_otherwise = -1.0 * t1[0];
      form_form0_cell_integral_otherwise_0 = form_form0_cell_integral_otherwise + t1[3];
      form_form0_cell_integral_otherwise_1 = -1.0 * t1[1];
      form_form0_cell_integral_otherwise_2 = form_form0_cell_integral_otherwise_1 + t1[7];
      form_form0_cell_integral_otherwise_3 = -1.0 * t1[2];
      form_form0_cell_integral_otherwise_4 = form_form0_cell_integral_otherwise_3 + t1[11];
      form_form0_cell_integral_otherwise_5 = form_form0_cell_integral_otherwise_1 + t1[10];
      form_form0_cell_integral_otherwise_6 = form_form0_cell_integral_otherwise_3 + t1[8];
      form_form0_cell_integral_otherwise_7 = form_form0_cell_integral_otherwise_2 * form_form0_cell_integral_otherwise_4 + -1.0 * form_form0_cell_integral_otherwise_5 * form_form0_cell_integral_otherwise_6;
      form_form0_cell_integral_otherwise_8 = form_form0_cell_integral_otherwise + t1[6];
      form_form0_cell_integral_otherwise_9 = form_form0_cell_integral_otherwise_3 + t1[5];
      form_form0_cell_integral_otherwise_10 = form_form0_cell_integral_otherwise_5 * form_form0_cell_integral_otherwise_9;
      form_form0_cell_integral_otherwise_11 = form_form0_cell_integral_otherwise_1 + t1[4];
      form_form0_cell_integral_otherwise_12 = form_form0_cell_integral_otherwise + t1[9];
      form_form0_cell_integral_otherwise_13 = form_form0_cell_integral_otherwise_11 * form_form0_cell_integral_otherwise_6 + -1.0 * form_form0_cell_integral_otherwise_2 * form_form0_cell_integral_otherwise_9;
      form_form0_cell_integral_otherwise_14 = form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_13 + form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_7 + form_form0_cell_integral_otherwise_8 * (form_form0_cell_integral_otherwise_10 + -1.0 * form_form0_cell_integral_otherwise_11 * form_form0_cell_integral_otherwise_4);
      #pragma omp simd
      for (int n_batch_simd = 0; n_batch_simd <= -1 + end + -8 * n_outer; ++n_batch_simd)
        form_form0_cell_integral_otherwise_15[n_batch_simd] = fabs(form_form0_cell_integral_otherwise_14[n_batch_simd]);
      for (int form_j = 0; form_j <= 3; ++form_j)
        form_form0_cell_integral_otherwise_22[form_j] = zero_vec_float64;
      for (int form_ip = 0; form_ip <= 3; ++form_ip)
      {
        form_form0_cell_integral_otherwise_18 = zero_vec_float64;
        for (int form_i = 0; form_i <= 3; ++form_i)
          form_form0_cell_integral_otherwise_18 = form_form0_cell_integral_otherwise_18 + form_form0_cell_integral_otherwise_17[4 * form_ip + form_i] * t0[form_i];
        form_form0_cell_integral_otherwise_19 = form_form0_cell_integral_otherwise_16[form_ip] * form_form0_cell_integral_otherwise_15;
        form_form0_cell_integral_otherwise_20 = form_form0_cell_integral_otherwise_20 + form_form0_cell_integral_otherwise_19;
        form_form0_cell_integral_otherwise_21 = form_form0_cell_integral_otherwise_19 * glob0[0] * form_form0_cell_integral_otherwise_18;
        for (int form_j_0 = 0; form_j_0 <= 3; ++form_j_0)
          form_form0_cell_integral_otherwise_22[form_j_0] = form_form0_cell_integral_otherwise_22[form_j_0] + form_form0_cell_integral_otherwise_17[4 * form_ip + form_j_0] * form_form0_cell_integral_otherwise_21;
      }
      form_form0_cell_integral_otherwise_23 = 1.0 / form_form0_cell_integral_otherwise_14;
      form_form0_cell_integral_otherwise_24 = form_form0_cell_integral_otherwise_7 * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_25 = -1.0 * t0[0];
      form_form0_cell_integral_otherwise_26 = form_form0_cell_integral_otherwise_25 + t0[1];
      form_form0_cell_integral_otherwise_27 = (form_form0_cell_integral_otherwise_10 + form_form0_cell_integral_otherwise_11 * -1.0 * form_form0_cell_integral_otherwise_4) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_28 = form_form0_cell_integral_otherwise_25 + t0[2];
      form_form0_cell_integral_otherwise_29 = form_form0_cell_integral_otherwise_13 * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_30 = form_form0_cell_integral_otherwise_25 + t0[3];
      form_form0_cell_integral_otherwise_31 = form_form0_cell_integral_otherwise_29 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_24 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_27 * form_form0_cell_integral_otherwise_28;
      form_form0_cell_integral_otherwise_32 = (form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_6 + form_form0_cell_integral_otherwise_4 * -1.0 * form_form0_cell_integral_otherwise_8) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_33 = (form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_4 + form_form0_cell_integral_otherwise_9 * -1.0 * form_form0_cell_integral_otherwise_12) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_34 = (form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_9 + -1.0 * form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_6) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_35 = form_form0_cell_integral_otherwise_34 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_32 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_33 * form_form0_cell_integral_otherwise_28;
      form_form0_cell_integral_otherwise_36 = (form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_5 + -1.0 * form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_2) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_37 = (form_form0_cell_integral_otherwise_12 * form_form0_cell_integral_otherwise_11 + -1.0 * form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_5) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_38 = (form_form0_cell_integral_otherwise_0 * form_form0_cell_integral_otherwise_2 + -1.0 * form_form0_cell_integral_otherwise_8 * form_form0_cell_integral_otherwise_11) * form_form0_cell_integral_otherwise_23;
      form_form0_cell_integral_otherwise_39 = form_form0_cell_integral_otherwise_38 * form_form0_cell_integral_otherwise_30 + form_form0_cell_integral_otherwise_36 * form_form0_cell_integral_otherwise_26 + form_form0_cell_integral_otherwise_37 * form_form0_cell_integral_otherwise_28;
      form_form0_cell_integral_otherwise_40 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_38 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_29 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_34) * form_form0_cell_integral_otherwise_20;
      form_form0_cell_integral_otherwise_42 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_37 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_27 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_33) * form_form0_cell_integral_otherwise_20;
      form_form0_cell_integral_otherwise_44 = (form_form0_cell_integral_otherwise_39 * form_form0_cell_integral_otherwise_36 + form_form0_cell_integral_otherwise_31 * form_form0_cell_integral_otherwise_24 + form_form0_cell_integral_otherwise_35 * form_form0_cell_integral_otherwise_32) * form_form0_cell_integral_otherwise_20;
      for (int form_j_1 = 0; form_j_1 <= 3; ++form_j_1)
        t2[form_j_1] = t2[form_j_1] + form_form0_cell_integral_otherwise_41[form_j_1] * form_form0_cell_integral_otherwise_40 + form_form0_cell_integral_otherwise_43[form_j_1] * form_form0_cell_integral_otherwise_42 + form_form0_cell_integral_otherwise_22[form_j_1] + form_form0_cell_integral_otherwise_45[form_j_1] * form_form0_cell_integral_otherwise_44;
      for (int n_batch = 0; n_batch <= -1 + end + -8 * n_outer; ++n_batch)
      {
        /* no-op (insn=statement4) */
        /*   */
      }
      for (int i3 = 0; i3 <= 3; ++i3)
        for (int n_batch = 0; n_batch <= -1 + end + -8 * n_outer; ++n_batch)
          dat2[map0[32 * n_outer + 4 * n_batch + i3]] = dat2[map0[32 * n_outer + 4 * n_batch + i3]] + t2[i3][n_batch];
    }
  }
}