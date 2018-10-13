print '\n'.join("%i Byte = %i Bit = largest number: %i" % (j, j*8, 256**j-1) for j in (1 << i for i in xrange(8)))
