def golden_width(acc,leng):
    a,b = 0,1
    for i in range(acc):
        a,b = b,b+a
    gol_rat = b / a
    gol_wid = leng * gol_rat
    return(gol_wid)
