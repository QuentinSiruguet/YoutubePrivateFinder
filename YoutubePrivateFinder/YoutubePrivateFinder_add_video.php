<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" >
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	</head>

	<body>
		<?php
			$api_key = $_GET['api_key'];
			$id = $_GET['id']; 

			if($api_key == "THEKEYISNOTAAA")
			{
				$link = mysqli_connect("ghyfodia.fr", "ghyfodia", "Thisisnotmypassword", "ghyfodiadatabase");

				if($link === false){
					die("ERROR: Could not connect. " . mysqli_connect_error());
				}
					
				$sql = "INSERT INTO YoutubePrivateFinder_video (video_id) VALUES ('".$id."')";

				if(mysqli_query($link, $sql)){
					echo "Insert";
				} 

				else{
					echo "Error : " . mysqli_error($link);
				}
				mysqli_close($link);
			}
		?>
	</body>
</html>

