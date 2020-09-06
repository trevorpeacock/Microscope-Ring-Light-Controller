EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L MCU_Microchip_ATtiny:ATtiny85-20PU U2
U 1 1 5F530BE5
P 4700 2000
F 0 "U2" H 4171 2046 50  0000 R CNN
F 1 "ATtiny85-20PU" H 4171 1955 50  0000 R CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 4700 2000 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf" H 4700 2000 50  0001 C CNN
	1    4700 2000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J1
U 1 1 5F531BBD
P 2850 1850
F 0 "J1" H 2900 2167 50  0000 C CNN
F 1 "Conn_02x03_Odd_Even" H 2900 2076 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 2850 1850 50  0001 C CNN
F 3 "~" H 2850 1850 50  0001 C CNN
	1    2850 1850
	1    0    0    -1  
$EndComp
Text Label 2650 1750 2    50   ~ 0
MISO
Text Label 2650 1850 2    50   ~ 0
SCK
Text Label 2650 1950 2    50   ~ 0
RST
Text Label 3150 1750 0    50   ~ 0
5V
Text Label 3150 1850 0    50   ~ 0
MOSI
$Comp
L power:GND #PWR0101
U 1 1 5F5323CD
P 3150 1950
F 0 "#PWR0101" H 3150 1700 50  0001 C CNN
F 1 "GND" H 3155 1777 50  0000 C CNN
F 2 "" H 3150 1950 50  0001 C CNN
F 3 "" H 3150 1950 50  0001 C CNN
	1    3150 1950
	1    0    0    -1  
$EndComp
Text Label 5300 1800 0    50   ~ 0
MISO
Text Label 5300 1900 0    50   ~ 0
SCK
Text Label 5300 2200 0    50   ~ 0
RST
Text Label 4700 1400 0    50   ~ 0
5V
Text Label 5300 1700 0    50   ~ 0
MOSI
$Comp
L power:GND #PWR0102
U 1 1 5F5329B8
P 4700 2600
F 0 "#PWR0102" H 4700 2350 50  0001 C CNN
F 1 "GND" H 4705 2427 50  0000 C CNN
F 2 "" H 4700 2600 50  0001 C CNN
F 3 "" H 4700 2600 50  0001 C CNN
	1    4700 2600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5F536C65
P 6200 2000
F 0 "SW1" H 6200 2285 50  0000 C CNN
F 1 "SW_Push" H 6200 2194 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 6200 2200 50  0001 C CNN
F 3 "~" H 6200 2200 50  0001 C CNN
	1    6200 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5F5376FF
P 6400 2000
F 0 "#PWR0103" H 6400 1750 50  0001 C CNN
F 1 "GND" H 6405 1827 50  0000 C CNN
F 2 "" H 6400 2000 50  0001 C CNN
F 3 "" H 6400 2000 50  0001 C CNN
	1    6400 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2000 5300 2000
$Comp
L Device:Q_NMOS_GDS Q1
U 1 1 5F5385C4
P 6600 2550
F 0 "Q1" H 6804 2596 50  0000 L CNN
F 1 "Q_NMOS_GDS" H 6804 2505 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-252-3_TabPin2" H 6800 2650 50  0001 C CNN
F 3 "~" H 6600 2550 50  0001 C CNN
	1    6600 2550
	1    0    0    -1  
$EndComp
Text Label 5700 1800 0    50   ~ 0
LED_En
Text Label 6400 2550 2    50   ~ 0
LED_En
$Comp
L power:GND #PWR0104
U 1 1 5F53B9E7
P 6700 2900
F 0 "#PWR0104" H 6700 2650 50  0001 C CNN
F 1 "GND" H 6705 2727 50  0000 C CNN
F 2 "" H 6700 2900 50  0001 C CNN
F 3 "" H 6700 2900 50  0001 C CNN
	1    6700 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5F53BCC2
P 6400 2750
F 0 "R1" H 6459 2796 50  0000 L CNN
F 1 "R_Small" H 6459 2705 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric" H 6400 2750 50  0001 C CNN
F 3 "~" H 6400 2750 50  0001 C CNN
	1    6400 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 2650 6400 2550
