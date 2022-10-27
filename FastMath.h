#pragma once


// const double	one	= 1.0, tiny=1.0e-300;
// typedef union 
// {
//   double value;
//   struct 
//   {
//     __uint32_t lsw;
//     __uint32_t msw;
//   } parts;
// } ieee_double_shape_type;

#include <cmath>
#include <stdint.h>

//注意：O1及以上优化下，
//下列所有数学函数中以常量方式传速度开关参数，
//以及对应ifelse语句不会在汇编中体现，
//即多包装的一层“传参+选择判断”不会影响效率。
namespace fm{

    const float pi_f = 3.14159265358979323846264338327950288f;
    const double pi_d = 3.14159265358979323846264338327950288;

    #ifndef FM_SPEED_DEFAULT
        #define FM_SPEED_DEFAULT ESpeedNormal
    #endif


    enum speed_option{
        ESpeedNormal=0,
        ESpeedFast=1,
    };
    
    // fast O3用时少37%，最大min(绝对误差,相对误差)不超过8e-5
    inline float log2(float x,speed_option speed=FM_SPEED_DEFAULT){
        if(speed==ESpeedNormal){
            return std::log2(x);
        }
        else{
            // if(fabs(x-1)<0.1) return std::log2(x);
            union {float f; uint32_t i;} vx;
            union {uint32_t i; float f;} mx;
            vx.f = x;
            mx.i = (vx.i & 0x007FFFFF) | 0x3F000000;
            float y = vx.i;
            y *= 1.1920928955078125e-7f;
            return y - 124.22544637f - 1.498030302f * mx.f -
                1.72587999f / (0.3520887068f + mx.f);
        }
    }


    //经过测试，能够找到的其他实现均不如标准库（这些实现可见于DiscardedImpl.h）
    inline float sqrt(float x, speed_option speed=FM_SPEED_DEFAULT){
        return std::sqrt(x);
    }

    //经过测试，能够找到的其他实现均不如标准库（这些实现可见于DiscardedImpl.h）
    inline double sqrt(double x, speed_option speed=FM_SPEED_DEFAULT){
        return std::sqrt(x);
    }

    //经过测试，能够找到的其他实现均不如标准库（这些实现可见于DiscardedImpl.h）
    inline float exp2(float x, speed_option speed=FM_SPEED_DEFAULT){
        return std::exp2(x);
    }

