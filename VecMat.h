#pragma once

#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <initializer_list>
#include <type_traits>


namespace vecmat{
    
    template<uint32_t N,typename T>
    struct vec{
        T a[N];
        inline void clear(){memset(a,0,sizeof(a));}
        static constexpr vec zero(){vec r; memset(r.a,0,sizeof(r.a)); return r;}
        static constexpr vec fill(T x){vec r; for(int i=0;i<N;++i) r.a[i]=x; return r;}

        constexpr T x(){
            static_assert(N>0,"out of bound");
            return a[0];
        }
        constexpr T y(){
            static_assert(N>1,"out of bound");
            return a[1];
        }
        constexpr T z(){
            static_assert(N>2,"out of bound");
            return a[2];
        }
        constexpr T w(){
            static_assert(N>3,"out of bound");
            return a[3];
        }
        vec(){}
        vec(T x){
            static_assert(N>0,"too many argument");
            a[0]=x;
        }
        vec(T x,T y){
            static_assert(N>1,"too many argument");
            a[0]=x; a[1]=y;
        }        
        vec(T x,T y,T z){
            static_assert(N>2,"too many argument");
            a[0]=x; a[1]=y; a[2]=z;
        }        
        vec(T x,T y,T z,T w){
            static_assert(N>3,"too many argument");
            a[0]=x; a[1]=y; a[2]=z; a[3]=w;
        }          
        vec(const T *initarr){memcpy(a,initarr,sizeof(T)*N);}
        //为了效率暂时不考虑li.size()<N的情况（此时会复制进不可知的值）
        vec(std::initializer_list<T> li){
            for(int i=0;i<N;++i) a[i]=*(li.begin()+i);
        }
        inline T& operator[](int x){return a[x];}
        inline const T& operator[](int x)const{return a[x];}
        
        //欧几里得长度，2范数
        constexpr auto len() const{
            T rt=0;
            for(int i=0;i<N;++i)
                rt += a[i] * a[i];
            return std::sqrt(rt);
        }

        //欧几里得距离
        constexpr auto distance(const vec &b) const{
            return (*this - b).len();
        }

        constexpr T dot(const vec &o) const{
            T ret=0;
            for(int i=0;i<N;++i) ret+=a[i]*o[i];
            return ret;            
        }

        constexpr vec cwiseMult(const vec &o) const{
            vec<N,T> r; 
            for(int i=0;i<N;++i) 
                r[i] = a[i] * o[i]; 
            return r;        
        }

        constexpr vec cwiseDiv(const vec &o) const{
            vec<N,T> r; 
            for(int i=0;i<N;++i) 
                r[i] = a[i] / o[i]; 
            return r;        
        }

        void debug_print(char ed='\n') const{
            printf("[vec<%d>](",N);
            for(int i=0;i<N;++i){
                std::cout<<(i==0?'\0':',')<<a[i];
            }
            printf(")%c",ed);
            fflush(stdout);
        }
    };





    //只加减，cowise product另做
    //正确性tested，对于n=4速度与eigen基本相同
    #define VVBINARY_OP_DEF_HELPER(op) \
    template<uint32_t N,typename T> \
    inline vec<N,T> operator op(const vec<N,T>& a, const vec<N,T>& o){ \
        vec<N,T> r; \
        for(int i=0;i<N;++i) \
            r[i] = a[i] op o[i]; \
        return r; \
    }  
    VVBINARY_OP_DEF_HELPER(+)
    VVBINARY_OP_DEF_HELPER(-)
    #undef VVBINARY_OP_DEF_HELPER
    #define VVASSIGN_OP_DEF_HELPER(op) \
    template<uint32_t N,typename T> \
    inline vec<N,T>& operator op(vec<N,T>& a, const vec<N,T>& o){ \
        for(int i=0;i<N;++i) \
            a[i] op o[i]; \
        return a; \
    }  
    VVASSIGN_OP_DEF_HELPER(+=)
    VVASSIGN_OP_DEF_HELPER(-=)
    #undef VVASSIGN_OP_DEF_HELPER

