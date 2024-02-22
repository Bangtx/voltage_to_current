String data = "CO=5650, SO2=978, NO=0, _O2=19.95, NO2=10";

void setup() {
  Serial.begin(115200);
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

// CO, NO, dải là 0 đến 2000PPM, SO2 0 đến 1000ppm, NO2 là 0 đến 500ppm, O2 0 đến 22%
void loop() {
  // Your code here
  delay(1000); // Delay for serial initialization
  if (Serial.available() > 0) {
    String send_data = Serial.readString();
    int co2 = getValue(send_data, "CO=");
    int so2 = getValue(send_data, "SO2=");
    int no = getValue(send_data, "NO=");
    int o2 = getValue(send_data, "_O2=");
    int no2 = getValue(send_data, "NO2=");

    int pmw_co2 = map(co2, 0, 2000, 0, 255);
    int pmw_so2 = map(so2, 0, 1000, 0, 255);
    int pmw_no = map(no, 0, 2000, 0, 255);
    int pmw_o2 = map(o2, 0, 22, 0, 255);
    int pmw_no2 = map(no2, 0, 500, 0, 255);
    Serial.println(
      "pmw_co2=" + String(pmw_co2) +
      "pmw_so2=" + String(pmw_so2) +
      "pmw_co2=" + String(pmw_no) +
      "pmw_no=" + String(pmw_co2) +
      "pmw_o2=" + String(pmw_o2) +
      "pmw_no2=" + String(pmw_no2)
    );
//    Serial.println(
//      "co2=" + String(co2) +
//      "so2=" + String(so2) +
//      "co2=" + String(no) +
//      "no=" + String(co2) +
//      "o2=" + String(o2) +
//      "no2=" + String(no2)
//    );
    analogWrite(2, pmw_co2);
    analogWrite(3, pmw_so2);
    analogWrite(4, pmw_no);
    analogWrite(5, pmw_co2);
    analogWrite(6, pmw_o2);
    analogWrite(7, pmw_no2);
  }
//  Serial.println(data);

}

int getValue(String data, String parameter) {
  int startIndex = data.indexOf(parameter);
  if (startIndex != -1) { // If parameter is found
    startIndex += parameter.length(); // Move index to the start of value
    int endIndex = data.indexOf(',', startIndex); // Find the end index of the value
    if (endIndex == -1) { // If comma not found, consider until the end of string
      endIndex = data.length();
    }
//    Serial.println(startIndex);
//    Serial.println(endIndex);
    String valueString = data.substring(startIndex, endIndex);
//    Serial.println(valueString);
    int value = valueString.toInt(); // Convert string to float
    // Serial.print(parameter);
    // Serial.println(value);
    return value;
  }
}
