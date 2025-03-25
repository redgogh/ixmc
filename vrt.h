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
#ifndef VRT_H_
#define VRT_H_

#include "vec.h"
// std
#include <cstdio>
#include <cmath>
#include <stdexcept>

#define VRT_INT32   int
#define VRT_FLOAT32 float

namespace vrt {
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
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR int mod(T x, T y);

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
        template<typename T = VRT_FLOAT32>
        T
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR abs(T x);

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
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T pow(T x, T a);

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
        template<typename T = VRT_INT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR int degrees(T angrad);

        ///
        /// @brief 计算二维向量间的角度（度数）
        ///
        /// 计算两个二维向量之间的夹角，返回角度值（0-180度）。
        /// 通过点积公式计算：θ = arccos((v1·v2)/(|v1||v2|))，然后转换为度数。
        ///
        /// @tparam T 向量元素类型（默认为VRT_FLOAT32）
        /// @param v1 第一个二维向量
        /// @param v2 第二个二维向量
        /// @return int 两向量间的夹角度数[0,180]
        ///
        /// @note 特性：
        ///   - 结果总为正数
        ///   - 0度表示两向量同向
        ///   - 180度表示两向量反向
        ///   - 90度表示两向量正交
        ///
        /// @note 应用场景：
        ///  1. 游戏开发中的角色转向计算
        ///  2. 图形学中的法线夹角检测
        ///  3. 物理模拟中的力方向分析
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR int degrees(vec<2, T> const& v1, vec<2, T> const& v2);

        ///
        /// @brief 计算三维向量间的角度（度数）
        ///
        /// 计算两个三维向量之间的夹角，返回角度值（0-180度）。
        /// 通过点积公式计算：θ = arccos((v1·v2)/(|v1||v2|))，然后转换为度数。
        ///
        /// @tparam T 向量元素类型（默认为VRT_FLOAT32）
        /// @param v1 第一个三维向量
        /// @param v2 第二个三维向量
        /// @return int 两向量间的夹角度数[0,180]
        ///
        /// @note 典型应用：
        ///  1. 三维模型的面片夹角计算
        ///  2. 摄像机视角分析
        ///  3. 机械臂关节角度计算
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR int degrees(vec<3, T> const& v1, vec<3, T> const& v2);

        ///
        /// @brief 计算四维向量间的角度（度数） 
        ///
        /// 计算两个四维向量之间的夹角，返回角度值（0-180度）。
        /// 通过点积公式计算：θ = arccos((v1·v2)/(|v1||v2|))，然后转换为度数。
        ///
        /// @tparam T 向量元素类型（默认为VRT_FLOAT32）
        /// @param v1 第一个四维向量
        /// @param v2 第二个四维向量
        /// @return int 两向量间的夹角度数[0,180]
        ///
        /// @note 特殊用途：
        ///  1. 四维空间几何计算
        ///  2. 齐次坐标系下的角度分析
        ///  3. 高维数据相似度测量
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR int degrees(vec<4, T> const& v1, vec<4, T> const& v2);
        
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
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T radians(int angdeg);

        ///
        /// @brief 计算二维向量间的夹角弧度值
        ///
        /// 计算两个二维向量之间的最小夹角，返回弧度值而非度数。
        /// 使用点积公式计算：θ = arccos(dot(v1, v2) / (length(v1) * length(v2)))
        /// 结果范围为[0, π]弧度
        ///
        /// @tparam T 向量元素类型（默认为VRT_FLOAT32）
        /// @param v1 第一个输入向量
        /// @param v2 第二个输入向量 
        /// @return T 两向量间的弧度值，范围[0, π]
        ///
        /// @note 特性：
        ///   - 精确计算向量间最小夹角
        ///   - 返回弧度值而非度数
        ///   - 0表示同向，π表示反向，π/2表示正交
        ///
        /// @note 应用场景：
        ///  1. 物理引擎中的精确角度计算
        ///  2. 图形学着色器中的光照计算
        ///  3. 需要弧度值的数学运算
        ///
        /// @warning
        ///   - 零向量输入将导致未定义行为
        ///   - 对于边界情况建议先归一化向量
        ///
        /// @see degrees(), dot(), length(), normalize()
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T radians(vec<2, T> const& v1, vec<2, T> const& v2);

