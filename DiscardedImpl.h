// 保存所有曾找到的“优化实现”，
// 这些实现均由于测试结果发现O3下没有优化效果而被废弃，
// 但由于不排除其他测试环境下可能有用，也为了记录测过哪些实现，将他们保留在此文件。


#pragma once

#include <cmath>
#include <stdint.h>
#include <bits/stdc++.h>

namespace fm{

    const double one=1.0, tiny=1.0e-300;
    typedef union 
    {
        double value;
        struct 
        {
            __uint32_t lsw;
            __uint32_t msw;
        } parts;
    } ieee_double_shape_type;

    const float  hpi_f = 1.5707963267948966192313f;
    const double hpi_d = 1.5707963267948966192313;
    const float  pi_f  = 3.1415926535897932384626f;
    const double pi_d  = 3.1415926535897932384626;
    const float  tpi_f = 6.2831853071795864769252f;
    const float  tpi_d = 6.2831853071795864769252;

    #ifndef FM_SPEED_DEFAULT
        #define FM_SPEED_DEFAULT ESpeedNormal
    #endif

    enum speed_option{
        ESpeedStd=0, //直接调用std
        ESpeedNormal=1, //保证float最后一位级别精度
        ESpeedFast=2, //保证最大min(绝对误差,相对误差)不超过1e-4，不保证nan,inf的特殊处理
        ESpeedVeryFast=3, //保证最大min(绝对误差,相对误差)不超过1e-2
    };

    inline float sqrt(float x, speed_option speed=FM_SPEED_DEFAULT){
        if(speed==ESpeedNormal){
            return std::sqrt(x);
        }
        else{        
            //经过测试，速度与标准库一致但精度差
            float xhalf = 0.5f*x;
            int32_t i = *(int32_t*)&x;
            i = 0x5f3759df - (i >> 1);        
            x = *(float*)&i;
            x = x*(1.5f - xhalf*x*x);      
            return 1/x;

            //经过测试，速度不如标准库
            union{
                    int32_t intPart;
                    float floatPart;
            } convertor;
            union{
                    int32_t intPart;
                    float floatPart;
            } convertor2;
            convertor.floatPart = x;
            convertor2.floatPart = x;
            convertor.intPart = 0x1FBCF800 + (convertor.intPart >> 1);
            convertor2.intPart = 0x5f375a86 - (convertor2.intPart >> 1);
            return 0.5f*(convertor.floatPart + (x * convertor2.floatPart));
        }
    }

    
    inline double sqrt(double x, speed_option speed=FM_SPEED_DEFAULT){
        if(speed==ESpeedNormal){
            return std::sqrt(x);
        }
        else{        
            
            //经过测试，速度与标准库一致但精度差
            double xhalf = 0.5*x;
            uint64_t i = *(uint64_t*)&x;
            i = 0x5fe6ec85e7de30da - (i >> 1);        
            x = *(double*)&i;
            x = x*(1.5 - xhalf*x*x);      
            return 1/x;




            //经过测试，速度不如标准库
            // #define EXTRACT_WORDS(ix0,ix1,d)				\
            // do {								\
            // ieee_double_shape_type ew_u;					\
            // ew_u.value = (d);						\
            // (ix0) = ew_u.parts.msw;					\
            // (ix1) = ew_u.parts.lsw;					\
            // } while (0)
            // #define INSERT_WORDS(d,ix0,ix1)					\
            // do {								\
            // ieee_double_shape_type iw_u;					\
            // iw_u.parts.msw = (ix0);					\
            // iw_u.parts.lsw = (ix1);					\
            // (d) = iw_u.value;						\
            // } while (0)


            // double z;
            // __int32_t sign = 0x80000000; 
            // __uint32_t r,t1,s1,ix1,q1;
            // __int32_t ix0,s0,q,m,t,i;

            // EXTRACT_WORDS(ix0,ix1,x);

            // /* take care of Inf and NaN */
            // if((ix0&0x7ff00000)==0x7ff00000) {			
            //     return x*x+x;		/* sqrt(NaN)=NaN, sqrt(+inf)=+inf
            //                 sqrt(-inf)=sNaN */
            // } 
            // /* take care of zero */
            // if(ix0<=0) {
            //     if(((ix0&(~sign))|ix1)==0) return x;/* sqrt(+-0) = +-0 */
            //     else if(ix0<0)
            //     return (x-x)/(x-x);		/* sqrt(-ve) = sNaN */
            // }
            // /* normalize x */
            // m = (ix0>>20);
            // if(m==0) {				/* subnormal x */
            //     while(ix0==0) {
            //     m -= 21;
            //     ix0 |= (ix1>>11); ix1 <<= 21;
            //     }
            //     for(i=0;(ix0&0x00100000)==0;i++) ix0<<=1;
            //     m -= i-1;
            //     ix0 |= (ix1>>(32-i));
            //     ix1 <<= i;
            // }
            // m -= 1023;	/* unbias exponent */
            // ix0 = (ix0&0x000fffff)|0x00100000;
            // if(m&1){	/* odd m, double x to make it even */
            //     ix0 += ix0 + ((ix1&sign)>>31);
            //     ix1 += ix1;
            // }
            // m >>= 1;	/* m = [m/2] */

            // /* generate sqrt(x) bit by bit */
            // ix0 += ix0 + ((ix1&sign)>>31);
            // ix1 += ix1;
            // q = q1 = s0 = s1 = 0;	/* [q,q1] = sqrt(x) */
            // r = 0x00200000;		/* r = moving bit from right to left */

            // while(r!=0) {
            //     t = s0+r; 
            //     if(t<=ix0) { 
            //     s0   = t+r; 
            //     ix0 -= t; 
            //     q   += r; 
            //     } 
            //     ix0 += ix0 + ((ix1&sign)>>31);
            //     ix1 += ix1;
            //     r>>=1;
            // }

            // r = sign;
            // while(r!=0) {
            //     t1 = s1+r; 
            //     t  = s0;
            //     if((t<ix0)||((t==ix0)&&(t1<=ix1))) { 
            //     s1  = t1+r;
            //     if(((t1&sign)==sign)&&(s1&sign)==0) s0 += 1;
            //     ix0 -= t;
            //     if (ix1 < t1) ix0 -= 1;
            //     ix1 -= t1;
            //     q1  += r;
            //     }
            //     ix0 += ix0 + ((ix1&sign)>>31);
            //     ix1 += ix1;
            //     r>>=1;
            // }

            // /* use floating add to find out rounding direction */
            // if((ix0|ix1)!=0) {
            //     z = one-tiny; /* trigger inexact flag */
            //     if (z>=one) {
            //         z = one+tiny;
            //         if (q1==(__uint32_t)0xffffffff) { q1=0; q += 1;}
            //     else if (z>one) {
            //         if (q1==(__uint32_t)0xfffffffe) q+=1;
            //         q1+=2; 
            //     } else
            //             q1 += (q1&1);
            //     }
            // }
            // ix0 = (q>>1)+0x3fe00000;
            // ix1 =  q1>>1;
            // if ((q&1)==1) ix1 |= sign;
            // ix0 += (m <<20);
            // INSERT_WORDS(z,ix0,ix1);
            // return z;
        }
    }

