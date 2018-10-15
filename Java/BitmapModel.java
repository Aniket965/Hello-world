import java.nio.file.*;
import java.io.*;
import java.util.List;
import java.util.ArrayList;

import com.sun.javafx.image.PixelGetter;

/**
 * @author Luca Di Bello
 * @version 11.11.17
 * 
 * Questa classe permette di analizzare un file BitMap (passato tramite array di tipo byte) e ricavarne informazioni.
 */


public class BitmapModel{

    /**
     * Array contenente tutti i bit dell'immagine.
     */
    private int[] data;

    /**
     * Metodo costruttore.
     * @param bytes Array di byte contenente tutti i dati dell'immagine.
     */
    public BitmapModel(byte[] bytes){
        this.data = new int[bytes.length];

        for(int i = 0; i < data.length;i++){
            data[i] = bytes[i] & 0xFF;
        }
    }

    /**
     * Metodo che permette di ricavare il Magic Number in formato numerico.
     * @return Magic Number in formato numerico.
     */
    public String getMagicNumber(){
        String a = Integer.toString(data[0]);
        String b = Integer.toString(data[1]);
        
        return a+b;
    }
    
    /**
     * Metodo che permette di ricavare il Magic Number in formato alfabetico.
     * @return Magic Number in formato alfabetico.
     */
    public String getSignature(){
        Character a = (char) data[0];
        Character b = (char) data[1];
        return Character.toString(a) + Character.toString(b);
    }

    /**
     * Metodo che permette di ricavare il peso del file in Byte
     * @return Peso del file in Byte
     */
    public long getFileSize(){
        long value = getBytesAsLong(0x02, 4);
        return value;
    }

    /**
     * Metodo che permette di ricavare il primo Reserved code.
     * @return Valore primo Reserved Code.
     */
    public int getReserved1(){
        long value = getBytesAsLong(0x06, 2);
        return (int) value;
    }

    /**
     * Metodo che permette di ricavare il secondo Reserved code.
     * @return Valore secondo Reserved Code.
     */
    public int getReserved2(){
        long value = getBytesAsLong(0x08, 2);
        return (int) value;
    }
    
    /**
     * Metodo che permette di ricavare l'Offset dell'immagine.
     * @return Offset dell'immagine.
     */
    public long getOffset(){
        long value = getBytesAsLong(0x0a, 4);
        return value;
    }

    /**
     * Metodo che permette di ricavare la grandezza del DIB Header.
     * @return grandezza del DIB Header.
     */
    public long getHeaderSize(){
        long value = getBytesAsLong(0x0e, 2);
        return value;
    }

    /**
     * Metodo che permette di ricavare la larghezza dell'immagine.
     * @return larghezza dell'immagine.
     */
    public long getWidth(){
        long value = getBytesAsLong(0x12, 4);
        return value;
    }

    /**
     * Metodo che permette di ricavare l'altezza dell'immagine.
     * @return Altezza dell'immagine.
     */
    public long getHeight(){     
        long value = getBytesAsLong(0x16, 4);
        return value;
    }

    /**
    * Metodo che permette di ricavare i Color Planes dell'immagine.
    * @return numero Color Planes.
    */
    public int getPlanes(){
        long value = getBytesAsLong(0x1a, 2);
        return (int) value;
    }

    /**
     * Metodo che permette di ricavare il rapporto tra bits e pixel (bits/pixel).
     * @return Rapporto bits/pixel.
     */
    public int getBitsPerPixel(){
        long value = getBytesAsLong(0x1c, 2);
        return (int) value;
    }

    /**
     * Metodo che permette di ricavare il codice identificativo per metodo di compressione.
     * @return Codice identificativo per metodo di compressione.
     */
    public long getCompressionMethod(){
        long value = getBytesAsLong(0x1e, 2);
        return value;
    }

    /**
     * Metodo che permette di convertire il codice di compressione ad una stringa con il nome della compressione utilizzata.
     * @return Nome della compressione utilizzata.
     */
    public String getCompressionMethodName(){
        long code = getCompressionMethod();
        
        if(code == 0){
            return "BI_RGB" + " (none)";
        }
        else if(code == 1){
            return "BI_RLE8" + " (RLE 8-bit/pixel)" ;
        }
        else if(code == 2){
            return "BI_RLE4" + " (RLE 4-bit/pixel)";         
        }
        else if(code == 3){
            return "BI_BITDIELDS" + " (OS22XBITMAPHEADER: Huffman 1D)";      
        }
        else if(code == 4){
            return "BI_JPEG" + " (OS22XBITMAPHEADER: RLE-24)";    
        }
        else if(code == 5){
            return "BI_PNG";    
        }
        else if(code == 6){
            return "BI_ALPHABITFIELDS" + " (RGBA bit fields masks)";   
        }
        else if(code == 11){
            return "BI_CMYK" + " (none)";    
        }
        else if(code == 12){
            return "BI_CMYKRLE8" + " (RLE-8)";     
        }
        else if(code == 13){
            return "BI_CMYKRLE4" + " (RLE-4)";   
        }
        else{
            return "UNKNOWN";
        }
    }

    /**
     * Metodo che permette di ricavare la grandezza effettiva dell'immagine (byte).
     * @return Grandezza effettiva dell'immagine (byte).
     */
    public long getImageSize(){
        long value = getBytesAsLong(0x22, 4);
        return value;
    }