        ///
        /// @brief 计算三维向量间的夹角弧度值
        ///
        /// 计算两个三维向量之间的最小夹角，返回弧度值。
        /// 使用点积公式计算，结果范围为[0, π]弧度。
        ///
        /// @tparam T 向量元素类型（默认为VRT_FLOAT32）
        /// @param v1 第一个输入向量
        /// @param v2 第二个输入向量
        /// @return T 两向量间的弧度值，范围[0, π] 
        ///
        /// @note 典型应用：
        ///  1. 三维空间中的精确角度测量
        ///  2. 摄像机视野计算
        ///  3. 碰撞检测中的角度判断
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T radians(vec<3, T> const& v1, vec<3, T> const& v2);
        
        ///
        /// @brief 计算四维向量间的夹角弧度值
        ///
        /// 计算两个四维向量之间的最小夹角，返回弧度值。
        /// 使用点积公式计算，结果范围为[0, π]弧度。
        ///
        /// @tparam T 向量元素类型（默认为VRT_FLOAT32）
        /// @param v1 第一个输入向量
        /// @param v2 第二个输入向量
        /// @return T 两向量间的弧度值，范围[0, π]
        ///
        /// @note 特殊用途：
        ///  1. 四维空间几何计算
        ///  2. 齐次坐标系下的精确角度测量
        ///  3. 高维数据分析
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T radians(vec<4, T> const& v1, vec<4, T> const& v2);
        
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
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T sin(T x);

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
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T cos(T x);

        ///
        /// @brief 计算反余弦函数值
        ///
        /// 计算给定值x的反余弦(arccosine)值，返回对应的弧度值。
        /// 反余弦函数是余弦函数的逆运算，返回给定余弦值对应的角度。
        ///
        /// @tparam T 输入输出类型（默认为VRT_TEMPLATE_TYPE_FLOAT32）
        /// @param x 输入值，范围必须在[-1.0, 1.0]之间
        /// @return T 返回对应的弧度值，范围[0, π]
        ///
        /// @note 数学特性：
        ///   - 定义域：x ∈ [-1, 1]
        ///   - 值域：结果 ∈ [0, π] 弧度
        ///   - 单调递减函数
        ///   - 满足 cos(arccos(x)) = x，当x ∈ [-1, 1]
        ///
        /// @note 典型应用场景：
        ///  1. 计算两个向量间的夹角
        ///  2. 解决三角方程
        ///  3. 计算机图形学中的角度计算
        ///  4. 机器人运动学中的关节角度计算
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T arccos(T x);
        
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
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T sqrt(T x);

        ///
        /// @brief 计算 2个 浮点数的平方根。
        ///
        /// sqrt 函数用于计算给定浮点数 `x` 的平方根。
        /// 平方根是数学中的基本运算，常用于几何、物理和工程计算中。
        ///
        /// @param v 输入的浮点数向量（必须为非负数）
        /// @return vec<4, T> 返回 `v` 向量的平方根，结果为非负数。
        ///
        /// @note sqrt 的常见用途：
        ///  1. 计算几何中的距离或长度，如欧几里得距离。
        ///  2. 在物理中计算速度、加速度等。
        ///
        /// @warning 当 `x` 为负数时，结果可能为 NaN（未定义）。
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> sqrt(vec<4, T> const& v);

        ///
        /// @brief 计算 3个浮点数的平方根。
        ///
        /// sqrt 函数用于计算给定浮点数 `x` 的平方根。
        /// 平方根是数学中的基本运算，常用于几何、物理和工程计算中。
        ///
        /// @param v 输入的浮点数向量（必须为非负数）
        /// @return vec<4, T> 返回 `v` 向量的平方根，结果为非负数。
        ///
        /// @note sqrt 的常见用途：
        ///  1. 计算几何中的距离或长度，如欧几里得距离。
        ///  2. 在物理中计算速度、加速度等。
        ///
        /// @warning 当 `x` 为负数时，结果可能为 NaN（未定义）。
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> sqrt(vec<4, T> const& v);
        