    //不考虑精度，严格相等，考虑精度请使用vecmat::equal(a,b,eps)
    template<uint32_t N,typename T> 
    inline bool operator ==(const vec<N,T>& a, const vec<N,T>& o){
        for(int i=0;i<N;++i) 
            if(a[i] != o[i]) return false; 
        return true;
    } 
    //不考虑精度，考虑精度请使用vecmat::inequal(a,b,eps)
    template<uint32_t N,typename T> 
    inline bool operator !=(const vec<N,T>& a, const vec<N,T>& o){
        for(int i=0;i<N;++i) 
            if(a[i] != o[i]) return true; 
        return false;
    } 

    template<uint32_t N,typename T,typename T2> 
    inline bool equal(const vec<N,T>& a, const vec<N,T>& o, T2 eps){
        for(int i=0;i<N;++i) 
            if(abs(a[i] - o[i])>eps) return false; 
        return true;
    } 

    template<uint32_t N,typename T,typename T2> 
    inline bool inequal(const vec<N,T>& a, const vec<N,T>& o, T2 eps){
        for(int i=0;i<N;++i) 
            if(abs(a[i] - o[i])>eps) return true; 
        return false;
    } 

    //欧几里得距离
    template<uint32_t N,typename T> 
    inline auto distance(const vec<N,T>& a, const vec<N,T>& o){
        return a.distance(o);
    } 


    #define VSBINARY_OP_DEF_HELPER(op) \
    template<uint32_t N,typename T> \
    inline vec<N,T> operator op(const vec<N,T>& a,const T& b){ \
        vec<N,T> r; \
        for(int i=0;i<N;++i) \
            r[i] = a[i] op b; \
        return r; \
    }  \
    template<uint32_t N,typename T> \
    inline vec<N,T> operator op(const T& b,const vec<N,T>& a){ \
        vec<N,T> r; \
        for(int i=0;i<N;++i) \
            r[i] = a[i] op b; \
        return r; \
    }  
    VSBINARY_OP_DEF_HELPER(*)
    VSBINARY_OP_DEF_HELPER(/)
    #undef VSBINARY_OP_DEF_HELPER

    #define VSASSIGN_OP_DEF_HELPER(op) \
    template<uint32_t N,typename T> \
    inline vec<N,T>& operator op(vec<N,T>& a,const T& b){ \
        for(int i=0;i<N;++i) \
            a[i] op b; \
        return a; \
    }
    VSASSIGN_OP_DEF_HELPER(*=)
    VSASSIGN_OP_DEF_HELPER(/=)
    #undef VSASSIGN_OP_DEF_HELPER    
    

    //N*M矩阵
    template<uint32_t N,uint32_t M,typename T>
    struct mat{
        vec<M,T> rows[N];

        inline void clear(){memset((void *)this,0,sizeof(mat<N,M,T>));}
        static constexpr mat zero(){
            mat m; 
            m.clear();
            return m;
        }
        static constexpr mat scalar(T x){
            static_assert(N==M,"only available in square matrix");
            mat m; 
            for(int i=0;i<N;++i){ 
                m.rows[i]=vec<M,T>::zero(); 
                m.rows[i][i]=x;
            }
            return m;
        }    
        static constexpr mat diag(const vec<N,T> &li){
            static_assert(N==M,"only available in square matrix");
            mat m; 
            for(int i=0;i<N;++i){ 
                m.rows[i]=vec<M,T>::zero(); 
                m.rows[i][i]=li[i];
            }
            return m;
        }     
        static constexpr mat identity(){
            static_assert(N==M,"only available in square matrix");
            return scalar((T)1);
        }  

        inline vec<M,T>& operator[](int x){return rows[x];}
        inline const vec<M,T>& operator[](int x)const{return rows[x];}

