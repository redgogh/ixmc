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
#ifndef MATH_VEC_H_
#define MATH_VEC_H_

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

namespace umc {

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

        FNC_OPERATOR_VEC4_IMPLEMENTS(+);
        FNC_OPERATOR_VEC4_IMPLEMENTS(-);
        FNC_OPERATOR_VEC4_IMPLEMENTS(*);
        FNC_OPERATOR_VEC4_IMPLEMENTS(/);

};

typedef __vec2_t<float> vec2;
typedef __vec3_t<float> vec3;
typedef __vec4_t<float> vec4;

#define FNC_VECTOR_POINTER_IMPLEMENTS(tp)               \
    template<typename T>                                \
        inline static T* getptr(tp<T> &vec)             \
          {                                             \
            return &vec.array[0];                       \
          }

FNC_VECTOR_POINTER_IMPLEMENTS(__vec2_t)
FNC_VECTOR_POINTER_IMPLEMENTS(__vec3_t)
FNC_VECTOR_POINTER_IMPLEMENTS(__vec4_t)

} /* namespace umc */

#endif /* MATH_VEC_H_ */
