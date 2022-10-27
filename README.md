# FastMath

数学库 FastMath 是一个 one-header only 的库。  

想要使用，只需 `include "FastMath.h"` 即可，所有函数均被封装在 `namespace fm` 中，例如 `fm::sin(x)` 。

提供了用精度换取速度的服务，目前支持 `fm::ESpeedNormal` 和
`fm::ESpeedFast` 两档，想要调控精度，可以：

* 在构建阶段通过定义宏 `FM_SPEED_DEFAULT` 配置默认值：如在CMake中 `add_definitions(-DFM_SPEED_DEFAULT=ESpeedNormal)`。注：若未定义宏`FM_SPEED_DEFAULT`，则会默认取值`ESpeedNormal`。
* 在使用时显式指明：即例如 `fm::sin(x,fm::ESpeedFast)` 未显式指明的均默认取值 `FM_SPEED_DEFAULT`

项目目录文件说明：

`FastMath.h` ：one-header only 数学库

`DiscardedImpl.h` ：保存所有曾找到的“优化实现”，这些实现均由于测试结果发现O3下没有优化效果而被废弃，但由于不排除其他测试环境下可能有用，也为了记录测过哪些实现，将他们保留在此文件。

`TestMain.cpp` ：是用以测试 `FastMath.h` 速度的测试框架