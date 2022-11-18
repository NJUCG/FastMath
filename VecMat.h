#include<cstdlib>
#include<cstdint>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<initializer_list>
namespace vecmat{
    struct float44{
        float a[4][4];
        float44() noexcept{
            memset(a,0,sizeof(a));
            a[0][0]=a[1][1]=a[2][2]=a[3][3]=1;
        }
        float44(float a00,float a01,float a02,float a03,
                float a10,float a11,float a12,float a13,
                float a20,float a21,float a22,float a23,
                float a30,float a31,float a32,float a33)
        {
            a[0][0]=a00;a[0][1]=a01;a[0][2]=a02;a[0][3]=a03;
            a[1][0]=a10;a[1][1]=a11;a[1][2]=a12;a[1][3]=a13;
            a[2][0]=a20;a[2][1]=a21;a[2][2]=a22;a[2][3]=a23;
            a[3][0]=a30;a[3][1]=a31;a[3][2]=a32;a[3][3]=a33;
        }
    };
    inline auto operator*(float44 const& l,float44 const& r)noexcept{
        return float44(
            l.a[0][0]*r.a[0][0] + l.a[0][1]*r.a[1][0] + l.a[0][2]*r.a[2][0] + l.a[0][3]*r.a[3][0],
            l.a[0][0]*r.a[0][1] + l.a[0][1]*r.a[1][1] + l.a[0][2]*r.a[2][1] + l.a[0][3]*r.a[3][1],
            l.a[0][0]*r.a[0][2] + l.a[0][1]*r.a[1][2] + l.a[0][2]*r.a[2][2] + l.a[0][3]*r.a[3][2],
            l.a[0][0]*r.a[0][3] + l.a[0][1]*r.a[1][3] + l.a[0][2]*r.a[2][3] + l.a[0][3]*r.a[3][3],
            l.a[1][0]*r.a[0][0] + l.a[1][1]*r.a[1][0] + l.a[1][2]*r.a[2][0] + l.a[1][3]*r.a[3][0],
            l.a[1][0]*r.a[0][1] + l.a[1][1]*r.a[1][1] + l.a[1][2]*r.a[2][1] + l.a[1][3]*r.a[3][1],
            l.a[1][0]*r.a[0][2] + l.a[1][1]*r.a[1][2] + l.a[1][2]*r.a[2][2] + l.a[1][3]*r.a[3][2],
            l.a[1][0]*r.a[0][3] + l.a[1][1]*r.a[1][3] + l.a[1][2]*r.a[2][3] + l.a[1][3]*r.a[3][3],
            l.a[2][0]*r.a[0][0] + l.a[2][1]*r.a[1][0] + l.a[2][2]*r.a[2][0] + l.a[2][3]*r.a[3][0],
            l.a[2][0]*r.a[0][1] + l.a[2][1]*r.a[1][1] + l.a[2][2]*r.a[2][1] + l.a[2][3]*r.a[3][1],
            l.a[2][0]*r.a[0][2] + l.a[2][1]*r.a[1][2] + l.a[2][2]*r.a[2][2] + l.a[2][3]*r.a[3][2],
            l.a[2][0]*r.a[0][3] + l.a[2][1]*r.a[1][3] + l.a[2][2]*r.a[2][3] + l.a[2][3]*r.a[3][3],
            l.a[3][0]*r.a[0][0] + l.a[3][1]*r.a[1][0] + l.a[3][2]*r.a[2][0] + l.a[3][3]*r.a[3][0],
            l.a[3][0]*r.a[0][1] + l.a[3][1]*r.a[1][1] + l.a[3][2]*r.a[2][1] + l.a[3][3]*r.a[3][1],
            l.a[3][0]*r.a[0][2] + l.a[3][1]*r.a[1][2] + l.a[3][2]*r.a[2][2] + l.a[3][3]*r.a[3][2],
            l.a[3][0]*r.a[0][3] + l.a[3][1]*r.a[1][3] + l.a[3][2]*r.a[2][3] + l.a[3][3]*r.a[3][3]    
        );
    }


