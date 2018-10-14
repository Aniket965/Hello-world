function w = demodulator(y,fc,t,x)
  w = y.*cos(2.*pi.*fc.*t+x);
endfunction