#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <stdlib.h>

IPAddress server_addr(192,168,254,100); // IP of the MySQL server (change this)
char user[] = "noel"; // MySQL user login username (change this)
char password[] = "dimailig"; // MySQL user login password (change this)

// WiFi card example
char ssid[] = "WEMOS"; // your SSID (change this)
char pass[] = "wemos_2021"; // your SSID Password (change this)

// Sample query
const char UPDATE_ON[] = "UPDATE wemos.led SET status = 'ON' WHERE id=1";
const char UPDATE_OFF[] = "UPDATE wemos.led SET status = 'OFF' WHERE id=1";/// (change this)
const char READ_SQL[] = "SELECT delay FROM wemos.led WHERE id=1";
char query[128];

int ledPin = D5;
int del = 1000;
WiFiServer server(80);
WiFiClient client;
MySQL_Connection conn((Client *)&client);
MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
void setup() {
  Serial.begin(115200);
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  if (conn.connect(server_addr, 3306, user, password))
    delay(1000);
  else
    Serial.println("Connection failed.");
  // Start the server
  server.begin();
  Serial.println("Server started");
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");;
}

void loop() {
  read_data();
}
void read_data(){
  Serial.println("> Running SELECT with dynamically supplied parameter");
  sprintf(query, READ_SQL, 9000000);
  cur_mem->execute(query);
  column_names *cols = cur_mem->get_columns();
  for (int f = 0; f < cols->num_fields; f++) {
    Serial.print(cols->fields[f]->name);
    if (f < cols->num_fields-1) {
      Serial.print(',');
    }
  }
  Serial.println();
  // Read the rows and print them
  row_values *row = NULL;
  do {
    row = cur_mem->get_next_row();
    if (row != NULL) {
      for (int f = 0; f < cols->num_fields; f++) {
        digitalWrite(ledPin, HIGH);
        delay(del);
        digitalWrite(ledPin, LOW);
        del = atoi(row->values[f]);
        Serial.print(row->values[f]);
        if (f < cols->num_fields-1) {
          Serial.print(',');
        }
        Serial.println();
      }
    }
  } while (row != NULL);
}
