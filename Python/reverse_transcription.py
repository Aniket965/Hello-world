# Reverse transcribe a DNA string
# # If a character is not A, C, G, T or U it will be converted to X

import transcription 

def reverse_transcribe(sequence):
	return transcription.transcribe(sequence)[::-1]

def main():
	sequence = "AAATTTGGGCCCPPP"
	print "Original:"
	print sequence
	print "\nReverse Transcribed:"
	print reverse_transcribe(sequence)


if __name__ == '__main__':
	main()
