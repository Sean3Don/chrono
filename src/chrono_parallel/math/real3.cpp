#include "chrono_parallel/math/sse.h"
#include "chrono_parallel/math/simd.h"
#include "chrono_parallel/math/real3.h"

namespace chrono {

//========================================================
real3 operator+(const real3& a, const real3& b) {
    return simd::Add(a, b);
}
real3 operator-(const real3& a, const real3& b) {
    return simd::Sub(a, b);
}
real3 operator*(const real3& a, const real3& b) {
    return simd::Mul(a, b);
}
real3 operator/(const real3& a, const real3& b) {
    return simd::Div(a, b);
}
//========================================================
real3 operator+(const real3& a, real b) {
    return simd::Add(a, simd::Set(b));
}
real3 operator-(const real3& a, real b) {
    return simd::Sub(a, simd::Set(b));
}
real3 operator*(const real3& a, real b) {
    return simd::Mul(a, simd::Set(b));
}
real3 operator/(const real3& a, real b) {
    return simd::Div(a, simd::Set(b));
}
real3 operator*(real lhs, const real3& rhs) {
    return simd::Mul(simd::Set(lhs), rhs);
}
real3 operator/(real lhs, const real3& rhs) {
    return simd::Div(simd::Set(lhs), rhs);
}
real3 operator-(const real3& a) {
    return simd::Negate(a);
}
//========================================================

real Dot(const real3& v1, const real3& v2) {
    return simd::Dot3(v1, v2);
}
real Dot(const real3& v) {
    return simd::Dot3(v);
}
real3 Normalize(const real3& v) {
    return simd::Normalize3(v);
}
real Length(const real3& v) {
    return Sqrt(simd::Dot3(v));
}
real3 Sqrt(const real3& v) {
    return simd::SquareRoot(v);
}
real3 Cross(const real3& b, const real3& c) {
    return simd::Cross3(b.array, c.array);
}
real3 Abs(const real3& v) {
    return simd::Abs(v);
}
real3 Sign(const real3& v) {
    return simd::Max(simd::Min(v, simd::Set(1)), simd::Set(-1));
}
real3 Max(const real3& a, const real3& b) {
    return simd::Max(a, b);
}

real3 Min(const real3& a, const real3& b) {
    return simd::Min(a, b);
}

real3 Max(const real3& a, const real& b) {
    return simd::Max(a, simd::Set(b));
}

real3 Min(const real3& a, const real& b) {
    return simd::Min(a, simd::Set(b));
}
real Max(const real3& a) {
    return simd::Max(a);
}
real Min(const real3& a) {
    return simd::Min(a);
}
real3 Clamp(const real3& a, const real3& clamp_min, const real3& clamp_max) {
    return simd::Max(clamp_min, simd::Min(a, clamp_max));
}
bool operator==(const real3& a, const real3& b) {
    return (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]);
    // return simd::IsEqual(a, b);
}
real3 Round(const real3& v) {
    return simd::Round(v);
}
bool IsZero(const real3& v) {
    real3 t = simd::Abs(v);
    return t[0] < C_EPSILON && t[1] < C_EPSILON && t[2] < C_EPSILON;
}
}