        mat(){}
        mat(vec<M,T> x){
            static_assert(N>0,"too many argument");
            rows[0]=x;
        }
        mat(vec<M,T> x,vec<M,T> y){
            static_assert(N>1,"too many argument");
            rows[0]=x; rows[1]=y;
        }        
        mat(vec<M,T> x,vec<M,T> y,vec<M,T> z){
            static_assert(N>2,"too many argument");
            rows[0]=x; rows[1]=y; rows[2]=z;
        }        
        mat(vec<M,T> x,vec<M,T> y,vec<M,T> z,vec<M,T> w){
            static_assert(N>3,"too many argument");
            rows[0]=x; rows[1]=y; rows[2]=z; rows[3]=w;
        }      
        //为了效率暂时不考虑li.size()<N的情况（此时会复制进不可知的值）
        mat(std::initializer_list<T> li){
            for(int i=0;i<N;++i)
                for(int j=0;j<M;++j) 
                    rows[i][j]=*(li.begin()+i*M+j);
        }
        mat(std::initializer_list< vec<M,T> > li){
            for(int i=0;i<N;++i)
                rows[i]=*(li.begin()+i);
        }
        mat(T t00){
            static_assert(N==1&&M==1,"do not support initialize like this");
            rows[0][0]=t00; 
        }
        mat(T t00,T t01,T t10,T t11){
            static_assert(N==2&&M==2,"do not support initialize like this");
            rows[0][0]=t00; rows[0][1]=t01; 
            rows[1][0]=t10; rows[1][1]=t11; 
        }
        mat(T t00,T t01,T t02,T t10,T t11,T t12,T t20,T t21,T t22){
            static_assert(N==3&&M==3,"do not support initialize like this");
            rows[0][0]=t00; rows[0][1]=t01; rows[0][2]=t02; 
            rows[1][0]=t10; rows[1][1]=t11; rows[1][2]=t12; 
            rows[2][0]=t20; rows[2][1]=t21; rows[2][2]=t22; 
        }
        mat(T t00,T t01,T t02,T t03,T t10,T t11,T t12,T t13,T t20,T t21,T t22,T t23,T t30,T t31,T t32,T t33){
            static_assert(N==4&&M==4,"do not support initialize like this");
            rows[0][0]=t00; rows[0][1]=t01; rows[0][2]=t02; rows[0][3]=t03; 
            rows[1][0]=t10; rows[1][1]=t11; rows[1][2]=t12; rows[1][3]=t13; 
            rows[2][0]=t20; rows[2][1]=t21; rows[2][2]=t22; rows[2][3]=t23; 
            rows[3][0]=t30; rows[3][1]=t31; rows[3][2]=t32; rows[3][3]=t33; 
        }        

        constexpr mat<M,N,T> transpose() const{
            mat<M,N,T> m;
            for(int i=0;i<M;++i)
                for(int j=0;j<N;++j)
                    m[i][j]=rows[j][i];
            return m;
        }
        constexpr T dot(const mat &o) const{
            T ret=0;
            for(int i=0;i<N;++i) ret+=rows[i].dot(o[i]);
            return ret;
        }

        constexpr auto norm2() const{
            T ret=0;
            for(int i=0;i<N;++i)
                for(int j=0;j<M;++j)
                    ret += rows[i][j] * rows[i][j];
            return std::sqrt(ret);
        }
        
        // 计算行列式（目前仅支持size<=4的矩阵），因为浮点数精度问题，一些情况下会有较大误差（Eigen也会），40M测试点总误差与Eigen库相当，效率与Eigen相当
        constexpr T determinant() const{
            static_assert(N==M,"only available in square matrix");
            static_assert(std::is_floating_point<T>::value,"do not support nonfloating-point type");
            static_assert(N>=1||N<=4,"do not support this size");
            if constexpr(N==1){
                return rows[0][0];
            } else if constexpr(N==2){
                return rows[0][0] * rows[1][1] - rows[1][0] * rows[0][1];;
            } else if constexpr(N==3){
                return rows[0][0] * (rows[1][1] * rows[2][2] - rows[2][1] * rows[1][2]) -
                       rows[1][0] * (rows[0][1] * rows[2][2] - rows[2][1] * rows[0][2]) +
                       rows[2][0] * (rows[0][1] * rows[1][2] - rows[1][1] * rows[0][2]); 
            } else {//N==4  from GLM
                T SubFactor00 = rows[2][2] * rows[3][3] - rows[3][2] * rows[2][3];
                T SubFactor01 = rows[2][1] * rows[3][3] - rows[3][1] * rows[2][3];
                T SubFactor02 = rows[2][1] * rows[3][2] - rows[3][1] * rows[2][2];
                T SubFactor03 = rows[2][0] * rows[3][3] - rows[3][0] * rows[2][3];
                T SubFactor04 = rows[2][0] * rows[3][2] - rows[3][0] * rows[2][2];
                T SubFactor05 = rows[2][0] * rows[3][1] - rows[3][0] * rows[2][1];

                vec<4,T> DetCof(
                    + (rows[1][1] * SubFactor00 - rows[1][2] * SubFactor01 + rows[1][3] * SubFactor02),
                    - (rows[1][0] * SubFactor00 - rows[1][2] * SubFactor03 + rows[1][3] * SubFactor04),
                    + (rows[1][0] * SubFactor01 - rows[1][1] * SubFactor03 + rows[1][3] * SubFactor05),
                    - (rows[1][0] * SubFactor02 - rows[1][1] * SubFactor04 + rows[1][2] * SubFactor05));

                return
                    rows[0][0] * DetCof[0] + rows[0][1] * DetCof[1] +
                    rows[0][2] * DetCof[2] + rows[0][3] * DetCof[3];
            }
        }

