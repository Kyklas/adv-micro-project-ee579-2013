EESchema Schematic File Version 2  date 25/02/2013 10:51:28
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 43  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "25 feb 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BAT V?
U 1 1 512B4221
P 4100 1350
F 0 "V?" H 4150 1450 50  0000 L CNN
F 1 "BAT" H 4150 1250 50  0000 L CNN
	1    4100 1350
	1    0    0    -1  
$EndComp
$Comp
L LM7805 U?
U 1 1 512B4041
P 4800 1300
F 0 "U?" H 4950 1104 60  0000 C CNN
F 1 "LD1117S33" H 4800 1500 60  0000 C CNN
	1    4800 1300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 512B3FFF
P 2750 1800
F 0 "R?" V 2830 1800 50  0000 C CNN
F 1 "470" V 2750 1800 50  0000 C CNN
	1    2750 1800
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 512B3FFD
P 2400 1800
F 0 "R?" V 2480 1800 50  0000 C CNN
F 1 "470" V 2400 1800 50  0000 C CNN
	1    2400 1800
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 512B3FF2
P 2050 1800
F 0 "R?" V 2130 1800 50  0000 C CNN
F 1 "470" V 2050 1800 50  0000 C CNN
	1    2050 1800
	-1   0    0    1   
$EndComp
$Comp
L LED D?
U 1 1 512B3FF0
P 2750 1350
F 0 "D?" H 2750 1450 50  0000 C CNN
F 1 "Mbed LED" H 2750 1250 50  0000 C CNN
	1    2750 1350
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 512B3FEE
P 2400 1350
F 0 "D?" H 2400 1450 50  0000 C CNN
F 1 "Mbed LED" H 2400 1250 50  0000 C CNN
	1    2400 1350
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 512B3FBA
P 2050 1350
F 0 "D?" H 2050 1450 50  0000 C CNN
F 1 "Mbed LED" H 2050 1250 50  0000 C CNN
	1    2050 1350
	0    -1   -1   0   
$EndComp
Text Notes 8550 1150 0    60   ~ 0
Toy Car Front Drive
Wire Notes Line
	8400 1050 8400 2050
Wire Notes Line
	8400 1050 10550 1050
Wire Notes Line
	10550 1050 10550 2050
Wire Notes Line
	10550 2050 8400 2050
Wire Wire Line
	8000 1600 8600 1600
Wire Wire Line
	8900 1800 9500 1800
Wire Wire Line
	9500 1800 10100 1800
Connection ~ 9500 1800
Wire Wire Line
	8000 1950 10400 1950
Connection ~ 10400 1600
Wire Notes Line
	10600 2300 8300 2300
Wire Notes Line
	10600 2300 10600 4550
Wire Notes Line
	10600 4550 8300 4550
Wire Notes Line
	8300 4550 8300 2300
Wire Wire Line
	9850 3350 9850 3450
Wire Wire Line
	9850 3450 9850 3800
Connection ~ 9650 3450
Wire Wire Line
	9650 3450 9650 3400
Wire Wire Line
	9650 3400 8750 3400
Wire Wire Line
	8750 3400 8750 3650
Wire Wire Line
	8750 3650 8600 3650
Wire Wire Line
	10350 3150 10150 3150
Connection ~ 10150 4000
Wire Wire Line
	10150 4350 10150 4000
Wire Wire Line
	10150 4000 10150 3700
Wire Wire Line
	10150 4350 8000 4350
Connection ~ 9150 3700
Wire Wire Line
	9150 3700 9300 3700
Connection ~ 9150 3800
Connection ~ 9850 3800
Connection ~ 9500 2700
Wire Wire Line
	9500 2600 9500 2700
Connection ~ 9850 3450
Wire Wire Line
	9550 3450 9650 3450
Wire Wire Line
	9650 3450 9850 3450
Connection ~ 9150 3450
Wire Wire Line
	9450 3450 9300 3450
Wire Wire Line
	9300 3450 9150 3450
Connection ~ 9500 4200
Wire Wire Line
	9150 4200 9500 4200
Wire Wire Line
	9500 4200 9850 4200
Wire Wire Line
	9850 2950 9850 2700
Wire Wire Line
	9850 2700 9500 2700
Wire Wire Line
	9500 2700 9150 2700
Wire Wire Line
	9150 2700 9150 2800
Wire Wire Line
	9150 2800 9150 2950
Wire Wire Line
	8000 4000 8850 4000
Wire Wire Line
	10150 3700 9800 3700
Wire Wire Line
	8850 3150 8600 3150
Connection ~ 9150 2800
Wire Wire Line
	9150 3350 9150 3450
Wire Wire Line
	9150 3450 9150 3700
Wire Wire Line
	9150 3700 9150 3800
Wire Wire Line
	10350 3650 10150 3650
Wire Wire Line
	10150 3650 10150 3500
Wire Wire Line
	10150 3500 9300 3500
Wire Wire Line
	9300 3500 9300 3450
Connection ~ 9300 3450
Wire Wire Line
	10400 1950 10400 1600
