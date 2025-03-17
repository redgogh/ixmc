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
// std
#include <cmath>

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

float sin(float x)
{
        return std::sin(x);
}

float cos(float x) {
        return std::cos(x);
}

float sqrt(float x)
{
        if (x < 0)
                return NAN;

        __m128 vec = _mm_set_ss(x);
        vec = _mm_sqrt_ss(vec);

        return _mm_cvtss_f32(vec);
}

float length(const vec2 &vec)
{
        return sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

float length(const vec3 &vec)
{
        return sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

float length(const vec4 &vec)
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

vec3 normalize(const vec3 &vec)
{
        float l = length(vec);
        return l == 0 ? vec3(0.0f) : vec3(vec.x / l, vec.y / l, vec.z / l);
}

mat4 rotate(const mat4 &matrix, float angrad, const vec3 &vec)
{
        vec3 n = normalize(vec);
        
        float c = cos(angrad), s = sin(angrad);
        float t = 1 - c, x = n.x, y = n.y, z = n.z;
        
        mat4 rotation(
            (t * x * x + c),      (t * x * y - s * z),   (t * x * z + s * y), 0.0f,
            (t * x * y + s * z),  (t * y * y + c),       (t * y * z - s * x), 0.0f,
            (t * x * z - s * y),  (t * y * z + s * x),   (t * z * z + c),     0.0f,
            0.0f,                 0.0f,                  0.0f,                1.0f
        );
        
        return matrix * rotation;
}

mat4 translate(const mat4 &matrix, const vec3 &vec)
{
        mat4 translation(
            1.0f,  0.0f,  0.0f,  vec.x,
            0.0f,  1.0f,  0.0f,  vec.y,
            0.0f,  0.0f,  1.0f,  vec.z,
            0.0f,  0.0f,  0.0f,  1.0f
        );

        return matrix * translation;
}

mat4 scale(const mat4 &matrix, const vec3 &vec)
{
        mat4 scaling(
            vec.x, 0.0f,  0.0f,  0.0f,
            0.0f,  vec.y, 0.0f,  0.0f,
            0.0f,  0.0f,  vec.z, 0.0f,
            0.0f,  0.0f,  0.0f,  1.0f
        );

        return matrix * scaling;
}

} /* namespace xmc */

#endif /* MATH_H_ */
