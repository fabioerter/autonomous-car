#include <ESP8266WiFi.h>
#include <credentials.h>
#include <FS/FileManager.h>
#include <ESP8266WebServer.h>
#include <HtmlTemplates/htmlTemplates.h>
#include <AsyncElegantOTA.h>

String html, version = "v1.0";
bool AUpdate = true;
ESP8266WebServer server(80);
String IpAddress;
void initial()
{
  Serial.println("[info] Send HTML");
  html = append_page_header(AUpdate, version, html, IpAddress);

  html += "<div id=\"Logger\" class=\"tabcontent\"><p>";
  html += append_joyStick_html();
  html += "</p>";

  html += "<div id=\"Logger\" class=\"tabcontent\"><p>";
  html += readFile("");
  html += "</p>";

  html = append_page_footer(AUpdate, html);

  server.send(200, "text/html", html);
  writeFile("Route called '/'");
}

void clearLog()
{
  deleteFile();
  createFile();
  initial();
}
void toggleAutoUpdate()
{
  AUpdate = !AUpdate;
  server.send(200, "application/json", "{""sucesso!""}");
}
void setup(void)
{
  // Configura a porta serial para 115200bps
  Serial.begin(115200);

  // Abre o sistema de arquivos (mount)
  openFS();
  // Cria o arquivo caso o mesmo não exista
  createFile();

  writeFile("Booting ESP8266...");
  writeFile("Connecting to " + (String)ssid);

  // Inicia a conexão WiFi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  writeFile("WiFi connected");
  Serial.println(WiFi.localIP());
  IpAddress = WiFi.localIP().toString();
  // Inicia o webserver
  server.begin();
  writeFile("Web Server started");
  server.on("/", initial);
  server.on("/clearLog", clearLog);
  server.on("/toggleAutoUpdate", HTTP_PUT, toggleAutoUpdate);
  server.begin();

  AsyncElegantOTA.begin(&server);
}
void loop(void)
{
  server.handleClient();
}