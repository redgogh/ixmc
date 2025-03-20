#ifndef EQU_VEC_H_
#define EQU_VEC_H_

#include <cstdio>
#include <cmath>

#define EQU_FUNC_DECL          /* UNDEF */
#define EQU_INLINE             inline
#define EQU_CONSTEXPR          constexpr

namespace equ {

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

                const T ZERO = static_cast<T>(0);

                union {
                        struct { T x, y; };
                        struct { T r, g; };
                };

                // -- Constructor for vec2 --

                EQU_FUNC_DECL vec();
                EQU_FUNC_DECL explicit vec(T scalar);
                EQU_FUNC_DECL EQU_INLINE EQU_CONSTEXPR vec(T x, T y);

                // -- Operator override --

                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T> operator+(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T> operator-(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T> operator*(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T> operator/(T const &scalar);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T> operator+(vec<2, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T> operator-(vec<2, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T> operator*(vec<2, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T> operator/(vec<2, T> const &v);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T>& operator+=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T>& operator-=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T>& operator*=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T>& operator/=(T const &scalar);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T>& operator+=(vec<2, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T>& operator-=(vec<2, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T>& operator*=(vec<2, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<2, T>& operator/=(vec<2, T> const &v);

        };

        // -- struct vec<3, T> --

        template<typename T>
        struct vec<3, T> {
                // -- Store data define --

                const T ZERO = static_cast<T>(0);

                union {
                        struct { T x, y, z; };
                        struct { T r, g, b; };
                };

                // -- Constructor for vec3 --

                EQU_FUNC_DECL vec();
                EQU_FUNC_DECL explicit vec(T scalar);
                EQU_FUNC_DECL EQU_INLINE EQU_CONSTEXPR vec(T x, T y, T z);

                // -- Operator override --

                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T> operator+(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T> operator-(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T> operator*(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T> operator/(T const &scalar);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T> operator+(vec<3, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T> operator-(vec<3, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T> operator*(vec<3, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T> operator/(vec<3, T> const &v);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T>& operator+=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T>& operator-=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T>& operator*=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T>& operator/=(T const &scalar);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T>& operator+=(vec<3, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T>& operator-=(vec<3, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T>& operator*=(vec<3, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<3, T>& operator/=(vec<3, T> const &v);

        };

        // -- struct vec<4, T> --

        template<typename T>
        struct vec<4, T> {
                // -- Store data define --

                const T ZERO = static_cast<T>(0);

                union {
                        struct { T x, y, z, w; };
                        struct { T r, g, b, a; };
                };

                // -- Constructor for vec4 --

                EQU_FUNC_DECL vec();
                EQU_FUNC_DECL explicit vec(T scalar);
                EQU_FUNC_DECL EQU_INLINE EQU_CONSTEXPR vec(T x, T y, T z, T w);

                // -- Operator override --

                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T> operator+(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T> operator-(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T> operator*(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T> operator/(T const &scalar);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T> operator+(vec<4, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T> operator-(vec<4, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T> operator*(vec<4, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T> operator/(vec<4, T> const &v);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T>& operator+=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T>& operator-=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T>& operator*=(T const &scalar);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T>& operator/=(T const &scalar);

                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T>& operator+=(vec<4, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T>& operator-=(vec<4, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T>& operator*=(vec<4, T> const &v);
                EQU_FUNC_DECL EQU_CONSTEXPR vec<4, T>& operator/=(vec<4, T> const &v);

        };
        
        // -- struct vec<2, T>: implements --

        template<typename T>
        vec<2, T>::vec() : vec(ZERO, ZERO) {}

        template<typename T>
        vec<2, T>::vec(T scalar) : vec(scalar, scalar) {}

        template<typename T>
        EQU_CONSTEXPR vec<2, T>::vec(T x, T y) : r(static_cast<T>(x)), g(static_cast<T>(y)) {}

        template<typename T>
        EQU_CONSTEXPR vec<2, T> vec<2, T>::operator+(T const &scalar)
        {
                return vec<2, T>(x + scalar, y + scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> vec<2, T>::operator-(T const &scalar)
        {
                return vec<2, T>(x - scalar, y - scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> vec<2, T>::operator*(T const &scalar)
        {
                return vec<2, T>(x * scalar, y * scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> vec<2, T>::operator/(T const &scalar)
        {
                return vec<2, T>(x / scalar, y / scalar);
        }
        
        template<typename T>
        EQU_CONSTEXPR vec<2, T> vec<2, T>::operator+(const vec<2, T> &v)
        {
                return vec<2, T>(x + v.x, y + v.y);
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> vec<2, T>::operator-(const vec<2, T> &v)
        {
                return vec<2, T>(x - v.x, y - v.y);
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> vec<2, T>::operator*(const vec<2, T> &v)
        {
                return vec<2, T>(x * v.x, y * v.y);
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> vec<2, T>::operator/(const vec<2, T> &v)
        {
                return vec<2, T>(x / v.x, y / v.y);
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> &vec<2, T>::operator+=(T const &scalar)
        {
                this->x = this->x + scalar;
                this->y = this->y + scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> &vec<2, T>::operator-=(T const &scalar)
        {
                this->x = this->x - scalar;
                this->y = this->y - scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> &vec<2, T>::operator*=(T const &scalar)
        {
                this->x = this->x * scalar;
                this->y = this->y * scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> &vec<2, T>::operator/=(T const &scalar)
        {
                this->x = this->x / scalar;
                this->y = this->y / scalar;
                return *this;
        }
        
        template<typename T>
        EQU_CONSTEXPR vec<2, T> &vec<2, T>::operator+=(const vec<2, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> &vec<2, T>::operator-=(const vec<2, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> &vec<2, T>::operator*=(const vec<2, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<2, T> &vec<2, T>::operator/=(const vec<2, T> &v)
        {
                this->x = this->x / v.x;
                this->y = this->y / v.y;
                return *this;
        }

        // -- struct vec<3, T>: implements --

        template<typename T>
        vec<3, T>::vec() : vec(ZERO, ZERO, ZERO) {}

        template<typename T>
        vec<3, T>::vec(T scalar) : vec(scalar, scalar, scalar) {}

        template<typename T>
        EQU_CONSTEXPR vec<3, T>::vec(T x, T y, T z) : r(static_cast<T>(x)), g(static_cast<T>(y)), b(static_cast<T>(z)) {}

        template<typename T>
        EQU_CONSTEXPR vec<3, T> vec<3, T>::operator+(T const &scalar)
        {
                return vec<3, T>(x + scalar, y + scalar, z + scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> vec<3, T>::operator-(T const &scalar)
        {
                return vec<3, T>(x - scalar, y - scalar, z - scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> vec<3, T>::operator*(T const &scalar)
        {
                return vec<3, T>(x * scalar, y * scalar, z * scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> vec<3, T>::operator/(T const &scalar)
        {
                return vec<3, T>(x / scalar, y / scalar, z / scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> vec<3, T>::operator+(const vec<3, T> &v)
        {
                return vec<3, T>(x + v.x, y + v.y, z + v.z);
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> vec<3, T>::operator-(const vec<3, T> &v)
        {
                return vec<3, T>(x - v.x, y - v.y, z - v.z);
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> vec<3, T>::operator*(const vec<3, T> &v)
        {
                return vec<3, T>(x * v.x, y * v.y, z * v.z);
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> vec<3, T>::operator/(const vec<3, T> &v)
        {
                return vec<3, T>(x / v.x, y / v.y, z / v.z);
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> &vec<3, T>::operator+=(T const &scalar)
        {
                this->x = this->x + scalar;
                this->y = this->y + scalar;
                this->z = this->z + scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> &vec<3, T>::operator-=(T const &scalar)
        {
                this->x = this->x - scalar;
                this->y = this->y - scalar;
                this->z = this->z - scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> &vec<3, T>::operator*=(T const &scalar)
        {
                this->x = this->x * scalar;
                this->y = this->y * scalar;
                this->z = this->z * scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> &vec<3, T>::operator/=(T const &scalar)
        {
                this->x = this->x / scalar;
                this->y = this->y / scalar;
                this->z = this->z / scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> &vec<3, T>::operator+=(const vec<3, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                this->z = this->z + v.z;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> &vec<3, T>::operator-=(const vec<3, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                this->z = this->z - v.z;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> &vec<3, T>::operator*=(const vec<3, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                this->z = this->z * v.z;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<3, T> &vec<3, T>::operator/=(const vec<3, T> &v)
        {
                this->x = this->x / v.x;
                this->y = this->y / v.y;
                this->z = this->z / v.z;
                return *this;
        }

        // -- struct vec<4, T>: implements --

        template<typename T>
        vec<4, T>::vec() : vec(ZERO, ZERO, ZERO, ZERO) {}

        template<typename T>
        vec<4, T>::vec(T scalar) : vec(scalar, scalar, scalar, scalar) {}

        template<typename T>
        EQU_CONSTEXPR vec<4, T>::vec(T x, T y, T z, T w) : r(static_cast<T>(x)), g(static_cast<T>(y))
                                                         , b(static_cast<T>(z)), a(static_cast<T>(w)) {}

        template<typename T>
        EQU_CONSTEXPR vec<4, T> vec<4, T>::operator+(T const &scalar)
        {
                return vec<4, T>(x + scalar, y + scalar, z + scalar, w + scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> vec<4, T>::operator-(T const &scalar)
        {
                return vec<4, T>(x - scalar, y - scalar, z - scalar, w - scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> vec<4, T>::operator*(T const &scalar)
        {
                return vec<4, T>(x * scalar, y * scalar, z * scalar, w * scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> vec<4, T>::operator/(T const &scalar)
        {
                return vec<4, T>(x / scalar, y / scalar, z / scalar, w / scalar);
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> vec<4, T>::operator+(const vec<4, T> &v)
        {
                return vec<4, T>(x + v.x, y + v.y, z + v.z, w + v.w);
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> vec<4, T>::operator-(const vec<4, T> &v)
        {
                return vec<4, T>(x - v.x, y - v.y, z - v.z, w - v.w);
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> vec<4, T>::operator*(const vec<4, T> &v)
        {
                return vec<4, T>(x * v.x, y * v.y, z * v.z, w * v.w);
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> vec<4, T>::operator/(const vec<4, T> &v)
        {
                return vec<4, T>(x / v.x, y / v.y, z / v.z, w / w.w);
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> &vec<4, T>::operator+=(T const &scalar)
        {
                this->x = this->x + scalar;
                this->y = this->y + scalar;
                this->z = this->z + scalar;
                this->w = this->w + scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> &vec<4, T>::operator-=(T const &scalar)
        {
                this->x = this->x - scalar;
                this->y = this->y - scalar;
                this->z = this->z - scalar;
                this->w = this->w - scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> &vec<4, T>::operator*=(T const &scalar)
        {
                this->x = this->x * scalar;
                this->y = this->y * scalar;
                this->z = this->z * scalar;
                this->w = this->w * scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> &vec<4, T>::operator/=(T const &scalar)
        {
                this->x = this->x / scalar;
                this->y = this->y / scalar;
                this->z = this->z / scalar;
                this->w = this->w / scalar;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> &vec<4, T>::operator+=(const vec<4, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                this->z = this->z + v.z;
                this->w = this->w + v.w;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> &vec<4, T>::operator-=(const vec<4, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                this->z = this->z - v.z;
                this->w = this->w - v.w;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> &vec<4, T>::operator*=(const vec<4, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                this->z = this->z * v.z;
                this->w = this->w * v.w;
                return *this;
        }

        template<typename T>
        EQU_CONSTEXPR vec<4, T> &vec<4, T>::operator/=(const vec<4, T> &v)
        {
                this->x = this->x / v.x;
                this->y = this->y / v.y;
                this->z = this->z / v.z;
                this->w = this->w / v.w;
                return *this;
        }
        
        // -- data --
        
        template<typename T>
        EQU_INLINE EQU_CONSTEXPR T* value_ptr(vec<2, T> &v);

        template<typename T>
        EQU_INLINE EQU_CONSTEXPR T* value_ptr(vec<3, T> &v);

        template<typename T>
        EQU_INLINE EQU_CONSTEXPR T* value_ptr(vec<4, T> &v);

        // -- debug --

        template<typename T>
        EQU_INLINE void println(vec<2, T> const &v);

        template<typename T>
        EQU_INLINE void println(vec<3, T> const &v);

        template<typename T>
        EQU_INLINE void println(vec<4, T> const &v);

        // -- implements --
        
        template<typename T>
        EQU_CONSTEXPR T* value_ptr(vec<2, T> &v)
        {
                return &v.x;
        }

        template<typename T>
        EQU_CONSTEXPR T* value_ptr(vec<3, T> &v)
        {
                return static_cast<T*>(&v.x);
        }

        template<typename T>
        EQU_CONSTEXPR T* value_ptr(vec<4, T> &v)
        {
                return &v.x;
        }
        
        template<typename T>
        void println(vec<2, T> const &v)
        {
                printf("(%f, %f)\n", v.x, v.y);
        }

        template<typename T>
        void println(vec<3, T> const &v)
        {
                printf("(%f, %f, %f)\n", v.x, v.y, v.z);
        }

        template<typename T>
        void println(vec<4, T> const &v)
        {
                printf("(%f, %f, %f, %f)\n", v.x, v.y, v.z, v.w);
        }
}

#endif /* EQU_VEC_H_ */
