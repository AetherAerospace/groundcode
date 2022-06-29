const char mainIndex[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
</head>
  <body style="width: 99%; height: 99%; background-color:#141441;">
    <section>

      <h1 style="font-size: 5em; padding-left: 0.4em; text-align: center; color:white;">AETHER ONE</h1>
      <h2 style="font-size: 3em; padding-left: 15%; color:white;"><u>TELEMETRY DATA</u></h2>
      <h2 style="font-size: 2.5em; padding-top:2.5em;  padding-left: 10%; color:white;" class="sensore_value"><u>Sensor
      <h1>Value: </u><span id="Log"> 0</span></h1>
      <h2 style="font-size: 2.5em; padding-top:2.5em; padding-left: 10%; color:white;"><u>About Motor:</u></h2>

    </section>

    <script>
      setInterval(function () {
        getData();
      }, 500); //update rate

      function getData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("Log").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readLog", true);
        xhttp.send();
      }
    </script>
    <style>
      button {
        background: #5a5a7a;
        color: #fff;

        /* For button Size */
        font-size: 340%;
        padding-top: 5%;
        width: 70%;
        padding-bottom: 5%;

        margin-top: 10px;
        margin-left: 15%;
        border: none;
        border-radius: 4px;
      }
    </style>
  </body>
</html>
)=====";

const char updateIndex[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <style>
            * {
                background-color: black;
                font-family: Arial, Helvetica, sans-serif
            }
            p, h1, label {
                color: white;
                font-size: 40px;
            }
            a {
                text-decoration: none;
                color: white;
            }
            button {
                background-color: black;
                color: white;
                border: solid white;
                margin: 10px;
                font-size: 40px;
                border-radius: 15px;
            }
            input {
                color: white;
                margin: 10px;
                font-size: 20px;
                border-radius: 15px;
            }
            #mainContainer {
                border: solid white;
                border-width: 10px;
                text-align: center;
                margin: 0 auto;
                padding: 10px;
            }
            #submitButton {
                background-color: black;
                color: white;
                border: solid white;
                margin: 10px;
                font-size: 20px;
                border-radius: 15px;
            }
            @media (pointer:none), (pointer:coarse) {
                p, h1, label {
                    font-size: 70px;
                }
                button {
                    font-size: 70px;
                }
                input {
                    font-size: 30px;
                }
                #submitButton {
                    font-size: 40px;
                }
            }
        </style>
        <script>
            function notify_update() {
                document.getElementById("update").innerHTML = "<p>Updating...</p>";
            }
        </script>
    </head>
    <body>
        <section id="mainContainer">
            <h1>AETHER-OTA</h1>
            <p>Only *.bin files will work!!</p>
            <form method='POST' action='/doUpdate' enctype='multipart/form-data' target='_self' onsubmit='notify_update()'>
                <input type='file' name='update' accept=".bin" required><br>
                <input id="submitButton" type='submit' value='Start Update!'>
            </form>
            <div id="update"></div>
        </section>
    </body>
</html>
)=====";

const char updateDoneIndex[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <style>
            * {
                background-color: black;
                font-family: Arial, Helvetica, sans-serif
            }
            p, h1, label {
                color: white;
                font-size: 40px;
            }
            a {
                text-decoration: none;
                color: white;
            }
            @media (pointer:none), (pointer:coarse) {
                p, h1, label {
                    font-size: 70px;
                }
            }
        </style>
        <script>
            let counter = 4;
            setTimeout(refresh, 5000);
            var upInt = setInterval(updateNumber, 1000);
            function refresh() {
                clearInterval(upInt);
                window.location.replace("/");
            }
            function updateNumber() {
                document.getElementById("updateText").innerHTML = "Update done! Refreshing in " + counter + " ..."
                counter--;
            }
        </script>
    </head>
    <body>
        <p id="updateText">Update done! Refreshing in 5 ...</p>
    </body>
</html>
)=====";