    const int32_t bk=1024;
    const float sin_lut[bk+2]={
0,0.00613588,0.0122715,0.0184067,0.0245412,0.0306748,0.0368072,0.0429383,0.0490677,0.0551952,
0.0613207,0.0674439,0.0735646,0.0796824,0.0857973,0.091909,0.0980171,0.104122,0.110222,0.116319,0.122411,0.128498,0.134581,0.140658,0.14673,0.152797,0.158858,0.164913,0.170962,0.177004,0.18304,0.189069,0.19509,0.201105,0.207111,0.21311,0.219101,0.225084,0.231058,0.237024,0.24298,0.248928,0.254866,0.260794,0.266713,0.272621,0.27852,0.284408,0.290285,0.296151,0.302006,0.30785,0.313682,0.319502,0.32531,0.331106,0.33689,0.342661,0.348419,0.354164,0.359895,0.365613,0.371317,0.377007,0.382683,0.388345,0.393992,0.399624,0.405241,0.410843,0.41643,0.422,0.427555,0.433094,0.438616,0.444122,0.449611,0.455084,0.460539,0.465977,0.471397,0.476799,0.482184,0.48755,0.492898,0.498228,0.503538,0.50883,0.514103,0.519356,0.52459,0.529804,0.534998,0.540172,0.545325,0.550458,0.55557,0.560662,0.565732,0.570781,0.575808,0.580814,0.585798,0.59076,0.595699,0.600617,0.605511,0.610383,0.615232,0.620057,
0.62486,0.629638,0.634393,0.639124,0.643832,0.648514,0.653173,0.657807,0.662416,0.667,0.671559,0.676093,0.680601,0.685084,0.689541,0.693971,0.698376,0.702755,0.707107,0.711432,0.715731,0.720003,0.724247,0.728464,0.732654,0.736817,0.740951,0.745058,0.749136,0.753187,0.757209,0.761202,0.765167,0.769103,0.77301,0.776888,0.780737,0.784557,0.788346,0.792107,0.795837,0.799537,0.803208,0.806848,0.810457,0.814036,0.817585,0.821103,0.824589,0.828045,0.83147,0.834863,0.838225,0.841555,0.844854,0.84812,0.851355,0.854558,0.857729,0.860867,0.863973,0.867046,0.870087,0.873095,0.87607,0.879012,0.881921,0.884797,0.88764,0.890449,0.893224,0.895966,0.898674,0.901349,0.903989,0.906596,0.909168,0.911706,0.91421,0.916679,0.919114,0.921514,0.92388,0.92621,0.928506,0.930767,0.932993,0.935184,0.937339,0.939459,0.941544,0.943593,0.945607,0.947586,0.949528,0.951435,0.953306,0.955141,0.95694,0.958704,
0.960431,0.962121,0.963776,0.965394,0.966976,0.968522,0.970031,0.971504,0.97294,0.974339,0.975702,0.977028,0.978317,0.97957,0.980785,0.981964,0.983105,0.98421,0.985278,0.986308,0.987301,0.988258,0.989177,0.990058,0.990903,0.99171,0.99248,0.993212,0.993907,0.994565,0.995185,0.995767,0.996313,0.99682,0.99729,0.997723,0.998118,0.998476,0.998795,0.999078,0.999322,0.999529,0.999699,0.999831,0.999925,0.999981,1,0.999981,0.999925,0.999831,0.999699,0.999529,0.999322,0.999078,0.998795,0.998476,0.998118,0.997723,0.99729,0.99682,0.996313,0.995767,0.995185,0.994565,0.993907,0.993212,0.99248,0.99171,0.990903,0.990058,0.989177,0.988258,0.987301,0.986308,0.985278,0.98421,0.983105,0.981964,0.980785,0.97957,0.978317,0.977028,0.975702,0.974339,0.97294,0.971504,0.970031,0.968522,0.966976,0.965394,0.963776,0.962121,0.960431,0.958703,0.95694,0.955141,0.953306,0.951435,0.949528,0.947586,
0.945607,0.943593,0.941544,0.939459,0.937339,0.935184,0.932993,0.930767,0.928506,0.92621,0.92388,0.921514,0.919114,0.916679,0.91421,0.911706,0.909168,0.906596,0.903989,0.901349,0.898674,0.895966,0.893224,0.890449,0.88764,0.884797,0.881921,0.879012,0.87607,0.873095,0.870087,0.867046,0.863973,0.860867,0.857729,0.854558,0.851355,0.84812,0.844854,0.841555,0.838225,0.834863,0.83147,0.828045,0.824589,0.821102,0.817585,0.814036,0.810457,0.806848,0.803208,0.799537,0.795837,0.792107,0.788346,0.784557,0.780737,0.776888,0.77301,0.769103,0.765167,0.761202,0.757209,0.753187,0.749136,0.745058,0.740951,0.736816,0.732654,0.728464,0.724247,0.720003,0.715731,0.711432,0.707107,0.702755,0.698376,0.693971,0.689541,0.685084,0.680601,0.676093,0.671559,0.667,0.662416,0.657807,0.653173,0.648514,0.643832,0.639124,0.634393,0.629638,0.624859,0.620057,0.615232,0.610383,0.605511,0.600616,0.595699,0.59076,
0.585798,0.580814,0.575808,0.570781,0.565732,0.560661,0.55557,0.550458,0.545325,0.540171,0.534997,0.529803,0.52459,0.519356,0.514103,0.50883,0.503538,0.498228,0.492898,0.48755,0.482184,0.476799,0.471397,0.465976,0.460539,0.455083,0.449611,0.444122,0.438616,0.433094,0.427555,0.422,0.416429,0.410843,0.405241,0.399624,0.393992,0.388345,0.382683,0.377007,0.371317,0.365613,0.359895,0.354164,0.348419,0.342661,0.33689,0.331106,0.32531,0.319502,0.313682,0.307849,0.302006,0.296151,0.290285,0.284408,0.27852,0.272621,0.266713,0.260794,0.254866,0.248928,0.24298,0.237023,0.231058,0.225084,0.219101,0.21311,0.207111,0.201105,0.19509,0.189069,0.18304,0.177004,0.170962,0.164913,0.158858,0.152797,0.14673,0.140658,0.134581,0.128498,0.122411,0.116319,0.110222,0.104122,0.0980171,0.0919089,0.0857972,0.0796823,0.0735644,0.0674438,0.0613206,0.0551951,0.0490675,0.0429381,0.0368072,0.0306748,0.0245412,0.0184067,
0.0122715,0.00613581,-8.74228e-08,-0.00613599,-0.0122717,-0.0184069,-0.0245414,-0.030675,-0.0368074,-0.0429382,-0.0490677,-0.0551952,-0.0613208,-0.067444,-0.0735646,-0.0796825,-0.0857974,-0.0919091,-0.0980173,-0.104122,-0.110222,-0.116319,-0.122411,-0.128498,-0.134581,-0.140658,-0.14673,-0.152797,-0.158858,-0.164913,-0.170962,-0.177004,-0.18304,-0.189069,-0.19509,-0.201105,-0.207112,-0.21311,-0.219101,-0.225084,-0.231058,-0.237024,-0.24298,-0.248928,-0.254866,-0.260794,-0.266713,-0.272622,-0.27852,-0.284408,-0.290285,-0.296151,-0.302006,-0.30785,-0.313682,-0.319502,-0.32531,-0.331106,-0.33689,-0.342661,-0.348419,-0.354164,-0.359895,-0.365613,-0.371317,-0.377007,-0.382683,-0.388345,-0.393992,-0.399624,-0.405241,-0.410843,-0.41643,-0.422,-0.427555,-0.433094,-0.438616,-0.444122,-0.449612,-0.455084,-0.460539,-0.465977,-0.471397,-0.476799,-0.482184,-0.48755,-0.492898,-0.498228,-0.503538,-0.50883,-0.514103,-0.519356,-0.52459,-0.529804,-0.534998,-0.540172,-0.545325,-0.550458,-0.55557,-0.560662,
-0.565732,-0.570781,-0.575808,-0.580814,-0.585798,-0.59076,-0.595699,-0.600617,-0.605511,-0.610383,-0.615232,-0.620057,-0.62486,-0.629638,-0.634393,-0.639125,-0.643832,-0.648515,-0.653173,-0.657807,-0.662416,-0.667,-0.671559,-0.676093,-0.680601,-0.685084,-0.689541,-0.693972,-0.698376,-0.702755,-0.707107,-0.711432,-0.715731,-0.720003,-0.724247,-0.728464,-0.732654,-0.736817,-0.740951,-0.745058,-0.749136,-0.753187,-0.757209,-0.761202,-0.765167,-0.769103,-0.77301,-0.776888,-0.780737,-0.784557,-0.788346,-0.792107,-0.795837,-0.799537,-0.803208,-0.806848,-0.810457,-0.814036,-0.817585,-0.821103,-0.824589,-0.828045,-0.83147,-0.834863,-0.838225,-0.841555,-0.844854,-0.848121,-0.851355,-0.854558,-0.857729,-0.860867,-0.863973,-0.867046,-0.870087,-0.873095,-0.87607,-0.879012,-0.881921,-0.884797,-0.88764,-0.890449,-0.893224,-0.895966,-0.898675,-0.901349,-0.903989,-0.906596,-0.909168,-0.911706,-0.91421,-0.916679,-0.919114,-0.921514,-0.92388,-0.92621,-0.928506,-0.930767,-0.932993,-0.935183,
-0.937339,-0.939459,-0.941544,-0.943593,-0.945607,-0.947586,-0.949528,-0.951435,-0.953306,-0.955141,-0.95694,-0.958704,-0.960431,-0.962121,-0.963776,-0.965394,-0.966977,-0.968522,-0.970031,-0.971504,-0.97294,-0.974339,-0.975702,-0.977028,-0.978317,-0.97957,-0.980785,-0.981964,-0.983105,-0.98421,-0.985278,-0.986308,-0.987301,-0.988258,-0.989177,-0.990058,-0.990903,-0.99171,-0.99248,-0.993212,-0.993907,-0.994565,-0.995185,-0.995767,-0.996313,-0.99682,-0.99729,-0.997723,-0.998118,-0.998476,-0.998795,-0.999078,-0.999322,-0.999529,-0.999699,-0.999831,-0.999925,-0.999981,-1,-0.999981,-0.999925,-0.999831,-0.999699,-0.999529,-0.999322,-0.999078,-0.998795,-0.998476,-0.998118,-0.997723,-0.99729,-0.99682,-0.996313,-0.995767,-0.995185,-0.994565,-0.993907,-0.993212,-0.99248,-0.99171,-0.990903,-0.990058,-0.989177,-0.988258,-0.987301,-0.986308,-0.985278,-0.98421,-0.983105,-0.981964,-0.980785,-0.97957,-0.978317,-0.977028,-0.975702,-0.974339,-0.97294,-0.971504,-0.970031,-0.968522,
-0.966976,-0.965394,-0.963776,-0.962121,-0.96043,-0.958703,-0.95694,-0.955141,-0.953306,-0.951435,-0.949528,-0.947586,-0.945607,-0.943593,-0.941544,-0.939459,-0.937339,-0.935183,-0.932993,-0.930767,-0.928506,-0.92621,-0.923879,-0.921514,-0.919114,-0.916679,-0.91421,-0.911706,-0.909168,-0.906596,-0.903989,-0.901349,-0.898674,-0.895966,-0.893224,-0.890449,-0.88764,-0.884797,-0.881921,-0.879012,-0.87607,-0.873095,-0.870087,-0.867046,-0.863973,-0.860867,-0.857729,-0.854558,-0.851355,-0.84812,-0.844853,-0.841555,-0.838225,-0.834863,-0.831469,-0.828045,-0.824589,-0.821102,-0.817585,-0.814036,-0.810457,-0.806847,-0.803208,-0.799537,-0.795837,-0.792107,-0.788346,-0.784557,-0.780737,-0.776888,-0.77301,-0.769103,-0.765167,-0.761202,-0.757209,-0.753187,-0.749136,-0.745058,-0.740951,-0.736816,-0.732654,-0.728464,-0.724247,-0.720002,-0.715731,-0.711432,-0.707107,-0.702754,-0.698376,-0.693971,-0.689541,-0.685084,-0.680601,-0.676093,-0.671559,-0.667,-0.662416,-0.657807,-0.653173,-0.648514,
-0.643831,-0.639124,-0.634393,-0.629638,-0.624859,-0.620057,-0.615231,-0.610383,-0.605511,-0.600616,-0.595699,-0.590759,-0.585798,-0.580814,-0.575808,-0.57078,-0.565732,-0.560661,-0.55557,-0.550458,-0.545325,-0.540172,-0.534998,-0.529804,-0.52459,-0.519356,-0.514103,-0.50883,-0.503538,-0.498228,-0.492898,-0.48755,-0.482184,-0.476799,-0.471397,-0.465976,-0.460538,-0.455083,-0.449611,-0.444122,-0.438616,-0.433094,-0.427555,-0.422,-0.416429,-0.410843,-0.405241,-0.399624,-0.393992,-0.388345,-0.382683,-0.377007,-0.371317,-0.365613,-0.359895,-0.354163,-0.348419,-0.342661,-0.33689,-0.331106,-0.32531,-0.319502,-0.313682,-0.307849,-0.302006,-0.296151,-0.290284,-0.284407,-0.278519,-0.272621,-0.266712,-0.260794,-0.254865,-0.248928,-0.24298,-0.237024,-0.231058,-0.225084,-0.219101,-0.21311,-0.207111,-0.201105,-0.19509,-0.189069,-0.18304,-0.177004,-0.170962,-0.164913,-0.158858,-0.152797,-0.14673,-0.140658,-0.13458,-0.128498,-0.12241,-0.116318,-0.110222,-0.104121,-0.0980168,-0.0919086,
-0.0857969,-0.0796825,-0.0735646,-0.0674439,-0.0613207,-0.0551952,-0.0490676,-0.0429382,-0.0368072,-0.0306747,-0.0245411,-0.0184066,-0.0122714,-0.00613573,1.74846e-07        
    };

    //fast O3用时少82%，最大min(绝对误差,相对误差)不超过6e-3
    inline float sin(float x, speed_option speed=FM_SPEED_DEFAULT){
        // return std::exp2(x);
        
        if(speed==ESpeedNormal){
            return std::sin(x);
        }
        else{        
            x = x * (bk/(2.0f*pi_f));
            int32_t id = (int32_t)x;
            if(x<0) id--;
            x -= id;
            id = ((id & 1023) + 1024) & 1023;
            return x*sin_lut[id]+(1-x)*sin_lut[id+1];

        }       
    }

    inline float cos(float x, speed_option speed=FM_SPEED_DEFAULT){
        return sin(x+pi_f/2,speed);
    }







}//namespace fm