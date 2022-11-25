//仅用于VecMat.h中#include，提供N,M,K较小(<=4)时矩阵乘法的特化实现(M,K,N各四种取值，共64种)

namespace vecmat{



template<typename T>
inline mat<1,1,T> operator*(const mat<1,1,T>& l,const mat<1,1,T>& r){
return mat<1,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0])
);}


template<typename T>
inline mat<1,2,T> operator*(const mat<1,1,T>& l,const mat<1,2,T>& r){
return mat<1,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1])
);}


template<typename T>
inline mat<1,3,T> operator*(const mat<1,1,T>& l,const mat<1,3,T>& r){
return mat<1,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1],
   l.rows[0][0]*r.rows[0][2])
);}


template<typename T>
inline mat<1,4,T> operator*(const mat<1,1,T>& l,const mat<1,4,T>& r){
return mat<1,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1],
   l.rows[0][0]*r.rows[0][2],
   l.rows[0][0]*r.rows[0][3])
);}


template<typename T>
inline mat<1,1,T> operator*(const mat<1,2,T>& l,const mat<2,1,T>& r){
return mat<1,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0])
);}


template<typename T>
inline mat<1,2,T> operator*(const mat<1,2,T>& l,const mat<2,2,T>& r){
return mat<1,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1])
);}


template<typename T>
inline mat<1,3,T> operator*(const mat<1,2,T>& l,const mat<2,3,T>& r){
return mat<1,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2])
);}


template<typename T>
inline mat<1,4,T> operator*(const mat<1,2,T>& l,const mat<2,4,T>& r){
return mat<1,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3])
);}


template<typename T>
inline mat<1,1,T> operator*(const mat<1,3,T>& l,const mat<3,1,T>& r){
return mat<1,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0])
);}


template<typename T>
inline mat<1,2,T> operator*(const mat<1,3,T>& l,const mat<3,2,T>& r){
return mat<1,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1])
);}


template<typename T>
inline mat<1,3,T> operator*(const mat<1,3,T>& l,const mat<3,3,T>& r){
return mat<1,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2])
);}


template<typename T>
inline mat<1,4,T> operator*(const mat<1,3,T>& l,const mat<3,4,T>& r){
return mat<1,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3] + l.rows[0][2]*r.rows[2][3])
);}


template<typename T>
inline mat<1,1,T> operator*(const mat<1,4,T>& l,const mat<4,1,T>& r){
return mat<1,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0])
);}


template<typename T>
inline mat<1,2,T> operator*(const mat<1,4,T>& l,const mat<4,2,T>& r){
return mat<1,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1])
);}


template<typename T>
inline mat<1,3,T> operator*(const mat<1,4,T>& l,const mat<4,3,T>& r){
return mat<1,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2] + l.rows[0][3]*r.rows[3][2])
);}


template<typename T>
inline mat<1,4,T> operator*(const mat<1,4,T>& l,const mat<4,4,T>& r){
return mat<1,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2] + l.rows[0][3]*r.rows[3][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3] + l.rows[0][2]*r.rows[2][3] + l.rows[0][3]*r.rows[3][3])
);}


template<typename T>
inline mat<2,1,T> operator*(const mat<2,1,T>& l,const mat<1,1,T>& r){
return mat<2,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0])
);}


template<typename T>
inline mat<2,2,T> operator*(const mat<2,1,T>& l,const mat<1,2,T>& r){
return mat<2,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1])
);}


template<typename T>
inline mat<2,3,T> operator*(const mat<2,1,T>& l,const mat<1,3,T>& r){
return mat<2,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1],
   l.rows[0][0]*r.rows[0][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1],
   l.rows[1][0]*r.rows[0][2])
);}


template<typename T>
inline mat<2,4,T> operator*(const mat<2,1,T>& l,const mat<1,4,T>& r){
return mat<2,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1],
   l.rows[0][0]*r.rows[0][2],
   l.rows[0][0]*r.rows[0][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1],
   l.rows[1][0]*r.rows[0][2],
   l.rows[1][0]*r.rows[0][3])
);}


template<typename T>
inline mat<2,1,T> operator*(const mat<2,2,T>& l,const mat<2,1,T>& r){
return mat<2,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0])
);}


template<typename T>
inline mat<2,2,T> operator*(const mat<2,2,T>& l,const mat<2,2,T>& r){
return mat<2,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1])
);}


template<typename T>
inline mat<2,3,T> operator*(const mat<2,2,T>& l,const mat<2,3,T>& r){
return mat<2,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2])
);}