        // only used for err testing
        // constexpr T det2()const{
        //     long double SubFactor00 = (long double)rows[2][2] * rows[3][3] - (long double)rows[3][2] * rows[2][3];
        //     long double SubFactor01 = (long double)rows[2][1] * rows[3][3] - (long double)rows[3][1] * rows[2][3];
        //     long double SubFactor02 = (long double)rows[2][1] * rows[3][2] - (long double)rows[3][1] * rows[2][2];
        //     long double SubFactor03 = (long double)rows[2][0] * rows[3][3] - (long double)rows[3][0] * rows[2][3];
        //     long double SubFactor04 = (long double)rows[2][0] * rows[3][2] - (long double)rows[3][0] * rows[2][2];
        //     long double SubFactor05 = (long double)rows[2][0] * rows[3][1] - (long double)rows[3][0] * rows[2][1];
        //     vec<4,long double> DetCof(
        //         + (rows[1][1] * SubFactor00 - rows[1][2] * SubFactor01 + rows[1][3] * SubFactor02),
        //         - (rows[1][0] * SubFactor00 - rows[1][2] * SubFactor03 + rows[1][3] * SubFactor04),
        //         + (rows[1][0] * SubFactor01 - rows[1][1] * SubFactor03 + rows[1][3] * SubFactor05),
        //         - (rows[1][0] * SubFactor02 - rows[1][1] * SubFactor04 + rows[1][2] * SubFactor05));
        //     return
        //         rows[0][0] * DetCof[0] + rows[0][1] * DetCof[1] +
        //         rows[0][2] * DetCof[2] + rows[0][3] * DetCof[3];
        // }

