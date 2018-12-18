EESchema Schematic File Version 4
LIBS:MARP-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L dk_Interface-Sensor-and-Detector-Interfaces:MAX31855KASA_ U?
U 1 1 5C2353FF
P 1950 1200
F 0 "U?" H 2391 953 60  0000 L CNN
F 1 "MAX31855KASA_" H 2391 847 60  0000 L CNN
F 2 "digikey-footprints:SOIC-8_W3.9mm" H 2150 1400 60  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX31855.pdf" H 2150 1500 60  0001 L CNN
F 4 "MAX31855KASA+-ND" H 2150 1600 60  0001 L CNN "Digi-Key_PN"
F 5 "MAX31855KASA+" H 2150 1700 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 2150 1800 60  0001 L CNN "Category"
F 7 "Interface - Sensor and Detector Interfaces" H 2150 1900 60  0001 L CNN "Family"
F 8 "https://datasheets.maximintegrated.com/en/ds/MAX31855.pdf" H 2150 2000 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/maxim-integrated/MAX31855KASA-/MAX31855KASA--ND/2591564" H 2150 2100 60  0001 L CNN "DK_Detail_Page"
F 10 "IC CONV THERMOCOUPLE-DGTL SOIC" H 2150 2200 60  0001 L CNN "Description"
F 11 "Maxim Integrated" H 2150 2300 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2150 2400 60  0001 L CNN "Status"
	1    1950 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 1900 2150 2100
$Comp
L power:GND #PWR?
U 1 1 5C235407
P 2150 2100
F 0 "#PWR?" H 2150 1850 50  0001 C CNN
F 1 "GND" H 2155 1927 50  0000 C CNN
F 2 "" H 2150 2100 50  0001 C CNN
F 3 "" H 2150 2100 50  0001 C CNN
	1    2150 2100
	1    0    0    -1  
$EndComp
$Comp
L power:-3V3 #PWR?
U 1 1 5C23576C
P 2050 800
F 0 "#PWR?" H 2050 900 50  0001 C CNN
F 1 "-3V3" H 2065 973 50  0000 C CNN
F 2 "" H 2050 800 50  0001 C CNN
F 3 "" H 2050 800 50  0001 C CNN
	1    2050 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 800  2050 900 
$Comp
L Device:C C?
U 1 1 5C235CB7
P 2200 900
F 0 "C?" V 1950 950 50  0000 C CNN
F 1 "0.1uF" V 2050 1000 50  0000 C CNN
F 2 "" H 2238 750 50  0001 C CNN
F 3 "~" H 2200 900 50  0001 C CNN
	1    2200 900 
	0    1    1    0   
$EndComp
Connection ~ 2050 900 
Wire Wire Line
	2050 900  2050 1100
Wire Wire Line
	2350 900  2450 900 
$Comp
L power:GND #PWR?
U 1 1 5C235D67
P 2450 900
F 0 "#PWR?" H 2450 650 50  0001 C CNN
F 1 "GND" V 2455 772 50  0000 R CNN
F 2 "" H 2450 900 50  0001 C CNN
F 3 "" H 2450 900 50  0001 C CNN
	1    2450 900 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1650 1300 1600 1300
Wire Wire Line
	1600 1300 1600 1100
Wire Wire Line
	1600 1100 1250 1100
Wire Wire Line
	1650 1400 1250 1400
$Comp
L Device:C C?
U 1 1 5C236428
P 1250 1250
F 0 "C?" V 1000 1300 50  0000 C CNN
F 1 "0.1uF" V 1100 1350 50  0000 C CNN
F 2 "" H 1288 1100 50  0001 C CNN
F 3 "~" H 1250 1250 50  0001 C CNN
	1    1250 1250
	-1   0    0    1   
$EndComp
Connection ~ 1250 1100
Wire Wire Line
	1250 1400 1050 1400
Connection ~ 1250 1400
$Comp
L pspice:INDUCTOR L?
U 1 1 5C2366D3
P 600 1150
F 0 "L?" V 554 1228 50  0000 L CNN
F 1 "470OHM" V 645 1228 50  0000 L CNN
F 2 "" H 600 1150 50  0001 C CNN
F 3 "~" H 600 1150 50  0001 C CNN
	1    600  1150
	0    1    1    0   
$EndComp
Wire Wire Line
	900  1100 900  900 
Wire Wire Line
	900  900  600  900 
Wire Wire Line
	900  1100 1250 1100
$Comp
L pspice:INDUCTOR L?
U 1 1 5C236878
P 1050 1650
F 0 "L?" V 1004 1728 50  0000 L CNN
F 1 "470OHM" V 1095 1728 50  0000 L CNN
F 2 "" H 1050 1650 50  0001 C CNN
F 3 "~" H 1050 1650 50  0001 C CNN
	1    1050 1650
	0    1    1    0   
$EndComp
$EndSCHEMATC
