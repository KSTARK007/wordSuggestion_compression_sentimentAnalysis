<!DOCTYPE html>
<html>
  <head>
    <link rel="stylesheet" href="main.css">
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
<div class="container">
    <div id="headerImageDiv"><img src="avatar.png" id="headerImg"></div>
    <span id="headerMain">WELCOME To the BLOG of the great  </span>
    <div><span id="headerText">KSTARK</span></div>
</div>

<h1 id="topicText" >SOME TOPIC</h1>
<img id="blogImage" src="avatar.png" alt="image ">
<br><br>
<form action="index.php" method="post">
  <textarea name="text" rows="8" cols="80"></textarea>
  <br>
  <input type="submit" name="" value="SUBMIT">
</form>
<?php
$text = $_POST["text"];
echo $text;
$file = fopen("inputfile.txt","w+");
fwrite($file,$text."\n");
fclose($file);
exec("final.exe<inputfile.txt>outputfile.txt");

 ?>


  <script type="text/javascript" src="main.js"></script>
  </body>
</html>