        // 计算逆矩阵，误差同，但4x4显著慢于Eigen，待优化
        constexpr mat inverse() const{
            static_assert(N==M,"only available in square matrix");
            static_assert(std::is_floating_point<T>::value,"do not support nonfloating-point type");
            static_assert(N>=1||N<=4,"do not support this size");            
            if constexpr(N==1){
                return mat<1,1,T>(vec<1,T>(static_cast<T>(1)/(rows[0][0])));
            } else if constexpr(N==2){
                T OneOverDeterminant = static_cast<T>(1) / (rows[0][0] * rows[1][1] - rows[1][0] * rows[0][1]);
                return mat<2,2,T>(
                        vec<2,T>(+rows[1][1] * OneOverDeterminant,
                                 -rows[0][1] * OneOverDeterminant),
                        vec<2,T>(-rows[1][0] * OneOverDeterminant,
                                 +rows[0][0] * OneOverDeterminant)); 
            } else if constexpr(N==3){ // from GLM
                T OneOverDeterminant = static_cast<T>(1) / (
                    + rows[0][0] * (rows[1][1] * rows[2][2] - rows[2][1] * rows[1][2])
                    - rows[1][0] * (rows[0][1] * rows[2][2] - rows[2][1] * rows[0][2])
                    + rows[2][0] * (rows[0][1] * rows[1][2] - rows[1][1] * rows[0][2]));

                mat<3,3,T> Inverse;
                Inverse[0][0] = + (rows[1][1] * rows[2][2] - rows[2][1] * rows[1][2]) * OneOverDeterminant;
                Inverse[1][0] = - (rows[1][0] * rows[2][2] - rows[2][0] * rows[1][2]) * OneOverDeterminant;
                Inverse[2][0] = + (rows[1][0] * rows[2][1] - rows[2][0] * rows[1][1]) * OneOverDeterminant;
                Inverse[0][1] = - (rows[0][1] * rows[2][2] - rows[2][1] * rows[0][2]) * OneOverDeterminant;
                Inverse[1][1] = + (rows[0][0] * rows[2][2] - rows[2][0] * rows[0][2]) * OneOverDeterminant;
                Inverse[2][1] = - (rows[0][0] * rows[2][1] - rows[2][0] * rows[0][1]) * OneOverDeterminant;
                Inverse[0][2] = + (rows[0][1] * rows[1][2] - rows[1][1] * rows[0][2]) * OneOverDeterminant;
                Inverse[1][2] = - (rows[0][0] * rows[1][2] - rows[1][0] * rows[0][2]) * OneOverDeterminant;
                Inverse[2][2] = + (rows[0][0] * rows[1][1] - rows[1][0] * rows[0][1]) * OneOverDeterminant;
                
                return Inverse;
            } else {//N==4  from GLM
                T Coef00 = rows[2][2] * rows[3][3] - rows[3][2] * rows[2][3];
                T Coef02 = rows[1][2] * rows[3][3] - rows[3][2] * rows[1][3];
                T Coef03 = rows[1][2] * rows[2][3] - rows[2][2] * rows[1][3];

                T Coef04 = rows[2][1] * rows[3][3] - rows[3][1] * rows[2][3];
                T Coef06 = rows[1][1] * rows[3][3] - rows[3][1] * rows[1][3];
                T Coef07 = rows[1][1] * rows[2][3] - rows[2][1] * rows[1][3];

                T Coef08 = rows[2][1] * rows[3][2] - rows[3][1] * rows[2][2];
                T Coef10 = rows[1][1] * rows[3][2] - rows[3][1] * rows[1][2];
                T Coef11 = rows[1][1] * rows[2][2] - rows[2][1] * rows[1][2];

                T Coef12 = rows[2][0] * rows[3][3] - rows[3][0] * rows[2][3];
                T Coef14 = rows[1][0] * rows[3][3] - rows[3][0] * rows[1][3];
                T Coef15 = rows[1][0] * rows[2][3] - rows[2][0] * rows[1][3];

                T Coef16 = rows[2][0] * rows[3][2] - rows[3][0] * rows[2][2];
                T Coef18 = rows[1][0] * rows[3][2] - rows[3][0] * rows[1][2];
                T Coef19 = rows[1][0] * rows[2][2] - rows[2][0] * rows[1][2];

                T Coef20 = rows[2][0] * rows[3][1] - rows[3][0] * rows[2][1];
                T Coef22 = rows[1][0] * rows[3][1] - rows[3][0] * rows[1][1];
                T Coef23 = rows[1][0] * rows[2][1] - rows[2][0] * rows[1][1];

                vec<4, T> Fac0(Coef00, Coef00, Coef02, Coef03);
                vec<4, T> Fac1(Coef04, Coef04, Coef06, Coef07);
                vec<4, T> Fac2(Coef08, Coef08, Coef10, Coef11);
                vec<4, T> Fac3(Coef12, Coef12, Coef14, Coef15);
                vec<4, T> Fac4(Coef16, Coef16, Coef18, Coef19);
                vec<4, T> Fac5(Coef20, Coef20, Coef22, Coef23);

                vec<4, T> Vec0(rows[1][0], rows[0][0], rows[0][0], rows[0][0]);
                vec<4, T> Vec1(rows[1][1], rows[0][1], rows[0][1], rows[0][1]);
                vec<4, T> Vec2(rows[1][2], rows[0][2], rows[0][2], rows[0][2]);
                vec<4, T> Vec3(rows[1][3], rows[0][3], rows[0][3], rows[0][3]);

                vec<4, T> Inv0(Vec1.cwiseMult(Fac0) - Vec2.cwiseMult(Fac1) + Vec3.cwiseMult(Fac2));
                vec<4, T> Inv1(Vec0.cwiseMult(Fac0) - Vec2.cwiseMult(Fac3) + Vec3.cwiseMult(Fac4));
                vec<4, T> Inv2(Vec0.cwiseMult(Fac1) - Vec1.cwiseMult(Fac3) + Vec3.cwiseMult(Fac5));
                vec<4, T> Inv3(Vec0.cwiseMult(Fac2) - Vec1.cwiseMult(Fac4) + Vec2.cwiseMult(Fac5));

                vec<4, T> SignA(+1, -1, +1, -1);
                vec<4, T> SignB(-1, +1, -1, +1);
                mat<4, 4, T> Inverse(Inv0.cwiseMult(SignA), Inv1.cwiseMult(SignB), Inv2.cwiseMult(SignA), Inv3.cwiseMult(SignB));

                vec<4, T> Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

                vec<4, T> Dot0(rows[0].cwiseMult(Row0));
                T Dot1 = (Dot0[0] + Dot0[1]) + (Dot0[2] + Dot0[3]);

                T OneOverDeterminant = static_cast<T>(1) / Dot1;

                return Inverse * OneOverDeterminant;                
            }            
        }


