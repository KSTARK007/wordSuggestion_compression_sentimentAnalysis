<html>
<head>

	<style media="screen">
		.emo
		{
			border: none;
			width: 200px;
			font-size: 30px;
			height: 70px;
			margin-top: 20px;
			margin-left: 900px;
			border-radius: 10px;
			background-color: #4484CE;
		}
		body
		{
			width: 100%;
			background-image: url("bg.png");
			background-repeat: no-repeat;
			background-size: cover;
		}
		.titleText
		{
			position: absolute;
			color: white;
			font-family: Open_Sans;
			margin-left:800px;
			margin-top: 5px;
			font-size: 90px;
		}
		.textBox
		{
			position: absolute;
			background-color: rgba(255, 255, 255, 0.9);
			color: black;
			font-size: 40px;
			margin-left:50px;
			margin-top: 150px;
		}
		.header
		{
			position: absolute;
			margin-left: -10px;
			margin-top: -10px;
			height: 100px;
			width: 100.1%;
			background-color: #0F1626;
		}
		.SUBMIT
		{
			border: none;
			width: 200px;
			font-size: 30px;
			height: 70px;
			margin-top: 20px;
			margin-left: 900px;
			border-radius: 10px;
			background-color: #4484CE;
		}
		button
		{
			position: relative;
			margin-top: 600px;
			margin-left: 100px;
			font-size: 30px;
			border: none;
			width: 300px;
			border-radius: 10px;
			background-color: #F9Cf00;
		}
	</style>
	</head>
	<body>
		<div class = "header">
			<span class="titleText">JKK BLOG</span>
		</div>
	<?php
		$exp = "";
		$arr = NULL;
		if(isset($_COOKIE["text"]))
		{
			$exp = $_COOKIE["text"];
			$arr = explode(" ", $exp);
			$suggests = exec("word ".$arr[count($arr)-1]);
		}
		echo "<br><textarea class = \"textBox\" rows='10' cols='90'>".$exp."</textarea><br><br>";
		echo "<script>function selectThis(val){document.cookie = 'text = '+document.querySelector('textarea').value+val.id+' ';window.location.reload()}</script>";
		if($arr)
		{
			for($i=0; $i<count(explode(" ",$suggests)); $i++)
			{
				echo "<button width='100px' onclick='selectThis(this)' id=".explode(" ",$suggests)[$i]."> ".$arr[count($arr)-1].explode(" ",$suggests)[$i]."</button>";
			}
		}
		$file = fopen("inputfile.txt","w+");
		fwrite($file,$exp."\n");
		fclose($file);
		exec("final.exe<inputfile.txt>outputfile.txt");
		$emofile = fopen("check.txt","w+");
		fwrite($emofile,$exp."\n");
		fclose($emofile);
		$emoval = exec("emofinal.exe");
		$_COOKIE["emo"] = $emoval;
	?>
	<br><br><button id="suggest" class="SUBMIT">Suggest</button><emo><br>
	<button type="button" id="emo" class="EMO">EMO</button>
	<script>
		document.querySelector("textarea").focus();
		var v = document.querySelector("textarea").value;
		document.querySelector("textarea").value = "";
		document.querySelector("textarea").value = v;
		if(document.cookie.split(";")[0].split("=")[0] = "text")
			exp = document.cookie.split(";")[0].split("=")[1]
		else
			exp = "";
		obj = {}
		obj.addToExp = function(event)
		{
			if(event.which==32)
			{
				exp = exp + " ";
				document.cookie = "text = "+exp;
				return;
			}

			if(exp==document.querySelector("textarea").value)
				return;
			exp = document.querySelector("textarea").value;
			document.cookie = "text = "+exp;
		}
		obj.emochange = function()
		{
			document.querySelector("emo").innerHTML = document.cookie.split(";")[1].split("=")[1];
		}
		obj.reload = function()
		{
			window.location.reload();
		}
		window.addEventListener("keyup", obj.addToExp)
		document.querySelector("#suggest").addEventListener("click", obj.reload)
	</script>
</body>
</html>
