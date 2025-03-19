/* -------------------------------------------------------------------------------- *\
|*                                                                                  *|
|*    Copyright (K) 2019-2024 RedGogh All rights reserved.                          *|
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
#include <immintrin.h>
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
          : __vec2_t(scalar, scalar)
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
          : __vec3_t(scalar, scalar, scalar)
            { /* do nothing... */ }

        explicit __vec3_t(const __vec2_t<T> &vec, T z)
          : __vec3_t(vec.x, vec.y, z)
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
          : __vec4_t(scalar, scalar, scalar, scalar)
            { /* do nothing... */ }

        explicit __vec4_t(const __vec3_t<T> &vec, T w)
          : __vec4_t(vec.x, vec.y, vec.z, w)
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

template<typename T, size_t N>
  inline static T *value_ptr(__vec2_t<T, N> &tp)
    { return &tp.data[0]; }

template<typename T, size_t N>
  inline static T *value_ptr(__vec3_t<T, N> &tp)
    { return &tp.data[0]; }

template<typename T, size_t N>
  inline static T *value_ptr(__vec4_t<T, N> &tp)
    { return &tp.data[0]; }
  
template<typename T, size_t N = 2, size_t K = 2>
struct __mat2_t {
        __vec2_t<T, N> data[K];

        IXMC_MACRO_CONSTRACTOR(__mat2_t);

        explicit __mat2_t(T s)
        {
                data[0] = __vec2_t<T>(s, 0);
                data[1] = __vec2_t<T>(0, s);
        }

        __mat2_t(
            T x0, T y0,
            T x1, T y1)
        {
                data[0] = __vec2_t<T>(x0, y0);
                data[1] = __vec2_t<T>(x1, y1);
        }

        const __vec2_t<T> &operator[](size_t i) const
          { return data[i]; }

        __vec2_t<T> &operator[](size_t i)
          { return data[i]; }
};

template<typename T, size_t N = 3, size_t K = 3>
struct __mat3_t {
        __mat3_t<T, N> data[K];

        IXMC_MACRO_CONSTRACTOR(__mat3_t);

        explicit __mat3_t(T s)
        {
                data[0] = __vec3_t<T>(s, 0, 0);
                data[1] = __vec3_t<T>(0, s, 0);
                data[2] = __vec3_t<T>(0, 0, s);
        }

        __mat3_t(
            T x0, T y0, T z0,
            T x1, T y1, T z1,
            T x2, T y2, T z2)
        {
                data[0] = __vec3_t<T>(x0, y0, z0);
                data[1] = __vec3_t<T>(x1, y1, z1);
                data[2] = __vec3_t<T>(x2, y2, z2);
        }

        const __vec3_t<T> &operator[](size_t i) const
          { return data[i]; }

        __vec3_t<T> &operator[](size_t i)
          { return data[i]; }
};

template<typename T, size_t N = 4, size_t K = 4>
struct __mat4_t {
        __vec4_t<T, N> data[K];
        
        IXMC_MACRO_CONSTRACTOR(__mat4_t);
        
        explicit __mat4_t(T s)
          {
                data[0] = __vec4_t<T>(s, 0, 0, 0);
                data[1] = __vec4_t<T>(0, s, 0, 0);
                data[2] = __vec4_t<T>(0, 0, s, 0);
                data[3] = __vec4_t<T>(0, 0, 0, s);
          }
        
        __mat4_t(
            T x0, T y0, T z0, T w0,    
            T x1, T y1, T z1, T w1,    
            T x2, T y2, T z2, T w2,    
            T x3, T y3, T z3, T w3) 
          {
                data[0] = __vec4_t<T>(x0, y0, z0, w0);
                data[1] = __vec4_t<T>(x1, y1, z1, w1);
                data[2] = __vec4_t<T>(x2, y2, z2, w2);
                data[3] = __vec4_t<T>(x3, y3, z3, w3);
          }
          
        const __vec4_t<T> &operator[](size_t i) const
          { return data[i]; }