    //目前正确性tested，对于n=4速度与eigen基本相同
    
    template<uint32_t N,typename T>
    struct vec{
        T a[N];
        static constexpr vec zero(){vec r; memset(r.a,0,sizeof(r.a)); return r;}
        static constexpr vec fill(T x){vec r; for(int i=0;i<N;++i) r.a[i]=x; return r;}

        vec(){}
        vec(const T *initarr){memcpy(a,initarr,sizeof(T)*N);}
        //为了效率暂时不考虑li.size()<N的情况（此时会复制进不可知的值）
        vec(std::initializer_list<T> li){
            for(int i=0;i<N;++i) a[i]=*(li.begin()+i);
        }
        inline T& operator[](int x){return a[x];}
        inline const T& operator[](int x)const{return a[x];}
        
        //欧几里得长度，2范数
        constexpr T len(){
            T rt=0;
            for(int i=0;i<N;++i)
                rt += a[i] * a[i];
            return std::sqrt(rt);
        }

        void debug_print(char ed='\n'){
            printf("[vec<%d>](",N);
            for(int i=0;i<N;++i){
                std::cout<<(i==0?'\0':',')<<a[i];
            }
            printf(")%c",ed);
            fflush(stdout);
        }
    };



    // template<>
    // void vec<4,float>::spec(int x){
    //     printf();

    // }


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

    //不考虑精度，严格相等，考虑精度请使用vecmat::equal(eps)
    template<uint32_t N,typename T> 
    inline bool operator ==(const vec<N,T>& a, const vec<N,T>& o){
        for(int i=0;i<N;++i) 
            if(a[i] != o[i]) return false; 
        return true;
    } 
    //不考虑精度，考虑精度请使用vecmat::inequal(eps)
    template<uint32_t N,typename T> 
    inline bool operator !=(const vec<N,T>& a, const vec<N,T>& o){
        for(int i=0;i<N;++i) 
            if(a[i] != o[i]) return true; 
        return false;
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
    
    //目前正确性tested，对于n=4速度与eigen基本相同
    
    //下面的还没测试过。
    //TODO 测试 & 是否确定complie time & 好用的构造函数

    //对于zero scalar等，不是complie time const直接复制，而是当场执行，但是可能这样反而更快（只要xmm一直store，无需load一下store一下）
    //暂定：构造函数对于泛型用初始化列表（即{a,b,c}），234的特化则可加上(a,b,c)的形式

    //N*M矩阵
    template<uint32_t N,uint32_t M,typename T>
    struct mat{
        vec<M,T> rows[N];

        static constexpr mat zero(){
            mat m; 
            for(int i=0;i<N;++i) 
                m.rows[i]=vec<M,T>::zero(); 
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
        static constexpr mat diag(std::initializer_list<T> li){
            static_assert(N==M,"only available in square matrix");
            mat m; 
            for(int i=0;i<N;++i){ 
                m.rows[i]=vec<M,T>::zero(); 
                m.rows[i][i]=*(li.begin()+i);
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

        void debug_print(){
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











    // typename maker
    #define VECMAT_TYPEDEF_MAKER(T,Tsym) \
    using vec##2##Tsym = vec<2, T>;     \
    using vec##3##Tsym = vec<3, T>;     \
    using vec##4##Tsym = vec<4, T>;     \
    using mat##22##Tsym = mat<2, 2, T>;     \
    using mat##33##Tsym = mat<3, 3, T>;     \
    using mat##44##Tsym = mat<4, 4, T>;      

    VECMAT_TYPEDEF_MAKER(float,f);
    VECMAT_TYPEDEF_MAKER(double,d);
    VECMAT_TYPEDEF_MAKER(int,i);
    VECMAT_TYPEDEF_MAKER(long,l);
    VECMAT_TYPEDEF_MAKER(long long,ll);

    #undef VECMAT_TYPEDEF_MAKER
}
