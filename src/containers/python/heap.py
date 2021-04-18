import random

class Kopiec():

    def __init__(self, rozmiar = 10):
        self.rozmiar = rozmiar
        self.kopiec = [0]*self.rozmiar
        self.aktualnaPozycja = -1

    def wstaw(self, item):
        if self.czyPelny():
            print("Kopiec jest przepełniony")
            return

        self.aktualnaPozycja = self.aktualnaPozycja + 1
        self.kopiec[self.aktualnaPozycja] = item
        self.naprawGore(self.aktualnaPozycja)
		
    def naprawGore(self, pozycja):
        parentPozycja = int((pozycja-1)/2)

        while parentPozycja >= 0 and self.kopiec[parentPozycja] < self.kopiec[pozycja]:
            temp = self.kopiec[pozycja]
            self.kopiec[pozycja] = self.kopiec[parentPozycja]
            self.kopiec[parentPozycja] = temp
            pozycja=parentPozycja
            parentPozycja = (int)((pozycja-1)/2)

    def sortowaniePrzezKopcowanie(self):
        for i in range(0,self.aktualnaPozycja+1):
            temp = self.kopiec[0]
            print("%d " % temp)
            self.kopiec[0] = self.kopiec[self.aktualnaPozycja-i]
            self.kopiec[self.aktualnaPozycja-i] = temp
            self.naprawDol(0,self.aktualnaPozycja-i-1)

    def naprawDol(self, pozycja, koniec):
        while pozycja <= koniec:
            leweDziecko = 2*pozycja+1
            praweDziecko = 2*pozycja+2

            if leweDziecko < koniec:
                indeksDoZamiany = None

                if praweDziecko > koniec:
                    indeksDoZamiany = leweDziecko

                else:
                    if self.kopiec[leweDziecko] > self.kopiec[praweDziecko]:
                        indeksDoZamiany = leweDziecko
                    else:
                        indeksDoZamiany = praweDziecko

                    if self.kopiec[pozycja] < self.kopiec[indeksDoZamiany]:
                        temp = self.kopiec[pozycja]
                        self.kopiec[pozycja] = self.kopiec[indeksDoZamiany]
                        self.kopiec[indeksDoZamiany] = temp
                    else:
                        break
                    
                    pozycja = indeksDoZamiany
            else:
                break						
			
    def czyPelny(self):
        if self.aktualnaPozycja == self.rozmiar:
            return True
        return False
			
kopiec = Kopiec()

for i in range(10):
    x = random.randint(0,100)
    print('Wstawiam: ', x)
    kopiec.wstaw(x)

kopiec.sortowaniePrzezKopcowanie()
