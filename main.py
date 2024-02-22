from serial import Serial
from time import sleep

data = "[24.12.2020 10:53:18] CO       2000ppm  SO2       500ppm  NO       1000ppm  -----0       ---- -----0       ---- -----0       ---- O2      21.95%Vol NO2        10ppm  -----0       ---- -----0       ---- "

ser = Serial('COM3', 115200, timeout=5)

while True:
# for data in datas:
    CO = data[29:35].strip()
    SO2 = data[47:53].strip()
    NO = data[65:71].strip()
    O2 = data[137:143].strip()
    NO2 = data[155:161].strip()
    # print(CO, SO2, NO, O2, NO2)
    send_data = f'CO={CO} SO2={SO2}, NO={NO}, _O2={O2}, NO2={NO2}'
    ser.write(send_data.encode())
    print(ser.readline().decode())
    # sleep(0.3)


print(ser.isOpen())