        void debug_print() const{
            printf("[mat<%d,%d>]\n",N,M);
            for(int i=0;i<N;++i)
                rows[i].debug_print('\n');
            fflush(stdout);
        }
    };

    //只加减，cowise product另做
    #define MMBINARY_OP_DEF_HELPER(op) \
    template<uint32_t N,uint32_t M,typename T> \
    inline mat<N,M,T> operator op(const mat<N,M,T>& a, const mat<N,M,T>& o){ \
        mat<N,M,T> r; \
        for(int i=0;i<N;++i) \
            r[i] = a[i] op o[i]; \
        return r; \
    }  
    MMBINARY_OP_DEF_HELPER(+)
    MMBINARY_OP_DEF_HELPER(-)
    #undef MMBINARY_OP_DEF_HELPER
    #define MMASSIGN_OP_DEF_HELPER(op) \
    template<uint32_t N,uint32_t M,typename T> \
    inline mat<N,M,T> operator op(mat<N,M,T>& a, const mat<N,M,T>& o){ \
        for(int i=0;i<N;++i) \
            a[i] op o[i]; \
        return a; \
    }  
    MMASSIGN_OP_DEF_HELPER(+=)
    MMASSIGN_OP_DEF_HELPER(-=)
    #undef MMASSIGN_OP_DEF_HELPER    
    
    //不考虑精度，严格相等，考虑精度请使用vecmat::equal(eps)
    template<uint32_t N,uint32_t M,typename T> \
    inline mat<N,M,T> operator ==(const mat<N,M,T>& a, const mat<N,M,T>& o){ \
        for(int i=0;i<N;++i) 
            if(a[i] != o[i]) return false; 
        return true;
    } 
    //不考虑精度，考虑精度请使用vecmat::inequal(eps)
    template<uint32_t N,uint32_t M,typename T> \
    inline mat<N,M,T> operator !=(const mat<N,M,T>& a, const mat<N,M,T>& o){ \
        for(int i=0;i<N;++i) 
            if(a[i] != o[i]) return true; 
        return false;
    } 
    template<uint32_t N,uint32_t M,typename T,typename T2> 
    inline bool equal(const mat<N,M,T>& a, const mat<N,M,T>& o, T2 eps){
        for(int i=0;i<N;++i) 
            if(inequal(a[i],o[i],eps)) return false; 
        return true;
    } 

    template<uint32_t N,uint32_t M,typename T,typename T2> 
    inline bool inequal(const mat<N,M,T>& a, const mat<N,M,T>& o, T2 eps){
        for(int i=0;i<N;++i) 
            if(inequal(a[i],o[i],eps)) return true; 
        return false;
    } 

    #define VSBINARY_OP_DEF_HELPER(op) \
    template<uint32_t N,uint32_t M,typename T> \
    inline mat<N,M,T> operator op(const mat<N,M,T>& a,const T& b){ \
        mat<N,M,T> r; \
        for(int i=0;i<N;++i) \
            r[i] = a[i] op b; \
        return r; \
    }  \
    template<uint32_t N,uint32_t M,typename T> \
    inline mat<N,M,T> operator op(const T& b,const mat<N,M,T>& a){ \
        mat<N,M,T> r; \
        for(int i=0;i<N;++i) \
            r[i] = a[i] op b; \
        return r; \
    }  
    VSBINARY_OP_DEF_HELPER(*)
    VSBINARY_OP_DEF_HELPER(/)
    #undef VSBINARY_OP_DEF_HELPER

