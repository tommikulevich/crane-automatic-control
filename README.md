# 📈 Wizualizacja Systemów Automatyki 
### 📜 Opis
Przedstawiamy program symulujący działanie **dźwigu**! Program automatycznie buduje wieżę złożoną z 3 elementów: *kwadrat->trójkąt->koło*.

> Program został zrealizowany w środowisku Visual Studio 2019 za pomocą Windows Forms (CRL Project with .NET Framework 4.7.2).

![Image alt](https://github.com/jwszol-classes/tp-2021-Garikmal/raw/master/Screen0.png)

### 🎯 Jak uruchomić?
Aby uruchomić program i zapewnić poprawne jego działanie, należy:
1. Upewnić się, że w Visual Studio 2019 jest zainstalowany **C++/CLI support for v142 build tools**.
	Pomóc: https://docs.microsoft.com/en-us/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp?view=msvc-160
2. Wejść w *Project->Project4 Properties->Configuration Properties->Linker->System* i zmienić wartość *SubSystem* na **Windows (/SUBSYSTEM:WINDOWS)**.

![Image alt](https://github.com/jwszol-classes/tp-2021-Garikmal/raw/master/Screen1.png)

3. Wejść w *Project->Project4 Properties->Configuration Properties->Linker->Advanced* i zmienić wartość *Entry point* na **main**. 

![Image alt](https://github.com/jwszol-classes/tp-2021-Garikmal/raw/master/Screen2.png)

4. W przypadku blędów przy uruchamianiu spróbować wejść w folder z projektem, otworzyć ustawienia pliku *FormCrane.resx* i zaznaczyć opcję **Unblock** (jeżeli taka opcja jest).  

*Dodatkowo:* jeżeli przy pierwszym otwarzaniu projektu zamiast formy wyświetla się błąd, należy ponownie uruchomić Visual Studio.

### 💻 Zasady działania 
Windows Forms jest bardzo przyjemnym narzędziem do robienia GUI. Mamy dużo różnych ustawień elementów okna, które niekoniecznie musimy ręcznie wpisywać w kod. Działanie programu można określić w kilku krokach:
- Start programu - wyświetlanie elementów okna.
- Użytkownik naciska przycisk **Go!**
- Program generuje bloki.
- Program *etapami* rozpoczyna budowę wieży.
- Gdy wieża zostanie zbudowana, wyświetli się odpowiedni komunikat.

| Etap         | Wizualizacja | Opis                                                     |
| :----------: |:------------:| :--------------------------------------------------------|
| **1**        | 🔗 ▶️       | hak porusza się w kierunku trójkąta                      |
| **2**        | 🔗 🔽       | hak opada w dół                                          |
| **3**        | 🔗🔺⏫     | hak (razem z trójkątem) podnoszą się                      |
| **4**        | 🔗🔺⏩     | hak (razem z trójkątem) poruszają się w kierunku kwadratu |
| **5**        | 🔗🔺⏬     | hak (razem z trójkątem) opadają w dół                     |
| **6**        | 🔗🔼        | hak podnosi się                                          |
| **7**        | 🔗▶️        | hak porusza się w kierunku koła                          |
| **8**        | 🔗🔽        | hak opada w dół                                          |
| **9**        | 🔗⚫⏫     | hak (razem z kołem) podnoszą się                          |
| **10**       | 🔗⚫⏩     | hak (razem z kołem) poruszają się w kierunku kwadratu     |
| **11**       | 🔗⚫⏬     | hak (razem z kołem) opadają w dół                         |
|              |🔗⚫🔺🟥   | Koniec działania                                          |

### 💪 Autorzy
- **Tomash Mikulevich** | 187720 | ACiR3  
- **Igor Malkovskiy** | 187717 | ACiR3
