/* -------------------------------------------------------------------------------- *\
|*                                                                                  *|
|*    Copyright (C) 2019-2024 RedGogh All rights reserved.                          *|
|*                                                                                  *|
|*    Licensed under the Apache License, Version 2.0 (the "License");               *|
|*    you may not use this file except in compliance with the License.              *|
|*    You may obtain a copy of the License at                                       *|
|*                                                                                  *|
|*        http://www.apache.org/licenses/LICENSE-2.0                                *|
|*                                                                                  *|
|*    Unless required by applicable law or agreed to in writing, software           *|
|*    distributed under the License is distributed on an "AS IS" BASIS,             *|
|*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.      *|
|*    See the License for the specific language governing permissions and           *|
|*    limitations under the License.                                                *|
|*                                                                                  *|
\* -------------------------------------------------------------------------------- */
#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-reserved-identifier"
#pragma ide diagnostic ignored "modernize-deprecated-headers"
#pragma ide diagnostic ignored "portability-simd-intrinsics"

#ifndef IXMC_VEC_H_
#define IXMC_VEC_H_

#include <stdio.h>
#include <xmmintrin.h>
#include <pmmintrin.h>
#include <array>
#include <initializer_list>

// Default constructor for vec type.
#define IXMC_MACRO_CONSTRACTOR(vec)                                                                     \
        vec()                         = default;                                                        \
        vec(const vec&)               = default;                                                        \
        vec& operator=(const vec&)    = default;

#define IXMC_OPERATION_VEC2_IMPLEMENTS(op)                                                              \
        __vec2_t<T, N>                                                                                  \
            operator op (T scalar)                                                                      \
                {                                                                                       \
                   return __vec2_t<T, N>(x op scalar, y op scalar);                                     \
                };                                                                                      \
                                                                                                        \
        __vec2_t<T, N>                                                                                  \
            operator op (const __vec2_t<T, N> &vec)                                                     \
                {                                                                                       \
                   return __vec2_t<T, N>(x op vec.x, y op vec.y);                                       \
                }

#define IXMC_OPERATION_VEC3_IMPLEMENTS(op)                                                              \
        __vec3_t<T, N>                                                                                  \
            operator op (T scalar)                                                                      \
                {                                                                                       \
                   return __vec3_t<T, N>(x op scalar, y op scalar, z op scalar);                        \
                };                                                                                      \
                                                                                                        \
        __vec3_t<T, N>                                                                                  \
            operator op (const __vec3_t<T, N> &vec)                                                     \
                {                                                                                       \
                   return __vec3_t<T, N>(x op vec.x, y op vec.y, z op vec.z);                           \
                }

#define IXMC_OPERATION_VEC4_IMPLEMENTS(op)                                                              \
        __vec4_t<T, N>                                                                                  \
            operator op (T scalar)                                                                      \
                {                                                                                       \
                   return __vec4_t<T, N>(x op scalar, y op scalar, z op scalar, w op scalar);           \
                };                                                                                      \
                                                                                                        \
        __vec4_t<T, N>                                                                                  \
            operator op (const __vec4_t<T, N> &vec)                                                     \
                {                                                                                       \
                   return __vec4_t<T, N>(x op vec.x, y op vec.y, z op vec.z, w op vec.w);               \
                }

#define IXMC_VALUE_PTR_IMPLEMENTS(type)                                                                 \
    template<typename T>                                                                                \
        inline static T* value_ptr(type<T> &tp)                                                         \
          {                                                                                             \
            return &tp.data[0];                                                                         \
          }

/* namespace ixmc */
namespace ixmc {

template<typename T, size_t N>
struct __vec_t {
        union {
                std::array<T, N> data;
                struct { T x, y, z, w; };
                struct { T r, g, b, a; };
        };

        T& operator[](size_t index)
          {
            return this->data[index];
          }

        const T& operator[](size_t index) const
          {
            return this->data[index];
          }

};

template<typename T, size_t N = 2>
struct __vec2_t : private __vec_t<T, N> {
        // using x, y members
        using __vec_t<T, N>::x;
        using __vec_t<T, N>::y;

        // using r, g members
        using __vec_t<T, N>::r;
        using __vec_t<T, N>::g;

        // using data
        using __vec_t<T, N>::data;

        // using operator
        using __vec_t<T, N>::operator[];

        IXMC_MACRO_CONSTRACTOR(__vec2_t);

        explicit __vec2_t(const T& scalar)
          : __vec2_t(static_cast<T>(scalar), static_cast<T>(scalar))
            { /* do nothing... */ }

        __vec2_t(T x, T y)
          {
            this->data[0] = static_cast<T>(x);
            this->data[1] = static_cast<T>(y);
          }

