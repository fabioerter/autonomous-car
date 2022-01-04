#include "arduino.h"

String append_joyStick_script()
{
    return F("");
}

String append_joyStick_style()
{
    return F("* { "
             "    box-sizing: border-box; "
             "} "
             " "
             "body { "
             "    margin: 0px; "
             "    padding: 0px; "
             "    font-family: monospace; "
             "} "
             " "
             ".row { "
             "    display: inline-flex; "
             "    clear: both; "
             "} "
             " "
             ".columnLateral { "
             "    float: left; "
             "    width: 15%; "
             "    min-width: 300px; "
             "} "
             " "
             ".columnCetral { "
             "    float: left; "
             "    width: 70%; "
             "    min-width: 300px; "
             "} "
             " "
             "#joy2Div { "
             "    width: 200px; "
             "    height: 200px; "
             "    margin: 50px "
             "} "
             " "
             "#joystick { "
             "    border: 1px solid #FF0000; "
             "} "
             " "
             "#joystick2 { "
             "    border: 1px solid #0000FF; "
             "}");
}
String append_joyStick_html()
{
    return F(" <div id =\"joy3Div\" style=\"width:200px;height:200px;margin:50px;position:fixed;bottom:30px;left:500px;\"></div> "
             "    </div> "
             "    <!-- Example of two JoyStick integrated in the page structure --> "
             "    <div class=\"row\"> "
             "        <div class=\"columnLateral\"> "
             "            <div id=\"joy1Div\" style=\"width:200px;height:200px;margin:50px\"></div> "
             "            Posizione X:<input id=\"joy1PosizioneX\" type=\"text\" /><br /> "
             "            Posizione Y:<input id=\"joy1PosizioneY\" type=\"text\" /><br /> "
             "            Direzione:<input id=\"joy1Direzione\" type=\"text\" /><br /> "
             "            X :<input id=\"joy1X\" type=\"text\" /></br> "
             "            Y :<input id=\"joy1Y\" type=\"text\" /> "
             "        </div> "
             "    </div> "
             "    <script type=\"text/javascript\"> "
             " "
             "        var joy1IinputPosX = document.getElementById(\"joy1PosizioneX\"); "
             "        var joy1InputPosY = document.getElementById(\"joy1PosizioneY\"); "
             "        var joy1Direzione = document.getElementById(\"joy1Direzione\"); "
             "        var joy1X = document.getElementById(\"joy1X\"); "
             "        var joy1Y = document.getElementById(\"joy1Y\"); "
             "        var Joy1 = new JoyStick('joy1Div', {}, function (stickData) { "
             "            joy1IinputPosX.value = stickData.xPosition; "
             "            joy1InputPosY.value = stickData.yPosition; "
             "            joy1Direzione.value = stickData.cardinalDirection; "
             "            joy1X.value = stickData.x; "
             "            joy1Y.value = stickData.y; "
             "        }); "
             " "
             "        var joy2Param = { \"title\": \"joystick2\", \"autoReturnToCenter\": false }; "
             "        var Joy2 = new JoyStick('joy2Div', joy2Param); "
             " "
             "        var joy2IinputPosX = document.getElementById(\"joy2PosizioneX\"); "
             "        var joy2InputPosY = document.getElementById(\"joy2PosizioneY\"); "
             "        var joy2Direzione = document.getElementById(\"joy2Direzione\"); "
             "        var joy2X = document.getElementById(\"joy2X\"); "
             "        var joy2Y = document.getElementById(\"joy2Y\"); "
             " "
             "        setInterval(function () { joy2IinputPosX.value = Joy2.GetPosX(); }, 50); "
             "        setInterval(function () { joy2InputPosY.value = Joy2.GetPosY(); }, 50); "
             "        setInterval(function () { joy2Direzione.value = Joy2.GetDir(); }, 50); "
             "        setInterval(function () { joy2X.value = Joy2.GetX(); }, 50); "
             "        setInterval(function () { joy2Y.value = Joy2.GetY(); }, 50); "
             " "
             "        var joy3Param = { \"title\": \"joystick3\" }; "
             "        var Joy3 = new JoyStick('joy3Div', joy3Param); "
             " "
             "        var joy3IinputPosX = document.getElementById(\"joy3PosizioneX\"); "
             "        var joy3InputPosY = document.getElementById(\"joy3PosizioneY\"); "
             "        var joy3Direzione = document.getElementById(\"joy3Direzione\"); "
             "        var joy3X = document.getElementById(\"joy3X\"); "
             "        var joy3Y = document.getElementById(\"joy3Y\"); "
             " "
             "        setInterval(function () { joy3IinputPosX.value = Joy3.GetPosX(); }, 50); "
             "        setInterval(function () { joy3InputPosY.value = Joy3.GetPosY(); }, 50); "
             "        setInterval(function () { joy3Direzione.value = Joy3.GetDir(); }, 50); "
             "        setInterval(function () { joy3X.value = Joy3.GetX(); }, 50); "
             "        setInterval(function () { joy3Y.value = Joy3.GetY(); }, 50); "
             "    </script>");
}

