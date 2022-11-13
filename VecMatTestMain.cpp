#include "testdep/Eigen/Dense"
#include "VecMat.h"

#include<random>
template <typename T>
class my_rd_real_eng{
    private:
    std::default_random_engine e;
    std::uniform_real_distribution<T> u;

    public:

    my_rd_real_eng(T l=-1000.0,T r=1000.0,
            int sd=time(NULL)):e(sd),u(l,r){}
    T get_rd_val(){return u(e);}
};

my_rd_real_eng<float> dft_rd_eg1(-1000.0,1000.0,12345);
struct eigen_wpmat44{
	Eigen::Matrix4f matrix=Eigen::Matrix4f::Identity();
    auto operator *(const eigen_wpmat44 &o){
        Eigen::Matrix4f tmp(matrix*o.matrix);
        return tmp;
    }
    void rdinit(){
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                matrix.coeffRef(i,j)=dft_rd_eg1.get_rd_val();
    }
};
my_rd_real_eng<float> dft_rd_eg2(-1000.0,1000.0,12345);
struct my_wpmat44{
    vecmat::float44 matrix=vecmat::float44();
    auto operator *(const my_wpmat44 &o){
        auto tmp(matrix*o.matrix);
        return tmp;
    }
    void rdinit(){
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                matrix.a[i][j]=dft_rd_eg2.get_rd_val();
    }
};

#define MAX_DATA_N 5000005
// #define MAX_DIFF_N 20
struct test_tmp{
    eigen_wpmat44 ein1[MAX_DATA_N],ein2[MAX_DATA_N],eout[MAX_DATA_N];
    my_wpmat44 min1[MAX_DATA_N],min2[MAX_DATA_N],mout[MAX_DATA_N];

    #define pre(a) {for(int oo=0;oo<MAX_DATA_N;++oo) a[oo].rdinit();} 
    #define run_op(in1,in2,out,ti) {ti=clock(); \
                                    for(int i=0;i<MAX_DATA_N;++i) out[i].matrix=in1[i]*in2[i]; \
                                    ti=(clock()-ti)/CLOCKS_PER_SEC;}
    void test(){
        int rd=20;
        double time_dummy=0,time_opt=0,time_dummyd=0,time_optd=0;  
            double tmean_rel_err_d=0,tmean_rel_err_o=0;
            for(int t1=0;t1<rd;++t1){
                pre(ein1) pre(ein2)
                pre(min1) pre(min2)
                if(!(t1&1)){ //消除先后顺序造成的cache影响
                    run_op(ein1,ein2,eout,time_dummyd);
                    run_op(min1,min2,mout,time_optd);
                }
                else{
                    run_op(min1,min2,mout,time_optd);
                    run_op(ein1,ein2,eout,time_dummyd);
                }

                printf("[##%3d] Time dummy: %.6lf  Time optmi: %.6lf\n",t1,time_dummyd,time_optd);
                time_dummy+=time_dummyd;
                time_opt+=time_optd;
            }    
        printf("[TOTAL] Time dummy: %.6lf  Time optmi: %.6lf\n",time_dummy,time_opt);
    }
}dft;

int main(){
    dft.test();
}