Wire Wire Line
	6400 2850 6700 2850
Wire Wire Line
	6700 2850 6700 2900
Wire Wire Line
	6700 2850 6700 2750
Connection ~ 6700 2850
$Comp
L Regulator_Linear:L7805 U1
U 1 1 5F53DC92
P 3200 2600
F 0 "U1" H 3200 2842 50  0000 C CNN
F 1 "L7805" H 3200 2751 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 3225 2450 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 3200 2550 50  0001 C CNN
	1    3200 2600
	1    0    0    -1  
$EndComp
Text Label 2900 2600 2    50   ~ 0
24V
Text Label 3500 2600 0    50   ~ 0
5V
$Comp
L power:GND #PWR0105
U 1 1 5F5403DA
P 3200 2900
F 0 "#PWR0105" H 3200 2650 50  0001 C CNN
F 1 "GND" H 3205 2727 50  0000 C CNN
F 2 "" H 3200 2900 50  0001 C CNN
F 3 "" H 3200 2900 50  0001 C CNN
	1    3200 2900
	1    0    0    -1  
$EndComp
Text Label 3800 2650 0    50   ~ 0
5V
$Comp
L power:GND #PWR0106
U 1 1 5F54160E
P 3800 2850
F 0 "#PWR0106" H 3800 2600 50  0001 C CNN
F 1 "GND" H 3805 2677 50  0000 C CNN
F 2 "" H 3800 2850 50  0001 C CNN
F 3 "" H 3800 2850 50  0001 C CNN
	1    3800 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5F541931
P 3800 2750
F 0 "C1" H 3892 2796 50  0000 L CNN
F 1 "C_Small" H 3892 2705 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 3800 2750 50  0001 C CNN
F 3 "~" H 3800 2750 50  0001 C CNN
	1    3800 2750
	1    0    0    -1  
$EndComp
Text Label 6700 1950 2    50   ~ 0
24V
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5F54B208
P 6900 2100
F 0 "J2" H 6980 2092 50  0000 L CNN
F 1 "Conn_01x02" H 6980 2001 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6900 2100 50  0001 C CNN
F 3 "~" H 6900 2100 50  0001 C CNN
	1    6900 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2100 6700 1950
Wire Wire Line
	6700 2200 6700 2350
Text Label 2000 1950 2    50   ~ 0
24V
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5F54FEAF
P 2200 2100
F 0 "J3" H 2280 2092 50  0000 L CNN
F 1 "Conn_01x02" H 2280 2001 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2200 2100 50  0001 C CNN
F 3 "~" H 2200 2100 50  0001 C CNN
	1    2200 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 2100 2000 1950
Wire Wire Line
	2000 2200 2000 2350
$Comp
L power:GND #PWR0107
U 1 1 5F550578
P 2000 2350
F 0 "#PWR0107" H 2000 2100 50  0001 C CNN
F 1 "GND" H 2005 2177 50  0000 C CNN
F 2 "" H 2000 2350 50  0001 C CNN
F 3 "" H 2000 2350 50  0001 C CNN
	1    2000 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5F552E8E
P 2550 2800
F 0 "#PWR0108" H 2550 2550 50  0001 C CNN
F 1 "GND" H 2555 2627 50  0000 C CNN
F 2 "" H 2550 2800 50  0001 C CNN
F 3 "" H 2550 2800 50  0001 C CNN
	1    2550 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5F552E94
P 2550 2700
F 0 "C2" H 2642 2746 50  0000 L CNN
F 1 "C_Small" H 2642 2655 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P5.00mm" H 2550 2700 50  0001 C CNN
F 3 "~" H 2550 2700 50  0001 C CNN
	1    2550 2700
	1    0    0    -1  
$EndComp
Text Label 2550 2600 2    50   ~ 0
24V
Wire Wire Line
	5700 1800 5300 1800
$EndSCHEMATC
