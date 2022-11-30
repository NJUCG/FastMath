# FastMath & VecMat

目前 FastMath 与 VecMat 之间互不依赖。
最低标准版本要求: c++17

## FastMath
数学库 FastMath 是一个 one-header only 的库。  

想要使用，只需 `include "FastMath.h"` 即可，所有函数均被封装在 `namespace fm` 中，例如 `fm::sin(x)` 。

暂时仅支持double和float，其他类型（如int）请调用时自行按需类型转换。

提供了用精度换取速度的服务，目前支持如下档位：
```cpp
namespace fm{
    enum speed_option{
        ESpeedStd=0, //直接调用std
        ESpeedNormal=1, //保证float最后一位级别精度
        ESpeedFast1=2, //保证所有输入min(绝对误差,相对误差)不超过1e-4，不保证nan,inf的特殊处理
        ESpeedFast2=3, //保证所有输入min(绝对误差,相对误差)不超过2e-3，不保证nan,inf的特殊处理        
        ESpeedFast3=4, //保证所有输入min(绝对误差,相对误差)不超过4e-2，不保证nan,inf的特殊处理
    };
}
```
想要调控精度，可以：

* 在构建阶段通过定义宏 `FM_SPEED_DEFAULT` 配置默认值：如在CMake中 `add_definitions(-DFM_SPEED_DEFAULT=ESpeedNormal)`。注：若未定义宏`FM_SPEED_DEFAULT`，则会默认取值`ESpeedNormal`。
* 在使用时显式指明：即例如 `fm::sin(x,fm::ESpeedFast1)` 未显式指明的均默认取值 `FM_SPEED_DEFAULT`

项目目录文件说明：

`FastMath.h` ：one-header only 数学库

`DiscardedImpl.h` ：保存所有曾找到的“优化实现”，这些实现均由于测试结果发现O3下没有优化效果而被废弃，但由于不排除其他测试环境下可能有用，也为了记录测过哪些实现，将他们保留在此文件。

`TestMain.cpp` ：是用以测试 `FastMath.h` 速度的测试框架

## VecMat
数学库 VecMat 是一个 one-header only 的库。  

想要使用，只需 `include "VecMat.h"` 即可（但是需要保证文件`VecMatMult.inl.h`处在`VecMatMult.h`的同目录下），所有实现均被封装在 `namespace vecmat` 中，例如4维float向量 `vecmat::vec<4,float>` 。

#### API Referance

##### 模板类`vecmat::vec<N,T>`封装一个N维类型为T的向量
对于234维和常见类型int/long long/float/double等，可缩写为`vecmat::vec2f vecmat::vec2ll vecmat::vec3i vecmat::vec4d`等

提供：

重载运算符[]

重载运算符+,-,+=,-= (vec,vec) （逐位加减）

重载运算符*,/,*=,/= (vec,T)  （与标量乘除）

基本的构造函数

为防止混淆，运算符*(vec vec)没有重载，点乘请使用成员函数`A.dot(vec B)`或者函数`vecmat::dot(vec A,vec B)`，逐位相乘请使用``A.cwiseMult(vec B)`，逐位相除请使用`A.cwiseDiv(vec B)`

`A.len()` 返回A的欧式长度

`A.distance(vec B)``vecmat::distance(vec A,vec B)` 返回AB的欧式距离

`A.clear()` 将A清0

`A.debug_print(char ed='\n')` 打印A，末尾为ed

`static vecmat::vec<N,T>::zero();` 获取一个N维类型为T的0向量

`static vecmat::vec<N,T>::fill(T x);` 获取一个N维类型为T的全x向量

`A.x() A.y() A.z() A.w()` 访问`A[0] A[1] A[2] A[3]`，总体更建议用[]方式访问

##### 模板类`vecmat::mat<N,M,T>`封装一个N行M列类型为T的向量
对于234维和常见类型int/long long/float/double等，可缩写为`vecmat::mat22f vecmat::mat23ll vecmat::mat33i vecmat::mat44d`等

提供：

重载运算符[] （这里`A[i]`表示第i个行向量，`A[i][j]`表示第i行第j列的元素）

重载运算符+,-,+=,-= (mat,mat) （逐位加减）

重载运算符*,/,*=,/= (mat,T)  （与标量乘除）

重载运算符* (mat,mat) （矩阵乘法）注：目前对N>4的矩阵乘法并未做优化

重载运算符* (mat,vec) （矩阵乘向量，这里的向量被看作是列向量）

基本的构造函数

`A.dot(mat B)`或者函数`vecmat::dot(mat A,mat B)` 点乘

`A.norm2()` 计算A的二范数

`A.clear()` 将A清0

`A.transpose()` 返回A的转置

`A.determinant()` 返回A的行列式，目前仅支持N<=4

`A.inverse()` 返回A的逆矩阵，目前仅支持N<=4

`A.debug_print()` 打印A

`static vecmat::mat<N,M,T>::zero();` 获取一个N行M列类型为T的0向量

`static vecmat::mat<N,M,T>::identity();` 获取一个N行M列（M必须等于N）类型为T的单位向量

`static vecmat::mat<N,M,T>::scalar(T x);` 获取一个N行M列（M必须等于N）类型为T的对角值全为x的标量矩阵

`static vecmat::mat<N,M,T>::diag(std::vec<N,T> li);` 获取一个N行M列（M必须等于N）类型为T的对角值按序为li中值的对角矩阵

##### 其他
重载运算符==,!= (vec,vec) (mat,mat)  不考虑精度，表示严格相等/不等

`vecmat::equal(vec a,vec b,T eps)``vecmat::inequal(vec a,vec b,T eps)``vecmat::equal(mat a,mat b,T eps)``vecmat::inequal(mat a,mat b,T eps)` 考虑容许（绝对）精度误差eps情况下的相等/不等

`vecmat::cross(vec<3,T> A,vec<3,T> B)` 三维向量的叉乘

#### 项目目录文件说明

`VecMat.h` ：one-header only 向量矩阵库

`VecMatMult.inl.h` ：仅用于VecMat.h中 `#include`，提供N,M,K较小(<=4)时矩阵乘法的特化实现(M,K,N各四种取值，共64种)

`VecMatTestMain.cpp` ：是用以测试 `VecMat.h` 速度的测试程序

`testdep/*`：Eigen库，用于测试