template<typename T>
inline mat<2,4,T> operator*(const mat<2,2,T>& l,const mat<2,4,T>& r){
return mat<2,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3])
);}


template<typename T>
inline mat<2,1,T> operator*(const mat<2,3,T>& l,const mat<3,1,T>& r){
return mat<2,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0])
);}


template<typename T>
inline mat<2,2,T> operator*(const mat<2,3,T>& l,const mat<3,2,T>& r){
return mat<2,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1])
);}


template<typename T>
inline mat<2,3,T> operator*(const mat<2,3,T>& l,const mat<3,3,T>& r){
return mat<2,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2])
);}


template<typename T>
inline mat<2,4,T> operator*(const mat<2,3,T>& l,const mat<3,4,T>& r){
return mat<2,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3] + l.rows[0][2]*r.rows[2][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3] + l.rows[1][2]*r.rows[2][3])
);}


template<typename T>
inline mat<2,1,T> operator*(const mat<2,4,T>& l,const mat<4,1,T>& r){
return mat<2,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0])
);}


template<typename T>
inline mat<2,2,T> operator*(const mat<2,4,T>& l,const mat<4,2,T>& r){
return mat<2,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1])
);}


template<typename T>
inline mat<2,3,T> operator*(const mat<2,4,T>& l,const mat<4,3,T>& r){
return mat<2,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2] + l.rows[0][3]*r.rows[3][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2] + l.rows[1][3]*r.rows[3][2])
);}


template<typename T>
inline mat<2,4,T> operator*(const mat<2,4,T>& l,const mat<4,4,T>& r){
return mat<2,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2] + l.rows[0][3]*r.rows[3][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3] + l.rows[0][2]*r.rows[2][3] + l.rows[0][3]*r.rows[3][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2] + l.rows[1][3]*r.rows[3][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3] + l.rows[1][2]*r.rows[2][3] + l.rows[1][3]*r.rows[3][3])
);}


template<typename T>
inline mat<3,1,T> operator*(const mat<3,1,T>& l,const mat<1,1,T>& r){
return mat<3,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0])
,vec<1,T>(   l.rows[2][0]*r.rows[0][0])
);}


template<typename T>
inline mat<3,2,T> operator*(const mat<3,1,T>& l,const mat<1,2,T>& r){
return mat<3,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1])
,vec<2,T>(   l.rows[2][0]*r.rows[0][0],
   l.rows[2][0]*r.rows[0][1])
);}


template<typename T>
inline mat<3,3,T> operator*(const mat<3,1,T>& l,const mat<1,3,T>& r){
return mat<3,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1],
   l.rows[0][0]*r.rows[0][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1],
   l.rows[1][0]*r.rows[0][2])
,vec<3,T>(   l.rows[2][0]*r.rows[0][0],
   l.rows[2][0]*r.rows[0][1],
   l.rows[2][0]*r.rows[0][2])
);}


template<typename T>
inline mat<3,4,T> operator*(const mat<3,1,T>& l,const mat<1,4,T>& r){
return mat<3,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1],
   l.rows[0][0]*r.rows[0][2],
   l.rows[0][0]*r.rows[0][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1],
   l.rows[1][0]*r.rows[0][2],
   l.rows[1][0]*r.rows[0][3])
,vec<4,T>(   l.rows[2][0]*r.rows[0][0],
   l.rows[2][0]*r.rows[0][1],
   l.rows[2][0]*r.rows[0][2],
   l.rows[2][0]*r.rows[0][3])
);}


template<typename T>
inline mat<3,1,T> operator*(const mat<3,2,T>& l,const mat<2,1,T>& r){
return mat<3,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0])
,vec<1,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0])
);}


template<typename T>
inline mat<3,2,T> operator*(const mat<3,2,T>& l,const mat<2,2,T>& r){
return mat<3,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1])
,vec<2,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1])
);}


template<typename T>
inline mat<3,3,T> operator*(const mat<3,2,T>& l,const mat<2,3,T>& r){
return mat<3,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2])
,vec<3,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2])
);}


template<typename T>
inline mat<3,4,T> operator*(const mat<3,2,T>& l,const mat<2,4,T>& r){
return mat<3,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3])
,vec<4,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2],
   l.rows[2][0]*r.rows[0][3] + l.rows[2][1]*r.rows[1][3])
);}


template<typename T>
inline mat<3,1,T> operator*(const mat<3,3,T>& l,const mat<3,1,T>& r){
return mat<3,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0])
,vec<1,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0])
);}


template<typename T>
inline mat<3,2,T> operator*(const mat<3,3,T>& l,const mat<3,2,T>& r){
return mat<3,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1])
,vec<2,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1])
);}


