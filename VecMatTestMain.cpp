#include "testdep/Eigen/Dense"
#include "VecMat.h"
#include<iostream>
using namespace std;

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
template<typename T> T calc_err(T a,T b){
    return min(abs(a-b),abs(a-b)/max((T)1,max(abs(a),abs(b))));
}

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


struct vecei{
    Eigen::Vector4f vec;
    void rdinit(){
        for(int i=0;i<4;++i)
            vec[i]=dft_rd_eg1.get_rd_val();
    }
    void print(){
        printf(" [vecei](");
        for(int i=0;i<4;++i)
            printf("%c%.4lf",i==0?'\0':',',vec[i]);
        printf(")  \n");
    }
};
struct vecmy{
    vecmat::vec<4,float> vec;
    void rdinit(){
        for(int i=0;i<4;++i)
            vec[i]=dft_rd_eg2.get_rd_val();
    }    
    void print(){
        printf(" [vecmy](");
        for(int i=0;i<4;++i)
            printf("%c%.4lf",i==0?'\0':',',vec[i]);
        printf(")  \n");
    }    
};
#define equal_impl \
    {for(int i=0;i<4;++i) \
        if(calc_err(a.vec[i],b.vec[i])>1e-5) return false; \
    return true;}

bool operator ==(vecei &a,vecmy &b) equal_impl
bool operator ==(vecmy &a,vecei &b) equal_impl

#define MAX_DATA_N 5000005
// #define MAX_DIFF_N 20
#define testop +
template<typename T1,typename T2>
struct test_tmp{
    T1 ein1[MAX_DATA_N],ein2[MAX_DATA_N],eout[MAX_DATA_N];
    T2 min1[MAX_DATA_N],min2[MAX_DATA_N],mout[MAX_DATA_N];

    #define pre(a) {for(int oo=0;oo<MAX_DATA_N;++oo) a[oo].rdinit();} 
    #define run_op(in1,in2,out,ti) \
        {ti=clock(); \
        for(int i=0;i<MAX_DATA_N;++i) \
        out[i].vec=in1[i].vec testop in2[i].vec; \
        ti=(clock()-ti)/CLOCKS_PER_SEC;}
    void check(){
        for(int i=0;i<MAX_DATA_N;++i)
            if(!(eout[i]==mout[i])){
                eout[i].print();
                mout[i].print();
                fflush(stdout);
                assert(0);
            }
    }
    void test(){
        int rd=20;
        double time_ei=0,time_my=0,time_eid=0,time_myd=0;  
            double tmean_rel_err_d=0,tmean_rel_err_o=0;
            for(int t1=0;t1<rd;++t1){
                pre(ein1) pre(ein2)
                pre(min1) pre(min2)
                if(!(t1&1)){ //消除先后顺序造成的cache影响
                    run_op(ein1,ein2,eout,time_eid);
                    run_op(min1,min2,mout,time_myd);
                }
                else{
                    run_op(min1,min2,mout,time_myd);
                    run_op(ein1,ein2,eout,time_eid);
                }
                check();
                printf("[##%3d] Time ei: %.6lf  Time my: %.6lf\n",t1,time_eid,time_myd);
                time_ei+=time_eid;
                time_my+=time_myd;
            }    
        printf("[TOTAL] Time ei: %.6lf  Time my: %.6lf\n",time_ei,time_my);
    }
};

test_tmp<vecei,vecmy> dft;

__attribute_noinline__ vecmat::mat<10,10,float> noinlinewp(){
    vecmat::mat<10,10,float> a=vecmat::mat<10,10,float>::zero();
    return a;
}

int main(){
    vecmat::mat<10,10,float> b1=noinlinewp(),b2=noinlinewp();
    cout<<b1[1][1]<<b2[2][2]<<endl;
    vecmat::vec<30,float> a;
    cout<<a[4]<<endl;
    a[0]=1;
    int t=0;
    cout<<((t+=1)+=1)<<endl;

    dft.test();
}