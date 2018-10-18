import java.util.Scanner;
import java.util.ArrayList;

public class Warungv2 {
	static Scanner sc = new Scanner(System.in);
	static String uname,pass,tipe,paket,pilihan_tipe,pilihan_paket,pilihan_bayar,jns_bank,jns_bayar,diskon,no_rek,cus1,cus2,cus3;
	static int jml_beli,total,grandTotal,cash,hrg_cus1,hrg_cus2,hrg_cus3;
	static ArrayList<String> menu_custom = new ArrayList<String>();
	static ArrayList<String> list_menu = new ArrayList<String>();
	static ArrayList<Integer> hrg_custom = new ArrayList<Integer>();

	public static void login(){
		System.out.println("\t+------------------------------------+");
		System.out.println("\t|       Catering Cash Register       |");
		System.out.println("\t+------------------------------------+");
		System.out.print("\t-> Username : ");uname=sc.nextLine();
		System.out.print("\t-> Password : ");pass=sc.nextLine();

		if (uname.equals("Gopla") && pass.equals("123")) {
			main();
		}else{
			System.out.println("\n\t-> Username / Password salah!");
			login();
		}
	}

	public static void main(){
		System.out.println("\t+------------------------------------+");
		System.out.println("\t|          Pilih Tipe Pesanan        |");
		System.out.println("\t+------------------------------------+");
		System.out.println("\t|1.      Menu Ringan                 |");
		System.out.println("\t|2.      Menu Berat                  |");
		System.out.println("\t|3.      Menu Custom                 |");
		System.out.println("\t+------------------------------------+");
		System.out.print("\t-> Pilihan : ");tipe=sc.nextLine();
            switch (tipe) {
                case "1":
                    pilihan_tipe="Menu Ringan";
                    menuRingan();
                    break;
                case "2":
                    pilihan_tipe="Menu Berat";
                    menuBerat();
                    break;
                case "3":
                    pilihan_tipe="Menu Custom";
                    menuCustom();
                    break;
                default:
                    System.out.println("\n\t-> Input salah! <-");
                    main();
                    break;
            }
	}

	public static void diskon(){
		if (jml_beli<=10){
			diskon="-";
			grandTotal=total;
		}else if (jml_beli<15) {
			diskon="15%";
			grandTotal=total-(total*15/100);
		}else if (jml_beli>=15 && jml_beli<=30) {
			diskon="20%";
			grandTotal=total-(total*20/100);
		}else if (jml_beli>30) {
			diskon="25%";
			grandTotal=total-(total*25/100);
		}
	}

	public static void menuRingan(){
		System.out.println("\t+-----------------------------------+");
		System.out.println("\t|     Pilihan Paket Menu Ringan     |");
		System.out.println("\t+-----------------------------------+");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t|1.  Paket A  |       |2.  Paket B  |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t| Muffin      |       | Croisant    |");
		System.out.println("\t| Roti Susu   |       | Roti Sosis  |");
		System.out.println("\t| Sundae      |       | Choco Sundae|");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t| Rp. 15,000  |       | Rp. 12,000  |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\n\t+-------------+       +-------------+");
		System.out.println("\t|3.  Paket C  |       |4.  Paket D  |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t| Kroket      |       | Sandwich    |");
		System.out.println("\t| Donat       |       | Mini Tart   |");
		System.out.println("\t| BerryIceCone|       | Pudding     |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t| Rp. 18,000  |       | Rp. 17,000  |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t|*Tekan 0 untuk kembali.            |");
		System.out.println("\t+-----------------------------------+");
		System.out.print("\n\t-> Pilihan      : ");paket=sc.nextLine();

		if (paket.equals("0")) {
			main();
		} else {
			System.out.print("\t-> Jumlah Beli  : ");jml_beli=sc.nextInt();	

			switch (paket) {
				case "1":
				case "A":{
					pilihan_paket="Paket A";
					list_menu.add("Muffin");
					list_menu.add("Roti Susu");
					list_menu.add("Sundae");
					total=15000*jml_beli;
					break;
				}

				case "2":
				case "B":{
					pilihan_paket="Paket B";
					list_menu.add("Croisant");
					list_menu.add("Roti Sosis");
					list_menu.add("Choco Sundae");
					total=12000*jml_beli;
					break;
				}

				case "3":
				case "C":{
					pilihan_paket="Paket C";
					list_menu.add("Kroket");
					list_menu.add("Donat");
					list_menu.add("BerryIceCone");
					total=18000*jml_beli;
					break;
				}

				case "4":
				case "D":{
					pilihan_paket="Paket D";
					list_menu.add("Sandwich");
					list_menu.add("Mini Tart");
					list_menu.add("Pudding");
					total=17000*jml_beli;
					break;
				}

				default:{
					System.out.println("\n\t-> Pilihan salah! <- \n");
					menuRingan();
					break;
				}				
			}
		}
	}

