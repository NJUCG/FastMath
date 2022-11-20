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



#define tmp_test_n 3
#define tmp_test_m 3

my_rd_real_eng<float> dft_rd_eg1(-1000.0,1000.0,12345);
struct eigen_wpmat44{
	Eigen::Matrix4f matrix=Eigen::Matrix4f::Identity();
    auto operator *(const eigen_wpmat44 &o){
        Eigen::Matrix4f tmp(matrix*o.matrix);
        return tmp;
    }
    void rdinit(){
        for(int i=0;i<tmp_test_n;++i)
            for(int j=0;j<tmp_test_n;++j)
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
        for(int i=0;i<tmp_test_n;++i)
            for(int j=0;j<tmp_test_n;++j)
                matrix.a[i][j]=dft_rd_eg2.get_rd_val();
    }
};


struct vecei{
    Eigen::Matrix<float,tmp_test_n,1> vec;
    vecei(){}
    vecei(Eigen::Matrix<float,tmp_test_n,1> _vec):vec{_vec}{}
    void rdinit(){
        for(int i=0;i<tmp_test_n;++i)
            vec[i]=dft_rd_eg1.get_rd_val();
    }
    void print(){
        printf(" [vecei](");
        for(int i=0;i<tmp_test_n;++i)
            printf("%c%.4lf",i==0?'\0':',',vec[i]);
        printf(")  \n");
    }
    vecei operator *(const vecei &o){
        return vecei(vec.cross(o.vec)); 
    } 
};
struct vecmy{
    vecmat::vec<tmp_test_n,float> vec;
    vecmy(){}
    vecmy(vecmat::vec<tmp_test_n,float> _vec):vec{_vec}{}
    void rdinit(){
        for(int i=0;i<tmp_test_n;++i)
            vec[i]=dft_rd_eg2.get_rd_val();
    }    
    void print(){
        printf(" [vecmy](");
        for(int i=0;i<tmp_test_n;++i)
            printf("%c%.4lf",i==0?'\0':',',vec[i]);
        printf(")  \n");
    } 
    vecmy operator *(const vecmy &o){
        return vecmy(vecmat::cross(vec,o.vec)); 
    }    
};
#define equal_impl \
    {for(int i=0;i<tmp_test_n;++i) \
        if(calc_err(a.vec[i],b.vec[i])>1e-1) return false; \
    return true;}

bool operator ==(vecei &a,vecmy &b) equal_impl
bool operator ==(vecmy &a,vecei &b) equal_impl
#undef equal_impl


struct matei{
    Eigen::Matrix<float,tmp_test_n,tmp_test_m> vec;
    void rdinit(){
        for(int i=0;i<tmp_test_n;++i)
            for(int j=0;j<tmp_test_m;++j)
                vec.coeffRef(i,j)=dft_rd_eg1.get_rd_val();
    }
    float val(int i,int j){
        return vec.coeff(i,j);
    }
    // void print(){
    //     printf(" [vecei](");
    //     for(int i=0;i<tmp_test_n;++i)
    //         printf("%c%.4lf",i==0?'\0':',',vec[i]);
    //     printf(")  \n");
    // }
};
struct matmy{
    vecmat::mat<tmp_test_n,tmp_test_m,float> vec;
    void rdinit(){
        for(int i=0;i<tmp_test_n;++i)
            for(int j=0;j<tmp_test_m;++j)
                vec[i][j]=dft_rd_eg2.get_rd_val();
    }    
    float val(int i,int j){
        return vec[i][j];
    }
    // matmy operator *(const matmy &o){
        
    // }
    // void print(){
    //     printf(" [vecmy](");
    //     for(int i=0;i<tmp_test_n;++i)
    //         printf("%c%.4lf",i==0?'\0':',',vec[i]);
    //     printf(")  \n");
    // }    
};

#define equal_impl \
    {for(int i=0;i<tmp_test_n;++i) \
        for(int j=0;j<tmp_test_m;++j) \
        if(calc_err(a.val(i,j),b.val(i,j))>1e-3) return false; \
    return true;}

bool operator ==(matei &a,matmy &b) equal_impl
bool operator ==(matmy &a,matei &b) equal_impl
#undef equal_impl
#undef tmp_test_m
#undef tmp_test_n

#define MAX_DATA_N 20000005
// #define MAX_DIFF_N 20
#define testop /=
template<typename T1,typename T2>
struct test_tmp{
    T1 ein1[MAX_DATA_N],ein2[MAX_DATA_N],eout[MAX_DATA_N];
    T2 min1[MAX_DATA_N],min2[MAX_DATA_N],mout[MAX_DATA_N];

    #define pre(a) {for(int oo=0;oo<MAX_DATA_N;++oo) a[oo].rdinit();} 
    #define run_op(in1,in2,out,ti) \
        {ti=clock(); \
        for(int i=0;i<MAX_DATA_N;++i) \
        out[i]=in1[i] * in2[i]; \
        ti=(clock()-ti)/CLOCKS_PER_SEC;}
    void check(){
        for(int i=0;i<MAX_DATA_N;++i)
            if(!(eout[i]==mout[i])){
                ein1[i].print();
                ein2[i].print();
                eout[i].print();
                mout[i].print();
                fflush(stdout);
                assert(0);
            }
    }
    void test(int rd=10){
        double time_ei=0,time_my=0,time_eid=0,time_myd=0;  
            double tmean_rel_err_d=0,tmean_rel_err_o=0;
            for(int t1=0;t1<rd;++t1){
                pre(ein1) pre(ein2)
                pre(min1) pre(min2)
                if((t1&1)){ //消除先后顺序造成的cache影响
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
// test_tmp<matei,matmy> dft;

// __attribute_noinline__ vecmat::mat<10,10,float> noinlinewp(){
//     vecmat::mat<10,10,float> a=vecmat::mat<10,10,float>::zero();
//     return a;
// }

int main(){
    // vecmat::mat<10,10,float> b1=noinlinewp(),b2=noinlinewp();
    // cout<<b1[1][1]<<b2[2][2]<<endl;
    // vecmat::vec<3,float> a({1,2,3});
    // cout<<a.w()<<endl;
    // a[0]=1;
    // int t=0;
    // cout<<((t+=1)+=1)<<endl;

    vecmat::mat<2,4,float> b1(
        vecmat::vec4f(1,6,3,4),
        vecmat::vec4f(2,6,3,4)
    );
    b1.transpose().debug_print();

    // int a=0;
    // cout<<((a+=1)+=1)<<endl;
    // cout<<a<<endl;
    // b1.debug_print();

    // Eigen::Vector3f a(4,5,6),b(1,2,3);
    // a = a.cwiseProduct(b);
    // cout<<a[0]<<endl;

    dft.test();
}