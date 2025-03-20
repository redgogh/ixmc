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
#ifndef ALG_H_
#define ALG_H_

#include "vec.h"
// std
#include <cstdio>
#include <cmath>
#include <stdexcept>

#define ALG_TEMPLATE_TYPE_INT32   int
#define ALG_TEMPLATE_TYPE_INT64   long
#define ALG_TEMPLATE_TYPE_FLOAT32 float
#define ALG_TEMPLATE_TYPE_FLOAT64 double

namespace alg {
        // -- define --

        ///
        /// @brief 计算 x 除以 y 的浮点数取模（余数）。
        ///
        /// fmod 计算的是 x 除以 y 后的余数，结果与 x 具有相同的符号.
        ///
        /// 计算公式如下：
        ///   fmod(x, y) = x - n * y，其中 n = trunc(x / y)（n 为整数部分）。
        ///
        /// @param x 被除数（浮点数）
        /// @param y 除数（浮点数，不能为 0）
        /// @return float 返回 x 除以 y 的余数，满足 0 ≤ |余数| < |y|
        ///
        /// @note fmod 的常见用途：
        ///  1. 角度归一化：fmod(angle, 360.0f) 让角度保持在 [0, 360) 之间。
        ///  2. 处理周期性计算，如波形生成、动画循环等。
        ///  3. 保留小数部分，例如 fmod(5.75, 1.0) 结果为 0.75。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_FLOAT32>
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR int mod(U x, U y);

        ///
        /// @brief 计算浮点数的绝对值。
        ///
        /// abs 函数用于计算给定浮点数 `a` 的绝对值。绝对值是指一个数在数轴上到原点的距离，
        /// 因此无论 `a` 是正数还是负数，其绝对值总是非负的。
        ///
        /// 计算公式如下：
        ///   abs(a) = |a|
        ///
        /// @param a 输入的浮点数
        /// @return float 返回 `a` 的绝对值，结果总是非负的。
        ///
        /// @note abs 的常见用途：
        ///  1. 计算距离或差值时，确保结果为非负数。
        ///  2. 在需要忽略符号的场合，如计算误差、比较大小等。
        ///  3. 在数学运算中，确保某些值始终为正数，例如向量的模长计算。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_FLOAT32>
        U
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR abs(U x);

        ///
        /// @brief 计算浮点数 `x` 的整数次幂。
        ///
        /// pow 函数用于计算浮点数 `x` 的 `a` 次幂，其中 `a` 是一个整数。
        /// 该函数通过连续乘法实现幂运算，适用于需要高效计算整数次幂的场景。
        ///
        /// 计算公式如下：
        ///   pow(x, a) = x^a
        ///
        /// @param x 底数（浮点数）
        /// @param a 指数（整数）
        /// @return float 返回 `x` 的 `a` 次幂结果。
        ///
        /// @note pow 的常见用途：
        ///  1. 计算几何增长或衰减，如复利计算、物理中的指数衰减等。
        ///  2. 在图形学中计算光照衰减、颜色混合等。
        ///  3. 在数学运算中，快速计算幂次结果。
        ///
        /// @warning 当 `x` 为负数且 `a` 为非整数时，结果可能为 NaN（未定义）。
        ///          当 `x` 为 0 且 `a` 为负数时，结果可能为无穷大（inf）。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_FLOAT32>
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR U pow(U x, U a);

        ///
        /// @brief 将弧度值转换为角度值。
        ///
        /// degrees 函数用于将给定的弧度值 `angrad` 转换为对应的角度值。
        /// 转换公式基于圆周的弧度与角度关系：180 度 = π 弧度。
        ///
        /// 计算公式如下：
        ///   degrees(angrad) = angrad * (180 / π)
        ///
        /// @param angrad 输入的弧度值（浮点数）
        /// @return int 返回转换后的角度值，结果为整数。
        ///
        /// @note degrees 的常见用途：
        ///  1. 在图形学中将弧度转换为角度，便于理解和计算。
        ///  2. 在物理仿真中处理角度相关的计算。
        ///  3. 在游戏开发中处理角色的旋转和方向。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_INT32>
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR int degrees(U angrad);

        ///
        /// @brief 将角度值转换为弧度值。
        ///
        /// radians 函数用于将给定的角度值 `angdeg` 转换为对应的弧度值。
        /// 转换公式基于圆周的弧度与角度关系：180 度 = π 弧度。
        ///
        /// 计算公式如下：
        ///   radians(angdeg) = angdeg * (π / 180)
        ///
        /// @param angdeg 输入的角度值（整数）
        /// @return float 返回转换后的弧度值，结果为浮点数。
        ///
        /// @note radians 的常见用途：
        ///  1. 在数学计算中将角度转换为弧度，便于使用三角函数。
        ///  2. 在物理仿真中处理弧度相关的计算。
        ///  3. 在游戏开发中处理角色的旋转和方向。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_FLOAT32>
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR U radians(int angdeg);