        ///
        /// @brief 计算 4个 浮点数的平方根。
        ///
        /// sqrt 函数用于计算给定浮点数 `x` 的平方根。
        /// 平方根是数学中的基本运算，常用于几何、物理和工程计算中。
        ///
        /// @param v 输入的浮点数向量（必须为非负数）
        /// @return vec<4, T> 返回 `v` 向量的平方根，结果为非负数。
        ///
        /// @note sqrt 的常见用途：
        ///  1. 计算几何中的距离或长度，如欧几里得距离。
        ///  2. 在物理中计算速度、加速度等。
        ///
        /// @warning 当 `x` 为负数时，结果可能为 NaN（未定义）。
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> sqrt(vec<4, T> const& v);

        ///
        /// @brief 计算二维向量的规约和
        ///
        /// 对二维向量的所有分量进行求和操作，返回标量结果。
        /// 对于向量 v = (x,y)，计算结果为 x + y。
        ///
        /// @tparam T 向量元素类型（默认为 VRT_FLOAT32）
        /// @param v 输入向量
        /// @return T 返回向量各分量的总和
        ///
        /// @note 典型应用场景：
        ///  1. 计算向量分量总和
        ///  2. 简化向量运算
        ///  3. 作为更复杂运算的中间步骤
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T reduce(vec<2, T> const& v);

        ///
        /// @brief 计算三维向量的规约和 
        ///
        /// 对三维向量的所有分量进行求和操作，返回标量结果。
        /// 对于向量 v = (x,y,z)，计算结果为 x + y + z。
        ///
        /// @tparam T 向量元素类型（默认为 VRT_FLOAT32）
        /// @param v 输入向量
        /// @return T 返回向量各分量的总和
        ///
        /// @note 典型应用场景：
        ///  1. 计算空间坐标总和
        ///  2. 物理模拟中的量值汇总
        ///  3. 图形学中的简化计算
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T reduce(vec<3, T> const& v);

        ///
        /// @brief 计算四维向量的规约和
        ///
        /// 对四维向量的所有分量进行求和操作，返回标量结果。
        /// 对于向量 v = (x,y,z,w)，计算结果为 x + y + z + w。
        ///
        /// @tparam T 向量元素类型（默认为 VRT_FLOAT32）
        /// @param v 输入向量
        /// @return T 返回向量各分量的总和
        ///
        /// @note 典型应用场景：
        ///  1. 齐次坐标计算
        ///  2. 高维数据聚合
        ///  3. 复杂变换的中间计算
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T reduce(vec<4, T> const& v);

        ///
        /// @brief 计算两个二维向量的点积
        ///
        /// 点积（又称内积）用于衡量两个向量的相似程度。
        /// 对于向量 v1 = (x1,y1) 和 v2 = (x2,y2)，点积计算公式为 x1*x2 + y1*y2。
        ///
        /// @tparam T 向量元素类型（默认为 VRT_FLOAT32）
        /// @param v1 第一个输入向量
        /// @param v2 第二个输入向量
        /// @return T 返回两个向量的点积结果
        ///
        /// @note 点积的重要特性：
        ///   - 当向量方向相近时结果为正
        ///   - 当向量方向相反时结果为负
        ///   - 当向量垂直时结果为0
        ///
        /// @note 典型应用场景：
        ///  1. 计算向量间夹角的余弦值（cosθ = (a·b)/(|a||b|)）
        ///  2. 计算向量投影
        ///  3. 判断向量是否正交
        ///  4. 计算向量长度的平方（dot(v,v) = |v|²）
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T dot(vec<2, T> const& v1, vec<2, T> const& v2);

