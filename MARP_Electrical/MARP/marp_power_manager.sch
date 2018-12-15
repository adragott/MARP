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
L Regulator_Switching:LM2576HVS-ADJ U?
U 1 1 5BC081F3
P 2100 1650
F 0 "U?" H 2100 2017 50  0000 C CNN
F 1 "LM2576HVS-ADJ(LANE1)" H 2100 1926 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-5_TabPin3" H 2100 1400 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2576.pdf" H 2100 1650 50  0001 C CNN
	1    2100 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5BC0831F
P 2750 1500
F 0 "R?" H 2809 1546 50  0000 L CNN
F 1 "R_Small" H 2809 1455 50  0000 L CNN
F 2 "" H 2750 1500 50  0001 C CNN
F 3 "~" H 2750 1500 50  0001 C CNN
	1    2750 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5BC083A3
P 3200 1500
F 0 "R?" H 3259 1546 50  0000 L CNN
F 1 "R_Small" H 3259 1455 50  0000 L CNN
F 2 "" H 3200 1500 50  0001 C CNN
F 3 "~" H 3200 1500 50  0001 C CNN
	1    3200 1500
	1    0    0    -1  
$EndComp
$Comp
L dk_Interface-Sensor-and-Detector-Interfaces:MAX31855KASA_ U?
U 1 1 5BC087C9
P 1250 3100
F 0 "U?" H 1691 2853 60  0000 L CNN
F 1 "MAX31855KASA_" H 1691 2747 60  0000 L CNN
F 2 "digikey-footprints:SOIC-8_W3.9mm" H 1450 3300 60  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX31855.pdf" H 1450 3400 60  0001 L CNN
F 4 "MAX31855KASA+-ND" H 1450 3500 60  0001 L CNN "Digi-Key_PN"
F 5 "MAX31855KASA+" H 1450 3600 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 1450 3700 60  0001 L CNN "Category"
F 7 "Interface - Sensor and Detector Interfaces" H 1450 3800 60  0001 L CNN "Family"
F 8 "https://datasheets.maximintegrated.com/en/ds/MAX31855.pdf" H 1450 3900 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/maxim-integrated/MAX31855KASA-/MAX31855KASA--ND/2591564" H 1450 4000 60  0001 L CNN "DK_Detail_Page"
F 10 "IC CONV THERMOCOUPLE-DGTL SOIC" H 1450 4100 60  0001 L CNN "Description"
F 11 "Maxim Integrated" H 1450 4200 60  0001 L CNN "Manufacturer"
F 12 "Active" H 1450 4300 60  0001 L CNN "Status"
	1    1250 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3800 1450 4000
$Comp
L power:GND #PWR?
U 1 1 5BC0949D
P 1450 4000
F 0 "#PWR?" H 1450 3750 50  0001 C CNN
F 1 "GND" H 1455 3827 50  0000 C CNN
F 2 "" H 1450 4000 50  0001 C CNN
F 3 "" H 1450 4000 50  0001 C CNN
	1    1450 4000
	1    0    0    -1  
$EndComp
$Comp
L MARP:2x2_Connector J?
U 1 1 5BC2CD48
P 1450 1050
F 0 "J?" H 1475 1465 50  0000 C CNN
F 1 "Lane1_CONN" H 1475 1374 50  0000 C CNN
F 2 "" H 1550 1050 50  0001 C CNN
F 3 "" H 1550 1050 50  0001 C CNN
	1    1450 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC2D3FD
P 2100 2100
F 0 "#PWR?" H 2100 1850 50  0001 C CNN
F 1 "GND" H 2105 1927 50  0000 C CNN
F 2 "" H 2100 2100 50  0001 C CNN
F 3 "" H 2100 2100 50  0001 C CNN
	1    2100 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1950 2100 2100
$Comp
L Device:CP1 C?
U 1 1 5BC33E9C
P 900 1700
F 0 "C?" H 1015 1746 50  0000 L CNN
F 1 "220uF" H 1015 1655 50  0000 L CNN
F 2 "" H 900 1700 50  0001 C CNN
F 3 "~" H 900 1700 50  0001 C CNN
	1    900  1700
	1    0    0    -1  
$EndComp
$Comp
L MAX31855:CAP_CERAMIC0603 C?
U 1 1 5BC34D59
P 1300 1750
F 0 "C?" H 1378 1846 50  0000 L CNN
F 1 "10uF" H 1378 1755 50  0000 L CNN
F 2 "" H 1300 1750 50  0001 C CNN
F 3 "" H 1300 1750 50  0001 C CNN
	1    1300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 950  900  950 
Wire Wire Line
	900  950  900  1550
Wire Wire Line
	1750 950  1900 950 
Wire Wire Line
	1900 950  1900 1000
Wire Wire Line
	1900 1050 1750 1050
Wire Wire Line
	1900 1000 2050 1000
Connection ~ 1900 1000
Wire Wire Line
	1900 1000 1900 1050
$Comp
L power:GND #PWR?
U 1 1 5BC34FBE
P 2050 1000
F 0 "#PWR?" H 2050 750 50  0001 C CNN
F 1 "GND" V 2055 872 50  0000 R CNN
F 2 "" H 2050 1000 50  0001 C CNN
F 3 "" H 2050 1000 50  0001 C CNN
	1    2050 1000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	900  1850 1300 1850
Wire Wire Line
	1300 1850 1300 1950
Wire Wire Line
	1300 1950 2100 1950
Connection ~ 1300 1850
Connection ~ 2100 1950
Wire Wire Line
	900  1550 1300 1550
Connection ~ 900  1550
Wire Wire Line
	1300 1550 1600 1550
Connection ~ 1300 1550
$EndSCHEMATC
