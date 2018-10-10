function v = Filter(w,fc,fs)
  [b,a] = butter(3,1/20);
  v = filter(b,a,w);
endfunction
