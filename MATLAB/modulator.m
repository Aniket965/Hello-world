function y = modulator(x,fc,t)
  y = x.*cos(2.*pi.*fc.*t);
endfunction