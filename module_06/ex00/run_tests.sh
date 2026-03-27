

while IFS= read -r line
do
	echo "\033[33m>>> $line\033[0m"
	$line
	echo
done < test_cases.txt