        // operation for __vec2_t<T, N>
        IXMC_OPERATION_VEC2_IMPLEMENTS(+);
        IXMC_OPERATION_VEC2_IMPLEMENTS(-);
        IXMC_OPERATION_VEC2_IMPLEMENTS(*);
        IXMC_OPERATION_VEC2_IMPLEMENTS(/);

};

template<typename T, size_t N = 3>
struct __vec3_t : private __vec_t<T, N> {
        // using x, y, z members
        using __vec_t<T, N>::x;
        using __vec_t<T, N>::y;
        using __vec_t<T, N>::z;

        // using r, g, b members
        using __vec_t<T, N>::r;
        using __vec_t<T, N>::g;
        using __vec_t<T, N>::b;

        // using data
        using __vec_t<T, N>::data;

        // using operator
        using __vec_t<T, N>::operator[];

        IXMC_MACRO_CONSTRACTOR(__vec3_t);

        explicit __vec3_t(const T& scalar)
          : __vec3_t(static_cast<T>(scalar), static_cast<T>(scalar), static_cast<T>(scalar))
            { /* do nothing... */ }

        explicit __vec3_t(const __vec2_t<T> &vec, T z)
          : __vec3_t(vec.x, vec.y, static_cast<T>(z))
            { /* do nothing... */ }

        __vec3_t(T x, T y, T z)
          {
            this->data[0] = static_cast<T>(x);
            this->data[1] = static_cast<T>(y);
            this->data[2] = static_cast<T>(z);
          }

        __vec2_t<T> xy()
          { return __vec2_t<T>(x, y); }

        // operation for __vec3_t<T, N>
        IXMC_OPERATION_VEC3_IMPLEMENTS(+);
        IXMC_OPERATION_VEC3_IMPLEMENTS(-);
        IXMC_OPERATION_VEC3_IMPLEMENTS(*);
        IXMC_OPERATION_VEC3_IMPLEMENTS(/);

};

template<typename T, size_t N = 4>
struct __vec4_t : private __vec_t<T, N> {
        // using x, y, z members
        using __vec_t<T, N>::x;
        using __vec_t<T, N>::y;
        using __vec_t<T, N>::z;
        using __vec_t<T, N>::w;

        // using r, g, b members
        using __vec_t<T, N>::r;
        using __vec_t<T, N>::g;
        using __vec_t<T, N>::b;
        using __vec_t<T, N>::a;

        // using data
        using __vec_t<T, N>::data;

        // using operator
        using __vec_t<T, N>::operator[];

        IXMC_MACRO_CONSTRACTOR(__vec4_t);

        explicit __vec4_t(const T& scalar)
          : __vec4_t(static_cast<T>(scalar), static_cast<T>(scalar), static_cast<T>(scalar),
                     static_cast<T>(scalar))
            { /* do nothing... */ }

        explicit __vec4_t(const __vec3_t<T> &vec, T w)
          : __vec4_t(vec.x, vec.y, vec.z, static_cast<T>(w))
            { /* do nothing... */ }

        __vec4_t(T x, T y, T z, T w)
          {
            this->data[0] = static_cast<T>(x);
            this->data[1] = static_cast<T>(y);
            this->data[2] = static_cast<T>(z);
            this->data[3] = static_cast<T>(w);
          }

        __vec2_t<T> xy()
          { return __vec2_t<T>(x, y); }

        __vec3_t<T> xyz()
          { return __vec3_t<T>(x, y, z); }

        // operation for __vec4_t<T, N>
        IXMC_OPERATION_VEC4_IMPLEMENTS(+);
        IXMC_OPERATION_VEC4_IMPLEMENTS(-);
        IXMC_OPERATION_VEC4_IMPLEMENTS(*);
        IXMC_OPERATION_VEC4_IMPLEMENTS(/);

};

typedef __vec2_t<float, 2> vec2;
typedef __vec3_t<float, 3> vec3;
typedef __vec4_t<float, 4> vec4;

IXMC_VALUE_PTR_IMPLEMENTS(__vec2_t)
IXMC_VALUE_PTR_IMPLEMENTS(__vec3_t)
IXMC_VALUE_PTR_IMPLEMENTS(__vec4_t)

template <typename T, int N = 2>
struct __mat2_t {
        std::array<T, N * N> array = {};

        explicit __mat2_t() : __mat2_t(1.0f) {}
        explicit __mat2_t(T scalar)
          {
            for (int i = 0; i < N; i++)
                    array[i * N + i] = scalar;
          }

        explicit __mat2_t(T x, T y) : __mat2_t(
           x, 0,
           0, y
        ) {}
        