template<typename T>
inline mat<3,3,T> operator*(const mat<3,3,T>& l,const mat<3,3,T>& r){
return mat<3,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2])
,vec<3,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2] + l.rows[2][2]*r.rows[2][2])
);}


template<typename T>
inline mat<3,4,T> operator*(const mat<3,3,T>& l,const mat<3,4,T>& r){
return mat<3,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3] + l.rows[0][2]*r.rows[2][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3] + l.rows[1][2]*r.rows[2][3])
,vec<4,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2] + l.rows[2][2]*r.rows[2][2],
   l.rows[2][0]*r.rows[0][3] + l.rows[2][1]*r.rows[1][3] + l.rows[2][2]*r.rows[2][3])
);}


template<typename T>
inline mat<3,1,T> operator*(const mat<3,4,T>& l,const mat<4,1,T>& r){
return mat<3,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0])
,vec<1,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0] + l.rows[2][3]*r.rows[3][0])
);}


template<typename T>
inline mat<3,2,T> operator*(const mat<3,4,T>& l,const mat<4,2,T>& r){
return mat<3,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1])
,vec<2,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0] + l.rows[2][3]*r.rows[3][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1] + l.rows[2][3]*r.rows[3][1])
);}


template<typename T>
inline mat<3,3,T> operator*(const mat<3,4,T>& l,const mat<4,3,T>& r){
return mat<3,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2] + l.rows[0][3]*r.rows[3][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2] + l.rows[1][3]*r.rows[3][2])
,vec<3,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0] + l.rows[2][3]*r.rows[3][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1] + l.rows[2][3]*r.rows[3][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2] + l.rows[2][2]*r.rows[2][2] + l.rows[2][3]*r.rows[3][2])
);}


template<typename T>
inline mat<3,4,T> operator*(const mat<3,4,T>& l,const mat<4,4,T>& r){
return mat<3,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2] + l.rows[0][3]*r.rows[3][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3] + l.rows[0][2]*r.rows[2][3] + l.rows[0][3]*r.rows[3][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2] + l.rows[1][3]*r.rows[3][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3] + l.rows[1][2]*r.rows[2][3] + l.rows[1][3]*r.rows[3][3])
,vec<4,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0] + l.rows[2][3]*r.rows[3][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1] + l.rows[2][3]*r.rows[3][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2] + l.rows[2][2]*r.rows[2][2] + l.rows[2][3]*r.rows[3][2],
   l.rows[2][0]*r.rows[0][3] + l.rows[2][1]*r.rows[1][3] + l.rows[2][2]*r.rows[2][3] + l.rows[2][3]*r.rows[3][3])
);}


template<typename T>
inline mat<4,1,T> operator*(const mat<4,1,T>& l,const mat<1,1,T>& r){
return mat<4,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0])
,vec<1,T>(   l.rows[2][0]*r.rows[0][0])
,vec<1,T>(   l.rows[3][0]*r.rows[0][0])
);}


template<typename T>
inline mat<4,2,T> operator*(const mat<4,1,T>& l,const mat<1,2,T>& r){
return mat<4,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1])
,vec<2,T>(   l.rows[2][0]*r.rows[0][0],
   l.rows[2][0]*r.rows[0][1])
,vec<2,T>(   l.rows[3][0]*r.rows[0][0],
   l.rows[3][0]*r.rows[0][1])
);}


template<typename T>
inline mat<4,3,T> operator*(const mat<4,1,T>& l,const mat<1,3,T>& r){
return mat<4,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1],
   l.rows[0][0]*r.rows[0][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1],
   l.rows[1][0]*r.rows[0][2])
,vec<3,T>(   l.rows[2][0]*r.rows[0][0],
   l.rows[2][0]*r.rows[0][1],
   l.rows[2][0]*r.rows[0][2])
,vec<3,T>(   l.rows[3][0]*r.rows[0][0],
   l.rows[3][0]*r.rows[0][1],
   l.rows[3][0]*r.rows[0][2])
);}


template<typename T>
inline mat<4,4,T> operator*(const mat<4,1,T>& l,const mat<1,4,T>& r){
return mat<4,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0],
   l.rows[0][0]*r.rows[0][1],
   l.rows[0][0]*r.rows[0][2],
   l.rows[0][0]*r.rows[0][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0],
   l.rows[1][0]*r.rows[0][1],
   l.rows[1][0]*r.rows[0][2],
   l.rows[1][0]*r.rows[0][3])
