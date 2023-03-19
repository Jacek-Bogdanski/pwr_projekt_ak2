# Projekt AK2, PWR 2023

Tematem projektu jest Implementacja biblioteki arytmetyki liczb stałoprzecinkowych dowolnej precyzji z wykorzystaniem wewnętrznej reprezentacji U2.

## Autorzy 
Jacek Bogdański & Michał Kaźmierczak

## Pierwsze uruchomienie

1. Otwórz folder `pwr_projekt_ak2/cmake-build-debug` w terminalu / wierszu poleceń
2. Uruchom polecenie ./aLib sum 1 2
3. Wykonanie programu spowoduje wyświetlenie liczby 3

## Użytkownanie

### Składnia polecenia

Każde polecenie składa się z następujących elementów:

1. Nazwa operacji: `sum, subtract, multiply, divide`
2. Operandy: `4-bitowe liczby całkowite`
4. (opcjonalny) Przełącznik trybu debugowania: `-d, -debug` - uruchamia wyświetlanie danych pomocniczych

Parametry można zamieszczać w dowolnej kolejności, przy czym <b>należy zachować kolejność operandów!</b>

Program umożliwia pracę w dwóch trybach: tryb pojedynczego wywołania i tryb potokowych wywołań. 
Brak przekazania jednego operandu w parametrze spowoduje automatyczne uruchomienie trybu potokowych wywołań.

### Tryb pojedynczego wywołania

Wymagane jest podanie nazwy operacji i dwóch operandów: 

```bash 
./aLib sum 1 2
```

Opcjonalnie można włączyć tryb debugowania:

```bash 
./aLib sum 1 2 -d
```

### Tryb potokowego wywołania

Ten tryb pozwala na wykonywanie obliczeń złożonych z kilku operacji. 
Uruchamia się automatycznie, gdy podany zostanie jeden operand. Wówczas program pobierze **pierwszą wartość ze standardowego strumienia wejścia**, a **drugą z parametru programu**.

Polecenie składamy z następujących po sobie wywołań programu, oddzielając je znakiem `|`. 
Pierwsze wywołanie powinno być uruchomione w trybie pojedynczgo wywołania, a każde kolejne w trybie potokowym.

Jeśli program zostanie uruchomiony w trybie porokowym (zostanie podany jeden operand), a nie otrzyma danych z potoku, zatrzyma się i będzie oczekiwał podania wartości manualnie. Po wprowadzeniu liczby kontunuuje działanie.

Działania zostaną wykonane w następujący sposób:

1. Zostanie wykonane pierwsze wywołanie programu
2. Standardowy strumień wyjścia pierwszego wywołania zostanie skierowany do standardowego strumienia wejścia drugiego wywołania
3. Drugie wywołanie pobierze wartość ze standardowego strumienia wejścia jako **operand nr 1**
4. Operand nr 2 zostanie pobrany z parametru

Wówczas wywołanie:

```bash 
./aLib sum 9 21 | ./aLib divide 3 
```

Jest równoważne wyrażeniu (9 + 21) / 6.


**UWAGA: opcję debugowania można uruchomić wyłącznie w ostatnim wywołaniu!**

```bash 
./aLib sum 1 2 | ./aLib multiply 6 | ./aLib sum 8 -d
```

### Przykłady wywołań

--- 
Obliczenie sumy liczb 2 i 4:
```bash
./aLib sum 2 4
```


Obliczenie różnicy liczb 9 i 5:
```bash
./aLib subtract 9 5
```


Obliczenie iloczynu liczb 2 i 3:
```bash
./aLib multiply 2 3
```


Obliczenie ilorazu liczb 9 i 2:
```bash
./aLib divide 2 3
```

Włączenie trybu debugowania:
```bash
./aLib divide 2 3 -d
```
lub
```bash
./aLib divide 2 3 -debug
```
