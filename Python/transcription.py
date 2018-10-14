# Transcribe a DNA string
# If a character is not A, C, G, T or U it will be converted to X

def transcribe(sequence):
	transcribed = []

	for b in sequence.upper():
		if b == "A":
			transcribed.append("T")
		elif b == "C":
			transcribed.append("G")
		elif b == "G":
			transcribed.append("C")
		elif (b == "T" or b == "U"):
			transcribed.append("A")
		else:
			transcribed.append("X")

	return "".join(transcribed)

def main():
	sequence = "ATGCPGTCA"
	print "Original:", sequence
	print "Transcribed:", transcribe(sequence)


if __name__ == '__main__':
	main()
