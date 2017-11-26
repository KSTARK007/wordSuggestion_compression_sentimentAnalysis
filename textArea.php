<html>
	<?php
		$exp = "";
		$arr = NULL;
		if(isset($_COOKIE["text"]))
		{
			$exp = $_COOKIE["text"];
			$arr = explode(" ", $exp);
			$suggests = exec("word ".$arr[count($arr)-1]);
		}

		echo "<form action=\"textArea.php\" method=\"post\"><textarea name = \"text\" rows='10' cols='90'>".$exp."</textarea><br><input type=\"submit\" value=\"SUGGEST\"><br>";
		if($arr)
		echo $arr[count($arr)-1].implode("  ".$arr[count($arr)-1],explode(" ",$suggests));
		$file = fopen("inputfile.txt","w+");
		fwrite($file,$exp."\n");
		fclose($file);
		exec("final.exe<inputfile.txt>outputfile.txt");

	?>
	<script>
		document.querySelector("textarea").focus();
		var v = document.querySelector("textarea").value;
		document.querySelector("textarea").value = "";
		document.querySelector("textarea").value = v;
		if(document.cookie.split(";")[0].split("=")[0] = "text")
			exp = document.cookie.split(";")[0].split("=")[1];
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
		window.addEventListener("keyup", obj.addToExp);
	</script>
</html>