	public static void menuCustom(){
		System.out.println("\t+-----------------------------------+");
		System.out.println("\t|     Daftar Menu Paket Custom      |");
		System.out.println("\t+-----------------------------------+");
		System.out.println("\t+---------------+    +--------------+");
		System.out.println("\t|      Menu     |    |     Harga    |");
		System.out.println("\t+---------------+    +--------------+");
		System.out.println("\t|1. Nasi Hangat        Rp. 2,500    |");
		System.out.println("\t|2. Ayam Geprek        Rp. 7,000    |");
		System.out.println("\t|3. Ayam Crispy        Rp. 7,000    |");
		System.out.println("\t|4. Tahu Goreng        Rp. 4,000    |");
		System.out.println("\t|5. Kentang            Rp. 4,000    |");
		System.out.println("\t|6. Muffin             Rp. 3,000    |");
		System.out.println("\t|7. Croisant           Rp. 5,000    |");
		System.out.println("\t|8. Kroket             Rp. 4,000    |");
		System.out.println("\t|9. Sundae             Rp. 5,000    |");
		System.out.println("\t|10.Pudding            Rp. 5,000    |");
		System.out.println("\t+-----------------------------------+");
		System.out.println("\t|*Tekan 0 untuk kembali.            |");
		System.out.println("\t+-----------------------------------+");
		
		System.out.println("\n\t->Masukkan 3 menu yang ingin dipesan:");

		System.out.print("\t1. ");cus1=sc.next();
		if (cus1.equals("0")) {
			main();
		} else if(cus1.equals("1") || cus1.equals("2") || cus1.equals("3") ||cus1.equals("4") ||cus1.equals("5") || cus1.equals("6") ||cus1.equals("7") ||cus1.equals("8") ||cus1.equals("9") ||cus1.equals("10")){
			System.out.print("\t2. ");cus2=sc.next();
			if (cus2.equals("1") || cus2.equals("2") || cus2.equals("3") ||cus2.equals("4") ||cus2.equals("5") || cus2.equals("6") ||cus2.equals("7") ||cus2.equals("8") ||cus2.equals("9") ||cus2.equals("10")) {
				System.out.print("\t3. ");cus3=sc.next();
				if (cus3.equals("1") || cus3.equals("2") || cus3.equals("3") ||cus3.equals("4") ||cus3.equals("5") || cus3.equals("6") ||cus3.equals("7") ||cus3.equals("8") ||cus3.equals("9") ||cus3.equals("10")) {

						switch (cus1) {
			                case "1":
			                    cus1 = "Nasi Hangat";
			                    hrg_cus1 = 2500;
			                    break;
			                case "2":
			                    cus1 = "Ayam Geprek";
			                    hrg_cus1 = 7000;
			                    break;
			                case "3":
			                    cus1 = "Ayam Crispy";
			                    hrg_cus1 = 7000;
			                    break;
			                case "4":
			                    cus1 = "Tahu Goreng";
			                    hrg_cus1 = 4000;
			                    break;
			                case "5":
			                    cus1 = "Kentang";
			                    hrg_cus1 = 4000;
			                    break;
			                case "6":
			                    cus1 = "Muffin";
			                    hrg_cus1 = 3000;
			                    break;
			                case "7":
			                    cus1 = "Croisant";
			                    hrg_cus1 = 5000;
			                    break;
			                case "8":
			                    cus1 = "Kroket";
			                    hrg_cus1 = 4000;
			                    break;
			                case "9":
			                    cus1 = "Sundae";
			                    hrg_cus1 = 5000;
			                    break;
			                case "10":
			                    cus1 = "Pudding";
			                    hrg_cus1 = 5000;
			                    break;
			                default:
			                    System.out.println("\n\t-> Pilihan salah! <- \n");
			                    break;
			            }

			            switch (cus2) {
			                case "1":
			                    cus2 = "Nasi Hangat";
			                    hrg_cus2 = 2500;
			                    break;
			                case "2":
			                    cus2 = "Ayam Geprek";
			                    hrg_cus2 = 7000;
			                    break;
			                case "3":
			                    cus2 = "Ayam Crispy";
			                    hrg_cus2 = 7000;
			                    break;
			                case "4":
			                    cus2 = "Tahu Goreng";
			                    hrg_cus2 = 4000;
			                    break;
			                case "5":
			                    cus2 = "Kentang";
			                    hrg_cus2 = 4000;
			                    break;
			                case "6":
			                    cus2 = "Muffin";
			                    hrg_cus2 = 3000;
			                    break;
			                case "7":
			                    cus2 = "Croisant";
			                    hrg_cus2 = 5000;
			                    break;
			                case "8":
			                    cus2 = "Kroket";
			                    hrg_cus2 = 4000;
			                    break;
			                case "9":
			                    cus2 = "Sundae";
			                    hrg_cus2 = 5000;
			                    break;
			                case "10":
			                    cus2 = "Pudding";
			                    hrg_cus2 = 5000;
			                    break;
			                default:
			                    System.out.println("\n\t-> Pilihan salah! <- \n");
			                    break;
			            }

			            switch (cus3) {
			                case "1":
			                    cus3 = "Nasi Hangat";
			                    hrg_cus3 = 2500;
			                    break;
			                case "2":
			                    cus3 = "Ayam Geprek";
			                    hrg_cus3 = 7000;
			                    break;
			                case "3":
			                    cus3 = "Ayam Crispy";
			                    hrg_cus3 = 7000;
			                    break;
			                case "4":
			                    cus3 = "Tahu Goreng";
			                    hrg_cus3 = 4000;
			                    break;
			                case "5":
			                    cus3 = "Kentang";
			                    hrg_cus3 = 4000;
			                    break;
			                case "6":
			                    cus3 = "Muffin";
			                    hrg_cus3 = 3000;
			                    break;
			                case "7":
			                    cus3 = "Croisant";
			                    hrg_cus3 = 5000;
			                    break;
			                case "8":
			                    cus3 = "Kroket";
			                    hrg_cus3 = 4000;
			                    break;
			                case "9":
			                    cus2 = "Sundae";
			                    hrg_cus3 = 5000;
			                    break;
			                case "10":
			                    cus3 = "Pudding";
			                    hrg_cus3 = 5000;
			                    break;
			                default:
			                    System.out.println("\n\t-> Pilihan salah! <- \n");
			                    break;
			            }						

			            System.out.print("\t-> Jumlah Beli : ");jml_beli=sc.nextInt();
				}else {
					System.out.println("\n\t-> Pilihan salah! <- \n");
    				menuCustom();				
				}	
			}else {
				System.out.println("\n\t-> Pilihan salah! <- \n");
        		menuCustom();
			}
		}else {
			System.out.println("\n\t-> Pilihan salah! <- \n");
        	menuCustom();
		}
			
			menu_custom.add(cus1);
			menu_custom.add(cus2);
			menu_custom.add(cus3);
			hrg_custom.add(hrg_cus1);
			hrg_custom.add(hrg_cus2);
			hrg_custom.add(hrg_cus3);
			total=(hrg_custom.get(0)+hrg_custom.get(1)+hrg_custom.get(2))*jml_beli;
			pilihan_paket = "Paket Custom";	
	}