    inline float exp2(float x, speed_option speed=FM_SPEED_DEFAULT){        
        if(speed==ESpeedNormal){
            return std::exp2(x);
        }
        else{        

            ////经过测试，速度不如标准库
            #define _BIT(n) (1<<(n))
            union {uint32_t i; float f;} v;
            float offset = (x<0)? 1.0f : 0.0f;
            float clipp = (x<-126) ? -126.0f : x;
            int32_t w = clipp;
            float z = clipp - w + offset;
            v.i = (uint32_t)(_BIT(23) * (clipp + 121.2740575f + 27.7280233f / 
                (4.84252568f - z) - 1.49012907f * z));
            return v.f;
            #undef _BIT
        }
    }


    // 用来生成表的代码
    // const int32_t bk=1024;
    // float sin_lut[bk+2];
    // float asin_lut[bk+2];
    // void init(){
    //     for(int32_t i=0;i<=bk;++i){
    //         float y=(-1.0f)+i*2.0f/bk;
    //         asin_lut[i]=std::asin(y);
    //     }
    //     for(int32_t i=0;i<=bk;++i){
    //         std::cout<<asin_lut[i]<<",";
    //         if(i%100==9) puts(""); 
    //     }
    // }

    inline float sin(float x, speed_option speed=FM_SPEED_DEFAULT){        
        if(speed==ESpeedNormal){
            return std::sin(x);
        }
        else{        
            
            //经过测试，速度不如标准库
            x = std::fmod(x+pi_f,pi_f*2);
            if(x<0) x+=pi_f;
            else x-=pi_f;
            if (x < 0){
                return 1.27323954f * x+ 0.405284735f * x* x;
            }
            else{
                return 1.27323954f * x- 0.405284735f * x* x;
            }

        }       
    }

    inline float atan(float x, speed_option speed=FM_SPEED_DEFAULT){
        if(speed==ESpeedNormal){
            return std::atan(x);
        }
        else{ 
            //这个公式速度与Fast2ArcTan一致，但是精度更差
            if(abs(x)<=1){
                return (pi_f/4.0f)*x - x*(abs(x) - 1)*(0.2447f + 0.0663f*abs(x));
                // return Fast2ArcTan(x);
            }
            else{
                x=1/x;
                float t=/*Fast2ArcTan(x);*/(pi_f/4.0f)*x - x*(abs(x) - 1)*(0.2447f + 0.0663f*abs(x));
                return ((x>0)-0.5f)*pi_f - t;
            }
        }
    }

    inline double pow(double a,double b, speed_option speed=FM_SPEED_DEFAULT){
        if(speed==ESpeedNormal){
            return std::pow(a,b);
        }
        else{ 

            //快是很快，但精度可以差到50%误差，不可用
            if(a<=0) return std::pow(a,b);
            union {
                double d;
                int32_t x[2];
            } u = { a };
            u.x[1] = (int32_t)((b) * (u.x[1] - 1072632447) + 1072632447);
            u.x[0] = 0;
            return  u.d;


            //比标准库更慢，精度也仅2e-2
            // int e = (int) b;
            // union {
            //     double d;
            //     int x[2];
            // } u = { a };
            // u.x[1] = (int)((b - e) * (u.x[1] - 1072632447) + 1072632447);
            // u.x[0] = 0;

            // double r = 1.0;
            // while (e) {
            //     if (e & 1) {
            //     r *= a;
            //     }
            //     a *= a;
            //     e >>= 1;
            // }

            // return r * u.d;            
        }    
    }   


}//namespace fm