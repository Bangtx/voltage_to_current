String data = "CO=5650, SO2=978, NO=0, O2=19.95, NO2=10";

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

void loop() {
  // Your code here
  delay(1000); // Delay for serial initialization
  if (Serial.available() > 0) {
    String send_data = Serial.readString();
    int co2 = getValue(data, "CO=");
    int so2 = getValue(data, "SO2=");
    int no = getValue(data, "NO=");
    int o2 = getValue(data, "O2=");
    int no2 = getValue(data, "NO2=");
    Serial.println("co2" + String(co2));
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
    // Serial.println(startIndex);
    // Serial.println(endIndex);
    String valueString = data.substring(startIndex, endIndex);
    int value = valueString.toInt(); // Convert string to float
    // Serial.print(parameter);
    // Serial.println(value);
    return value;
  }
}

