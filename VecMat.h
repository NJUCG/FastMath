#include<cstdlib>
#include<cstring>
namespace vecmat{
    // struct float44{
    //     float a[4][4];
    //     float44() noexcept{
    //         memset(a,0,sizeof(a));
    //         a[0][0]=a[1][1]=a[2][2]=a[3][3]=1;
    //     }
    //     float44(float a00,float a01,float a02,float a03,
    //             float a10,float a11,float a12,float a13,
    //             float a20,float a21,float a22,float a23,
    //             float a30,float a31,float a32,float a33)
    //     {
    //         a[0][0]=a00;a[0][1]=a01;a[0][2]=a02;a[0][3]=a03;
    //         a[1][0]=a10;a[1][1]=a11;a[1][2]=a12;a[1][3]=a13;
    //         a[2][0]=a20;a[2][1]=a21;a[2][2]=a22;a[2][3]=a23;
    //         a[3][0]=a30;a[3][1]=a31;a[3][2]=a32;a[3][3]=a33;
    //     }
    // };
    // inline auto operator*(float44 const& l,float44 const& r)noexcept{
    //     return float44(
    //         l.a[0][0]*r.a[0][0] + l.a[0][1]*r.a[1][0] + l.a[0][2]*r.a[2][0] + l.a[0][3]*r.a[3][0],
    //         l.a[0][0]*r.a[0][1] + l.a[0][1]*r.a[1][1] + l.a[0][2]*r.a[2][1] + l.a[0][3]*r.a[3][1],
    //         l.a[0][0]*r.a[0][2] + l.a[0][1]*r.a[1][2] + l.a[0][2]*r.a[2][2] + l.a[0][3]*r.a[3][2],
    //         l.a[0][0]*r.a[0][3] + l.a[0][1]*r.a[1][3] + l.a[0][2]*r.a[2][3] + l.a[0][3]*r.a[3][3],
    //         l.a[1][0]*r.a[0][0] + l.a[1][1]*r.a[1][0] + l.a[1][2]*r.a[2][0] + l.a[1][3]*r.a[3][0],
    //         l.a[1][0]*r.a[0][1] + l.a[1][1]*r.a[1][1] + l.a[1][2]*r.a[2][1] + l.a[1][3]*r.a[3][1],
    //         l.a[1][0]*r.a[0][2] + l.a[1][1]*r.a[1][2] + l.a[1][2]*r.a[2][2] + l.a[1][3]*r.a[3][2],
    //         l.a[1][0]*r.a[0][3] + l.a[1][1]*r.a[1][3] + l.a[1][2]*r.a[2][3] + l.a[1][3]*r.a[3][3],
    //         l.a[2][0]*r.a[0][0] + l.a[2][1]*r.a[1][0] + l.a[2][2]*r.a[2][0] + l.a[2][3]*r.a[3][0],
    //         l.a[2][0]*r.a[0][1] + l.a[2][1]*r.a[1][1] + l.a[2][2]*r.a[2][1] + l.a[2][3]*r.a[3][1],
    //         l.a[2][0]*r.a[0][2] + l.a[2][1]*r.a[1][2] + l.a[2][2]*r.a[2][2] + l.a[2][3]*r.a[3][2],
    //         l.a[2][0]*r.a[0][3] + l.a[2][1]*r.a[1][3] + l.a[2][2]*r.a[2][3] + l.a[2][3]*r.a[3][3],
    //         l.a[3][0]*r.a[0][0] + l.a[3][1]*r.a[1][0] + l.a[3][2]*r.a[2][0] + l.a[3][3]*r.a[3][0],
    //         l.a[3][0]*r.a[0][1] + l.a[3][1]*r.a[1][1] + l.a[3][2]*r.a[2][1] + l.a[3][3]*r.a[3][1],
    //         l.a[3][0]*r.a[0][2] + l.a[3][1]*r.a[1][2] + l.a[3][2]*r.a[2][2] + l.a[3][3]*r.a[3][2],
    //         l.a[3][0]*r.a[0][3] + l.a[3][1]*r.a[1][3] + l.a[3][2]*r.a[2][3] + l.a[3][3]*r.a[3][3]    
    //     );
    // }
    template<uint32_t l,typename T>
    struct vec{
        private:
        T a[l];
        public:
        inline auto operator[](int x)const{return a[x];}
        //只加减，cowise product另做
    };
    
}
