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
#ifndef MATH_H_
#define MATH_H_

#include "vec.h"
// SIMD(__SSE__)
#include <immintrin.h>

#define NAN     __builtin_nanf("")
#define PI      (3.14159265358979323846F)

namespace xmc {

float fmod (float x, float y)
{
        if (y == 0)
                return 0.0f;

        return x - ((int) (x / y)) * y; // NOLINT(*-narrowing-conversions)
}

float abs(float a)
{
        return a < 0.0f ? -a : a;
}

float pow(float x, int a)
{
        if (a < 2)
                return x;

        float q = 1.0f;

        while ((a--) > 0)
                q *= x;

        return q;
}

int degrees(float angrad)
{
        return (int) (angrad * (180.0f / PI));
}

float radians(int angdeg)
{
        return (float) angdeg * (PI / 180.0f);
}

float sin(float a)
{
        a = fmod(a, 2 * PI);

        float q = a;
        float t = a;
        int sign = 1;
        int limit = a < 1.0f ? 16 : 32;

        for (int n = 3; n <= limit; n += 2) {
                t *= (a * a) / (float) (n * (n - 1));
                q += (float) (sign *= -1) * t;
        }

        return q;
}

float cos(float a)
{
        a = fmod(a, 2 * PI);

        float q = 1.0f;
        float t = 1.0f;
        int sign = 1;
        int limit = a < 1.0f ? 16 : 32;

        for (int n = 2; n <= limit; n += 2) {
                t *= (a * a) / (float) (n * (n - 1));
                q += (float) (sign *= -1) * t;
        }

        return q;
}

float sqrt(float x)
{
        if (x < 0)
                return NAN;

        __m128 vec = _mm_set_ss(x);
        vec = _mm_sqrt_ss(vec);
        
        return _mm_cvtss_f32(vec);
}

float len(const vec2 &vec)
{
        return sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

float len(const vec3 &vec)
{
        return sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

float len(const vec4 &vec)
{
        return sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z) + (vec.w * vec.w));
}

float dot(const vec2 &a, const vec2 &b)
{
        return (a.x * b.x) + (a.y * b.y);
}

float dot(const vec3 &a, const vec3 &b)
{
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

float dot(const vec4 &a, const vec4 &b)
{
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

float cross(const vec2 &a, const vec2 &b)
{
        return (a.x * b.y) - (a.y * b.x);
}

vec3 cross(const vec3 &a, const vec3 &b)
{
        return vec3(
            (a.y * b.z) - (a.z * b.y),
            (a.z * b.x) - (a.x * b.z),
            (a.x * b.y) - (a.y * b.x)
        );
}

vec2 rotate(float angrad, const vec2 &vec)
{
        mat2 a(
          cos(angrad), -sin(angrad),
          sin(angrad),  cos(angrad)
        );
        return a * vec;
}

} /* namespace xmc */

#endif /* MATH_H_ */
