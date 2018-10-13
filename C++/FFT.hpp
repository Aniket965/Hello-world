#include <vector>  // std::vector
#include <complex> // std::complex

#define _USE_MATH_DEFINES // M_PI
#include <cmath> // std::sin, std::cos

using base_t  = std::complex<double>;
using vCoef_t = std::vector<base_t>;

//====================================================================================================================================
//!
//! \brief       Realization of FFT(Fast Fourier transform) - a method that allows calculating the DFT(discrete Fourier transform),
//!              which is used to convolve polynomials
//!
//! \param[out]  A  Array of polynomial coefficients; result will be here also
//!         		 
//!				 T(N) = O(NlogN)
//!              M(N) = O(N)
//!
//====================================================================================================================================

void FFT(vCoef_t &A)
{
	auto N{ A.size() };
	if (N == 1)
		return;

	vCoef_t A0(N >> 1),
		    A1(N >> 1);
	for (auto i{ 0ull }, j{ 0ull }; i < N; i += 2, ++j)
	{
		A0[j] = A[i];
		A1[j] = A[i + 1];
	}

	FFT(A0);
	FFT(A1);

	double alf = 2 * M_PI / static_cast<double>(N);

	N >>= 1;

	base_t w{ 1 },
		   wn{ std::cos(alf), std::sin(alf) };
	for (auto i{ 0ull }; i < N; ++i)
	{
		A[i]     = A0[i] + w * A1[i];
		A[i + N] = A0[i] - w * A1[i];

		w *= wn;
	}
}

//====================================================================================================================================
//!
//! \brief       Realization of IFFT(Inverse fast Fourier transform) algorithm, which is used to reconstruct 
//!              the coefficients of the polynomial from the values at the points, the interpolation analog
//!
//! \param[out]  A  Array of polynomial coefficients; result will be here also
//!         		 
//!				 T(N) = O(NlogN)
//!              M(N) = O(N)
//!
//====================================================================================================================================

void IFFT(vCoef_t &A)
{
	auto N = A.size();
	if (N == 1)
		return;

	vCoef_t A0(N >> 1),
		    A1(N >> 1);
	for (auto i{ 0ull }, j{ 0ull }; i < N; i += 2, ++j)
	{
		A0[j] = A[i];
		A1[j] = A[i + 1];
	}

	IFFT(A0);
	IFFT(A1);

	double alf = -2 * M_PI / static_cast<double>(N);

	N >>= 1;

	base_t w{ 1 },
		   wn{ std::cos(alf), std::sin(alf) };
	for (auto i{ 0ull }; i < N; ++i)
	{
		A[i]     = (A0[i] + w * A1[i]) / 2.;
		A[i + N] = (A0[i] - w * A1[i]) / 2.;

		w *= wn;
	}
}