	public static void menuBerat(){
		System.out.println("\t+-----------------------------------+");
		System.out.println("\t|      Pilihan Paket Menu Berat     |");
		System.out.println("\t+-----------------------------------+");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t|1.  Paket A  |       |2.  Paket B  |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t| Ayam Crispy |       | Ayam Geprek |");
		System.out.println("\t| Nasi Hangat |       | Nasi Hangat |");
		System.out.println("\t| Kentang     |       | Tahu Goreng |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t| Rp. 13,500  |       | Rp. 13,500  |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\n\t+-------------+       +-------------+");
		System.out.println("\t|3.  Paket C  |       |4.  Paket D  |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t| Mapo Tofu   |       | Tamagoyaki  |");
		System.out.println("\t| Nasi Hangat |       | Nasi Hangat |");
		System.out.println("\t| Tempura     |       | Kroket      |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t| Rp. 14,000  |       | Rp. 15,000  |");
		System.out.println("\t+-------------+       +-------------+");
		System.out.println("\t|*Tekan 0 untuk kembali.            |");
		System.out.println("\t+-----------------------------------+");
		System.out.print("\n\t-> Pilihan     : ");paket=sc.nextLine();

		if (paket.equals("0")) {
			main();
		} else {
			System.out.print("\t-> Jumlah Beli : ");jml_beli=sc.nextInt();

			switch (paket) {
				case "1":
				case "A":{
					pilihan_paket="Paket A";
					list_menu.add("Ayam Crispy");
					list_menu.add("Nasi Hangat");
					list_menu.add("Kentang");
					total=13500*jml_beli;
					break;
				}

				case "2":
				case "B":{
					pilihan_paket="Paket B";
					list_menu.add("Ayam Geprek");
					list_menu.add("Nasi Hangat");
					list_menu.add("Tahu Goreng");
					total=13500*jml_beli;
					break;
				}

				case "3":
				case "C":{
					pilihan_paket="Paket C";
					list_menu.add("Mapo Tofu");
					list_menu.add("Nasi Hangat");
					list_menu.add("Tempura");
					total=14000*jml_beli;
					break;
				}

				case "4":
				case "D":{
					pilihan_paket="Paket D";
					list_menu.add("Tamagoyaki");
					list_menu.add("Nasi Hangat");
					list_menu.add("Kroket");
					total=15000*jml_beli;
					break;
				}

				default:{
					System.out.println("\n\t-> Pilihan salah! <- \n");
					menuBerat();
					break;
				}
			}	
		}				
	}

