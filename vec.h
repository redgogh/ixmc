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
#ifndef ALG_VEC_H_
#define ALG_VEC_H_

#include <cstdio>
#include <cmath>
#include <stdexcept>
#include <experimental/simd>

#define ALG_FUNC_DECL          /* UNDEF */
#define ALG_INLINE             inline
#define ALG_CONSTEXPR          constexpr

namespace alg {
        // -- Constant Variables --
        
        static constexpr unsigned int ZERO_VALUE = 0U;
        
        static constexpr unsigned int ONE_VALUE = 1U;
        
        // -- Vector & Matrix --
        
        template<size_t N, typename T> struct vec;
        template<size_t N, typename T> struct mat;

        template<typename T> struct vec<2, T>;
        template<typename T> struct vec<3, T>;
        template<typename T> struct vec<4, T>;

        template<typename T> struct mat<2, T>;
        template<typename T> struct mat<3, T>;
        template<typename T> struct mat<4, T>;

        // -- typedef --

        typedef struct vec<2, int> vec2i32;
        typedef struct vec<3, int> vec3i32;
        typedef struct vec<4, int> vec4i32;

        typedef struct vec<2, long> vec2i64;
        typedef struct vec<3, long> vec3i64;
        typedef struct vec<4, long> vec4i64;

        typedef struct vec<2, float> vec2f32;
        typedef struct vec<3, float> vec3f32;
        typedef struct vec<4, float> vec4f32;

        typedef struct vec<2, double> vec2f64;
        typedef struct vec<3, double> vec3f64;
        typedef struct vec<4, double> vec4f64;

        typedef struct vec<2, float> vec2;
        typedef struct vec<3, float> vec3;
        typedef struct vec<4, float> vec4;

        typedef struct mat<2, int> mat2i32;
        typedef struct mat<3, int> mat3i32;
        typedef struct mat<4, int> mat4i32;

        typedef struct mat<2, long> mat2i64;
        typedef struct mat<3, long> mat3i64;
        typedef struct mat<4, long> mat4i64;

        typedef struct mat<2, float> mat2f32;
        typedef struct mat<3, float> mat3f32;
        typedef struct mat<4, float> mat4f32;

        typedef struct mat<2, double> mat2f64;
        typedef struct mat<3, double> mat3f64;
        typedef struct mat<4, double> mat4f64;

        typedef struct mat<2, float> mat2;
        typedef struct mat<3, float> mat3;
        typedef struct mat<4, float> mat4;

        // -- struct vec<2, T> --

        template<typename T>
        struct vec<2, T> {
                // -- Store data define --

                const T ZERO_VALUE = static_cast<T>(1);

                union {
                        struct { T x, y; };
                        struct { T r, g; };
                };

                // -- Constructor for vec2 --

                ALG_FUNC_DECL vec();
                ALG_FUNC_DECL explicit vec(T scalar);
                ALG_FUNC_DECL ALG_INLINE ALG_CONSTEXPR vec(T x, T y);

                // -- Operator override --