String append_page_header(bool AUpdate, String version, String IpAddress)
{
    String result = "<!DOCTYPE html><head>";
    // if (AUpdate)
    //     html += F("<meta http-equiv='refresh' content='5'>"); // 30-sec refresh time, test needed to prevent auto updates repeating some commands
    result += F("<title>Veículo autonomo</title>");
    result += F("<style>ul{list-style-type:none;margin:0;padding:0;overflow:hidden;background-color:#31c1f9;font-size:14px;}");
    result += F("li{float:left;}");
    result += F("li a{display:block;text-align:center;padding:5px 25px;text-decoration:none;}");
    result += F("li a:hover{background-color:#FFFFFF;}");
    result += F("h1{background-color:#31c1f9;}");
    result += F("body{width:");
    result += F("px;margin:0 auto;font-family:arial;font-size:14px;text-align:center;color:#ed6495;background-color:#F7F2Fd;}");
    result += F(".tab {");
    result += F("overflow: hidden;");
    result += F("border: 1px solid #ccc;");
    result += F("background-color: #f1f1f1;");
    result += F("}");
    result += F(".tab button {");
    result += F("background-color: inherit;");
    result += F("float: left;");
    result += F("border: none;");
    result += F("outline: none;");
    result += F("cursor: pointer;");
    result += F("padding: 14px 16px;");
    result += F("transition: 0.3s;");
    result += F("font-size: 17px;");
    result += F("}");
    result += F(".tab button:hover {");
    result += F("background-color: #ddd;");
    result += F("}");
    result += F(".tab button.active {");
    result += F("background-color: #ccc;");
    result += F("}");
    result += F(".tabcontent {");
    result += F("display: none;");
    result += F("padding: 6px 12px;");
    result += F("border: 1px solid #ccc;");
    result += F("border-top: none;");
    result += F("}");
    result += F("</style>");
    result += F("<style>");
    result += append_joyStick_style();
    result += F("</style>");
    result += F("<script>"
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
                "function deleteLog(){"
                "const xhttp = new XMLHttpRequest();"
                "xhttp.onload = (e)=>{"
                "console.log(xhttp.responseText);"
                "};"
                "xhttp.open(\"PUT\",window.location.href + \"clearLog\", true);"
                "xhttp.send();"
                "}"
                "</script>");
    result += F("<script> "
              "        let StickStatus = "
              "        { "
              "            xPosition: 0, "
              "            yPosition: 0, "
              "            x: 0, "
              "            y: 0, "
              "            cardinalDirection: \"C\" "
              "        }; "
              "        var JoyStick = (function (container, parameters, callback) { "
              "            parameters = parameters || {}; "
              "            var title = (typeof parameters.title === \"undefined\" ? \"joystick\" : parameters.title), "
              "                width = (typeof parameters.width === \"undefined\" ? 0 : parameters.width), "
              "                height = (typeof parameters.height === \"undefined\" ? 0 : parameters.height), "
              "                internalFillColor = (typeof parameters.internalFillColor === \"undefined\" ? \"#00AA00\" : parameters.internalFillColor), "
              "                internalLineWidth = (typeof parameters.internalLineWidth === \"undefined\" ? 2 : parameters.internalLineWidth), "
              "                internalStrokeColor = (typeof parameters.internalStrokeColor === \"undefined\" ? \"#003300\" : parameters.internalStrokeColor), "
              "                externalLineWidth = (typeof parameters.externalLineWidth === \"undefined\" ? 2 : parameters.externalLineWidth), "
              "                externalStrokeColor = (typeof parameters.externalStrokeColor === \"undefined\" ? \"#008000\" : parameters.externalStrokeColor), "
              "                autoReturnToCenter = (typeof parameters.autoReturnToCenter === \"undefined\" ? true : parameters.autoReturnToCenter); "
              " "
              "            callback = callback || function (StickStatus) { }; "
              " "
              "            var objContainer = document.getElementById(container); "
              " "
              "            objContainer.style.touchAction = \"none\"; "
              " "
              "            var canvas = document.createElement(\"canvas\"); "
              "            canvas.id = title; "
              "            if (width === 0) { width = objContainer.clientWidth; } "
              "            if (height === 0) { height = objContainer.clientHeight; } "
              "            canvas.width = width; "
              "            canvas.height = height; "
              "            objContainer.appendChild(canvas); "
              "            var context = canvas.getContext(\"2d\"); "
              " "
              "            var pressed = 0; "
              "            var circumference = 2 * Math.PI; "
              "            var internalRadius = (canvas.width - ((canvas.width / 2) + 10)) / 2; "
              "            var maxMoveStick = internalRadius + 5; "
              "            var externalRadius = internalRadius + 30; "
              "            var centerX = canvas.width / 2; "
              "            var centerY = canvas.height / 2; "
              "            var directionHorizontalLimitPos = canvas.width / 10; "
              "            var directionHorizontalLimitNeg = directionHorizontalLimitPos * -1; "
              "            var directionVerticalLimitPos = canvas.height / 10; "
              "            var directionVerticalLimitNeg = directionVerticalLimitPos * -1; "
              "            var movedX = centerX; "
              "            var movedY = centerY; "
              " "
              "            if (\"ontouchstart\" in document.documentElement) { "
              "                canvas.addEventListener(\"touchstart\", onTouchStart, false); "
              "                document.addEventListener(\"touchmove\", onTouchMove, false); "
              "                document.addEventListener(\"touchend\", onTouchEnd, false); "
              "            } "
              "            else { "
              "                canvas.addEventListener(\"mousedown\", onMouseDown, false); "
              "                document.addEventListener(\"mousemove\", onMouseMove, false); "
              "                document.addEventListener(\"mouseup\", onMouseUp, false); "
              "            } "
              "            drawExternal(); "
              "            drawInternal(); "
              " "
              "            function drawExternal() { "
              "                context.beginPath(); "
              "                context.arc(centerX, centerY, externalRadius, 0, circumference, false); "
              "                context.lineWidth = externalLineWidth; "
              "                context.strokeStyle = externalStrokeColor; "
              "                context.stroke(); "
              "            } "
              " "
              "            function drawInternal() { "
              "                context.beginPath(); "
              "                if (movedX < internalRadius) { movedX = maxMoveStick; } "
              "                if ((movedX + internalRadius) > canvas.width) { movedX = canvas.width - (maxMoveStick); } "
              "                if (movedY < internalRadius) { movedY = maxMoveStick; } "
              "                if ((movedY + internalRadius) > canvas.height) { movedY = canvas.height - (maxMoveStick); } "
              "                context.arc(movedX, movedY, internalRadius, 0, circumference, false); "
              "                var grd = context.createRadialGradient(centerX, centerY, 5, centerX, centerY, 200); "
              "                grd.addColorStop(0, internalFillColor); "
              "                grd.addColorStop(1, internalStrokeColor); "
              "                context.fillStyle = grd; "
              "                context.fill(); "
              "                context.lineWidth = internalLineWidth; "
              "                context.strokeStyle = internalStrokeColor; "
              "                context.stroke(); "
              "            } "
              "            function onTouchStart(event) { "
              "                pressed = 1; "
              "            } "
              " "
              "            function onTouchMove(event) { "
              "                if (pressed === 1 && event.targetTouches[0].target === canvas) { "
              "                    movedX = event.targetTouches[0].pageX; "
              "                    movedY = event.targetTouches[0].pageY; "
              "                    if (canvas.offsetParent.tagName.toUpperCase() === \"BODY\") { "
              "                        movedX -= canvas.offsetLeft; "
              "                        movedY -= canvas.offsetTop; "
              "                    } "
              "                    else { "
              "                        movedX -= canvas.offsetParent.offsetLeft; "
              "                        movedY -= canvas.offsetParent.offsetTop; "
              "                    } "
              "                    context.clearRect(0, 0, canvas.width, canvas.height); "
              "                    drawExternal(); "
              "                    drawInternal(); "
              " "
              "                    StickStatus.xPosition = movedX; "
              "                    StickStatus.yPosition = movedY; "
              "                    StickStatus.x = (100 * ((movedX - centerX) / maxMoveStick)).toFixed(); "
              "                    StickStatus.y = ((100 * ((movedY - centerY) / maxMoveStick)) * -1).toFixed(); "
              "                    StickStatus.cardinalDirection = getCardinalDirection(); "
              "                    callback(StickStatus); "
              "                } "
              "            } "
              " "
              "            function onTouchEnd(event) { "
              "                pressed = 0; "
              "                if (autoReturnToCenter) { "
              "                    movedX = centerX; "
              "                    movedY = centerY; "
              "                } "
              "                context.clearRect(0, 0, canvas.width, canvas.height); "
              "                drawExternal(); "
              "                drawInternal(); "
              " "
              "                StickStatus.xPosition = movedX; "
              "                StickStatus.yPosition = movedY; "
              "                StickStatus.x = (100 * ((movedX - centerX) / maxMoveStick)).toFixed(); "
              "                StickStatus.y = ((100 * ((movedY - centerY) / maxMoveStick)) * -1).toFixed(); "
              "                StickStatus.cardinalDirection = getCardinalDirection(); "
              "                callback(StickStatus); "
              "            } "
              " "
              "            function onMouseDown(event) { "
              "                pressed = 1; "
              "            } "
              " "
              "            function onMouseMove(event) { "
              "                if (pressed === 1) { "
              "                    movedX = event.pageX; "
              "                    movedY = event.pageY; "
              "                    if (canvas.offsetParent.tagName.toUpperCase() === \"BODY\") { "
              "                        movedX -= canvas.offsetLeft; "
              "                        movedY -= canvas.offsetTop; "
              "                    } "
              "                    else { "
              "                        movedX -= canvas.offsetParent.offsetLeft; "
              "                        movedY -= canvas.offsetParent.offsetTop; "
              "                    } "
              "                    context.clearRect(0, 0, canvas.width, canvas.height); "
              "                    drawExternal(); "
              "                    drawInternal(); "
              " "
              "                    StickStatus.xPosition = movedX; "
              "                    StickStatus.yPosition = movedY; "
              "                    StickStatus.x = (100 * ((movedX - centerX) / maxMoveStick)).toFixed(); "
              "                    StickStatus.y = ((100 * ((movedY - centerY) / maxMoveStick)) * -1).toFixed(); "
              "                    StickStatus.cardinalDirection = getCardinalDirection(); "
              "                    callback(StickStatus); "
              "                } "
              "            } "
              " "
              "            function onMouseUp(event) { "
              "                pressed = 0; "
              "                if (autoReturnToCenter) { "
              "                    movedX = centerX; "
              "                    movedY = centerY; "
              "                } "
              "                context.clearRect(0, 0, canvas.width, canvas.height); "
              "                drawExternal(); "
              "                drawInternal(); "
              " "
              "                StickStatus.xPosition = movedX; "
              "                StickStatus.yPosition = movedY; "
              "                StickStatus.x = (100 * ((movedX - centerX) / maxMoveStick)).toFixed(); "
              "                StickStatus.y = ((100 * ((movedY - centerY) / maxMoveStick)) * -1).toFixed(); "
              "                StickStatus.cardinalDirection = getCardinalDirection(); "
              "                callback(StickStatus); "
              "            } "
              " "
              "            function getCardinalDirection() { "
              "                let result = \"\"; "
              "                let orizontal = movedX - centerX; "
              "                let vertical = movedY - centerY; "
              " "
              "                if (vertical >= directionVerticalLimitNeg && vertical <= directionVerticalLimitPos) { "
              "                    result = \"C\"; "
              "                } "
              "                if (vertical < directionVerticalLimitNeg) { "
              "                    result = \"N\"; "
              "                } "
              "                if (vertical > directionVerticalLimitPos) { "
              "                    result = \"S\"; "
              "                } "
              " "
              "                if (orizontal < directionHorizontalLimitNeg) { "
              "                    if (result === \"C\") { "
              "                        result = \"W\"; "
              "                    } "
              "                    else { "
              "                        result += \"W\"; "
              "                    } "
              "                } "
              "                if (orizontal > directionHorizontalLimitPos) { "
              "                    if (result === \"C\") { "
              "                        result = \"E\"; "
              "                    } "
              "                    else { "
              "                        result += \"E\"; "
              "                    } "
              "                } "
              " "
              "                return result; "
              "            } "
              " "
              " "
              "            this.GetHeight = function () { "
              "                return canvas.height; "
              "            }; "
              " "
              "            this.GetPosX = function () { "
              "                return movedX; "
              "            }; "
              " "
              "            this.GetPosY = function () { "
              "                return movedY; "
              "            }; "
              " "
              "            this.GetX = function () { "
              "                return (100 * ((movedX - centerX) / maxMoveStick)).toFixed(); "
              "            }; "
              " "
              "            this.GetY = function () { "
              "                return ((100 * ((movedY - centerY) / maxMoveStick)) * -1).toFixed(); "
              "            }; "
              " "
              "            this.GetDir = function () { "
              "                return getCardinalDirection(); "
              "            }; "
              "        }); "
              "    </script>");
    result += F("</head><body><a href='/'><h1>Aguia Branca - Carro Autonomo");
    result += version + "</h1></a>";
    result += F("<div class=\" tab \">");
    result += F("<button class=\" tablinks \" onclick=\" openTab(event, 'Controller') \">Controle</button>");
    result += F("<button class=\" tablinks \" onclick=\" openTab(event, 'Logger') \">Log</button>");
    result += F("<button class=\" tablinks \" onclick=\" openTab(event, 'Tokyo') \">Tokyo</button>");
    result += F("</div>");
    return result;
}

String append_page_footer(bool AUpdate)
{ // Saves repeating many lines of code for HTML page footers
    String result = "";
    result += F("<ul>");
    result += F("<li><button onclick=\"deleteLog()\">LimparLog</button></li>");
    result += F("<li><button onclick=\"toggleAutoUpdate()\">Auto Update:");
    result += !AUpdate ? "ligar" : "desligar";
    result += F("</button></li>");
    result += F("<li><a href='/DV'>Dial</a></li>");
    result += F("<li><a href='/LgTU'>Records&dArr;</a></li>");
    result += F("<li><a href='/LgTD'>Records&uArr;</a></li>");
    result += F("<li><a href='/AS'>AutoScale(");
    result += F("<li><a href='/AU'>Refresh(");
    result += F("<li><a href='/Setup'>Setup</a></li>");
    result += F("<li><a href='/Help'>Help</a></li>");
    result += F("<li><a href='/LogS'>Log Size</a></li>");
    result += F("<li><a href='/LogV'>Log View</a></li>");
    result += F("<li><a href='/LogE'>Log Erase</a></li></ul></div>");
    result += F("<footer><p ");
    result += F("style='background-color:#a3b2f7'>&copy;");
    result += F("</footer></body></html>");
    return result;
}