        ///
        /// @brief 计算两个三维向量的点积
        ///
        /// 点积用于衡量两个向量的相似程度。
        /// 对于向量 v1 = (x1,y1,z1) 和 v2 = (x2,y2,z2)，点积计算公式为 x1*x2 + y1*y2 + z1*z2。
        ///
        /// @tparam T 向量元素类型（默认为 VRT_FLOAT32）
        /// @param v1 第一个输入向量
        /// @param v2 第二个输入向量
        /// @return T 返回两个向量的点积结果
        ///
        /// @note 点积的重要特性：
        ///   - 与向量夹角相关（a·b = |a||b|cosθ）
        ///   - 符号表示方向相似性
        ///   - 常用于光照计算（如兰伯特余弦定律）
        ///
        /// @note 典型应用场景：
        ///  1. 图形学中的光照计算
        ///  2. 物理模拟（功、投影等计算）
        ///  3. 碰撞检测
        ///  4. 方向分析
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T dot(vec<3, T> const& v1, vec<3, T> const& v2);

        ///
        /// @brief 计算两个四维向量的点积
        ///
        /// 点积用于衡量两个向量的相似程度。
        /// 对于向量 v1 = (x1,y1,z1,w1) 和 v2 = (x2,y2,z2,w2)，点积计算公式为 x1*x2 + y1*y2 + z1*z2 + w1*w2。
        ///
        /// @tparam T 向量元素类型（默认为 VRT_FLOAT32）
        /// @param v1 第一个输入向量
        /// @param v2 第二个输入向量
        /// @return T 返回两个向量的点积结果
        ///
        /// @note 重要特性：
        ///   - 将三维点积概念扩展到四维空间
        ///   - 适用于齐次坐标计算
        ///   - 在投影几何中非常重要
        ///
        /// @note 典型应用场景：
        ///  1. 齐次坐标计算
        ///  2. 四维几何运算
        ///  3. 高级图形算法
        ///  4. 高维物理/数学计算
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T dot(vec<4, T> const& v1, vec<4, T> const& v2);
        
        /// 
        /// @brief 计算二维向量的长度（模）。
        /// 
        /// length 函数用于计算给定二维向量 `vec` 的长度（模）。
        /// 向量的长度是从原点到向量点的欧几里得距离。
        /// 
        /// 计算公式如下：
        ///   length(vec) = sqrt(vec.x * vec.x + vec.y * vec.y)
        /// 
        /// @param vec 输入的二维向量（vec2 类型）
        /// @return float 返回向量的长度，结果为非负数。
        /// 
        /// @note length 的常见用途：
        ///  1. 在图形学中计算向量的长度，用于光照、反射等计算。
        ///  2. 在物理仿真中计算速度、力的强度等。
        ///  3. 在游戏开发中计算距离或范围。
        /// 
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T length(vec<2, T> const& v);

        /// 
        /// @brief 计算三维向量的长度（模）。
        /// 
        /// length 函数用于计算给定二维向量 `vec` 的长度（模）。
        /// 向量的长度是从原点到向量点的欧几里得距离。
        /// 
        /// 计算公式如下：
        ///   length(vec) = sqrt(vec.x * vec.x + vec.y * vec.y)
        /// 
        /// @param vec 输入的二维向量（vec3 类型）
        /// @return float 返回向量的长度，结果为非负数。
        /// 
        /// @note length 的常见用途：
        ///  1. 在图形学中计算向量的长度，用于光照、反射等计算。
        ///  2. 在物理仿真中计算速度、力的强度等。
        ///  3. 在游戏开发中计算距离或范围。
        /// 
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T length(vec<3, T> const& v);

        /// 
        /// @brief 计算四维向量的长度（模）。
        /// 
        /// length 函数用于计算给定二维向量 `vec` 的长度（模）。
        /// 向量的长度是从原点到向量点的欧几里得距离。
        /// 
        /// 计算公式如下：
        ///   length(vec) = sqrt(vec.x * vec.x + vec.y * vec.y)
        /// 
        /// @param vec 输入的二维向量（vec4 类型）
        /// @return float 返回向量的长度，结果为非负数。
        /// 
        /// @note length 的常见用途：
        ///  1. 在图形学中计算向量的长度，用于光照、反射等计算。
        ///  2. 在物理仿真中计算速度、力的强度等。
        ///  3. 在游戏开发中计算距离或范围。
        /// 
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR T length(vec<4, T> const& v);