$Comp
L INDUCTOR L?
U 1 1 512B3F08
P 9800 1400
F 0 "L?" V 9750 1400 40  0000 C CNN
F 1 "INDUCTOR" V 9900 1400 40  0000 C CNN
	1    9800 1400
	0    -1   -1   0   
$EndComp
$Comp
L INDUCTOR L?
U 1 1 512B3EEE
P 9200 1400
F 0 "L?" V 9150 1400 40  0000 C CNN
F 1 "INDUCTOR" V 9300 1400 40  0000 C CNN
	1    9200 1400
	0    -1   -1   0   
$EndComp
$Comp
L +BAT_CAR #PWR?
U 1 1 512B3EAA
P 9500 1400
F 0 "#PWR?" H 9500 1350 20  0001 C CNN
F 1 "+BAT_CAR" H 9500 1500 30  0000 C CNN
	1    9500 1400
	1    0    0    -1  
$EndComp
$Comp
L NPN Q?
U 1 1 512B3E9E
P 8800 1600
F 0 "Q?" H 8800 1450 50  0000 R CNN
F 1 "NPN" H 8650 1450 50  0000 R CNN
	1    8800 1600
	1    0    0    -1  
$EndComp
$Comp
L NPN Q?
U 1 1 512B3E9D
P 10200 1600
F 0 "Q?" H 10200 1450 50  0000 R CNN
F 1 "NPN" H 10050 1450 50  0000 R CNN
	1    10200 1600
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 512B3E9C
P 9500 1800
F 0 "#PWR?" H 9500 1800 30  0001 C CNN
F 1 "GND" H 9500 1730 30  0001 C CNN
	1    9500 1800
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 512B3E9B
P 7750 1600
F 0 "R?" V 7830 1600 50  0000 C CNN
F 1 "750" V 7750 1600 50  0000 C CNN
	1    7750 1600
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 512B3E9A
P 7750 1950
F 0 "R?" V 7830 1950 50  0000 C CNN
F 1 "750" V 7750 1950 50  0000 C CNN
	1    7750 1950
	0    -1   -1   0   
$EndComp
Text Notes 8400 2450 0    60   ~ 0
Toy Car H Bridge 
$Comp
L R R?
U 1 1 512B3CEA
P 9550 3700
F 0 "R?" V 9630 3700 50  0000 C CNN
F 1 "0" V 9550 3700 50  0000 C CNN
	1    9550 3700
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 512B3CE2
P 7750 4350
F 0 "R?" V 7830 4350 50  0000 C CNN
F 1 "750" V 7750 4350 50  0000 C CNN
	1    7750 4350
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 512B3CD7
P 7750 4000
F 0 "R?" V 7830 4000 50  0000 C CNN
F 1 "750" V 7750 4000 50  0000 C CNN
	1    7750 4000
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 512B3CD3
P 8600 3400
F 0 "R?" V 8680 3400 50  0000 C CNN
F 1 "RPNP" V 8600 3400 50  0000 C CNN
	1    8600 3400
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 512B3C94
P 10350 3400
F 0 "R?" V 10430 3400 50  0000 C CNN
F 1 "RPNP" V 10350 3400 50  0000 C CNN
	1    10350 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 512B3BF4
P 9500 4200
F 0 "#PWR?" H 9500 4200 30  0001 C CNN
F 1 "GND" H 9500 4130 30  0001 C CNN
	1    9500 4200
	1    0    0    -1  
$EndComp
$Comp
L +BAT_CAR #PWR?
U 1 1 512B3BD4
P 9500 2600
F 0 "#PWR?" H 9500 2550 20  0001 C CNN
F 1 "+BAT_CAR" H 9500 2700 30  0000 C CNN
	1    9500 2600
	1    0    0    -1  
$EndComp
$Comp
L LEMO2 M
U 1 1 512B39C8
P 9500 3100
F 0 "M" V 9700 3100 70  0000 C CNN
F 1 "M" V 9700 3150 70  0000 C CNN
	1    9500 3100
	0    -1   -1   0   
$EndComp
$Comp
L PNP Q?
U 1 1 512B38B5
P 9950 3150
F 0 "Q?" H 9950 3000 60  0000 R CNN
F 1 "PNP" H 9800 3000 60  0000 R CNN
	1    9950 3150
	-1   0    0    1   
$EndComp
$Comp
L PNP Q?
U 1 1 512B38A3
P 9050 3150
F 0 "Q?" H 9050 3000 60  0000 R CNN
F 1 "PNP" H 8900 3000 60  0000 R CNN
	1    9050 3150
	1    0    0    1   
$EndComp
$Comp
L NPN Q?
U 1 1 512B3891
P 9950 4000
F 0 "Q?" H 9950 3850 50  0000 R CNN
F 1 "NPN" H 9800 3850 50  0000 R CNN
	1    9950 4000
	-1   0    0    -1  
$EndComp
$Comp
L NPN Q?
U 1 1 512B388B
P 9050 4000
F 0 "Q?" H 9050 3850 50  0000 R CNN
F 1 "NPN" H 8900 3850 50  0000 R CNN
	1    9050 4000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
