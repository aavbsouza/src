
#include<rsf.h>

void sf_wvlt_frck(int nf,
	sf_complex *buf,		// in frequency; out = ricker wavelet
	float *par)		/* 0 ref freq, 1 phase */
/*< frequency domain ricker wavelet >*/
{
	int ifr;
	double freq;
	for(ifr=0;ifr<nf;ifr++)
	{
		freq=crealf(buf[ifr])/par[0];
		freq=freq*freq;
		buf[ifr]=4.0*sqrt(M_PI)*freq*exp(-freq);
	}
}

void sf_wvlt_rck(int nt,
	float *buf,		// in time index; out = ricker wavelet
	float *par)		/* 0 ref freq, 1 phase */
/*< time domain ricker wavelet >*/
{
	int it;
	double d1, w0;

	w0 = 2.0*M_PI*par[0];
	for(it=0; it<nt; it++)
	{
		d1 = w0 * buf[it];
		d1 = d1*d1;
		buf[it] = (1.0 - 0.5*d1)*exp(-0.25*d1);
	}
}