        ///
        /// @brief 计算浮点数的正弦值。
        ///
        /// sin 函数用于计算给定浮点数 `x`（以弧度为单位）的正弦值。
        /// 正弦函数是三角函数之一，常用于描述周期性现象，如波形、振动等。
        ///
        /// @param x 输入的弧度值（浮点数）
        /// @return float 返回 `x` 的正弦值，范围在 [-1, 1] 之间。
        ///
        /// @note sin 的常见用途：
        ///  1. 在图形学中生成波形或处理旋转。
        ///  2. 在物理仿真中模拟周期性运动，如弹簧振动。
        ///  3. 在信号处理中分析周期性信号。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_FLOAT32>
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR U sin(U x);

        ///
        /// @brief 计算浮点数的余弦值。
        ///
        /// cos 函数用于计算给定浮点数 `x`（以弧度为单位）的余弦值。
        /// 余弦函数是三角函数之一，常用于描述周期性现象，如波形、振动等。
        ///
        /// @param x 输入的弧度值（浮点数）
        /// @return float 返回 `x` 的余弦值，范围在 [-1, 1] 之间。
        ///
        /// @note cos 的常见用途：
        ///  1. 在图形学中生成波形或处理旋转。
        ///  2. 在物理仿真中模拟周期性运动，如弹簧振动。
        ///  3. 在信号处理中分析周期性信号。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_FLOAT32>
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR U cos(U x);

        ///
        /// @brief 计算浮点数的平方根。
        ///
        /// sqrt 函数用于计算给定浮点数 `x` 的平方根。
        /// 平方根是数学中的基本运算，常用于几何、物理和工程计算中。
        ///
        /// @param x 输入的浮点数（必须为非负数）
        /// @return float 返回 `x` 的平方根，结果为非负数。
        ///
        /// @note sqrt 的常见用途：
        ///  1. 计算几何中的距离或长度，如欧几里得距离。
        ///  2. 在物理中计算速度、加速度等。
        ///
        /// @warning 当 `x` 为负数时，结果可能为 NaN（未定义）。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_FLOAT32>
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR U sqrt(U x);

        ///
        /// @brief 计算 4个 浮点数的平方根。
        ///
        /// sqrt 函数用于计算给定浮点数 `x` 的平方根。
        /// 平方根是数学中的基本运算，常用于几何、物理和工程计算中。
        ///
        /// @param v 输入的浮点数向量（必须为非负数）
        /// @return vec<4, U> 返回 `v` 向量的平方根，结果为非负数。
        ///
        /// @note sqrt 的常见用途：
        ///  1. 计算几何中的距离或长度，如欧几里得距离。
        ///  2. 在物理中计算速度、加速度等。
        ///
        /// @warning 当 `x` 为负数时，结果可能为 NaN（未定义）。
        ///
        template<typename U = ALG_TEMPLATE_TYPE_FLOAT32>
        ALG_FUNC_DECL ALG_FUNC_CONSTEXPR vec<4, U> sqrt(vec<4, U> const& v);

        // -- implements --

        template<typename U>
        ALG_FUNC_CONSTEXPR int mod(U x, U y) {
                if (y == 0)
                        return 0;
                return x - ((int) (x / y)) * y;
        }

        template<typename U>
        U
        ALG_FUNC_CONSTEXPR abs(U x) {
                return x < 0 ? -x : x;
        }

        template<typename U>
        ALG_FUNC_CONSTEXPR U pow(U x, U a) {
                return std::pow(x, a);
        }

        template<typename U>
        ALG_FUNC_CONSTEXPR int degrees(U angrad)
        {
                return angrad / (M_PI / 180);
        }

        template<typename U>
        ALG_FUNC_CONSTEXPR U radians(int angdeg)
        {
                return angdeg / (180 / M_PI);
        }

        template<typename U>
        ALG_FUNC_CONSTEXPR U sin(U x)
        {
                return std::sin(x);
        }

        template<typename U>
        ALG_FUNC_CONSTEXPR U cos(U x)
        {
                return std::cos(x);
        }

        template<typename U>
        ALG_FUNC_CONSTEXPR U sqrt(U x)
        {
                return std::sqrt(x);
        }

        template<typename U>
        ALG_FUNC_CONSTEXPR vec<4, U> sqrt(vec<4, U> const& v)
        {
                using namespace std::experimental;

                std::experimental::native_simd<U> data;
                data.copy_from(&v[0], element_aligned);
                auto Result = std::experimental::sqrt(data);

                return vec<4, U>(Result[0], Result[1], Result[2], Result[3]);
        }

}

#endif /* ALG_H_ */