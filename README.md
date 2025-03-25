# VRT 图形数学库

针对图形学中所需要用到的三角函数、线性代数等数学、模拟计算所提供的数学基础库。

# 示例

```c++
#include <vrt.h>

int main()
{
        vrt::vec3 v1(0,  1);
        vrt::vec3 v2(0, -1);
        
        std::cout << vrt::angle(v1, v2) << std::endl;
}
```

结果: $\cos \theta$ = 0，计算公式：

$$
\cos \theta = \frac{\alpha \cdot \upsilon}{{\lVert\alpha\rVert}{\lVert\upsilon\rVert}}
$$

通过反余弦函数得弧度后转角度得到结果为： **90°**
