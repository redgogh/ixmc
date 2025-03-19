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
#ifndef IXMC_H_
#define IXMC_H_

#include "_ixmc_vec.h"

#define PI      (3.14159265358979323846F)

namespace ixmc {

/**
 * @brief 计算 x 除以 y 的浮点数取模（余数）。
 *
 * fmod 计算的是 x 除以 y 后的余数，结果与 x 具有相同的符号.
 * 
 * 计算公式如下：
 *   fmod(x, y) = x - n * y，其中 n = trunc(x / y)（n 为整数部分）。
 *
 * @param x 被除数（浮点数）
 * @param y 除数（浮点数，不能为 0）
 * @return float 返回 x 除以 y 的余数，满足 0 ≤ |余数| < |y|
 *
 * @note fmod 的常见用途：
 *  1. 角度归一化：fmod(angle, 360.0f) 让角度保持在 [0, 360) 之间。
 *  2. 处理周期性计算，如波形生成、动画循环等。
 *  3. 保留小数部分，例如 fmod(5.75, 1.0) 结果为 0.75。
 */
float fmod (float x, float y);

/**
 * @brief 计算浮点数的绝对值。
 *
 * abs 函数用于计算给定浮点数 `a` 的绝对值。绝对值是指一个数在数轴上到原点的距离，
 * 因此无论 `a` 是正数还是负数，其绝对值总是非负的。
 *
 * 计算公式如下：
 *   abs(a) = |a|
 *
 * @param a 输入的浮点数
 * @return float 返回 `a` 的绝对值，结果总是非负的。
 *
 * @note abs 的常见用途：
 *  1. 计算距离或差值时，确保结果为非负数。
 *  2. 在需要忽略符号的场合，如计算误差、比较大小等。
 *  3. 在数学运算中，确保某些值始终为正数，例如向量的模长计算。
 */
float abs(float a);

/**
 * @brief 计算浮点数 `x` 的整数次幂。
 *
 * pow 函数用于计算浮点数 `x` 的 `a` 次幂，其中 `a` 是一个整数。
 * 该函数通过连续乘法实现幂运算，适用于需要高效计算整数次幂的场景。
 *
 * 计算公式如下：
 *   pow(x, a) = x^a
 *
 * @param x 底数（浮点数）
 * @param a 指数（整数）
 * @return float 返回 `x` 的 `a` 次幂结果。
 *
 * @note pow 的常见用途：
 *  1. 计算几何增长或衰减，如复利计算、物理中的指数衰减等。
 *  2. 在图形学中计算光照衰减、颜色混合等。
 *  3. 在数学运算中，快速计算幂次结果。
 *
 * @warning 当 `x` 为负数且 `a` 为非整数时，结果可能为 NaN（未定义）。
 *          当 `x` 为 0 且 `a` 为负数时，结果可能为无穷大（inf）。
 */
float pow(float x, int a);

/**
 * @brief 将弧度值转换为角度值。
 *
 * degrees 函数用于将给定的弧度值 `angrad` 转换为对应的角度值。
 * 转换公式基于圆周的弧度与角度关系：180 度 = π 弧度。
 *
 * 计算公式如下：
 *   degrees(angrad) = angrad * (180 / π)
 *
 * @param angrad 输入的弧度值（浮点数）
 * @return int 返回转换后的角度值，结果为整数。
 *
 * @note degrees 的常见用途：
 *  1. 在图形学中将弧度转换为角度，便于理解和计算。
 *  2. 在物理仿真中处理角度相关的计算。
 *  3. 在游戏开发中处理角色的旋转和方向。
 */
int degrees(float angrad);

/**
 * @brief 将角度值转换为弧度值。
 *
 * radians 函数用于将给定的角度值 `angdeg` 转换为对应的弧度值。
 * 转换公式基于圆周的弧度与角度关系：180 度 = π 弧度。
 *
 * 计算公式如下：
 *   radians(angdeg) = angdeg * (π / 180)
 *
 * @param angdeg 输入的角度值（整数）
 * @return float 返回转换后的弧度值，结果为浮点数。
 *
 * @note radians 的常见用途：
 *  1. 在数学计算中将角度转换为弧度，便于使用三角函数。
 *  2. 在物理仿真中处理弧度相关的计算。
 *  3. 在游戏开发中处理角色的旋转和方向。
 */
float radians(int angdeg);

/**
 * @brief 计算浮点数的正弦值。
 *
 * sin 函数用于计算给定浮点数 `x`（以弧度为单位）的正弦值。
 * 正弦函数是三角函数之一，常用于描述周期性现象，如波形、振动等。
 *
 * @param x 输入的弧度值（浮点数）
 * @return float 返回 `x` 的正弦值，范围在 [-1, 1] 之间。
 *
 * @note sin 的常见用途：
 *  1. 在图形学中生成波形或处理旋转。
 *  2. 在物理仿真中模拟周期性运动，如弹簧振动。
 *  3. 在信号处理中分析周期性信号。
 */
float sin(float x);

/**
 * @brief 计算浮点数的余弦值。
 *
 * cos 函数用于计算给定浮点数 `x`（以弧度为单位）的余弦值。
 * 余弦函数是三角函数之一，常用于描述周期性现象，如波形、振动等。
 *
 * @param x 输入的弧度值（浮点数）
 * @return float 返回 `x` 的余弦值，范围在 [-1, 1] 之间。
 *
 * @note cos 的常见用途：
 *  1. 在图形学中生成波形或处理旋转。
 *  2. 在物理仿真中模拟周期性运动，如弹簧振动。
 *  3. 在信号处理中分析周期性信号。
 */
float cos(float x);

/**
 * @brief 计算浮点数的平方根。
 *
 * sqrt 函数用于计算给定浮点数 `x` 的平方根。
 * 平方根是数学中的基本运算，常用于几何、物理和工程计算中。
 *
 * @param x 输入的浮点数（必须为非负数）
 * @return float 返回 `x` 的平方根，结果为非负数。
 *
 * @note sqrt 的常见用途：
 *  1. 计算几何中的距离或长度，如欧几里得距离。
 *  2. 在物理中计算速度、加速度等。
 *
 * @warning 当 `x` 为负数时，结果可能为 NaN（未定义）。
 */
float sqrt(float x);

/**
 * @brief 计算二维向量的长度（模）。
 *
 * length 函数用于计算给定二维向量 `vec` 的长度（模）。
 * 向量的长度是从原点到向量点的欧几里得距离。
 *
 * 计算公式如下：
 *   length(vec) = sqrt(vec.x * vec.x + vec.y * vec.y)
 *
 * @param vec 输入的二维向量（vec2 类型）
 * @return float 返回向量的长度，结果为非负数。
 *
 * @note length 的常见用途：
 *  1. 在图形学中计算向量的长度，用于光照、反射等计算。
 *  2. 在物理仿真中计算速度、力的强度等。
 *  3. 在游戏开发中计算距离或范围。
 */
float length(const vec2 &vec);

/**
 * @brief 计算三维向量的长度（模）。
 *
 * length 函数用于计算给定三维向量 `vec` 的长度（模）。
 * 向量的长度是从原点到向量点的欧几里得距离。
 *
 * 计算公式如下：
 *   length(vec) = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z)
 *
 * @param vec 输入的三维向量（vec3 类型）
 * @return float 返回向量的长度，结果为非负数。
 *
 * @note length 的常见用途：
 *  1. 在图形学中计算向量的长度，用于光照、反射等计算。
 *  2. 在物理仿真中计算速度、力的强度等。
 *  3. 在游戏开发中计算距离或范围。
 */
float length(const vec3 &vec);

/**
 * @brief 计算四维向量的长度（模）。
 *
 * length 函数用于计算给定四维向量 `vec` 的长度（模）。
 * 向量的长度是从原点到向量点的欧几里得距离。
 *
 * 计算公式如下：
 *   length(vec) = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w)
 *
 * @param vec 输入的四维向量（vec4 类型）
 * @return float 返回向量的长度，结果为非负数。
 *
 * @note length 的常见用途：
 *  1. 在图形学中计算向量的长度，用于光照、反射等计算。
 *  2. 在物理仿真中计算速度、力的强度等。
 *  3. 在游戏开发中计算距离或范围。
 */
float length(const vec4 &vec);

/**
 * @brief 计算两个二维向量的点积（内积）。
 *
 * 点积（dot product）是两个向量相乘的一种方式，
 * 其结果是一个标量，表示向量的相似程度或投影关系。
 * 
 * 计算公式：
 * dot(a, b) = (a.x * b.x + a.y * b.y)
 *
 * @param a 第一个二维向量
 * @param b 第二个二维向量
 * @return float 返回两个向量的点积结果
 *
 * @note 点积的结果可以用于：
 *  1. 判断两个向量的夹角：
 *     - 结果为正，表示夹角小于 90°（同向）。
 *     - 结果为零，表示夹角等于 90°（正交）。
 *     - 结果为负，表示夹角大于 90°（反向）。
 *  2. 计算投影：b 在 a 方向上的投影长度为 dot(a, b) / |a|。
 */
float dot(const vec2 &a, const vec2 &b);

/**
 * @brief 计算两个三维向量的点积（内积）。
 *
 * 点积（dot product）是两个向量相乘的一种方式，
 * 其结果是一个标量，表示向量的相似程度或投影关系。
 * 
 * 计算公式：
 * dot(a, b) = (a.x * b.x + a.y * b.y + a.z * b.z)
 *
 * @param a 第一个三维向量
 * @param b 第二个三维向量
 * @return float 返回两个向量的点积结果
 *
 * @note 点积的结果可以用于：
 *  1. 判断两个向量的夹角：
 *     - 结果为正，表示夹角小于 90°（同向）。
 *     - 结果为零，表示夹角等于 90°（正交）。
 *     - 结果为负，表示夹角大于 90°（反向）。
 *  2. 计算投影：b 在 a 方向上的投影长度为 dot(a, b) / |a|。
 */
float dot(const vec3 &a, const vec3 &b);

/**
 * @brief 计算两个四维向量的点积（内积）。
 *
 * 点积（dot product）是两个向量相乘的一种方式，
 * 其结果是一个标量，表示向量的相似程度或投影关系。
 * 
 * 计算公式：
 * dot(a, b) = (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w)
 *
 * @param a 第一个四维向量
 * @param b 第二个四维向量
 * @return float 返回两个向量的点积结果
 *
 * @note 点积的结果可以用于：
 *  1. 判断两个向量的夹角：
 *     - 结果为正，表示夹角小于 90°（同向）。
 *     - 结果为零，表示夹角等于 90°（正交）。
 *     - 结果为负，表示夹角大于 90°（反向）。
 *  2. 计算投影：b 在 a 方向上的投影长度为 dot(a, b) / |a|。
 */
float dot(const vec4 &a, const vec4 &b);

/**
 * @brief 计算两个二维向量的叉积。
 *
 * cross 函数用于计算两个二维向量 `a` 和 `b` 的叉积。
 * 二维向量的叉积结果是一个标量，表示两个向量形成的平行四边形的有符号面积。
 *
 * 计算公式如下：
 *   cross(a, b) = a.x * b.y - a.y * b.x
 *
 * @param a 第一个二维向量（vec2 类型）
 * @param b 第二个二维向量（vec2 类型）
 * @return float 返回两个向量的叉积结果（标量）。
 *
 * @note cross 的常见用途：
 *  1. 判断两个向量的相对方向（顺时针或逆时针）。
 *  2. 计算多边形的面积。
 *  3. 在图形学中用于背面剔除和法线计算。
 */
float cross(const vec2 &a, const vec2 &b);

/**
 * @brief 计算两个三维向量的叉积。
 *
 * cross 函数用于计算两个三维向量 `a` 和 `b` 的叉积。
 * 三维向量的叉积结果是一个新的向量，垂直于输入向量的平面。
 *
 * 计算公式如下：
 *   cross(a, b) = (a.y * b.z - a.z * b.y,
 *                  a.z * b.x - a.x * b.z,
 *                  a.x * b.y - a.y * b.x)
 *
 * @param a 第一个三维向量（vec3 类型）
 * @param b 第二个三维向量（vec3 类型）
 * @return vec3 返回两个向量的叉积结果（向量）。
 *
 * @note cross 的常见用途：
 *  1. 计算法线向量，用于光照和反射计算。
 *  2. 在物理仿真中计算扭矩或角动量。
 *  3. 在图形学中用于确定方向或生成正交基。
 */
vec3 cross(const vec3 &a, const vec3 &b);

/**
 * @brief 对三维向量进行归一化。
 *
 * normalize 函数用于将给定的三维向量 `vec` 归一化，即将向量的长度缩放到 1，
 * 同时保持其方向不变。归一化后的向量称为单位向量。
 *
 * 计算公式如下：
 *   normalize(vec) = vec / length(vec)
 *
 * @param vec 输入的三维向量（vec3 类型）
 * @return vec3 返回归一化后的单位向量。
 *
 * @note normalize 的常见用途：
 *  1. 在图形学中处理方向向量，如光照方向、视线方向等。
 *  2. 在物理仿真中规范化力的方向或速度方向。
 *  3. 在游戏开发中处理角色的移动方向或相机的朝向。
 *
 * @warning 当输入向量的长度接近 0 时，结果可能为未定义（NaN 或无穷大）。
 */
vec3 normalize(const vec3 &vec);

/**
 * @brief 对 4x4 矩阵应用旋转变换。
 *
 * rotate 函数用于对给定的 4x4 矩阵 `matrix` 应用旋转变换。
 * 旋转的角度由 `angrad` 指定（以弧度为单位），旋转轴由 `vec` 指定。
 *
 * 计算公式如下：
 *   rotate(matrix, angrad, vec) = matrix * rotation_matrix(angrad, vec)
 *
 * @param matrix 输入的 4x4 矩阵（mat4 类型）
 * @param angrad 旋转角度（以弧度为单位，浮点数）
 * @param vec 旋转轴（三维向量，vec3 类型）
 * @return mat4 返回应用旋转变换后的新矩阵。
 *
 * @note rotate 的常见用途：
 *  1. 在图形学中旋转物体或相机。
 *  2. 在物理仿真中模拟旋转运动。
 *  3. 在游戏开发中处理角色的旋转或视角变换。
 */
mat4 rotate(const mat4 &matrix, float angrad, const vec3 &vec);

/**
 * @brief 对 4x4 矩阵应用平移变换。
 *
 * translate 函数用于对给定的 4x4 矩阵 `matrix` 应用平移变换。
 * 平移的距离由 `vec` 指定。
 *
 * 计算公式如下：
 *   translate(matrix, vec) = matrix * translation_matrix(vec)
 *
 * @param matrix 输入的 4x4 矩阵（mat4 类型）
 * @param vec 平移向量（三维向量，vec3 类型）
 * @return mat4 返回应用平移变换后的新矩阵。
 *
 * @note translate 的常见用途：
 *  1. 在图形学中移动物体或相机。
 *  2. 在物理仿真中模拟位移运动。
 *  3. 在游戏开发中处理角色的移动或场景布局。
 */
mat4 translate(const mat4 &matrix, const vec3 &vec);

/**
 * @brief 对 4x4 矩阵应用缩放变换。
 *
 * scale 函数用于对给定的 4x4 矩阵 `matrix` 应用缩放变换。
 * 缩放的因子由 `vec` 指定，分别对应 x、y、z 轴。
 *
 * 计算公式如下：
 *   scale(matrix, vec) = matrix * scaling_matrix(vec)
 *
 * @param matrix 输入的 4x4 矩阵（mat4 类型）
 * @param vec 缩放因子（三维向量，vec3 类型）
 * @return mat4 返回应用缩放变换后的新矩阵。
 *
 * @note scale 的常见用途：
 *  1. 在图形学中缩放物体或调整场景比例。
 *  2. 在物理仿真中模拟尺寸变化。
 *  3. 在游戏开发中处理物体的缩放或动画效果。
 */
mat4 scale(const mat4 &matrix, const vec3 &vec);

} /* namespace ixmc */

#include "_ixmc.inl"

#endif /* IXMC_H_ */
