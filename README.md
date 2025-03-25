# VRT 图形数学库

针对图形学中所需要用到的三角函数、线性代数等数学、模拟计算所提供的数学基础库。

**示例**

计算两个向量之间的夹角（弧度）
```c++
#include <vrt.h>

int main()
{
        vrt::vec3 v1(0, 1);
        vrt::vec3 v2(1, 0);
        
        float a = vrt::angle(v1, v2);
        
        ......
}
```

计算公式：

$$
\theta = \arccos \left( \frac{\alpha \cdot \upsilon}{{\lVert\alpha\rVert}{\lVert\upsilon\rVert}} \right)
$$

通过反余弦函数得弧度后转角度得到结果为：**90°**，代码演示：

```c++
#include <vrt.h>

int main()
{
        ......
        
        float a = vrt::angle(v1, v2);
        
        std::cout << vrt::degress(a) << std::endl;
}
```

弧度转角度公式：

$$
\theta = \frac{\text{弧度}}{\pi / 180}
$$