                ALG_FUNC_DECL ALG_CONSTEXPR T& operator[](size_t n);
                ALG_FUNC_DECL ALG_CONSTEXPR T const& operator[](size_t n) const;

                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T> operator+(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T> operator-(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T> operator*(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T> operator/(T const &scalar);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T> operator+(vec<2, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T> operator-(vec<2, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T> operator*(vec<2, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T> operator/(vec<2, T> const &v);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T>& operator+=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T>& operator-=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T>& operator*=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T>& operator/=(T const &scalar);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T>& operator+=(vec<2, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T>& operator-=(vec<2, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T>& operator*=(vec<2, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<2, T>& operator/=(vec<2, T> const &v);

        };

        // -- struct vec<3, T> --

        template<typename T>
        struct vec<3, T> {
                // -- Store data define --

                const T ZERO_VALUE = static_cast<T>(1);

                union {
                        struct { T x, y, z; };
                        struct { T r, g, b; };
                };

                // -- Constructor for vec3 --

                ALG_FUNC_DECL vec();
                ALG_FUNC_DECL explicit vec(T scalar);
                ALG_FUNC_DECL explicit vec(vec<2, T> const& v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec(vec<2, T> const& v, T z);
                ALG_FUNC_DECL ALG_CONSTEXPR vec(T x, T y, T z);

                // -- Operator override --

                ALG_FUNC_DECL ALG_CONSTEXPR T& operator[](size_t n);
                ALG_FUNC_DECL ALG_CONSTEXPR T const& operator[](size_t n) const;

                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T> operator+(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T> operator-(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T> operator*(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T> operator/(T const &scalar);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T> operator+(vec<3, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T> operator-(vec<3, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T> operator*(vec<3, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T> operator/(vec<3, T> const &v);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T>& operator+=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T>& operator-=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T>& operator*=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T>& operator/=(T const &scalar);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T>& operator+=(vec<3, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T>& operator-=(vec<3, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T>& operator*=(vec<3, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<3, T>& operator/=(vec<3, T> const &v);

                ALG_FUNC_DECL vec<2, T> xy();
                
        };

        // -- struct vec<4, T> --

        template<typename T>
        struct vec<4, T> {
                // -- Store data define --ZERO_VALUE

                union {
                        struct { T x, y, z, w; };
                        struct { T r, g, b, a; };
                };

                // -- Constructor for vec4 --

                ALG_FUNC_DECL vec();
                ALG_FUNC_DECL explicit vec(T scalar);
                ALG_FUNC_DECL explicit vec(vec<2, T> const& v);
                ALG_FUNC_DECL explicit vec(vec<3, T> const& v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec(vec<2, T> const& v, T z, T w);
                ALG_FUNC_DECL ALG_CONSTEXPR vec(vec<3, T> const& v, T w);
                ALG_FUNC_DECL ALG_INLINE ALG_CONSTEXPR vec(T x, T y, T z, T w);

                // -- Operator override --

                ALG_FUNC_DECL ALG_CONSTEXPR T& operator[](size_t n);
                ALG_FUNC_DECL ALG_CONSTEXPR T const& operator[](size_t n) const;
                
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator+(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator-(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator*(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator/(T const &scalar);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator+(vec<4, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator-(vec<4, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator*(vec<4, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator/(vec<4, T> const &v);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator+=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator-=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator*=(T const &scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator/=(T const &scalar);

                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator+=(vec<4, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator-=(vec<4, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator*=(vec<4, T> const &v);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator/=(vec<4, T> const &v);

                ALG_FUNC_DECL ALG_INLINE vec<2, T> xy();
                ALG_FUNC_DECL ALG_INLINE vec<3, T> xyz();
                
        };
        
        // -- struct mat<4, T> --
        
        template<typename T>
        struct mat<4, T> {
                // -- Data --
                
                vec<4, T> data[4];
                
                // -- Constructor --
                
                ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T>();
                ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T>(T const& scalar);
                ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T>(
                        T const& x1, T y1, T const& z1, T const& w1,
                        T const& x2, T y2, T const& z2, T const& w2,
                        T const& x3, T y3, T const& z3, T const& w3,
                        T const& x4, T y4, T const& z4, T const& w4);
                ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T>(
                        vec<4, T> const &c1, 
                        vec<4, T> const &c2, 
                        vec<4, T> const &c3, 
                        vec<4, T> const &c4);
                
                // -- Operator overrides --

                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T>& operator[](size_t n);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> const& operator[](size_t n) const;

                ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T> operator*(T const& v);
                ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T> operator*(mat<4, T> const& m);
                ALG_FUNC_DECL ALG_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v);
                
        };

        // -- data --

        template<typename T>
        ALG_INLINE ALG_CONSTEXPR T* value_ptr(vec<2, T> &v);

        template<typename T>
        ALG_INLINE ALG_CONSTEXPR T* value_ptr(vec<3, T> &v);

        template<typename T>
        ALG_INLINE ALG_CONSTEXPR T* value_ptr(vec<4, T> &v);

        template<typename T>
        ALG_INLINE ALG_CONSTEXPR T* value_ptr(mat<4, T> &v);

        // -- debug --

        template<typename T>
        ALG_INLINE void println(vec<2, T> const &v);

        template<typename T>
        ALG_INLINE void println(vec<3, T> const &v);

        template<typename T>
        ALG_INLINE void println(vec<4, T> const &v);

        template<typename T>
        ALG_INLINE void println(mat<4, T> const &m);

        // -- struct vec<2, T>: implements --

        template<typename T>
        vec<2, T>::vec() : vec(ZERO_VALUE, ZERO_VALUE) {}

        template<typename T>
        vec<2, T>::vec(T scalar) : vec(scalar, scalar) {}

        template<typename T>
        ALG_CONSTEXPR vec<2, T>::vec(T x, T y) : r(static_cast<T>(x)), g(static_cast<T>(y)) {}

        template<typename T>
        ALG_CONSTEXPR T& vec<2, T>::operator[](size_t n)
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        default: throw std::runtime_error("no index");
                }
        }

        template<typename T>
        ALG_CONSTEXPR T const& vec<2, T>::operator[](size_t n) const
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        default: throw std::runtime_error("no index");
                }
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> vec<2, T>::operator+(T const &scalar)
        {
                return vec<2, T>(x + scalar, y + scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> vec<2, T>::operator-(T const &scalar)
        {
                return vec<2, T>(x - scalar, y - scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> vec<2, T>::operator*(T const &scalar)
        {
                return vec<2, T>(x * scalar, y * scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> vec<2, T>::operator/(T const &scalar)
        {
                return vec<2, T>(x / scalar, y / scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> vec<2, T>::operator+(const vec<2, T> &v)
        {
                return vec<2, T>(x + v.x, y + v.y);
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> vec<2, T>::operator-(const vec<2, T> &v)
        {
                return vec<2, T>(x - v.x, y - v.y);
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> vec<2, T>::operator*(const vec<2, T> &v)
        {
                return vec<2, T>(x * v.x, y * v.y);
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> vec<2, T>::operator/(const vec<2, T> &v)
        {
                return vec<2, T>(x / v.x, y / v.y);
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> &vec<2, T>::operator+=(T const &scalar)
        {
                this->x = this->x + scalar;
                this->y = this->y + scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> &vec<2, T>::operator-=(T const &scalar)
        {
                this->x = this->x - scalar;
                this->y = this->y - scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> &vec<2, T>::operator*=(T const &scalar)
        {
                this->x = this->x * scalar;
                this->y = this->y * scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> &vec<2, T>::operator/=(T const &scalar)
        {
                this->x = this->x / scalar;
                this->y = this->y / scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> &vec<2, T>::operator+=(const vec<2, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> &vec<2, T>::operator-=(const vec<2, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> &vec<2, T>::operator*=(const vec<2, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<2, T> &vec<2, T>::operator/=(const vec<2, T> &v)
        {
                this->x = this->x / v.x;
                this->y = this->y / v.y;
                return *this;
        }

        // -- struct vec<3, T>: implements --

        template<typename T>
        vec<3, T>::vec() : vec(ZERO_VALUE, ZERO_VALUE, ZERO_VALUE) {}

        template<typename T>
        vec<3, T>::vec(T scalar) : vec(scalar, scalar, scalar) {}

        template<typename T>
        vec<3, T>::vec(vec<2, T> const& v) : vec(v, ZERO_VALUE) {}

        template<typename T>
        ALG_CONSTEXPR vec<3, T>::vec(vec<2, T> const& v, T z) : vec(v.x, v.y, z) {}

        template<typename T>
        ALG_CONSTEXPR vec<3, T>::vec(T x, T y, T z) : r(static_cast<T>(x)), g(static_cast<T>(y)), b(static_cast<T>(z)) {}

        template<typename T>
        ALG_CONSTEXPR T& vec<3, T>::operator[](size_t n)
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        case 2: return z;
                        default: throw std::runtime_error("no index");
                }
        }

        template<typename T>
        ALG_CONSTEXPR T const& vec<3, T>::operator[](size_t n) const
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        case 2: return z;
                        default: throw std::runtime_error("no index");
                }
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> vec<3, T>::operator+(T const &scalar)
        {
                return vec<3, T>(x + scalar, y + scalar, z + scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> vec<3, T>::operator-(T const &scalar)
        {
                return vec<3, T>(x - scalar, y - scalar, z - scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> vec<3, T>::operator*(T const &scalar)
        {
                return vec<3, T>(x * scalar, y * scalar, z * scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> vec<3, T>::operator/(T const &scalar)
        {
                return vec<3, T>(x / scalar, y / scalar, z / scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> vec<3, T>::operator+(const vec<3, T> &v)
        {
                return vec<3, T>(x + v.x, y + v.y, z + v.z);
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> vec<3, T>::operator-(const vec<3, T> &v)
        {
                return vec<3, T>(x - v.x, y - v.y, z - v.z);
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> vec<3, T>::operator*(const vec<3, T> &v)
        {
                return vec<3, T>(x * v.x, y * v.y, z * v.z);
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> vec<3, T>::operator/(const vec<3, T> &v)
        {
                return vec<3, T>(x / v.x, y / v.y, z / v.z);
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> &vec<3, T>::operator+=(T const &scalar)
        {
                this->x = this->x + scalar;
                this->y = this->y + scalar;
                this->z = this->z + scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> &vec<3, T>::operator-=(T const &scalar)
        {
                this->x = this->x - scalar;
                this->y = this->y - scalar;
                this->z = this->z - scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> &vec<3, T>::operator*=(T const &scalar)
        {
                this->x = this->x * scalar;
                this->y = this->y * scalar;
                this->z = this->z * scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> &vec<3, T>::operator/=(T const &scalar)
        {
                this->x = this->x / scalar;
                this->y = this->y / scalar;
                this->z = this->z / scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> &vec<3, T>::operator+=(const vec<3, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                this->z = this->z + v.z;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> &vec<3, T>::operator-=(const vec<3, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                this->z = this->z - v.z;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> &vec<3, T>::operator*=(const vec<3, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                this->z = this->z * v.z;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<3, T> &vec<3, T>::operator/=(const vec<3, T> &v)
        {
                this->x = this->x / v.x;
                this->y = this->y / v.y;
                this->z = this->z / v.z;
                return *this;
        }

        template<typename T>
        vec<2, T> vec<3, T>::xy()
        {
                return vec<2, T>(x, y);
        }

        // -- struct vec<4, T>: implements --

        template<typename T>
        vec<4, T>::vec() : vec(ZERO_VALUE, ZERO_VALUE, ZERO_VALUE, ZERO_VALUE) {}

        template<typename T>
        vec<4, T>::vec(T scalar) : vec(scalar, scalar, scalar, scalar) {}

        template<typename T>
        vec<4, T>::vec(vec<2, T> const& v) : vec(v.x, v.y, ZERO_VALUE, ZERO_VALUE) {}

        template<typename T>
        vec<4, T>::vec(vec<3, T> const& v) : vec(v.x, v.y, v.z, ZERO_VALUE) {}

        template<typename T>
        ALG_CONSTEXPR vec<4, T>::vec(vec<2, T> const& v, T z, T w) : vec(v.x, v.y, z, w) {}

        template<typename T>
        ALG_CONSTEXPR vec<4, T>::vec(vec<3, T> const& v, T w) : vec(v.x, v.y, v.z, w) {}

        template<typename T>
        ALG_CONSTEXPR vec<4, T>::vec(T x, T y, T z, T w) : r(static_cast<T>(x)), g(static_cast<T>(y))
                , b(static_cast<T>(z)), a(static_cast<T>(w)) {}

        template<typename T>
        ALG_CONSTEXPR T& vec<4, T>::operator[](size_t n)
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        case 2: return z;
                        case 3: return w;
                        default: throw std::runtime_error("no index");
                }
        }

        template<typename T>
        ALG_CONSTEXPR T const& vec<4, T>::operator[](size_t n) const
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        case 2: return z;
                        case 3: return w;
                        default: throw std::runtime_error("no index");
                }
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> vec<4, T>::operator+(T const &scalar)
        {
                return vec<4, T>(x + scalar, y + scalar, z + scalar, w + scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> vec<4, T>::operator-(T const &scalar)
        {
                return vec<4, T>(x - scalar, y - scalar, z - scalar, w - scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> vec<4, T>::operator*(T const &scalar)
        {
                return vec<4, T>(x * scalar, y * scalar, z * scalar, w * scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> vec<4, T>::operator/(T const &scalar)
        {
                return vec<4, T>(x / scalar, y / scalar, z / scalar, w / scalar);
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> vec<4, T>::operator+(const vec<4, T> &v)
        {
                return vec<4, T>(x + v.x, y + v.y, z + v.z, w + v.w);
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> vec<4, T>::operator-(const vec<4, T> &v)
        {
                return vec<4, T>(x - v.x, y - v.y, z - v.z, w - v.w);
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> vec<4, T>::operator*(const vec<4, T> &v)
        {
                return vec<4, T>(x * v.x, y * v.y, z * v.z, w * v.w);
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> vec<4, T>::operator/(const vec<4, T> &v)
        {
                return vec<4, T>(x / v.x, y / v.y, z / v.z, w / w.w);
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> &vec<4, T>::operator+=(T const &scalar)
        {
                this->x = this->x + scalar;
                this->y = this->y + scalar;
                this->z = this->z + scalar;
                this->w = this->w + scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> &vec<4, T>::operator-=(T const &scalar)
        {
                this->x = this->x - scalar;
                this->y = this->y - scalar;
                this->z = this->z - scalar;
                this->w = this->w - scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> &vec<4, T>::operator*=(T const &scalar)
        {
                this->x = this->x * scalar;
                this->y = this->y * scalar;
                this->z = this->z * scalar;
                this->w = this->w * scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> &vec<4, T>::operator/=(T const &scalar)
        {
                this->x = this->x / scalar;
                this->y = this->y / scalar;
                this->z = this->z / scalar;
                this->w = this->w / scalar;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> &vec<4, T>::operator+=(const vec<4, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                this->z = this->z + v.z;
                this->w = this->w + v.w;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> &vec<4, T>::operator-=(const vec<4, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                this->z = this->z - v.z;
                this->w = this->w - v.w;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> &vec<4, T>::operator*=(const vec<4, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                this->z = this->z * v.z;
                this->w = this->w * v.w;
                return *this;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> &vec<4, T>::operator/=(const vec<4, T> &v)
        {
                this->x = this->x / v.x;
                this->y = this->y / v.y;
                this->z = this->z / v.z;
                this->w = this->w / v.w;
                return *this;
        }

        template<typename T>
        vec<2, T> vec<4, T>::xy()
        {
                return vec<2, T>(x, y);
        }

        template<typename T>
        vec<3, T> vec<4, T>::xyz()
        {
                return vec<3, T>(x, y, z);
        }

        // -- struct mat<4, T> --

        template<typename T>
        ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T>::mat() : mat(ONE_VALUE) {}

        template<typename T>
        ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T>::mat(T const& s)
                : mat(vec<4, T>(s, 0, 0, 0),
                      vec<4, T>(0, s, 0, 0),
                      vec<4, T>(0, 0, s, 0),
                      vec<4, T>(0, 0, 0, s))
        {}

        template<typename T>
        ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T>::mat(
                T const& x1, T y1, T const& z1, T const& w1,
                T const& x2, T y2, T const& z2, T const& w2,
                T const& x3, T y3, T const& z3, T const& w3,
                T const& x4, T y4, T const& z4, T const& w4)
                : mat(vec<4, T>(x1, y1, z1, w1),
                      vec<4, T>(x2, y2, z2, w2),
                      vec<4, T>(x3, y3, z3, w3),
                      vec<4, T>(x4, y4, z4, w4))
        {}

        template<typename T>
        ALG_FUNC_DECL ALG_CONSTEXPR mat<4, T>::mat(
                vec<4, T> const &c1,
                vec<4, T> const &c2,
                vec<4, T> const &c3,
                vec<4, T> const &c4)
        {
                data[0] = c1;
                data[1] = c2;
                data[2] = c3;
                data[3] = c4;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T>& mat<4, T>::operator[](size_t n)
        {
                return data[n];
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> const& mat<4, T>::operator[](size_t n) const
        {
                return data[n];
        }

        template<typename T>
        ALG_CONSTEXPR mat<4, T> mat<4, T>::operator*(T const& v)
        {
                mat<4, T> Result;

                for (int i = 0; i < 4; i++)
                        Result[i] = data[i] * v;

                return Result;
        }

        template<typename T>
        ALG_CONSTEXPR mat<4, T> mat<4, T>::operator*(mat<4, T> const& m)
        {
                using namespace std::experimental;

                mat<4, T> Result;

                for (int j = 0; j < 4; j++) {
                        simd<T, simd_abi::fixed_size<4>> col(&m[j].x, element_aligned);
                        for (int i = 0; i < 4; i++) {
                                T row_data[] = { data[0][i], data[1][i], data[2][i], data[3][i] };
                                simd<T, simd_abi::fixed_size<4>> row;
                                row.copy_from(row_data, element_aligned);
                                Result[j][i] = std::experimental::reduce(row * col);
                        }
                }

                return Result;
        }

        template<typename T>
        ALG_CONSTEXPR vec<4, T> mat<4, T>::operator*(vec<4, T> const& v)
        {
                using namespace std::experimental;

                vec<4, T> Result;

                simd<T, simd_abi::fixed_size<4>> col(&v.x, element_aligned);
                for (int i = 0; i < 4; i++) {
                        T row_data[] = { data[0][i], data[1][i], data[2][i], data[3][i] };
                        simd<T, simd_abi::fixed_size<4>> row;
                        row.copy_from(row_data, element_aligned);
                        Result[i] = std::experimental::reduce(row * col);
                }

                return Result;
        }

        // -- implements --

        template<typename T>
        ALG_CONSTEXPR T* value_ptr(vec<2, T> &v)
        {
                return &v.x;
        }

        template<typename T>
        ALG_CONSTEXPR T* value_ptr(vec<3, T> &v)
        {
                return static_cast<T*>(&v.x);
        }

        template<typename T>
        ALG_CONSTEXPR T* value_ptr(vec<4, T> &v)
        {
                return &v.x;
        }

        template<typename T>
        ALG_CONSTEXPR T* value_ptr(mat<4, T> &m)
        {
                return &m.data[0].x;
        }

}

#define ALG_PRINT_FORMAT_VECTOR2(v)                                                             \
        do {                                                                                    \
            printf("[%.2f, %.2f]\n", v[0], v[1]);                                               \
        } while(0)

#define ALG_PRINT_FORMAT_VECTOR3(v)                                                             \
        do {                                                                                    \
            printf("[%.2f, %.2f, %.2f]\n", v[0], v[1], v[2]);                                   \
        } while(0)

#define ALG_PRINT_FORMAT_VECTOR4(v)                                                             \
        do {                                                                                    \
            printf("[%.2f, %.2f]\n", v[0], v[1], v[2], v[3]);                                   \
        } while(0)

#define ALG_PRINT_FORMAT_MATRIX4(m)                                                             \
        do {                                                                                    \
            for (int i = 0; i < 4; i++)                                                         \
                printf("(%.2f, %.2f, %.2f, %.2f)\n", m[0][i], m[1][i], m[2][i], m[3][i]);       \
        } while(0)


#endif /* ALG_VEC_H_ */
