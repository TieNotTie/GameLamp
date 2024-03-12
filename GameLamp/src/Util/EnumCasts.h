#pragma once

namespace Lamp {
	template<typename CastType = int, class T> inline T operator~ (T a) { return (T)~(CastType)a; }
	template<typename CastType = int, class T> inline T operator| (T a, T b) { return (T)((CastType)a | (CastType)b); }
	template<typename CastType = int, class T> inline T operator& (T a, T b) { return (T)((CastType)a & (CastType)b); }
	template<typename CastType = int, class T> inline T operator^ (T a, T b) { return (T)((CastType)a ^ (CastType)b); }
	template<typename CastType = int, class T> inline T& operator|= (T& a, T b) { return (T&)((CastType&)a |= (CastType)b); }
	template<typename CastType = int, class T> inline T& operator&= (T& a, T b) { return (T&)((CastType&)a &= (CastType)b); }
	template<typename CastType = int, class T> inline T& operator^= (T& a, T b) { return (T&)((CastType&)a ^= (CastType)b); }
}
