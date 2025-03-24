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
#ifndef VRT_VEC_H_
#define VRT_VEC_H_

#include <experimental/simd>

#define VRT_FUNC_DECL          /* UNDEF */
#define VRT_INLINE             inline
#define VRT_FUNC_CONSTEXPR     constexpr
#define VRT_FUNC_DEFAULT_CTOR  = default

namespace vrt
{
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

                union {
                        struct { T x, y; };
                        struct { T r, g; };
                };

                // -- Constructor for vec2 --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec() VRT_FUNC_DEFAULT_CTOR;
                VRT_FUNC_DECL explicit vec(T s);
                VRT_FUNC_DECL VRT_INLINE VRT_FUNC_CONSTEXPR vec(T x, T y);

                // -- Operator override --
                
                template<typename U>
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator=(vec<2, U> const& v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator=(vec<2, T> const& v) VRT_FUNC_DEFAULT_CTOR;

                template<typename U>
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator=(vec<3, U> const& v);
                
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T & operator[](size_t n);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T const& operator[](size_t n) const;

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator+=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator-=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator*=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator/=(T const &s);

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator+=(vec<2, T> const &v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator-=(vec<2, T> const &v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator*=(vec<2, T> const &v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator/=(vec<2, T> const &v);

        };

        // -- struct vec<2, T>: Global operator overrides --

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v, T const &s);

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v1, vec<2, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v1, vec<2, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v1, vec<2, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v1, vec<2, T> const &v2);

        // -- struct vec<3, T> --

        template<typename T>
        struct vec<3, T> {
                // -- Store data define --

                union {
                        struct { T x, y, z; };
                        struct { T r, g, b; };
                };

                // -- Constructor for vec3 --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec() VRT_FUNC_DEFAULT_CTOR;
                VRT_FUNC_DECL explicit vec(T s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec(vec<2, T> const& v, T z);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec(T x, T y, T z);

                // -- Operator override --

                template<typename U>
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> & operator=(vec<3, U> const& v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> & operator=(vec<3, T> const& v) VRT_FUNC_DEFAULT_CTOR;
                
                template<typename U>
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> & operator=(vec<4, U> const& v);
                    
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T & operator[](size_t n);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T const& operator[](size_t n) const;
                
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T>& operator+=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T>& operator-=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T>& operator*=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T>& operator/=(T const &s);

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T>& operator+=(vec<3, T> const &v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T>& operator-=(vec<3, T> const &v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T>& operator*=(vec<3, T> const &v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T>& operator/=(vec<3, T> const &v);

                VRT_FUNC_DECL vec<2, T> xy();
                
        };

        // -- struct vec<3, T>: Global operator overrides --

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, T const &s);

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v1, vec<3, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v1, vec<3, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v1, vec<3, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v1, vec<3, T> const &v2);

        // -- struct vec<4, T> --

        template<typename T>
        struct vec<4, T> {
                // -- Store data define --

                union {
                        struct { T x, y, z, w; };
                        struct { T r, g, b, a; };
                };

                // -- Constructor for vec4 --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec() VRT_FUNC_DEFAULT_CTOR;
                VRT_FUNC_DECL explicit vec(T s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec(vec<2, T> const& v, T z, T w);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec(vec<3, T> const& v, T w);
                VRT_FUNC_DECL VRT_INLINE VRT_FUNC_CONSTEXPR vec(T x, T y, T z, T w);

                // -- Operator override --

                template<typename U>
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> & operator=(vec<4, U> const& v);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> & operator=(vec<4, T> const& v) = default;
                
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T & operator[](size_t n);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T const& operator[](size_t n) const;

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T>& operator+=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T>& operator-=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T>& operator*=(T const &s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T>& operator/=(T const &s);

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T>& operator+=(vec<4, T> const &vv);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T>& operator-=(vec<4, T> const &vv);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T>& operator*=(vec<4, T> const &vv);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T>& operator/=(vec<4, T> const &vv);
                
                VRT_FUNC_DECL VRT_INLINE vec<2, T> xy();
                VRT_FUNC_DECL VRT_INLINE vec<3, T> xyz();
                
        };

        // -- struct vec<4, T>: Global operator overrides --

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v, T const &s);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator/(vec<4, T> const& v, T const &s);
        
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v1, vec<4, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v1, vec<4, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v1, vec<4, T> const &v2);
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator/(vec<4, T> const& v1, vec<4, T> const &v2);

        // -- struct mat<2, T> --

        template<typename T>
        struct mat<2, T> {
                // -- Data --

                vec<2, T> data[2];

                // -- Constructor --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat() VRT_FUNC_DEFAULT_CTOR;
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR explicit mat<2, T>(T const& s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<2, T>(
                        T const& x1, T y1,
                        T const& x2, T y2);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<2, T>(
                        vec<2, T> const& c1,
                        vec<2, T> const& c2);

                // -- Operator overrides --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> & operator[](size_t n);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> const& operator[](size_t n) const;

        };

        // -- struct mat<3 T> --

        template<typename T>
        struct mat<3, T> {
                // -- Data --

                vec<3, T> data[3];

                // -- Constructor --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat() VRT_FUNC_DEFAULT_CTOR;
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR explicit mat<3, T>(T const& s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<3, T>(
                    T const& x1, T y1, T const& z1,
                    T const& x2, T y2, T const& z2,
                    T const& x3, T y3, T const& z3);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<3, T>(
                    vec<3, T> const& c1,
                    vec<3, T> const& c2,
                    vec<3, T> const& c3);

                // -- Operator overrides --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> & operator[](size_t n);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> const& operator[](size_t n) const;

        };
        
        // -- struct mat<4, T> --
        
        template<typename T>
        struct mat<4, T> {
                // -- Data --
                
                vec<4, T> data[4];
                
                // -- Constructor --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat() VRT_FUNC_DEFAULT_CTOR;
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR explicit mat<4, T>(T const& s);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T>(
                        T const& x1, T y1, T const& z1, T const& w1,
                        T const& x2, T y2, T const& z2, T const& w2,
                        T const& x3, T y3, T const& z3, T const& w3,
                        T const& x4, T y4, T const& z4, T const& w4);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T>(
                        vec<4, T> const& c1, 
                        vec<4, T> const& c2, 
                        vec<4, T> const& c3, 
                        vec<4, T> const& c4);
                
                // -- Operator overrides --

                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> & operator[](size_t n);
                VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> const& operator[](size_t n) const;
                
        };

        // -- struct mat<4, T>: Global operator overrides --
        
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T> operator*(mat<4, T> const& m, T const& v);
        
        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T> operator*(mat<4, T> const& m1, mat<4, T> const& m2);

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> operator*(mat<4, T> const& m, vec<4, T> const& v);
        
        // -- struct vec<2, T>: implements --

        template<typename T>
        vec<2, T>::vec(T s) : vec(s, s) {}

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T>::vec(T x, T y) : r(static_cast<T>(x)), g(static_cast<T>(y)) {}

        template<typename T>
        template<typename U>
        VRT_FUNC_CONSTEXPR vec<2, T> & vec<2, T>::operator=(vec<2, U> const& v)
        {
                this->x = static_cast<T>(v.x);
                this->y = static_cast<T>(v.y);

                return *this;
        }

        template<typename T>
        template<typename U>
        VRT_FUNC_CONSTEXPR vec<2, T> & vec<2, T>::operator=(vec<3, U> const& v)
        {
                this->x = static_cast<T>(v.x);
                this->y = static_cast<T>(v.y);

                return *this;
        }
        
        template<typename T>
        VRT_FUNC_CONSTEXPR T& vec<2, T>::operator[](size_t n)
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        default: throw std::runtime_error("out of index");
                }
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T const& vec<2, T>::operator[](size_t n) const
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        default: throw std::runtime_error("out of index");
                }
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> &vec<2, T>::operator+=(T const &s)
        {
                this->x = this->x + s;
                this->y = this->y + s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> &vec<2, T>::operator-=(T const &s)
        {
                this->x = this->x - s;
                this->y = this->y - s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> &vec<2, T>::operator*=(T const &s)
        {
                this->x = this->x * s;
                this->y = this->y * s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> &vec<2, T>::operator/=(T const &s)
        {
                this->x = this->x / s;
                this->y = this->y / s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> &vec<2, T>::operator+=(const vec<2, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> &vec<2, T>::operator-=(const vec<2, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> &vec<2, T>::operator*=(const vec<2, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> &vec<2, T>::operator/=(const vec<2, T> &v)
        {
                this->x = this->x / v.x;
                this->y = this->y / v.y;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v, T const& s)
        {
                return vec<2, T>(v.x + s, v.y + s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v, T const& s)
        {
                return vec<2, T>(v.x - s, v.y - s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v, T const& s)
        {
                return vec<2, T>(v.x * s, v.y * s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v, T const& s)
        {
                return vec<2, T>(v.x / s, v.y / s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v1, vec<2, T> const& v2)
        {
                return vec<2, T>(v1.x + v2.x, v1.y + v2.y);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v1, vec<2, T> const& v2)
        {
                return vec<2, T>(v1.x - v2.x, v1.y - v2.y);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v1, vec<2, T> const& v2)
        {
                return vec<2, T>(v1.x * v2.x, v1.y * v2.y);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v1, vec<2, T> const& v2)
        {
                return vec<2, T>(v1.x / v2.x, v1.y / v2.y);
        }
        
        // -- struct vec<3, T>: implements --

        template<typename T>
        vec<3, T>::vec(T s) : vec(s, s, s) {}

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T>::vec(vec<2, T> const& v, T z) : vec(v.x, v.y, z) {}

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T>::vec(T x, T y, T z) : r(static_cast<T>(x)), g(static_cast<T>(y)), b(static_cast<T>(z)) {}

        template<typename T>
        template<typename U>
        VRT_FUNC_CONSTEXPR vec<3, T> & vec<3, T>::operator=(vec<3, U> const& v)
        {
                this->x = static_cast<T>(v.x);
                this->y = static_cast<T>(v.y);
                this->z = static_cast<T>(v.z);

                return *this;
        }

        template<typename T>
        template<typename U>
        VRT_FUNC_CONSTEXPR vec<3, T> & vec<3, T>::operator=(vec<4, U> const& v)
        {
                this->x = static_cast<T>(v.x);
                this->y = static_cast<T>(v.y);
                this->z = static_cast<T>(v.z);

                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T& vec<3, T>::operator[](size_t n)
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        case 2: return z;
                        default: throw std::runtime_error("out of index");
                }
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T const& vec<3, T>::operator[](size_t n) const
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        case 2: return z;
                        default: throw std::runtime_error("out of index");
                }
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> &vec<3, T>::operator+=(T const &s)
        {
                this->x = this->x + s;
                this->y = this->y + s;
                this->z = this->z + s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> &vec<3, T>::operator-=(T const &s)
        {
                this->x = this->x - s;
                this->y = this->y - s;
                this->z = this->z - s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> &vec<3, T>::operator*=(T const &s)
        {
                this->x = this->x * s;
                this->y = this->y * s;
                this->z = this->z * s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> &vec<3, T>::operator/=(T const &s)
        {
                this->x = this->x / s;
                this->y = this->y / s;
                this->z = this->z / s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> &vec<3, T>::operator+=(const vec<3, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                this->z = this->z + v.z;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> &vec<3, T>::operator-=(const vec<3, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                this->z = this->z - v.z;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> &vec<3, T>::operator*=(const vec<3, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                this->z = this->z * v.z;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> &vec<3, T>::operator/=(const vec<3, T> &v)
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

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, T const& s)
        {
                return vec<3, T>(v.x + s, v.y + s, v.z + s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, T const& s)
        {
                return vec<3, T>(v.x - s, v.y - s, v.z - s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, T const& s)
        {
                return vec<3, T>(v.x * s, v.y * s, v.z * s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, T const& s)
        {
                return vec<3, T>(v.x / s, v.y / s, v.z / s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v1, vec<3, T> const& v2)
        {
                return vec<3, T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v1, vec<3, T> const& v2)
        {
                return vec<3, T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v1, vec<3, T> const& v2)
        {
                return vec<3, T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v1, vec<3, T> const& v2)
        {
                return vec<3, T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
        }

        // -- struct vec<4, T>: implements --

        template<typename T>
        vec<4, T>::vec(T s) : vec(s, s, s, s) {}

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T>::vec(vec<2, T> const& v, T z, T w) : vec(v.x, v.y, z, w) {}

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T>::vec(vec<3, T> const& v, T w) : vec(v.x, v.y, v.z, w) {}

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T>::vec(T x, T y, T z, T w) 
                : r(static_cast<T>(x)), g(static_cast<T>(y))
                , b(static_cast<T>(z)), a(static_cast<T>(w))
        {}

        template<typename T>
        template<typename U>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator=(vec<4, U> const& v)
        {
                this->x = static_cast<T>(v.x);
                this->y = static_cast<T>(v.y);
                this->z = static_cast<T>(v.z);
                this->w = static_cast<T>(v.w);
                
                return *this;
        }
                
        template<typename T>
        VRT_FUNC_CONSTEXPR T& vec<4, T>::operator[](size_t n)
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        case 2: return z;
                        case 3: return w;
                        default: throw std::runtime_error("out of index");
                }
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T const& vec<4, T>::operator[](size_t n) const
        {
                switch (n) {
                        case 0: return x;
                        case 1: return y;
                        case 2: return z;
                        case 3: return w;
                        default: throw std::runtime_error("out of index");
                }
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator+=(T const &s)
        {
                this->x = this->x + s;
                this->y = this->y + s;
                this->z = this->z + s;
                this->w = this->w + s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator-=(T const &s)
        {
                this->x = this->x - s;
                this->y = this->y - s;
                this->z = this->z - s;
                this->w = this->w - s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator*=(T const &s)
        {
                this->x = this->x * s;
                this->y = this->y * s;
                this->z = this->z * s;
                this->w = this->w * s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator/=(T const &s)
        {
                this->x = this->x / s;
                this->y = this->y / s;
                this->z = this->z / s;
                this->w = this->w / s;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator+=(const vec<4, T> &v2)
        {
                this->x = this->x + v2.x;
                this->y = this->y + v2.y;
                this->z = this->z + v2.z;
                this->w = this->w + v2.w;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator-=(const vec<4, T> &v2)
        {
                this->x = this->x - v2.x;
                this->y = this->y - v2.y;
                this->z = this->z - v2.z;
                this->w = this->w - v2.w;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator*=(const vec<4, T> &v2)
        {
                this->x = this->x * v2.x;
                this->y = this->y * v2.y;
                this->z = this->z * v2.z;
                this->w = this->w * v2.w;
                return *this;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> & vec<4, T>::operator/=(const vec<4, T> &v2)
        {
                this->x = this->x / v2.x;
                this->y = this->y / v2.y;
                this->z = this->z / v2.z;
                this->w = this->w / v2.w;
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

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v, T const &s)
        {
                return vec<4, T>(v.x + s, v.y + s, v.z + s, v.w + s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v, T const &s)
        {
                return vec<4, T>(v.x - s, v.y - s, v.z - s, v.w - s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v, T const &s)
        {
                return vec<4, T>(v.x * s, v.y * s, v.z * s, v.w * s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator/(vec<4, T> const& v, T const &s)
        {
                return vec<4, T>(v.x / s, v.y / s, v.z / s, v.w / s);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v1, const vec<4, T> &v2)
        {
                return vec<4, T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v1, const vec<4, T> &v2)
        {
                return vec<4, T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v1, const vec<4, T> &v2)
        {
                return vec<4, T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator/(vec<4, T> const& v1, const vec<4, T> &v2)
        {
                return vec<4, T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
        }

        // -- struct mat<2, T> --

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<2, T>::mat(T const& s)
            : mat(vec<2, T>(s, 0),
                  vec<2, T>(0, s))
        {}

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<2, T>::mat(
            T const& x1, T y1,
            T const& x2, T y2)
            : mat(vec<2, T>(x1, y1),
                  vec<2, T>(x2, y2))
        {}

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<2, T>::mat(
            vec<2, T> const& c1,
            vec<2, T> const& c2)
        {
                data[0] = c1;
                data[1] = c2;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T>& mat<2, T>::operator[](size_t n)
        {
                return data[n];
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> const& mat<2, T>::operator[](size_t n) const
        {
                return data[n];
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR mat<2, T> operator*(mat<2, T> const& m, T const& v)
        {
                mat<2, T> Result;

                for (int i = 0; i < 2; i++)
                        Result[i] = m[i] * v;

                return Result;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR mat<2, T> operator*(mat<2, T> const& m1, mat<2, T> const& m2)
        {
                using namespace std::experimental;

                mat<2, T> Result;

                for (int j = 0; j < 2; j++) {
                        simd<T, simd_abi::fixed_size<2>> col(&m2[j].x, element_aligned);
                        for (int i = 0; i < 2; i++) {
                                T row_data[] = { m1[0][i], m1[1][i] };
                                simd<T, simd_abi::fixed_size<2>> row;
                                row.copy_from(row_data, element_aligned);
                                Result[j][i] = std::experimental::reduce(row * col);
                        }
                }

                return Result;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> operator*(mat<2, T> const& m, vec<2, T> const& v)
        {
                using namespace std::experimental;

                vec<2, T> Result;

                simd<T, simd_abi::fixed_size<2>> col(&v.x, element_aligned);
                for (int i = 0; i < 2; i++) {
                        T row_data[] = { m[0][i], m[1][i] };
                        simd<T, simd_abi::fixed_size<2>> row;
                        row.copy_from(row_data, element_aligned);
                        Result[i] = std::experimental::reduce(row * col);
                }

                return Result;
        }

        // -- struct mat<3, T> --

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<3, T>::mat(T const& s)
            : mat(vec<3, T>(s, 0, 0),
                  vec<3, T>(0, s, 0),
                  vec<3, T>(0, 0, s))
        {}

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<3, T>::mat(
            T const& x1, T y1, T const& z1,
            T const& x2, T y2, T const& z2,
            T const& x3, T y3, T const& z3)
            : mat(vec<3, T>(x1, y1, z1),
                  vec<3, T>(x2, y2, z2),
                  vec<3, T>(x3, y3, z3))
        {}

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<3, T>::mat(
            vec<3, T> const& c1,
            vec<3, T> const& c2,
            vec<3, T> const& c3)
        {
                data[0] = c1;
                data[1] = c2;
                data[2] = c3;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T>& mat<3, T>::operator[](size_t n)
        {
                return data[n];
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> const& mat<3, T>::operator[](size_t n) const
        {
                return data[n];
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR mat<3, T> operator*(mat<3, T> const& m, T const& v)
        {
                mat<3, T> Result;

                for (int i = 0; i < 3; i++)
                        Result[i] = m[i] * v;

                return Result;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR mat<3, T> operator*(mat<3, T> const& m1, mat<3, T> const& m2)
        {
                using namespace std::experimental;

                mat<3, T> Result;

                for (int j = 0; j < 3; j++) {
                        simd<T, simd_abi::fixed_size<3>> col(&m2[j].x, element_aligned);
                        for (int i = 0; i < 3; i++) {
                                T row_data[] = { m1[0][i], m1[1][i], m1[2][i], m1[3][i] };
                                simd<T, simd_abi::fixed_size<3>> row;
                                row.copy_from(row_data, element_aligned);
                                Result[j][i] = std::experimental::reduce(row * col);
                        }
                }

                return Result;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> operator*(mat<3, T> const& m, vec<3, T> const& v)
        {
                using namespace std::experimental;

                vec<3, T> Result;

                simd<T, simd_abi::fixed_size<3>> col(&v.x, element_aligned);
                for (int i = 0; i < 3; i++) {
                        T row_data[] = { m[0][i], m[1][i], m[2][i] };
                        simd<T, simd_abi::fixed_size<3>> row;
                        row.copy_from(row_data, element_aligned);
                        Result[i] = std::experimental::reduce(row * col);
                }

                return Result;
        }
        
        // -- struct mat<4, T> --

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T>::mat(T const& s)
                : mat(vec<4, T>(s, 0, 0, 0),
                      vec<4, T>(0, s, 0, 0),
                      vec<4, T>(0, 0, s, 0),
                      vec<4, T>(0, 0, 0, s))
        {}

        template<typename T>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T>::mat(
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
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T>::mat(
                vec<4, T> const& c1,
                vec<4, T> const& c2,
                vec<4, T> const& c3,
                vec<4, T> const& c4)
        {
                data[0] = c1;
                data[1] = c2;
                data[2] = c3;
                data[3] = c4;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T>& mat<4, T>::operator[](size_t n)
        {
                return data[n];
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> const& mat<4, T>::operator[](size_t n) const
        {
                return data[n];
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR mat<4, T> operator*(mat<4, T> const& m, T const& v)
        {
                mat<4, T> Result;

                for (int i = 0; i < 4; i++)
                        Result[i] = m[i] * v;

                return Result;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR mat<4, T> operator*(mat<4, T> const& m1, mat<4, T> const& m2)
        {
                using namespace std::experimental;

                mat<4, T> Result;

                for (int j = 0; j < 4; j++) {
                        simd<T, simd_abi::fixed_size<4>> col(&m2[j].x, element_aligned);
                        for (int i = 0; i < 4; i++) {
                                T row_data[] = { m1[0][i], m1[1][i], m1[2][i], m1[3][i] };
                                simd<T, simd_abi::fixed_size<4>> row;
                                row.copy_from(row_data, element_aligned);
                                Result[j][i] = std::experimental::reduce(row * col);
                        }
                }

                return Result;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> operator*(mat<4, T> const& m, vec<4, T> const& v)
        {
                using namespace std::experimental;

                vec<4, T> Result;

                simd<T, simd_abi::fixed_size<4>> col(&v.x, element_aligned);
                for (int i = 0; i < 4; i++) {
                        T row_data[] = { m[0][i], m[1][i], m[2][i], m[3][i] };
                        simd<T, simd_abi::fixed_size<4>> row;
                        row.copy_from(row_data, element_aligned);
                        Result[i] = std::experimental::reduce(row * col);
                }

                return Result;
        }

        // -- tools define --

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE T* value_ptr(vec<2, T> &v);

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE T* value_ptr(vec<3, T> &v);

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE T* value_ptr(vec<4, T> &v);

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE T* value_ptr(mat<4, T> &v);

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE bool equals(T const* m1, T const* m2);
        
        // -- tools implements --
        
        template<typename T>
        VRT_FUNC_DECL VRT_INLINE T* value_ptr(vec<2, T> &v)
        {
                return &(v.x);
        }

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE T* value_ptr(vec<3, T> &v)
        {
                return &(v.x);
        }

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE T* value_ptr(vec<4, T> &v)
        {
                return &(v.x);
        }

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE T* value_ptr(mat<4, T> &m)
        {
                return &(m[0].x);
        }

        template<typename T>
        VRT_FUNC_DECL VRT_INLINE bool equals(T const* m1, T const* m2)
        {
                for (int i = 0; i < 16; i++)
                        if (m1[i] != m2[i])
                                return false;

                return true;
        }

}

#define VRT_PRINT_FORMAT_VECTOR2(v)                                                             \
        do {                                                                                    \
            printf("[%.2f, %.2f]\n", v[0], v[1]);                                               \
        } while(0)

#define VRT_PRINT_FORMAT_VECTOR3(v)                                                             \
        do {                                                                                    \
            printf("[%.2f, %.2f, %.2f]\n", v[0], v[1], v[2]);                                   \
        } while(0)

#define VRT_PRINT_FORMAT_VECTOR4(v)                                                             \
        do {                                                                                    \
            printf("[%.2f, %.2f, %.2f, %.2f]\n", v[0], v[1], v[2], v[3]);                       \
        } while(0)

#define VRT_PRINT_FORMAT_MATRIX4(m)                                                             \
        do {                                                                                    \
            for (int i = 0; i < 4; i++)                                                         \
                printf("(%.2f, %.2f, %.2f, %.2f)\n", m[0][i], m[1][i], m[2][i], m[3][i]);       \
        } while(0)
        
#endif /* VRT_VEC_H_ */