,vec<4,T>(   l.rows[2][0]*r.rows[0][0],
   l.rows[2][0]*r.rows[0][1],
   l.rows[2][0]*r.rows[0][2],
   l.rows[2][0]*r.rows[0][3])
,vec<4,T>(   l.rows[3][0]*r.rows[0][0],
   l.rows[3][0]*r.rows[0][1],
   l.rows[3][0]*r.rows[0][2],
   l.rows[3][0]*r.rows[0][3])
);}


template<typename T>
inline mat<4,1,T> operator*(const mat<4,2,T>& l,const mat<2,1,T>& r){
return mat<4,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0])
,vec<1,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0])
,vec<1,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0])
);}


template<typename T>
inline mat<4,2,T> operator*(const mat<4,2,T>& l,const mat<2,2,T>& r){
return mat<4,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1])
,vec<2,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1])
,vec<2,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1])
);}


template<typename T>
inline mat<4,3,T> operator*(const mat<4,2,T>& l,const mat<2,3,T>& r){
return mat<4,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2])
,vec<3,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2])
,vec<3,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1],
   l.rows[3][0]*r.rows[0][2] + l.rows[3][1]*r.rows[1][2])
);}


template<typename T>
inline mat<4,4,T> operator*(const mat<4,2,T>& l,const mat<2,4,T>& r){
return mat<4,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3])
,vec<4,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2],
   l.rows[2][0]*r.rows[0][3] + l.rows[2][1]*r.rows[1][3])
,vec<4,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1],
   l.rows[3][0]*r.rows[0][2] + l.rows[3][1]*r.rows[1][2],
   l.rows[3][0]*r.rows[0][3] + l.rows[3][1]*r.rows[1][3])
);}


template<typename T>
inline mat<4,1,T> operator*(const mat<4,3,T>& l,const mat<3,1,T>& r){
return mat<4,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0])
,vec<1,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0])
,vec<1,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0] + l.rows[3][2]*r.rows[2][0])
);}


template<typename T>
inline mat<4,2,T> operator*(const mat<4,3,T>& l,const mat<3,2,T>& r){
return mat<4,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1])
,vec<2,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1])
,vec<2,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0] + l.rows[3][2]*r.rows[2][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1] + l.rows[3][2]*r.rows[2][1])
);}


template<typename T>
inline mat<4,3,T> operator*(const mat<4,3,T>& l,const mat<3,3,T>& r){
return mat<4,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2])
,vec<3,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2] + l.rows[2][2]*r.rows[2][2])
,vec<3,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0] + l.rows[3][2]*r.rows[2][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1] + l.rows[3][2]*r.rows[2][1],
   l.rows[3][0]*r.rows[0][2] + l.rows[3][1]*r.rows[1][2] + l.rows[3][2]*r.rows[2][2])
);}


template<typename T>
inline mat<4,4,T> operator*(const mat<4,3,T>& l,const mat<3,4,T>& r){
return mat<4,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3] + l.rows[0][2]*r.rows[2][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3] + l.rows[1][2]*r.rows[2][3])
,vec<4,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2] + l.rows[2][2]*r.rows[2][2],
   l.rows[2][0]*r.rows[0][3] + l.rows[2][1]*r.rows[1][3] + l.rows[2][2]*r.rows[2][3])
,vec<4,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0] + l.rows[3][2]*r.rows[2][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1] + l.rows[3][2]*r.rows[2][1],
   l.rows[3][0]*r.rows[0][2] + l.rows[3][1]*r.rows[1][2] + l.rows[3][2]*r.rows[2][2],
   l.rows[3][0]*r.rows[0][3] + l.rows[3][1]*r.rows[1][3] + l.rows[3][2]*r.rows[2][3])
);}


template<typename T>
inline mat<4,1,T> operator*(const mat<4,4,T>& l,const mat<4,1,T>& r){
return mat<4,1,T>(
vec<1,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0])
,vec<1,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0])
,vec<1,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0] + l.rows[2][3]*r.rows[3][0])
,vec<1,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0] + l.rows[3][2]*r.rows[2][0] + l.rows[3][3]*r.rows[3][0])
);}


template<typename T>
inline mat<4,2,T> operator*(const mat<4,4,T>& l,const mat<4,2,T>& r){
return mat<4,2,T>(
vec<2,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1])
,vec<2,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1])
,vec<2,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0] + l.rows[2][3]*r.rows[3][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1] + l.rows[2][3]*r.rows[3][1])
,vec<2,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0] + l.rows[3][2]*r.rows[2][0] + l.rows[3][3]*r.rows[3][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1] + l.rows[3][2]*r.rows[2][1] + l.rows[3][3]*r.rows[3][1])
);}


