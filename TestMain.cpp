// 用以测试FastMath.h速度的测试框架

// #include<bits/stdc++.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include <assert.h>
#include "FastMath.h"
#include <algorithm>
#include <vector>

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
#define MAX_DATA_N 15000005
#define MAX_DIFF_N 20


// #define float double
my_rd_real_eng<float> default_rdeng;
class test_framework_unary{
    static float data[MAX_DATA_N],ans[MAX_DATA_N],gen[MAX_DATA_N];
    
    int round,n;
    my_rd_real_eng<float> &rd_eng;
    float(*func[MAX_DIFF_N])(float); //func[0]:err_standard
    int funcN;
    void gendata(){
        for(int i=1;i<=n;++i) data[i]=rd_eng.get_rd_val();
    }
    void get_rd_perm(int *p,int n){
        for(int i=0;i<n;++i) p[i]=i+1;
        for(int i=n-1;i>0;--i) {
            std::swap(p[i], p[std::rand() % (i+1)]);
        }
    }
    double calc_rerr(){
        double rt=0;
        for(int i=1;i<=n;++i)
        // if(fabs(data[i]-1)>10)
        // if(fabs(ans[i])>1e-2)
        {
            rt=std::max(rt,std::min(fabs((double)(ans[i]-gen[i])/ans[i]),fabs((double)(ans[i]-gen[i]))));
            // if(rt>4){
            //     printf("%.10lf %.10lf %.10lf\n",data[i],gen[i],ans[i]);
            //     assert(0);
            // }
        }
        return rt;
    }


    public:
    test_framework_unary(int round_i=20,
                        int n_i=MAX_DATA_N-5,
                        my_rd_real_eng<float>&re=default_rdeng):
        round(round_i),n(n_i),rd_eng(re){
            func[0]=NULL;
            funcN=0;
            srand(time(0));
        }
    void add_func(float(*func_i)(float)){
        funcN++;
        func[funcN]=func_i;
    }
    void set_err_standard(float(*func_i)(float)){
        func[0]=func_i;
    }
    int discard_round=2;
    #define apply_func(f,out) for(int oo=1;oo<=n;++oo) out[oo]=(f)(data[oo]);
    void runtest(int need_err=1){
        assert(need_err==0||func[0]!=NULL);
        double tm[MAX_DIFF_N],terr[MAX_DIFF_N];
        for(int i=0;i<=funcN;++i) tm[i]=0,terr[i]=0;
        for(int rd=1;rd<=round;++rd){
            double tuse[MAX_DIFF_N],rerr[MAX_DIFF_N];
            gendata();
            if(need_err) apply_func(func[0],ans);
            int p[MAX_DIFF_N];
            get_rd_perm(p,funcN);
            for(int i=0;i<funcN;++i){
                double tbg=(double)clock()/CLOCKS_PER_SEC;
                apply_func(func[p[i]],gen);
                tuse[p[i]]=(double)clock()/CLOCKS_PER_SEC-tbg;
                if(rd>discard_round){
                    tm[p[i]]+=tuse[p[i]]/(round-discard_round);
                }
                if(need_err){
                    rerr[p[i]]=calc_rerr();
                    terr[p[i]]=std::max(rerr[p[i]],terr[p[i]]);
                }
            }
            printf("[##%3d] Time: ",rd);
            for(int i=1;i<=funcN;++i)
                printf("%10.6lf",tuse[i]);
            if(need_err){
                printf("  Err:  ");
                for(int i=1;i<=funcN;++i)
                    printf("%.6lf ",rerr[i]);
            }
            printf("\n");
        }
        printf("\033[31m");
        printf("[TOTAL] Time: ");
        for(int i=1;i<=funcN;++i)
            printf("%10.6lf",tm[i]);
        if(need_err){
            printf("  Err:  ");
            for(int i=1;i<=funcN;++i)
                printf("%.6lf ",terr[i]);
        }
        printf("\033[0m\n");        
    }
};
float test_framework_unary::data[MAX_DATA_N],test_framework_unary::ans[MAX_DATA_N],test_framework_unary::gen[MAX_DATA_N];
using fm::pi_f;
int main(){
    // float a,b;
    // std::cin>>a>>b;
    // fm::init();
    // exit(0);

    #define totst cos
    my_rd_real_eng<float> myeg(-10,10);
    test_framework_unary tp(20,MAX_DATA_N-5,myeg);
    tp.add_func([](float x)->float{return fm::totst(x,fm::ESpeedFast);});
    tp.add_func([](float x)->float{return fm::totst(x,fm::ESpeedNormal);});
    tp.set_err_standard([](float x)->float{return std::totst(x);});
    tp.runtest(1);
    // printf("%.10lf\n",noinlinewp(a)+noinlinewp2(b));
}