        ///
        /// @brief 二维向量归一化
        ///
        /// 将输入的二维向量转换为单位向量（长度为1），保持原方向不变。
        /// 归一化公式为 v' = v / ||v||，其中 ||v|| 为向量的欧几里得范数。
        ///
        /// @tparam T 向量元素类型（默认为 VRT_FLOAT32）
        /// @param v 待归一化的二维向量
        /// @return vec<2, T> 返回归一化后的单位向量
        ///
        /// @note 特性：
        ///   - 结果向量方向与输入向量相同
        ///   - 结果向量长度为1（单位向量）
        ///   - 输入零向量将导致未定义行为
        ///
        /// @note 典型应用场景：
        ///  1. 图形学中的法线向量处理
        ///  2. 物理引擎中的方向向量标准化
        ///  3. 游戏开发中的移动方向处理
        ///  4. 机器学习中的特征向量归一化
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<2, T> normalize(vec<2, T> const& v);
        
        ///
        /// @brief 归一化三维向量。
        ///
        /// 将输入的三维向量 `v` 转换为单位向量（长度为1），保持原方向不变。
        /// 归一化操作常用于方向向量的标准化处理。
        ///
        /// @tparam T 浮点数类型，默认为 VRT_FLOAT32
        /// @param v 输入的三维向量
        /// @return vec<3, T> 返回归一化后的单位向量
        ///
        /// @note 使用场景：
        ///  1. 光照计算中的法线向量处理
        ///  2. 物理引擎中的方向向量标准化
        ///  3. 相机和视角控制
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<3, T> normalize(vec<3, T> const& v);

        ///
        /// @brief 归一化四维向量。
        ///
        /// 将输入的四维向量 `v` 转换为单位向量（长度为1），保持原方向不变。
        /// 适用于齐次坐标或四元数的归一化处理。
        ///
        /// @tparam T 浮点数类型，默认为 VRT_FLOAT32
        /// @param v 输入的四维向量
        /// @return vec<4, T> 返回归一化后的单位向量
        ///
        /// @note 使用场景：
        ///  1. 四元数旋转的标准化
        ///  2. 齐次坐标系的规范化
        ///  3. 投影空间计算
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR vec<4, T> normalize(vec<4, T> const& v);

        ///
        /// @brief 创建平移变换矩阵。
        ///
        /// 在现有4x4变换矩阵 `m` 基础上，应用由三维向量 `v` 指定的平移变换。
        /// 返回新的变换矩阵，保持原矩阵的其他变换不变。
        ///
        /// @tparam T 浮点数类型，默认为 VRT_FLOAT32
        /// @param m 输入的4x4变换矩阵
        /// @param v 平移向量(x,y,z分量分别对应各轴平移量)
        /// @return mat<4, T> 返回应用平移后的新变换矩阵
        ///
        /// @note 使用场景：
        ///  1. 3D物体位置变换
        ///  2. 相机视图矩阵构造
        ///  3. 场景图节点变换
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T> translate(mat<4, T> const& m, vec<3, T> const& v);

        ///
        /// @brief 创建缩放变换矩阵。
        ///
        /// 在现有4x4变换矩阵 `m` 基础上，应用由三维向量 `v` 指定的缩放变换。
        /// 返回新的变换矩阵，保持原矩阵的其他变换不变。
        ///
        /// @tparam T 浮点数类型，默认为 VRT_FLOAT32
        /// @param m 输入的4x4变换矩阵
        /// @param v 缩放向量(x,y,z分量分别对应各轴缩放比例)
        /// @return mat<4, T> 返回应用缩放后的新变换矩阵
        ///
        /// @note 使用场景：
        ///  1. 3D物体大小变换
        ///  2. 非均匀缩放效果实现
        ///  3. 模型空间变换
        ///
        template<typename T = VRT_FLOAT32>
        VRT_FUNC_DECL VRT_FUNC_CONSTEXPR mat<4, T> scale(mat<4, T> const& m, vec<3, T> const& v);

        // -- implements --

        template<typename T>
        VRT_FUNC_CONSTEXPR int mod(T x, T y) {
                if (y == 0)
                        return 0;
                return x - ((int) (x / y)) * y;
        }