        __mat2_t
          (
            T a1, T b1,
            T a2, T b2
          ) : array {
            a1, b1,
            a2, b2
          } {}

        /*
         * __proxy_ref_t struct for overriding the second [] operator.
         */
        struct __proxy_ref_t {
                T *ref;
                explicit __proxy_ref_t(T *p_ref) : ref(p_ref) {}
                T& operator[](size_t i) { return ref[i]; }
        };

        __proxy_ref_t
            operator[](size_t i) const
              {
                return __proxy_ref_t(&array[i * N]);
              }

        __mat2_t<T, N>
            operator*(const __mat2_t<T, N> &other) const
              {
                __mat2_t<T, N> q;
                for (int i = 0; i < N; i++) {
                        __m128 row = _mm_loadu_ps(&array[i * N]);
                        for (int j = 0; j < N; j++) {
                                __m128 col = _mm_set_ps(0.0f, 0.0f, other.array[1 * N + j], other.array[0 * N + j]);
                                __m128 mul = _mm_mul_ps(row, col); // NOLINT(*-simd-intrinsics)
                                mul = _mm_hadd_ps(mul, mul);
                                mul = _mm_hadd_ps(mul, mul);
                                _mm_store_ss(&q.array[i * N + j], mul);
                        }
                }
                return q;
              }

        __vec2_t<T, N>
            operator*(const __vec2_t<T, N> &other) const
              {
                __vec2_t<T, N> vec;
                for (int i = 0; i < N; i++) {
                        __m128 vec128 = _mm_set_ps(other[1], other[0], 0.0f, 0.0f);
                        __m128 row128 = _mm_set_ps(array[i * N + 1], array[i * N + 0], 0.0f, 0.0f);
                        __m128 mul128 = _mm_mul_ps(vec128, row128);

                        mul128 = _mm_hadd_ps(mul128, mul128);
                        mul128 = _mm_hadd_ps(mul128, mul128);

                        vec[i] = mul128[0];
                }
                return vec;
              }
              
};

template <typename T, int N = 3>
struct __mat3_t {
        std::array<T, N * N> array = {};

        explicit __mat3_t() : __mat3_t(1.0f) {}
        explicit __mat3_t(T scalar)
          {
            for (int i = 0; i < N; i++)
                    array[i * N + i] = scalar;
          }
          
        explicit __mat3_t(T x, T y, T z) : __mat3_t(
            x, 0, 0,
            0, y, 0,
            0, 0, z
        ) {}
          
        __mat3_t
          (
            T a1, T b1, T c1,
            T a2, T b2, T c2,
            T a3, T b3, T c3
          ) : array {
            a1, b1, c1,
            a2, b2, c2,
            a3, b3, c3
          } {}
          
        /*
         * __proxy_ref_t struct for overriding the second [] operator.
         */
        struct __proxy_ref_t {
                T *ref;
                explicit __proxy_ref_t(T *p_ref) : ref(p_ref) {}
                T& operator[](size_t i) { return ref[i]; }
                
        };

        __proxy_ref_t
            operator[](size_t i) const
              {
                return __proxy_ref_t(&array[i * N]);
              }

        __mat3_t<T, N>
            operator*(const __mat3_t<T, N> &other) const
              {
                __mat3_t<T, N> mat;
                for (int i = 0; i < N; i++) {
                        __m128 row = _mm_loadu_ps(&array[i * N]);
                        for (int j = 0; j < N; j++) {
                                __m128 col = _mm_set_ps(0.0f, other.array[2 * N + j],
                                                        other.array[1 * N + j], other.array[0 * N + j]);
                                __m128 mul = _mm_mul_ps(row, col); // NOLINT(*-simd-intrinsics)
                                mul = _mm_hadd_ps(mul, mul);
                                mul = _mm_hadd_ps(mul, mul);
                                _mm_store_ss(&mat.array[i * N + j], mul);
                        }
                }
                return mat;
              }

        __vec3_t<T, N>
            operator*(const __vec3_t<T, N> &other) const
              {
                __vec3_t<T, N> vec;
                for (int i = 0; i < N; i++) {
                        __m128 vec128 = _mm_set_ps(other[2], other[1], other[0], 0.0f);
                        __m128 row128 = _mm_set_ps(array[i * N + 2], array[i * N + 1], array[i * N + 0], 0.0f);
                        __m128 mul128 = _mm_mul_ps(vec128, row128);

                        mul128 = _mm_hadd_ps(mul128, mul128);
                        mul128 = _mm_hadd_ps(mul128, mul128);
                        
                        vec[i] = mul128[0];
                }
                return vec;
              }
              
};

template <typename T, int N = 4>
struct __mat4_t {
        std::array<T, N * N> array = {};