template<typename T>
inline mat<4,3,T> operator*(const mat<4,4,T>& l,const mat<4,3,T>& r){
return mat<4,3,T>(
vec<3,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2] + l.rows[0][3]*r.rows[3][2])
,vec<3,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2] + l.rows[1][3]*r.rows[3][2])
,vec<3,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0] + l.rows[2][3]*r.rows[3][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1] + l.rows[2][3]*r.rows[3][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2] + l.rows[2][2]*r.rows[2][2] + l.rows[2][3]*r.rows[3][2])
,vec<3,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0] + l.rows[3][2]*r.rows[2][0] + l.rows[3][3]*r.rows[3][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1] + l.rows[3][2]*r.rows[2][1] + l.rows[3][3]*r.rows[3][1],
   l.rows[3][0]*r.rows[0][2] + l.rows[3][1]*r.rows[1][2] + l.rows[3][2]*r.rows[2][2] + l.rows[3][3]*r.rows[3][2])
);}


template<typename T>
inline mat<4,4,T> operator*(const mat<4,4,T>& l,const mat<4,4,T>& r){
return mat<4,4,T>(
vec<4,T>(   l.rows[0][0]*r.rows[0][0] + l.rows[0][1]*r.rows[1][0] + l.rows[0][2]*r.rows[2][0] + l.rows[0][3]*r.rows[3][0],
   l.rows[0][0]*r.rows[0][1] + l.rows[0][1]*r.rows[1][1] + l.rows[0][2]*r.rows[2][1] + l.rows[0][3]*r.rows[3][1],
   l.rows[0][0]*r.rows[0][2] + l.rows[0][1]*r.rows[1][2] + l.rows[0][2]*r.rows[2][2] + l.rows[0][3]*r.rows[3][2],
   l.rows[0][0]*r.rows[0][3] + l.rows[0][1]*r.rows[1][3] + l.rows[0][2]*r.rows[2][3] + l.rows[0][3]*r.rows[3][3])
,vec<4,T>(   l.rows[1][0]*r.rows[0][0] + l.rows[1][1]*r.rows[1][0] + l.rows[1][2]*r.rows[2][0] + l.rows[1][3]*r.rows[3][0],
   l.rows[1][0]*r.rows[0][1] + l.rows[1][1]*r.rows[1][1] + l.rows[1][2]*r.rows[2][1] + l.rows[1][3]*r.rows[3][1],
   l.rows[1][0]*r.rows[0][2] + l.rows[1][1]*r.rows[1][2] + l.rows[1][2]*r.rows[2][2] + l.rows[1][3]*r.rows[3][2],
   l.rows[1][0]*r.rows[0][3] + l.rows[1][1]*r.rows[1][3] + l.rows[1][2]*r.rows[2][3] + l.rows[1][3]*r.rows[3][3])
,vec<4,T>(   l.rows[2][0]*r.rows[0][0] + l.rows[2][1]*r.rows[1][0] + l.rows[2][2]*r.rows[2][0] + l.rows[2][3]*r.rows[3][0],
   l.rows[2][0]*r.rows[0][1] + l.rows[2][1]*r.rows[1][1] + l.rows[2][2]*r.rows[2][1] + l.rows[2][3]*r.rows[3][1],
   l.rows[2][0]*r.rows[0][2] + l.rows[2][1]*r.rows[1][2] + l.rows[2][2]*r.rows[2][2] + l.rows[2][3]*r.rows[3][2],
   l.rows[2][0]*r.rows[0][3] + l.rows[2][1]*r.rows[1][3] + l.rows[2][2]*r.rows[2][3] + l.rows[2][3]*r.rows[3][3])
,vec<4,T>(   l.rows[3][0]*r.rows[0][0] + l.rows[3][1]*r.rows[1][0] + l.rows[3][2]*r.rows[2][0] + l.rows[3][3]*r.rows[3][0],
   l.rows[3][0]*r.rows[0][1] + l.rows[3][1]*r.rows[1][1] + l.rows[3][2]*r.rows[2][1] + l.rows[3][3]*r.rows[3][1],
   l.rows[3][0]*r.rows[0][2] + l.rows[3][1]*r.rows[1][2] + l.rows[3][2]*r.rows[2][2] + l.rows[3][3]*r.rows[3][2],
   l.rows[3][0]*r.rows[0][3] + l.rows[3][1]*r.rows[1][3] + l.rows[3][2]*r.rows[2][3] + l.rows[3][3]*r.rows[3][3])
);}





}//namespace vecmat