        template<typename T>
        T
        VRT_FUNC_CONSTEXPR abs(T x) {
                return x < 0 ? -x : x;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T pow(T x, T a) {
                return std::pow(x, a);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR int degrees(T angrad)
        {
                return angrad / (M_PI / 180);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR int degrees(vec<2, T> const& v1, vec<2, T> const& v2)
        {
                return degrees(radians(v1, v2));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR int degrees(vec<3, T> const& v1, vec<3, T> const& v2)
        {
                return degrees(radians(v1, v2));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR int degrees(vec<4, T> const& v1, vec<4, T> const& v2)
        {
                return degrees(radians(v1, v2));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T radians(int angdeg)
        {
                return angdeg / (180 / M_PI);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T radians(vec<2, T> const& v1, vec<2, T> const& v2)
        {
                return arccos(dot(v1, v2) / (length(v1) * length(v2)));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T radians(vec<3, T> const& v1, vec<3, T> const& v2)
        {
                return arccos(dot(v1, v2) / (length(v1) * length(v2)));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T radians(vec<4, T> const& v1, vec<4, T> const& v2)
        {
                return arccos(dot(v1, v2) / (length(v1) * length(v2)));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T sin(T x)
        {
                return std::sin(x);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T cos(T x)
        {
                return std::cos(x);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T arccos(T x)
        {
                return std::acos(x);
        }
        
        template<typename T>
        VRT_FUNC_CONSTEXPR T sqrt(T x)
        {
                return std::sqrt(x);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> sqrt(vec<2, T> const& v)
        {
                using namespace std::experimental;

                std::experimental::native_simd<T> data;
                data.copy_from(&v[0], element_aligned);
                auto Result = std::experimental::sqrt(data);

                return vec<2, T>(Result[0], Result[1]);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> sqrt(vec<3, T> const& v)
        {
                using namespace std::experimental;

                std::experimental::native_simd<T> data;
                data.copy_from(&v[0], element_aligned);
                auto Result = std::experimental::sqrt(data);

                return vec<3, T>(Result[0], Result[1], Result[2]);
        }
        
        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> sqrt(vec<4, T> const& v)
        {
                using namespace std::experimental;

                std::experimental::native_simd<T> data;
                data.copy_from(&v[0], element_aligned);
                auto Result = std::experimental::sqrt(data);

                return vec<4, T>(Result[0], Result[1], Result[2], Result[3]);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T reduce(vec<2, T> const& v)
        {
                return (v.x + v.y);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T reduce(vec<3, T> const& v)
        {
                return (v.x + v.y + v.z);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T reduce(vec<4, T> const& v)
        {
                return (v.x + v.y + v.z + v.w);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T dot(vec<2, T> const& v1, vec<2, T> const& v2)
        {
                return reduce(v1 * v2);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T dot(vec<3, T> const& v1, vec<3, T> const& v2)
        {
                return reduce(v1 * v2);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T dot(vec<4, T> const& v1, vec<4, T> const& v2)
        {
                return reduce(v1 * v2);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T length(vec<2, T> const& v)
        {
                return sqrt(reduce(v * v));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T length(vec<3, T> const& v)
        {
                return sqrt(reduce(v * v));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR T length(vec<4, T> const& v)
        {
                return sqrt(reduce(v * v));
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<2, T> normalize(vec<2, T> const& v)
        {
                return v / length(v);
        }
        
        template<typename T>
        VRT_FUNC_CONSTEXPR vec<3, T> normalize(vec<3, T> const& v)
        {
                return v / length(v);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR vec<4, T> normalize(vec<4, T> const& v)
        {
                return v / length(v);
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR mat<4, T> translate(mat<4, T> const& m, vec<3, T> const& v)
        {
                mat<4, T> t(1.0f);

                t[3][0] = v[0];
                t[3][1] = v[1];
                t[3][2] = v[2];
                
                return m * t;
        }

        template<typename T>
        VRT_FUNC_CONSTEXPR mat<4, T> scale(mat<4, T> const& m, vec<3, T> const& v)
        {
                mat<4, T> t(1.0f);

                t[0][0] = v[0];
                t[1][1] = v[1];
                t[2][2] = v[2];

                return m * t;
        }
        
}

#endif /* VRT_H_ */