<?php
session_start();
 ?>
<!DOCTYPE html>
<link rel="stylesheet" href="form.css" type="text/css" media="screen" title="no title" charset="utf-8"/>
<script src="jquery.min.js"></script>
<script src="validation.js"></script>
<script>
	function startTime() {
		myVar = setTimeout(function() {

			document.write("time finished");

		}, 3000);

	}
</script>
<?php

$opr = array('+', '-', '*', '/');
$questions = array();

function functionName($value1, $operator, $value2) {
	if ($operator == '+')
		return $value1 + $value2;
	if ($operator == '-')
		return $value1 - $value2;
	if ($operator == '*')
		return $value1 * $value2;
	if ($operator == '/')
		return $value1 / $value2;
}
 ?>
 
 
<html>
	<title>Regeistration Form</title>

	<body>
		<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>"class="basic-grey">
			<h1 id="test">Registration Form <span>please fill the below form</span></h1>
			
				<?php

				$left = rand(10, 100);
				$opre = $opr[rand(0, 3)];
				$right = rand(10, 100);
				$questions[0] = functionName($left, $opre, $right);
				?>
			<p>
				<label for="user"><?php echo $left, $opre, $right; ?></label>
				<input type="text" name="ques" value="" />
			</p>
			
				<input type="hidden" name="answer" value="<?php echo $questions[0]; ?>" />
			
			<p>
				<input type="submit" id="submit" value="Continue &rarr;"/>
			</p>
			
		</form>
		
	</body>
	<?php
	/*
	 echo "<h2>Your Input:</h2> ";
	 print_r($_POST);
	 echo "</br>";
	 echo "<h2>Your session:</h2> ";
	 print_r($_SESSION);
	 echo "</br>";*/

	if (!isset($_SESSION['count'])) {
		$_SESSION['count'] = 0;

		$_SESSION['time'] = time();
	} else {
		echo "</br>";
		echo "time: ";
		echo time() - $_SESSION['time'];
		echo "</br>";
		if ($_POST['ques'] == $_POST['answer']) {
			if (isset($_SESSION['right']))
				$_SESSION['right'] = $_SESSION['right'] + 1;
			else {
				$_SESSION['right'] = 1;
			}
			echo "right: ", $_POST['answer'];
		} else {
			if (isset($_SESSION['wrong']))
				$_SESSION['wrong'] = $_SESSION['wrong'] + 1;
			else {
				$_SESSION['wrong'] = 1;
			}
			echo "wrong: ", $_POST['answer'];
		}
		$_SESSION['count']++;

		if ($_SESSION['count'] == 5 || (time() - $_SESSION['time']) > 30) {
			echo "</br>";
			echo "your result \n";
			echo "</br>";
			echo "correct: ", $_SESSION['right'];

			echo "</br>";
			echo "wrong: ", $_SESSION['wrong'];
			session_destroy();

		}
	}
	?>
</html>