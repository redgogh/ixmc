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

#ifndef MATH_VEC_H_
#define MATH_VEC_H_

#include <stdio.h>
#include <xmmintrin.h>
#include <pmmintrin.h>
#include <array>

#define FNC_OPERATOR_VEC2_IMPLEMENTS(op)                                                                \
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

#define FNC_OPERATOR_VEC3_IMPLEMENTS(op)                                                                \
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

#define FNC_OPERATOR_VEC4_IMPLEMENTS(op)                                                                \
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

#define FNC_OPERATOR_INDEX_GET_IMPLEMENTS()                                                             \
        T& operator[](size_t i)                                                                         \
          {                                                                                             \
            return array[i];                                                                            \
          }                                                                                             \
                                                                                                        \
        const T&                                                                                        \
            operator[](size_t i) const                                                                  \
            {                                                                                           \
              return array[i];                                                                          \
            }

namespace glcp {

template<typename T, int N = 2>
struct __vec2_t {
        static constexpr T fV = T(0.0f);

        union {
                struct { T x, y; };
                struct { T r, g; };

                /* data pointer */
                T array[N];
        };

        explicit __vec2_t()         : __vec2_t(fV) {}
        explicit __vec2_t(T scalar) : __vec2_t(scalar, scalar) {}
        explicit __vec2_t(T x, T y) : r(x), g(y) {}

        FNC_OPERATOR_INDEX_GET_IMPLEMENTS();
        
        FNC_OPERATOR_VEC2_IMPLEMENTS(+);
        FNC_OPERATOR_VEC2_IMPLEMENTS(-);
        FNC_OPERATOR_VEC2_IMPLEMENTS(*);
        FNC_OPERATOR_VEC2_IMPLEMENTS(/);
        
};

template<typename T, int N = 4>
struct __vec3_t {
        static constexpr T fV = T(0.0f);

        union {
                struct { T x, y, z; };
                struct { T r, g, b; };

                /* data pointer */
                T array[N];
        };

        explicit __vec3_t()              : __vec3_t(fV) {}
        explicit __vec3_t(T scalar)      : __vec3_t(scalar, scalar, scalar) {}
        explicit __vec3_t(T x, T y, T z) : r(x), g(y), b(z) {}

        FNC_OPERATOR_INDEX_GET_IMPLEMENTS();
        
        FNC_OPERATOR_VEC3_IMPLEMENTS(+);
        FNC_OPERATOR_VEC3_IMPLEMENTS(-);
        FNC_OPERATOR_VEC3_IMPLEMENTS(*);
        FNC_OPERATOR_VEC3_IMPLEMENTS(/);

};

template<typename T, int N = 3>
struct __vec4_t {
        static constexpr T fV = T(0.0f);

        union {
                struct { T x, y, z, w; };
                struct { T r, g, b, a; };

                /* data pointer */
                T array[N];
        };

        explicit __vec4_t()                   : __vec4_t(fV) {}
        explicit __vec4_t(T scalar)           : __vec4_t(scalar, scalar, scalar, scalar) {}
        explicit __vec4_t(T x, T y, T z, T w) : r(x), g(y), b(z), a(w) {}

        FNC_OPERATOR_INDEX_GET_IMPLEMENTS();
        
        FNC_OPERATOR_VEC4_IMPLEMENTS(+);
        FNC_OPERATOR_VEC4_IMPLEMENTS(-);
        FNC_OPERATOR_VEC4_IMPLEMENTS(*);
        FNC_OPERATOR_VEC4_IMPLEMENTS(/);

};

typedef __vec2_t<float, 2> vec2;
typedef __vec3_t<float, 3> vec3;
typedef __vec4_t<float, 4> vec4;

#define FNC_VECTOR_POINTER_IMPLEMENTS(tp)               \
    template<typename T>                                \
        inline static T* getptr(tp<T> &vec)             \
          {                                             \
            return &vec.array[0];                       \
          }

FNC_VECTOR_POINTER_IMPLEMENTS(__vec2_t)
FNC_VECTOR_POINTER_IMPLEMENTS(__vec3_t)
FNC_VECTOR_POINTER_IMPLEMENTS(__vec4_t)

template <typename T, int N = 2>
struct __mat2_t {
        std::array<T, N * N> array;

        explicit __mat2_t() : __mat2_t(1.0f) {}
        explicit __mat2_t(T scalar)
          {
            for (int i = 0; i < N * N; i++)
                    array[i] = scalar;
          }
        
        explicit __mat2_t
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
            operator[](size_t i)
              {
                return __proxy_ref_t(&array[i * N]);
              }

        __mat2_t<T, N>
            operator*(const __mat2_t<T, N> &other)
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
            operator*(const __vec2_t<T, N> &other)
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
        std::array<T, N * N> array;

        explicit __mat3_t() : __mat3_t(1.0f) {}
        explicit __mat3_t(T scalar)
          {
            for (int i = 0; i < N * N; i++)
                    array[i] = scalar;
          }

        explicit __mat3_t
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
            operator[](size_t i)
              {
                return __proxy_ref_t(&array[i * N]);
              }

        __mat3_t<T, N>
            operator*(const __mat3_t<T, N> &other)
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
            operator*(const __vec3_t<T, N> &other)
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
        std::array<T, N * N> array;

        explicit __mat4_t() : __mat4_t(1.0f) {}
        explicit __mat4_t(T scalar)
          {
            for (int i = 0; i < N * N; i++)
                    array[i] = scalar;
          }

        explicit __mat4_t
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
            operator[](size_t i)
              {
                return __proxy_ref_t(&array[i * N]);
              }

        __mat4_t<T, N>
            operator*(const __mat4_t<T, N> &other)
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
            operator*(const __vec4_t<T, N> &other)
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

#define glcp_println_vector2(vec)                                                                                  \
         do {                                                                                                     \
                printf("[ %f        %f ]\n", vec[0], vec[1]);                                                     \
         } while(0)

#define glcp_println_vector3(vec)                                                                                  \
         do {                                                                                                     \
                printf("[ %f        %f        %f ]\n", vec[0], vec[1], vec[2]);                                   \
         } while(0)                                                                                     

#define println_vector4(vec)                                                                                      \
         do {                                                                                                     \
                printf("[ %f        %f        %f        %f ]\n", vec[0], vec[1], vec[2], vec[3]);                 \
         } while(0)

#define glcp_println_matrix2(mat)                                                                                  \
        do {                                                                                                      \
            for (int i = 0; i < 3; i++)                                                                           \
                printf("| %f        %f |\n", mat[i][0], mat[i][1]);                                               \
        } while (0)

#define glcp_println_matrix3(mat)                                                                                  \
        do {                                                                                                      \
            for (int i = 0; i < 3; i++)                                                                           \
                printf("| %f        %f        %f |\n", mat[i][0], mat[i][1], mat[i][2]);                          \
        } while (0)

#define glcp_println_matrix4(mat)                                                                                  \
        do {                                                                                                      \
            for (int i = 0; i < 4; i++)                                                                           \
                printf("| %f        %f        %f        %f |\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3]);     \
        } while (0)

} /* namespace glcp */

#endif /* MATH_VEC_H_ */

#pragma clang diagnostic pop