    #define MSASSIGN_OP_DEF_HELPER(op) \
    template<uint32_t N,uint32_t M,typename T> \
    inline mat<N,M,T>& operator op(mat<N,M,T>& a,const T& b){ \
        for(int i=0;i<N;++i) \
            a[i] op b; \
        return a; \
    }
    MSASSIGN_OP_DEF_HELPER(*=)
    MSASSIGN_OP_DEF_HELPER(/=)
    #undef MSASSIGN_OP_DEF_HELPER  

    template<uint32_t N,typename T> 
    inline T dot(const vec<N,T> &a, const vec<N,T> &b){
        return a.dot(b);
    } 

    template<uint32_t N,uint32_t M,typename T> 
    inline T dot(const mat<N,M,T> &a, const mat<N,M,T> &b){
        return a.dot(b);
    } 

    template<typename T> 
    inline vec<3,T> cross(const vec<3,T> &a, const vec<3,T> &b){
        return vec<3,T>(a[1] * b[2] - b[1] * a[2],
                a[2] * b[0] - b[2] * a[0],
                a[0] * b[1] - b[0] * a[1]);
    }




    template<uint32_t N,uint32_t M,typename T>
    inline vec<N,T> operator *(const mat<N,M,T>& m,const vec<M,T>& v){
        vec<N,T> rt;
        for(int i=0;i<N;++i)
            rt[i] = dot(m.rows[i],v);
        return rt;
    }

    // template<uint32_t M,uint32_t K,uint32_t N,typename T>
    // inline mat<M,N,T> mult1(const mat<M,K,T>& a,const mat<K,N,T>& b){
    //     mat<M,N,T> rt;
    //     rt.clear();
    //     for(int i=0;i<M;++i)
    //         for(int j=0;j<N;++j)
    //             for(int k=0;k<K;++k)
    //                 rt[i][j]+=a[i][k]*b[k][j];
    //     return rt;
    // }

    // //n=4 比不过mult1
    // template<uint32_t M,uint32_t K,uint32_t N,typename T>
    // inline mat<M,N,T> mult2(const mat<M,K,T>& a,const mat<K,N,T>& b){
    //     mat<M,N,T> rt;
    //     rt.clear();
    //     for(int k=0;k<K;++k)
    //         for(int i=0;i<M;++i)
    //             for(int j=0;j<N;++j)
    //                 rt[i][j]+=a[i][k]*b[k][j];
    //     return rt;
    // }

    // 优化TODO，n大时比eigen慢(注意: kij不如ijk)
    // N,M,K较小(<=4)时的特化版本见VecMatMult.inl.h (特化版本效率不低于甚至部分优于eigen)
    template<uint32_t M,uint32_t K,uint32_t N,typename T>
    inline mat<M,N,T> operator *(const mat<M,K,T>& a,const mat<K,N,T>& b){
        mat<M,N,T> rt;
        rt.clear();
        for(int i=0;i<M;++i)
            for(int j=0;j<N;++j)
                for(int k=0;k<K;++k)
                    rt[i][j]+=a[i][k]*b[k][j];
        return rt;
    }




    // typename maker
    #define VECMAT_TYPEDEF_MAKER(T,Tsym) \
    using vec##2##Tsym = vec<2, T>;     \
    using vec##3##Tsym = vec<3, T>;     \
    using vec##4##Tsym = vec<4, T>;     \
    using mat##22##Tsym = mat<2, 2, T>;     \
    using mat##23##Tsym = mat<2, 3, T>;     \
    using mat##24##Tsym = mat<2, 4, T>;     \
    using mat##32##Tsym = mat<3, 2, T>;     \
    using mat##33##Tsym = mat<3, 3, T>;     \
    using mat##34##Tsym = mat<3, 4, T>;     \
    using mat##42##Tsym = mat<4, 2, T>;     \
    using mat##43##Tsym = mat<4, 3, T>;     \
    using mat##44##Tsym = mat<4, 4, T>;    

    VECMAT_TYPEDEF_MAKER(float,f);
    VECMAT_TYPEDEF_MAKER(double,d);
    VECMAT_TYPEDEF_MAKER(int,i);
    VECMAT_TYPEDEF_MAKER(long,l);
    VECMAT_TYPEDEF_MAKER(long long,ll);

    #undef VECMAT_TYPEDEF_MAKER
}

//提供N,M,K较小(<=4)时矩阵乘法的特化实现(M,K,N各四种取值，共64种)
#include "VecMatMult.inl.h"