        __vec4_t<T> &operator[](size_t i)
          { return data[i]; }
};

typedef __mat2_t<float, 2, 2> mat2;
typedef __mat3_t<float, 3, 3> mat3;
typedef __mat4_t<float, 4, 4> mat4;

template<typename T, size_t N, size_t K>
  inline static T *value_ptr(__mat2_t<T, N, K> &tp)
    { return value_ptr(tp.data[0]); }

template<typename T, size_t N, size_t K>
  inline static T *value_ptr(__mat3_t<T, N, K> &tp)
    { return value_ptr(tp.data[0]); }

template<typename T, size_t N, size_t K>
  inline static T *value_ptr(__mat4_t<T, N, K> &tp)
    { return value_ptr(tp.data[0]); }

template<typename T, size_t N, size_t K>
__mat2_t<T, N, K> operator*(const __mat2_t<T, N, K> &m1, const __mat2_t<T, N, K> &m2)
{
        __mat2_t<T, N, K> result;

        for (int i = 0; i < N; i++) {
                __m128 row = _mm_set_ps(0, 0, m1[1][i], m1[0][i]);
                for (int k = 0; k < K; k++) {
                        __m128 col = _mm_set_ps(0, 0, m2[k][1], m2[k][0]);

                        __m128 mul;

                        mul = _mm_mul_ps(row, col);
                        mul = _mm_hadd_ps(mul, mul);
                        mul = _mm_hadd_ps(mul, mul);

                        _mm_store_ss(&result.data[k][i], mul);
                }
        }

        return result;
}

template<typename T, size_t N, size_t K>
__vec2_t<T, N> operator         *(const __mat2_t<T, N, K> &m, const __vec2_t<T, N> &v)
{
        __vec2_t<T, N> result;

       for (int i = 0; i < N; i++) {
               __m128 row = _mm_set_ps(0, 0, m[i + 1][0], m[i + 0][0]);
               __m128 vec = _mm_set_ps(0, 0, v[1], v[0]);
               __m128 mul = _mm_mul_ps(row, vec);

               mul = _mm_hadd_ps(mul, mul);
               mul = _mm_hadd_ps(mul, mul);

               _mm_store_ss(&result[i], mul);
       }

        return result;
}

template<typename T, size_t N, size_t K>
__mat3_t<T, N, K> operator*(const __mat3_t<T, N, K> &m1, const __mat3_t<T, N, K> &m2)
{
        __mat3_t<T, N, K> result;

        for (int i = 0; i < N; i++) {
                __m128 row = _mm_set_ps(0, m1[2][i], m1[1][i], m1[0][i]);
                for (int k = 0; k < K; k++) {
                        __m128 col = _mm_set_ps(0, m2[k][2], m2[k][1], m2[k][0]);

                        __m128 mul;

                        mul = _mm_mul_ps(row, col);
                        mul = _mm_hadd_ps(mul, mul);
                        mul = _mm_hadd_ps(mul, mul);

                        _mm_store_ss(&result.data[k][i], mul);
                }
        }

        return result;
}

template<typename T, size_t N, size_t K>
__mat4_t<T, N, K> operator*(const __mat4_t<T, N, K> &m1, const __mat4_t<T, N, K> &m2)
{
        __mat4_t<T, N, K> result;

        for (int i = 0; i < N; i++) {
                __m128 row = _mm_set_ps(m1[3][i], m1[2][i], m1[1][i], m1[0][i]);
                for (int k = 0; k < K; k++) {
                        __m128 col = _mm_set_ps(m2[k][3], m2[k][2], m2[k][1], m2[k][0]);

                        __m128 mul;

                        mul = _mm_mul_ps(row, col);
                        mul = _mm_hadd_ps(mul, mul);
                        mul = _mm_hadd_ps(mul, mul);

                        _mm_store_ss(&result.data[k][i], mul);
                }
        }

        return result;
}
  
} /* namespace ixmc */

#endif /* IXMC_VEC_H_ */

#pragma clang diagnostic pop