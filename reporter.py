#!/usr/bin/python3
#tkinter: sudo apt-get install python3-tk
#matplotlib: pip3 install matplotlib 

import matplotlib.pyplot as pltS
import subprocess as sbp
import numpy as np
import sys
import csv

N=20 #ilość powtórzeń pętli
nazwa_programu="lab6.exe"
dane_wejsciowe=[str(2**i) for i in range(4,17)]
flagi=["0.1","1.0","1.5","2.0"]
podpis=flagi[:]
flagi=["-s d -O r -o " + s for s in flagi]
os_x="Rozmiar Drzewa BST"    #podpis na osi x
os_y="Czas wypełnienia i wyszukania"    #podpis na osi y
tytul="dodawanie elementów rosnąco"
kolor="bgrcmykw"            #kolory na wykresie



#FAIL
#podpis_wz=["O(n*logn)"] 
#n=0.00000885       #mnożnik do wzorców
#danes=[float(i) for i in np.arange(int(dane_wejsciowe[0]),
#                  int(dane_wejsciowe[-1]),
#                  int(dane_wejsciowe[0]))]
#dane=[n*i for i in danes]  

#wzorce=[#dane*np.log2(dane)+[i*11+i for i in dane#],       #nlogn
    #np.log2(4*dane),               #logn
    #[i*i+i for i in dane ],                #n^2
    #dane                       #n
    #]


if len(podpis)!=len(flagi):
    sys.exit("ROZMIAR TABLICY FLAG NIE JEST RÓWNY ROZMIAROWI TABLICY PODPISÓW!!! WYCHODZĘ")
    

print("Podaj jak mają się nazywać pliki w których zapisze wyniki...")
print("!!!UWAŻAJ BO CELOWO NADPISUJĘ!!!")
wykres1=input('Pierwszy plik-skala liniowa:\n')
wykres2=input('Drugi plik-skala logarytmiczna\n')
tabela=input('Trzeci plik-tabela z wynikami\n')
print("Skrypt może milczy, ale to dlatego, że tak długo działają odpalone programy")
print("Usiądź wygodnie i czekaj, bo jeszcze daleko do wyników :-)")


srednie_wyniki_flagi={}
for j in flagi:
    wyniki_srednie=[]
    for i in dane_wejsciowe:
        sredni=0
        for k in range(0,N):
            p=float(sbp.run(["./"+nazwa_programu+" "+"-r "+i+" "+j],
                    shell=True,
                    stdout=sbp.PIPE)
                    .stdout)
            sredni+=p
            
        wyniki_srednie.append((1000*sredni)/N)    #zamień na milisekundy
    srednie_wyniki_flagi[j]=wyniki_srednie[:]


csvfile=open(tabela+'.csv', 'w')
fieldnames = ['Rozmiar', 'Czas[ms]','Flaga']
writer = csv.DictWriter(csvfile, fieldnames=fieldnames, dialect='excel-tab')
writer.writeheader()
print("Oto średnie wyniki dla kolejnego wejścia(ms):")
for j in srednie_wyniki_flagi:
    print("Dla flagi: ",j)
    writer.writerow({'Flaga': j})
    h=0
    for i in srednie_wyniki_flagi[j] :
        print(dane_wejsciowe[h],format(i, '.8f'))
        writer.writerow({'Rozmiar': dane_wejsciowe[h], 'Czas[ms]': format(i, '.8f')})
        h+=1

plt.figure(1)

for l in range(0,len(podpis)):
    plt.plot(
    dane_wejsciowe,
    srednie_wyniki_flagi[flagi[l]],
    kolor[l]+'o-',
    label=podpis[l])

#for l in range(0,len(wzorce)):
#   plt.plot(
#   danes,
#   wzorce[l], 
#   kolor[l]+'--',
#   label=podpis_wz[l])


figure = plt.gcf() #powiększam figure
figure.set_size_inches(6, 4)

plt.legend(bbox_to_anchor=(1, 1),loc=2, borderaxespad=0.)
plt.title(tytul+"-Skala Liniowa")
plt.ylabel(os_y)
plt.xlabel(os_x)
plt.grid(True)

plt.savefig(wykres1,bbox_inches='tight',papertype='a1',dpi=255)

plt.figure(2)
for l in range(0,len(flagi)):
    plt.loglog(
    dane_wejsciowe,
    srednie_wyniki_flagi[flagi[l]],
    kolor[l]+'o-',
    label=podpis[l])

#for l in range(0,len(wzorce)):
#   plt.loglog(
#   danes,
#   wzorce[l], 
#   kolor[l]+'--',
#   label=podpis_wz[l])

figure = plt.gcf() #powiększam figure
figure.set_size_inches(6, 4)

plt.legend(bbox_to_anchor=(1, 1),loc=2, borderaxespad=0.)
plt.title(tytul+"-Skala logarytmiczna")
plt.ylabel(os_y)
plt.xlabel(os_x)    
plt.grid(True)


plt.savefig(wykres2,bbox_inches='tight',papertype='a1',dpi=255)


plt.show()





