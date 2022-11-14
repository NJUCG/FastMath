#include<cstdlib>
#include<cstdint>
#include<cstring>
#include<cmath>

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
        inline T& operator[](int x){return a[x];}
        inline const T& operator[](int x)const{return a[x];}
        
        //正确性tested，对于n=4速度与eigen基本相同
        #define VVBINARY_OP_DEF_HELPER(op) \
        inline vec operator op(const vec& o) const{ \
            vec r; \
            for(int i=0;i<N;++i) \
                r[i] = a[i] op o[i]; \
            return r; \
        }  
        VVBINARY_OP_DEF_HELPER(+)
        VVBINARY_OP_DEF_HELPER(-)
        #undef VVBINARY_OP_DEF_HELPER
        #define VVASSIGN_OP_DEF_HELPER(op) \
        inline vec& operator op(const vec& o){ \
            for(int i=0;i<N;++i) \
                a[i] op o[i]; \
            return *this; \
        }  
        VVASSIGN_OP_DEF_HELPER(+=)
        VVASSIGN_OP_DEF_HELPER(-=)
        #undef VVASSIGN_OP_DEF_HELPER
        //不考虑精度，严格相等，考虑精度请使用vecmat::equal(eps)
        inline bool operator ==(const vec& o) const{
            for(int i=0;i<N;++i) 
                if(a[i] != o[i]) return false; 
            return true;
        } 
        //不考虑精度，考虑精度请使用vecmat::inequal(eps)
        inline bool operator !=(const vec& o) const{
            for(int i=0;i<N;++i) 
                if(a[i] != o[i]) return true; 
            return false;
        } 
        //只加减，cowise product另做

        //欧几里得长度，2范数
        constexpr T len(){
            T rt=0;
            for(int i=0;i<N;++i)
                rt += a[i] * a[i];
            return std::sqrt(rt);
        }
    };

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

    //N*M矩阵
    template<uint32_t N,uint32_t M,typename T>
    struct mat{
        vec<N,T> cols[M];

        static constexpr mat zero(){
            mat m; 
            for(int i=0;i<M;++i) 
                m.cols[i]=vec<N,T>::zero(); 
            return m;
        }
        static constexpr mat scalar(T x){
            mat m; 
            for(int i=0;i<M;++i){ 
                m.cols[i]=vec<N,T>::zero(); 
                m.cols[i][i]=x;
            }
            return m;
        }   
        static constexpr mat identity(){
            return scalar((T)1);
        }  

    };
    
}
