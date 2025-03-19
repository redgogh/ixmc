#ifndef BRA_VEC_H_
#define BRA_VEC_H_

#include <cstdio>
#include <cmath>

#define DONE                   {}
#define BRA_FUNC_DECL          /* UNDEF */
#define BRA_INLINE             inline
#define BRA_CONSTEXPR          constexpr

namespace bra {

        // -- Vector & Matrix --
        template<size_t N, typename T> struct vec;
        template<size_t N, typename T> struct mat;

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

                BRA_FUNC_DECL vec();
                BRA_FUNC_DECL explicit vec(T scalar);
                BRA_FUNC_DECL BRA_INLINE BRA_CONSTEXPR vec(T x, T y);

                // -- Operator override --

                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T> operator+(T const &scalar);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T> operator-(T const &scalar);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T> operator*(T const &scalar);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T> operator/(T const &scalar);

                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T> operator+(vec<2, T> const &v);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T> operator-(vec<2, T> const &v);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T> operator*(vec<2, T> const &v);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T> operator/(vec<2, T> const &v);

                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T>& operator+=(T const &scalar);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T>& operator-=(T const &scalar);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T>& operator*=(T const &scalar);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T>& operator/=(T const &scalar);

                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T>& operator+=(vec<2, T> const &v);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T>& operator-=(vec<2, T> const &v);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T>& operator*=(vec<2, T> const &v);
                BRA_FUNC_DECL BRA_CONSTEXPR vec<2, T>& operator/=(vec<2, T> const &v);

        };

        // -- struct vec<2, T>: implements --

        template<typename T>
        vec<2, T>::vec() : vec(ZERO, ZERO) {}

        template<typename T>
        vec<2, T>::vec(T scalar) : vec(scalar, scalar) {}

        template<typename T>
        BRA_CONSTEXPR vec<2, T>::vec(T x, T y) : r(static_cast<T>(x)), g(static_cast<T>(y)) {}

        template<typename T>
        BRA_CONSTEXPR vec<2, T> vec<2, T>::operator+(T const &scalar)
        {
                return vec<2, T>(x + scalar, y + scalar);
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> vec<2, T>::operator-(T const &scalar)
        {
                return vec<2, T>(x - scalar, y - scalar);
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> vec<2, T>::operator*(T const &scalar)
        {
                return vec<2, T>(x * scalar, y * scalar);
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> vec<2, T>::operator/(T const &scalar)
        {
                return vec<2, T>(x / scalar, y / scalar);
        }
        
        template<typename T>
        BRA_CONSTEXPR vec<2, T> vec<2, T>::operator+(const vec<2, T> &v)
        {
                return vec<2, T>(x + v.x, y + v.y);
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> vec<2, T>::operator-(const vec<2, T> &v)
        {
                return vec<2, T>(x - v.x, y - v.y);
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> vec<2, T>::operator*(const vec<2, T> &v)
        {
                return vec<2, T>(x * v.x, y * v.y);
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> vec<2, T>::operator/(const vec<2, T> &v)
        {
                return vec<2, T>(x / v.x, y / v.y);
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> &vec<2, T>::operator+=(T const &scalar)
        {
                this->x = this->x + scalar;
                this->y = this->y + scalar;
                return *this;
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> &vec<2, T>::operator-=(T const &scalar)
        {
                this->x = this->x - scalar;
                this->y = this->y - scalar;
                return *this;
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> &vec<2, T>::operator*=(T const &scalar)
        {
                this->x = this->x * scalar;
                this->y = this->y * scalar;
                return *this;
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> &vec<2, T>::operator/=(T const &scalar)
        {
                this->x = this->x / scalar;
                this->y = this->y / scalar;
                return *this;
        }
        
        template<typename T>
        BRA_CONSTEXPR vec<2, T> &vec<2, T>::operator+=(const vec<2, T> &v)
        {
                this->x = this->x + v.x;
                this->y = this->y + v.y;
                return *this;
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> &vec<2, T>::operator-=(const vec<2, T> &v)
        {
                this->x = this->x - v.x;
                this->y = this->y - v.y;
                return *this;
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> &vec<2, T>::operator*=(const vec<2, T> &v)
        {
                this->x = this->x * v.x;
                this->y = this->y * v.y;
                return *this;
        }

        template<typename T>
        BRA_CONSTEXPR vec<2, T> &vec<2, T>::operator/=(const vec<2, T> &v)
        {
                this->x = this->x / v.x;
                this->y = this->y / v.y;
                return *this;
        }

        // -- debug --

        template<typename T>
        BRA_INLINE void println(vec<2, T> const &v);

        template<typename T>
        void println(vec<2, T> const &v)
        {
                printf("(%f, %f)\n", v.x, v.y);
        }
}

#endif /* BRA_VEC_H_ */
