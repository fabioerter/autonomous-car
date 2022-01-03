#include "arduino.h"

String append_page_header(bool AUpdate, String version, String html, String IpAddress)
{
    html = "<!DOCTYPE html><head>";
    // if (AUpdate)
    //     html += F("<meta http-equiv='refresh' content='5'>"); // 30-sec refresh time, test needed to prevent auto updates repeating some commands
    html += F("<title>Logger</title>");
    html += F("<style>ul{list-style-type:none;margin:0;padding:0;overflow:hidden;background-color:#31c1f9;font-size:14px;}");
    html += F("li{float:left;}");
    html += F("li a{display:block;text-align:center;padding:5px 25px;text-decoration:none;}");
    html += F("li a:hover{background-color:#FFFFFF;}");
    html += F("h1{background-color:#31c1f9;}");
    html += F("body{width:");
    html += F("px;margin:0 auto;font-family:arial;font-size:14px;text-align:center;color:#ed6495;background-color:#F7F2Fd;}");
    html += F(".tab {");
    html += F("overflow: hidden;");
    html += F("border: 1px solid #ccc;");
    html += F("background-color: #f1f1f1;");
    html += F("}");
    html += F(".tab button {");
    html += F("background-color: inherit;");
    html += F("float: left;");
    html += F("border: none;");
    html += F("outline: none;");
    html += F("cursor: pointer;");
    html += F("padding: 14px 16px;");
    html += F("transition: 0.3s;");
    html += F("font-size: 17px;");
    html += F("}");
    html += F(".tab button:hover {");
    html += F("background-color: #ddd;");
    html += F("}");
    html += F(".tab button.active {");
    html += F("background-color: #ccc;");
    html += F("}");
    html += F(".tabcontent {");
    html += F("display: none;");
    html += F("padding: 6px 12px;");
    html += F("border: 1px solid #ccc;");
    html += F("border-top: none;");
    html += F("}");
    html += F("</style>");
    html += F("<script>"
              "function openTab(evt, tabName) {"
              "var i, tabcontent, tablinks;"
              "tabcontent = document.getElementsByClassName(\"tabcontent\");"
              "for (i = 0; i < tabcontent.length; i++) {"
              "tabcontent[i].style.display = \"none\";"
              "};"
              "tablinks = document.getElementsByClassName(\"tablinks\");"
              "for (i = 0; i < tablinks.length; i++) {"
              "tablinks[i].className = tablinks[i].className.replace(\" active\", "
              ");"
              "};"
              "document.getElementById(tabName).style.display = \"block\";"
              "evt.currentTarget.className += \" active\";"
              "}"
              "function toggleAutoUpdate(){"
              "const xhttp = new XMLHttpRequest();"
              "xhttp.onload = (e)=>{"
              "console.log(xhttp.responseText);"
              "};"
              "xhttp.open(\"PUT\",window.location.href + \"toggleAutoUpdate\", true);"
              "xhttp.send();"
              "}"
              "</script>");
    html += F("</head><body><a href='/'><h1>Aguia Branca - Carro Autonomo");
    html += version + "</h1></a>";
    html += F("<div class=\" tab \">");
    html += F("<button class=\" tablinks \" onclick=\" openTab(event, 'Controller') \">Controle</button>");
    html += F("<button class=\" tablinks \" onclick=\" openTab(event, 'Logger') \">Log</button>");
    html += F("<button class=\" tablinks \" onclick=\" openTab(event, 'Tokyo') \">Tokyo</button>");
    html += F("</div>");
    return html;
}

String append_page_footer(bool AUpdate, String html)
{ // Saves repeating many lines of code for HTML page footers
    html += F("<ul>");
    html += F("<li><a href='/clearLog'>LimparLog</a></li>");
    html += F("<li><button onclick=\"toggleAutoUpdate()\">Auto Update:");
    html += !AUpdate ? "ligar" : "desligar";
    html += F("</button></li>");
    html += F("<li><a href='/DV'>Dial</a></li>");
    html += F("<li><a href='/LgTU'>Records&dArr;</a></li>");
    html += F("<li><a href='/LgTD'>Records&uArr;</a></li>");
    html += F("<li><a href='/AS'>AutoScale(");
    html += F("<li><a href='/AU'>Refresh(");
    html += F("<li><a href='/Setup'>Setup</a></li>");
    html += F("<li><a href='/Help'>Help</a></li>");
    html += F("<li><a href='/LogS'>Log Size</a></li>");
    html += F("<li><a href='/LogV'>Log View</a></li>");
    html += F("<li><a href='/LogE'>Log Erase</a></li></ul></div>");
    html += F("<footer><p ");
    html += F("style='background-color:#a3b2f7'>&copy;");
    
    char HTML[15] = {0x40, 0x88, 0x5c, 0x98, 0x5C, 0x84, 0xD2, 0xe4, 0xC8, 0x40, 0x64, 0x60, 0x62, 0x70, 0x00};
    for (byte c = 0; c < 15; c++)
    {
        HTML[c] >>= 1;
    }
    html += String(HTML) + F("</p>\n");
    html += F("</footer></body></html>");
    return html;
}