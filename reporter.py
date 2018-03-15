#!/usr/bin/python3
#tkinter: sudo apt-get install python3-tk
#matplotlib: pip3 install matplotlib 

import matplotlib.pyplot as plt
import subprocess as sbp
import numpy as np
import sys
import csv
#TODO: translate to english
N=10 #ilość powtórzeń pętli
nazwa_programu="main.exe"
files=[10, 20, 50, 100]
schedulers=["sortR", "opt2" ]
dane_wejsciowe=["-f pliki/in"+ str(f) + ".txt" for f in files] 
flagi=["-s "+ s for s in schedulers]
podpis=files[:]
os_x="Rozmiar problemu"    #podpis na osi x
os_y="czas wykonania"    #podpis na osi y
tytul="Szeregowanie Zadań"
kolor="bgrcmykw"            #kolory na wykresie


if len(podpis)!=len(dane_wejsciowe):
    sys.exit("ROZMIAR TABLICY FLAG NIE JEST RÓWNY ROZMIAROWI TABLICY PODPISÓW!!! WYCHODZĘ")
    
wykres1="lin"
wykres2="log"
tabela="tab"
catalog="results/"

srednie_wyniki_flagi={}
for j in flagi:
    wyniki_srednie=[]
    for i in dane_wejsciowe:
        sredni=0
        for k in range(0,N):
            p=float(sbp.run(["./"+nazwa_programu+" " + i + " " + j],
                    shell=True,
                    stdout=sbp.PIPE)
                    .stdout)
            sredni+=p
            
        wyniki_srednie.append((1000*sredni)/N)    #zamień na milisekundy
    srednie_wyniki_flagi[j]=wyniki_srednie[:]


csvfile=open(catalog+tabela+'.csv', 'w')
fieldnames = ['Rozmiar', 'Czas[ms]','Flaga']
writer = csv.DictWriter(csvfile, fieldnames=fieldnames, dialect='excel-tab')
writer.writeheader()
print("Oto średnie wyniki dla kolejnego wejścia(ms):")
for j in srednie_wyniki_flagi:
    print("Dla flagi: ",j)
    writer.writerow({'Flaga': j})
    h=0
    for i in srednie_wyniki_flagi[j] :
        print(files[h],format(i, '.8f'))
        writer.writerow({'Rozmiar': dane_wejsciowe[h], 'Czas[ms]': format(i, '.8f')})
        h+=1

plt.figure(1)

for l in range(0,len(flagi)):
    plt.plot(
    files,
    srednie_wyniki_flagi[flagi[l]],
    kolor[l]+'o-',
    label=schedulers[l])

figure = plt.gcf() #powiększam figure
figure.set_size_inches(6, 4)

plt.legend(bbox_to_anchor=(1, 1),loc=2, borderaxespad=0)
plt.title(tytul+"-Skala Liniowa")
plt.ylabel(os_y)
plt.xlabel(os_x)
plt.grid(True)

plt.savefig(catalog+wykres1,bbox_inches='tight',papertype='a1',dpi=255)
"""
plt.figure(2)
for l in range(0,len(flagi)):
    plt.loglog(
    files,
    srednie_wyniki_flagi[flagi[l]],
    kolor[l]+'o-',
    label=schedulers[l])

figure = plt.gcf() #powiększam figure
figure.set_size_inches(6, 4)

plt.legend(bbox_to_anchor=(1, 1),loc=2, borderaxespad=0)
plt.title(tytul+"-Skala logarytmiczna")
plt.ylabel(os_y)
plt.xlabel(os_x)    
plt.grid(True)

plt.savefig(catalog+wykres2,bbox_inches='tight',papertype='a1',dpi=255)
"""
plt.show()

