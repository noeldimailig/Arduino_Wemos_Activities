#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

IPAddress server_addr(192,168,254,100); // IP of the MySQL server (change this)
char user[] = "noel"; // MySQL user login username (change this)
char password[] = "dimailig"; // MySQL user login password (change this)
// WiFi card example
char ssid[] = "WEMOS"; // your SSID (change this)
char pass[] = "wemos_2021"; // your SSID Password (change this)
// Sample query
char INSERT_SQL[] = "INSERT INTO wemos.users (username) VALUES ('noel_18')"; /// (change this)
WiFiClient client;
MySQL_Connection conn((Client *)&client);

void setup() {
Serial.begin(115200);
WiFi.begin(ssid, pass); // initializing the WIFI library
while ( WiFi.status() != WL_CONNECTED ) { // while loop to write dots during connecting
delay ( 500 );
Serial.print ( "." );
}

// print out information about the WIFI connection
Serial.println ( "" );
Serial.print ( "Connected to " );
Serial.println ( ssid );
Serial.print ( "IP address: " );
Serial.println ( WiFi.localIP() );
Serial.println("Connecting...");
if (conn.connect(server_addr, 3306, user, password)) {
delay(1000);
}
else
Serial.println("Connection failed.");
}

void loop() {
delay(2000);
Serial.println("Recording data.");
// Initiate the query class instance
MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
// Execute the query
cur_mem->execute(INSERT_SQL);
// Note: since there are no results, we do not need to read any data
// Deleting the cursor also frees up memory used
delete cur_mem;
}