    /**
     * Metodo che permette di ricavare la risoluzione orizzontale (pixel/metro).
     * @return Risoluzione orizzontale (pixel/metro).
     */
    public long getResolutionH(){
        long value = getBytesAsLong(0x26, 4);
        return value;
    }

    /**
     * Metodo che permette di ricavare la risoluzione verticale (pixel/metro).
     * @return Risoluzione verticale (pixel/metro).
     */
    public long getResolutionV(){
        long value = getBytesAsLong(0x2a, 4);
        return value;
    }

    /**
     * Metodo che permette di ricavare il numero di colori utilizzati.
     * @return Numero di colori.
     */
    public long getColorsNumber(){
        long value = getBytesAsLong(0x30, 2);
        return value;
    }

    /**
     * Metodo che permette di ricavare il numero di colori importanti utilizzati.
     * @return Numero di colori importanti.
     */
    public long getImportantColors(){
        long value = getBytesAsLong(0x32, 4);
        return value;
    }

    /**
     * Metodo che permette di ricavare il numero di Byte utilizzati per ogni singola riga di pixel.
     * @return Numero di Byte utilizzati per ogni riga di pixel.
     */
    public long getRowSize(){
        return getWidth() * getBitsPerPixel();
    }
    /**
     * Metodo che permette di convertire dei byte scritti in formato "Little Endian" e convertirli in decimale.
     * @param offset Posizione da dove deve iniziare a convertire.
     * @param lan Per quante posizioni a destra deve continuare a convertire (vertical span).
     * @return Valore dei byte.
     * 
     */
    private long getBytesAsLong(int offset, int lan){
        if(lan > 1){
            --lan;
        }
        else if(lan == 0){
            ++lan;
        }
        
        long value = 0;
        for(int i = (offset + lan); i >= offset; i--){
            value = value | data[i] << (8 * (i - offset));
        }

        return value;
    }

    public void dumpPixelsRGB(){
		int padding = 0;
		long x = getWidth() * 3;
		while(x%4 != 0){
			padding++;
			x++;
		}
		long size = data.length - padding - getWidth() * 3;
		long width = getWidth();
		long height = getHeight();	
		for(long i = 0; i < height; i++){
			for(long k = 0; k < width; k++){
				int indice = (int)size;
				System.out.print(String.format("%02X",data[indice+2]) + String.format("%02X",data[indice+1]) + String.format("%02X",data[indice]) + "\t");
				size += 3;
			}
			size = size - (getWidth() * 3 + padding) * 2 + padding;
			System.out.println();
		}
    }
    
    public int[] dumpPixelsRGBReturn(){
        int padding = 0;

        int[] pixels = new int[data.length];
        
        long x = getWidth() * 3;
		while(x%4 != 0){
			padding++;
			x++;
		}
		long size = data.length - padding - getWidth() * 3;
		long width = getWidth();
		long height = getHeight();	
		for(long i = 0; i < height; i++){
			for(long k = 0; k < width; k++){
                int indice = (int)size;

                pixels[indice+2] = data[indice+2];
                pixels[indice+1] = data[indice+1];
                pixels[indice] = data[indice];

				//System.out.print(String.format("%02X",data[indice+2]) + String.format("%02X",data[indice+1]) + String.format("%02X",data[indice]) + "\t");
				size += 3;
			}
			size = size - (getWidth() * 3 + padding) * 2 + padding;
            
        }

        return pixels;
	}

	public void getGrayScale(){
		int padding = 0;
		long x = getWidth() * 3;
		while(x%4 != 0){
			padding++;
			x++;
		}
		long size = data.length - padding - getWidth() * 3;
		long width = getWidth();
		long height = getHeight();	
		for(long i = 0; i < height; i++){
			for(long k = 0; k < width; k++){
				int indice = (int)size;
				int media = (data[indice+2] + data[indice+1] + data[indice]) / 3;
                
                System.out.print(String.format("%02X",media) + String.format("%02X",media) + String.format("%02X",media) + "\t");
				size += 3;
			}
			size = size - (getWidth() * 3 + padding) * 2 + padding;
			System.out.println();
		}
    }

    public void getHtmlImage(String fileName){

        int[] pixels = dumpPixelsRGBReturn();
        Path fileHtml = Paths.get(fileName + "-immagine.html");
        List<String> pixelsText = new ArrayList<String>(); 
        
        try{
            Files.createFile(fileHtml);
            int pixelsCounter = 0;
            for(int i = 0; i < pixels.length - 2; i+=3){
                //CICLA OGNI 3
                
                if(pixelsCounter > getWidth())
                {
                    pixelsCounter = 0;
                    System.out.println(pixelsCounter);
                    pixelsText.add("<br>");
                }

                String rgbPart = "rgb(" + pixels[i+2] + "," + pixels[i+1] + "," + pixels[i] + ");";
                String backgroundColorPart = "background-color:" + rgbPart;
                String style = "style=" + "'" + backgroundColorPart + "'";
                String full = "<span " + style + ">" + "&#8201;" + "</span>";
                pixelsText.add(full);
                pixelsCounter++;
            }
            Files.write(fileHtml,pixelsText);
        }
        catch(IOException e){
            System.out.println("Error while creating the html file.");
        }
    }
}