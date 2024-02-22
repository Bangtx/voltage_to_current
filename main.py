from serial import Serial
from time import sleep


def map_value(input_value, in_min, in_max, out_min, out_max):
    # Perform linear mapping
    return int((input_value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)


data = "[24.12.2020 10:53:18] CO       2000ppm  SO2       500ppm  NO       1000ppm  -----0       ---- -----0       ---- -----0       ---- O2      21.95%Vol NO2        10ppm  -----0       ---- -----0       ---- "

ser = Serial('COM3', 115200, timeout=5)

while True:
# for data in datas:

    CO = int(data[29:35].strip())
    SO2 = int(data[47:53].strip())
    NO = int(data[65:71].strip())
    O2 = float(data[137:143].strip())
    NO2 = int(data[155:161].strip())

    CO = map_value(CO, 0, 2000, 0, 255)
    SO2 = map_value(SO2, 0, 1000, 0, 255)
    NO = map_value(NO, 0, 2000, 0, 255)
    O2 = map_value(O2, 0, 22, 0, 255)
    NO2 = map_value(NO2, 0, 500, 0, 255)
    # print(CO, SO2, NO, O2, NO2)
    send_data = f'CO={CO} SO2={SO2}, NO={NO}, _O2={O2}, NO2={NO2}'
    # print(send_data)
    ser.write(send_data.encode())
    print(ser.readline().decode())
    # sleep(0.3)


print(ser.isOpen())