        explicit __mat4_t() : __mat4_t(1.0f) {}
        explicit __mat4_t(T scalar)
          {
            for (int i = 0; i < N; i++)
                    array[i * N + i] = scalar;
          }

        explicit __mat4_t(T x, T y, T z, T w) : __mat4_t(
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, w
        ) {}
          
        __mat4_t
          (
            T a1, T b1, T c1, T d1,
            T a2, T b2, T c2, T d2,
            T a3, T b3, T c3, T d3,
            T a4, T b4, T c4, T d4
          ) : array {
            a1, b1, c1, d1,
            a2, b2, c2, d2,
            a3, b3, c3, d3,
            a4, b4, c4, d4,
          } {}

        /*
         * __proxy_ref_t struct for overriding the second [] operator.
         */
        struct __proxy_ref_t {
                T *ref;
                explicit __proxy_ref_t(T *p_ref) : ref(p_ref) {}
                T& operator[](size_t i) { return ref[i]; }
        };

        __proxy_ref_t
            operator[](size_t i) const
              {
                return __proxy_ref_t(&array[i * N]);
              }

        __mat4_t<T, N>
            operator*(const __mat4_t<T, N> &other) const
              {
                __mat4_t<T, N> q;
                for (int i = 0; i < N; i++) {
                        __m128 row = _mm_loadu_ps(&array[i * N]);
                        for (int j = 0; j < N; j++) {
                                __m128 col = _mm_set_ps(other.array[3 * N + j], other.array[2 * N + j],
                                                        other.array[1 * N + j], other.array[0 * N + j]);
                                __m128 mul = _mm_mul_ps(row, col); // NOLINT(*-simd-intrinsics)
                                mul = _mm_hadd_ps(mul, mul);
                                mul = _mm_hadd_ps(mul, mul);
                                _mm_store_ss(&q.array[i * N + j], mul);
                        }
                }
                return q;
              }

        __vec4_t<T, N>
            operator*(const __vec4_t<T, N> &other) const
              {
                __vec4_t<T, N> vec;
                for (int i = 0; i < N; i++) {
                        __m128 vec128 = _mm_set_ps(other[3], other[2], other[1], other[0]);
                        __m128 row128 = _mm_set_ps(array[i * N + 3], array[i * N + 2], array[i * N + 1], array[i * N + 0]);
                        __m128 mul128 = _mm_mul_ps(vec128, row128);

                        mul128 = _mm_hadd_ps(mul128, mul128);
                        mul128 = _mm_hadd_ps(mul128, mul128);

                        vec[i] = mul128[0];
                }
                return vec;
              }

};

typedef __mat2_t<float, 2> mat2;
typedef __mat3_t<float, 3> mat3;
typedef __mat4_t<float, 4> mat4;

IXMC_VALUE_PTR_IMPLEMENTS(__mat2_t);
IXMC_VALUE_PTR_IMPLEMENTS(__mat3_t);
IXMC_VALUE_PTR_IMPLEMENTS(__mat4_t);

#define IXMC_WRITE_VECTOR2(vec)                                                                                   \
         do {                                                                                                     \
                printf("[ %f        %f ]\n", vec[0], vec[1]);                                                     \
         } while(0)

#define IXMC_WRITE_VECTOR3(vec)                                                                                   \
         do {                                                                                                     \
                printf("[ %f        %f        %f ]\n", vec[0], vec[1], vec[2]);                                   \
         } while(0)                                                                                     

#define IXMC_WRITE_VECTOR4(vec)                                                                                   \
         do {                                                                                                     \
                printf("[ %f        %f        %f        %f ]\n", vec[0], vec[1], vec[2], vec[3]);                 \
         } while(0)

#define IXMC_WRITE_MATRIX2(mat)                                                                                   \
        do {                                                                                                      \
            for (int i = 0; i < 2; i++)                                                                           \
                printf("| %f        %f |\n", mat[i][0], mat[i][1]);                                               \
        } while (0)

#define IXMC_WRITE_MATRIX3(mat)                                                                                   \
        do {                                                                                                      \
            for (int i = 0; i < 3; i++)                                                                           \
                printf("| %f        %f        %f |\n", mat[i][0], mat[i][1], mat[i][2]);                          \
        } while (0)

#define IXMC_WRITE_MATRIX4(mat)                                                                                   \
        do {                                                                                                      \
            for (int i = 0; i < 4; i++)                                                                           \
                printf("| %f        %f        %f        %f |\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3]);     \
        } while (0)

} /* namespace ixmc */

#endif /* IXMC_VEC_H_ */

#pragma clang diagnostic pop