	public static void pembayaran(){
		System.out.println("\t+------------------------------------+");
		System.out.println("\t|           Pilih Pembayaran         |");
		System.out.println("\t+------------------------------------+");
		System.out.println("\t|1.      Cash                        |");
		System.out.println("\t|2.      Transfer                    |");
		System.out.println("\t+------------------------------------+");
		System.out.print("\t-> Pilihan : ");pilihan_bayar=sc.next();

            switch (pilihan_bayar) {
                case "1":
                    jns_bayar="Cash";
                    cash();
                    break;
                case "2":
                    jns_bayar="Transfer";
                    transf();
                    break;
                default:
                    System.out.println("\n\t-> Pilihan salah! <- \n");
                    pembayaran();
                    break;
            }
	}

	public static void cash(){
		System.out.print("\t-> Total           : Rp. ");
		System.out.printf("%,d", grandTotal);
		System.out.print("\n\t-> Bayar           : Rp. ");cash=sc.nextInt();

		if (grandTotal>cash) {
			System.out.println("\t-> Maaf, uang Anda tidak mencukupi tagihan! <-\n");
			pembayaran();
		}
	}

	public static void transf(){
		System.out.println("\t+------------------------------------+");
		System.out.println("\t|             Pilih Bank             |");
		System.out.println("\t+------------------------------------+");
		System.out.println("\t|1.      BNI                         |");
		System.out.println("\t|2.      BCA                         |");
		System.out.println("\t|3.      BRI                         |");
		System.out.println("\t|4.      Mandiri                     |");
		System.out.println("\t+------------------------------------+");
		System.out.print("\t-> Pilihan : ");jns_bank=sc.next();
		
		switch (jns_bank) {
			case "1":
			case "BNI":{
				jns_bank="BNI";
				break;
			}

			case "2":
			case "BCA":{
				jns_bank="BCA";
				break;
			}

			case "3":
			case "BRI":{
				jns_bank="BRI";
				break;
			}

			case "4":
			case "Mandiri":{
				jns_bank="Mandiri";
				break;
			}

			default:{
				System.out.println("\n\t-> Pilihan salah! <- \n");
				transf();
			}
		}
		System.out.print("\t-> Masukkan Rekening : ");no_rek=sc.next();
	}

	public static void struk(){
		System.out.println("\n\t+------------------------------------+");
		System.out.println("\t|          Rincian Pembelian         |");
		System.out.println("\t+------------------------------------+");
		System.out.println("\t| Kasir : "+uname+"                      |");
		System.out.println("\t+------------------------------------+");
		System.out.println("\t -> Tipe Menu     : "+pilihan_tipe);
		System.out.println("\t -> Paket Pilihan : "+pilihan_paket);
		System.out.println("\t -> Daftar Menu   : ");

		if (pilihan_paket.equals("Paket Custom")) {
			System.out.println("\t\t 1. "+menu_custom.get(0));
			System.out.println("\t\t 2. "+menu_custom.get(1));
			System.out.println("\t\t 3. "+menu_custom.get(2));		
		}else {
			System.out.println("\t\t 1. "+list_menu.get(0));
			System.out.println("\t\t 2. "+list_menu.get(1));
			System.out.println("\t\t 3. "+list_menu.get(2));
		}

		System.out.println("\t -> Jumlah Beli   : "+jml_beli+" buah");
		System.out.println("\t -> Pembayaran    : "+jns_bayar);

		System.out.print("\t -> Harga         : Rp. ");
		System.out.printf("%,d", total);

		System.out.println("\n\t -> Diskon        : "+diskon);

		System.out.print("\t -> Total         : Rp. ");
		System.out.printf("%,d", grandTotal);
		
		if (jns_bayar.equals("Cash")) {
			System.out.print("\n\t -> Bayar         : Rp. ");
			System.out.printf("%,d", cash);
			System.out.print("\n\t -> Kembalian     : Rp. ");
			System.out.printf("%,d", (cash-grandTotal));
		}else{
			System.out.print("\n\t -> Bank          : "+jns_bank);
			System.out.print("\n\t -> Saldo dari    : "+no_rek+"\n\t    telah dikurangi sebesar\n\t    Rp. ");
			System.out.printf("%,d", grandTotal);
		}

		System.out.println("\n\t+------------------------------------+");
		System.out.println("\t|            Terima Kasih            |");
		System.out.println("\t+------------------------------------+");
	}

	public static void main(String[] args) {
		login();
		diskon();
		pembayaran();
		struk();
	}
}
