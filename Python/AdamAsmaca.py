import time,random

isim=input("ismin ne? ")
time.sleep(0.5)
print("Merhaba %s! Bugün seninle bir adam asmaca oyunu yapıyoruz!"%(isim))
time.sleep(1)

kelimeler = """kırmızı turuncu sarı yeşil mavi lacivert mor beyaz siyah
             kahverengi

             kare üçgen dörtgen daire elips beşgen altıgen yedigen
             sekizgen

             elma armut kiraz üzüm muz karpuz kavun çilek greyfurt
             portakal

             karınca porsuk yarasa ayı kunduz deve kedi istiridye kobra
             puma çakal karga geyik köpek ördek kartal gelincik tilki kurbağa keçi
             kaz şahin aslan kertenkele lama köstebek maymun geyik panda papağan
             güvercin tavşan koç gergedan köpekbalığı koyun yılan örümcek leylek
             kuğu kaplan kurbağa alabalık hindi kaplumbağa gelincik balina kurt
             zebra"""
resimler  = (

"""
   _________
    |/
    |
    |
    |
    |
    |
    |___
    """,

"""
   _________
    |/   |
    |
    |
    |
    |
    |
    |___
    A""",

"""
   _________
    |/   |
    |   (_)
    |
    |
    |
    |
    |___
    ADA""",

"""
   ________
    |/   |
    |   (_)
    |    |
    |    |
    |
    |
    |___
    ADAM""",


"""
   _________
    |/   |
    |   (_)
    |   /|
    |    |
    |
    |
    |___
    ADAM A""",


"""
   _________
    |/   |
    |   (_)
    |   /|\\
    |    |
    |
    |
    |___
    ADAM ASM""",



"""
   ________
    |/   |
    |   (_)
    |   /|\\
    |    |
    |   /
    |
    |___
    ADAM ASMAC""",


"""
   ________
    |/   |
    |   (_)
    |   /|\\
    |    |
    |   / \\
    |
    |___
    ADAM ASMACA! :(""")
'''
while True:
    for i in resimler:
        print(i)
        print("***",random.choice(kelimeler.split()).upper(),"***")
        time.sleep(0.5)
'''
def çiz(kel,tah):
    yeni=""
    for i in kel:
        if i in tah:
            yeni+=i
        else:yeni+="-"
    return yeni

while True:
    time.sleep(0.5)
    seçilenKelime= random.choice(kelimeler.split()).upper()
    tahminler=""
    i=0
    while i!=7:
        print(resimler[i])
        print("Kelime: *",çiz(seçilenKelime,tahminler),"*")
        while True:
            ekle=input("bir harf tahmin et!:")
            if len(ekle) != 1:
                continue
            elif not ekle.isalpha():
                continue
            tahminler+= ekle.upper()
            break
        if ekle.upper() not in seçilenKelime:
            i+=1
        if "-" not in çiz(seçilenKelime,tahminler):break
    time.sleep(1)
    if i==7:
        print("Kaybettiniz :(")
        print("kelime:",seçilenKelime)
    else:
        print("* * * * *")
        print("Kazandınız! Kelime:",seçilenKelime)
        print("* * * * *")
    time.sleep(1)
    print("peki.. tekrar oynamak ister misin? ")
    time.sleep(0.5)
    tekrar=input("(e/h):")
    if tekrar=="e" or tekrar=="E" or tekrar.startswith(("e","E")):continue
    else:break
time.sleep(1)
print("program bitti!")
