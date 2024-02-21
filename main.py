from serial import Serial
from time import sleep

datas = [
    "[24.12.2020 10:53:18] CO       5650ppm  SO2       978ppm  NO          0ppm  -----0       ---- -----0       ---- -----0       ---- O2      19.95%Vol NO2        10ppm  -----0       ---- -----0       ---- ",
    "[24.12.2020 10:53:18] CO       5650ppm  SO2       978ppm  NO          0ppm  -----0       ---- -----0       ---- -----0       ---- O2      19.95%Vol NO2        10ppm  -----0       ---- -----0       ---- "
]

ser = Serial('COM3', 115200, timeout=5)

while True:
    data = datas[0]
# for data in datas:
    CO = data[29:35].strip()
    SO2 = data[47:53].strip()
    NO = data[65:71].strip()
    O2 = data[137:143].strip()
    NO2 = data[155:161].strip()
    # print(CO, SO2, NO, O2, NO2)
    send_data = f'CO={CO} SO2={SO2}, NO={NO}, O2={O2}, NO2={NO2}'
    ser.write(send_data.encode())
    print(ser.readline().decode())
    # sleep(0.3)


print(ser.isOpen())